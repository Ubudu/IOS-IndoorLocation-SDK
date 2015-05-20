//
//  UBUBeacon.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 4/24/14.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

/**
 *  Represents a beacon placed on a map. Immutable object.
 */
@interface UBUBeacon : NSObject

/**
 *  Major value of the beacon.
 */
@property (nonatomic, copy, readonly) NSNumber *major;

/**
 *  Minor value of the beacon.
 */
@property (nonatomic, copy, readonly) NSNumber *minor;

/**
 *  Position of the beacon on the map.
 */
@property (nonatomic, readonly) CGPoint position;

/**
 *  Initialize a newly created beacon object.
 *
 *  @param major    Beacon major.
 *  @param minor    Beacon minor.
 *  @param position Beacon position.
 *
 *  @return A map initialized with its size.
 */
- (instancetype)initWithMajor:(NSNumber *)major
                        minor:(NSNumber *)minor
                     position:(CGPoint)position;

@end
