//
//  UBUUtils.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 22/04/14.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface UBUUtils : NSObject

+ (CGFloat)distanceToPoint:(CGPoint)p fromLineSegmentBetween:(CGPoint)l1 and:(CGPoint)l2;
+ (CGPoint)projectionOfPoint:(CGPoint)p onLineSegmenthBetween:(CGPoint)l1 and:(CGPoint)l2;
+ (double)distanceBetween:(CGPoint)p1 and:(CGPoint)p2;
+ (double)gaussianDistributionForX:(double)x mean:(double)mean andSd:(double)sd;
+ (NSString *)appNamespace;
@end
