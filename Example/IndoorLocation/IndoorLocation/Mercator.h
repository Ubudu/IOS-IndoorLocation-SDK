//
//  Mercator.h
//  Demo
//
//  Created by zioolek on 11/04/16.
//  Copyright © 2016 ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MapKit/MapKit.h>

@interface Mercator : NSObject

+ (double)xToLng:(NSInteger)x zoom:(NSInteger)zoom;
+ (double)yToLat:(NSInteger)y zoom:(NSInteger)zoom;
+ (CLLocationCoordinate2D ) locationCoordinateForX:(NSInteger)x y:(NSInteger)y zoom:(NSInteger)zoom;

@end
