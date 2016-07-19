//
//  UBUParticle.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 04/04/16.
//  Copyright © 2016 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface UBUParticle : NSObject

/**
 *  The coordinates of the particle represented as a CGPoint.
 */
@property (nonatomic, readwrite) CGPoint point;

/**
 *  The weight of the particle
 */
//@property (nonatomic, readonly) double weight;
@property (nonatomic, readwrite) double weight;
- (instancetype)initWithPoint:(CGPoint)point andWeight:(double)w;

- (void)moveX:(CGFloat)x Y:(CGFloat)y;

@end
