//
//  CachedTileLayer.h
//  Demo
//
//  Created by zioolek on 13/04/16.
//  Copyright © 2016 ubudu. All rights reserved.
//

#import <GoogleMaps/GoogleMaps.h>

@interface CachedTileLayer : GMSTileLayer

- (instancetype)initWithBaseURL:(NSString *)baseURL topLeftCoordinate:(CLLocationCoordinate2D)topLeft andBottomRightCoordinate:(CLLocationCoordinate2D)bottomRight;

+ (BOOL)clearCache;

@end
