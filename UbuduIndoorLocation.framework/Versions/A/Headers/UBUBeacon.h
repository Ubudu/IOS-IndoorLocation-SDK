//
//  UBUBeacon.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 4/24/14.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

@interface UBUBeacon : NSObject

/*
 * Beacon configuration
 */
@property (nonatomic, copy, readonly) NSNumber *major;
@property (nonatomic, copy, readonly) NSNumber *minor;

/*
 * Position of the beacon on the map
 */
@property (nonatomic, readonly) CGPoint position;

- (instancetype)initWithMajor:(NSNumber *)major
                        minor:(NSNumber *)minor
                     position:(CGPoint)position;

@end
