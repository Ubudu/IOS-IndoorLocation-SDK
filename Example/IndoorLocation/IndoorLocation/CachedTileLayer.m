//
//  CachedTileLayer.m
//  Demo
//
//  Created by zioolek on 13/04/16.
//  Copyright © 2016 ubudu. All rights reserved.
//

#import "CachedTileLayer.h"
#import "Mercator.h"
#import <CommonCrypto/CommonDigest.h>


static NSString *kTileCache = @"UbuduMapCache";

@interface CachedTileLayer ()

@property (nonatomic, strong) NSString *baseURL;
@property (nonatomic, strong) GMSCoordinateBounds *overlayBounds;

@end

@implementation CachedTileLayer

- (instancetype)initWithBaseURL:(NSString *)baseURL topLeftCoordinate:(CLLocationCoordinate2D)topLeft andBottomRightCoordinate:(CLLocationCoordinate2D)bottomRight
{
    self = [super init];
    if (self) {
        _baseURL = baseURL;
        
        CLLocationCoordinate2D topRightCoordinates = CLLocationCoordinate2DMake(topLeft.latitude, bottomRight.longitude);
        CLLocationCoordinate2D bottomLeftCoordinates = CLLocationCoordinate2DMake(bottomRight.latitude, topLeft.longitude);
        
        _overlayBounds = [[GMSCoordinateBounds alloc] initWithCoordinate:topRightCoordinates
                                                              coordinate:bottomLeftCoordinates];
    }
    
    return self;
}

+ (BOOL)clearCache
{
    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString* cachesPath = [paths objectAtIndex:0];
    NSString* cachePath = [cachesPath stringByAppendingPathComponent:kTileCache];
    return [self deletePathIfPossible:cachePath];
}

#pragma mark - Private methods

- (NSString *)urlForX:(NSUInteger)x Y:(NSUInteger)y zoom:(NSUInteger)zoom
{
    NSUInteger ymax = 1 << zoom;
    NSUInteger y_m = ymax - y - 1;
    CLLocationCoordinate2D s_w = [Mercator locationCoordinateForX:(NSInteger)(x*256) y:(NSInteger)(y+1)*256 zoom:zoom];
    CLLocationCoordinate2D n_e = [Mercator locationCoordinateForX:(NSInteger)((x+1)*256) y:(NSInteger)(y*256) zoom:zoom];
    GMSCoordinateBounds *tileBounds = [[GMSCoordinateBounds alloc] initWithCoordinate:s_w coordinate:n_e];
    NSString *url = @"https://imagesd.ubudu.com/u_maps_tiles/none.png";// nil; //@"http://imagescdn.ubudu.com/u_maps_tiles/none.png";
    
    if ([self.overlayBounds intersectsBounds:tileBounds]) {
        url = [self.baseURL stringByReplacingOccurrencesOfString:@"{x}" withString:[NSString stringWithFormat:@"%lu", (unsigned long)x]];
        url = [url stringByReplacingOccurrencesOfString:@"{y}" withString:[NSString stringWithFormat:@"%lu", (unsigned long)y_m]];
        url = [url stringByReplacingOccurrencesOfString:@"{z}" withString:[NSString stringWithFormat:@"%lu", (unsigned long)zoom]];
    }
    
    return url; // ???: Should return nil if there is no valid url or none.png?
}

- (void)requestTileForX:(NSUInteger)x y:(NSUInteger)y zoom:(NSUInteger)zoom receiver:(id<GMSTileReceiver>)receiver
{
    NSString *urlString = [self urlForX:x Y:y zoom:zoom];
    
    if (!urlString) {
        [receiver receiveTileWithX:x y:y zoom:zoom image:kGMSTileLayerNoTile];
        return;
    }
    
    NSString *filePath = [self filePathForURL:urlString andFileName:kTileCache];
    
    if ([[NSFileManager defaultManager] fileExistsAtPath: filePath]){
        // Draw cached image
        [self drawTileAtX:x Y:y Zoom:zoom Url:urlString Receiver:receiver] ;
        return;
    }else {
        // Download image
        NSURL *url = [NSURL URLWithString:urlString];
        [[[NSURLSession sessionWithConfiguration:[NSURLSessionConfiguration defaultSessionConfiguration]]
          dataTaskWithURL:url
          completionHandler:^(NSData *data, NSURLResponse *response, NSError *error) {
            if (error == nil) {
                [data writeToFile:filePath atomically:YES];
                [self drawTileAtX:x Y:y Zoom:zoom Url:urlString Receiver:receiver];
            } else {
                [receiver receiveTileWithX:x y:y zoom:zoom image:nil]; // ???: kGMSTileLayerNoTile instead of nil?
            }
        }] resume];
    }
}

- (void)drawTileAtX:(NSUInteger)x Y:(NSUInteger)y Zoom:(NSUInteger)zoom Url:(NSString *)url Receiver:(id<GMSTileReceiver>)receiver
{
    UIImage *image = [self loadTileForUrl:url];
    [receiver receiveTileWithX:x y:y zoom:zoom image:image];
}

- (UIImage *)loadTileForUrl:(NSString *)url
{
    UIImage  *image = nil;
    NSString *filePath = [self filePathForURL:url andFileName:kTileCache];
    if ([[NSFileManager defaultManager] fileExistsAtPath: filePath]){
        image = [UIImage imageWithData:[NSData dataWithContentsOfFile:filePath]];
    }
    return image;
}

- (NSString *)filePathForURL:(NSString *)stringUrl andFileName:(NSString *)folderName
{
    return [[self cachePathWithName:folderName] stringByAppendingPathComponent:[self md5Hash:stringUrl]];;
}

- (NSString *)cachePathWithName:(NSString *)name
{
    NSArray* paths = NSSearchPathForDirectoriesInDomains(NSDocumentDirectory, NSUserDomainMask, YES);
    NSString* cachesPath = [paths objectAtIndex:0];
    NSString* cachePath = [cachesPath stringByAppendingPathComponent:name];
    
    [self createPathIfNecessary:cachesPath];
    [self createPathIfNecessary:cachePath];
    
    return cachePath;
}

- (BOOL)createPathIfNecessary:(NSString *)path
{
    BOOL succeeded = YES;
    
    NSFileManager* fm = [NSFileManager defaultManager];
    if (![fm fileExistsAtPath:path]) {
        succeeded = [fm createDirectoryAtPath: path
                  withIntermediateDirectories: YES
                                   attributes: nil
                                        error: nil];
    }
    
    return succeeded;
}

+ (BOOL)deletePathIfPossible:(NSString *)path
{
    NSFileManager *fm = [NSFileManager defaultManager];
    NSError *error = nil;
    for (NSString *file in [fm contentsOfDirectoryAtPath:path error:&error]) {
        BOOL success = [fm removeItemAtPath:[NSString stringWithFormat:@"%@%@", path, file] error:&error];
        if (!success || error) {
            // it failed.
            return NO;
        }
    }
    return YES;
}

- (NSString *)md5Hash:(NSString *)stringData
{
    NSData *data = [stringData dataUsingEncoding:NSUTF8StringEncoding];
    unsigned char result[CC_MD5_DIGEST_LENGTH];
    CC_MD5([data bytes], (CC_LONG)[data length], result);
    
    return [NSString stringWithFormat:
            @"%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
            result[0], result[1], result[2], result[3], result[4], result[5], result[6], result[7],
            result[8], result[9], result[10], result[11], result[12], result[13], result[14], result[15]
            ];
    return nil;
}
@end
