//
//  Mercator.m
//  Demo
//
//  Created by zioolek on 11/04/16.
//  Copyright © 2016 ubudu. All rights reserved.
//

#import "Mercator.h"

//offset is defined at zoom level 21 which means that this Mercator is valid for 21 zoom levels
static double kOffset = 268435456;

@implementation Mercator

+ (double)xToLng:(NSInteger)x zoom:(NSInteger)zoom
{
    double radius = kOffset / M_PI;
    double lng = (((double)(x<<(21 - zoom)) - kOffset) / radius) * 180.0 / M_PI;
    return lng;
}

+ (double)yToLat:(NSInteger)y zoom:(NSInteger)zoom
{
    double radius = kOffset / M_PI;
    double lat = (M_PI / 2 - 2 * atan(exp((double)((y<<(21-zoom)) - kOffset) / radius)))*180.0/M_PI;
    return lat;
}

+ (CLLocationCoordinate2D )locationCoordinateForX:(NSInteger)x y:(NSInteger)y zoom:(NSInteger)zoom
{
    double lon = [self xToLng:x zoom:zoom];
    double lat = [self yToLat:y zoom:zoom];
    return CLLocationCoordinate2DMake(lat, lon);
}

@end
