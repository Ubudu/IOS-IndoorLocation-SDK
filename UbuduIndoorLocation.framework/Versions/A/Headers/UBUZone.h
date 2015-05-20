//
//  UBUZone.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 21/06/2014.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

/**
 *  Representation of a rectangular zone on the map. Immutable object.
 */
@interface UBUZone : NSObject

/**
 *  Identifier of the zone. Must be unique in a given map.
 */
@property (nonatomic, copy, readonly) NSNumber *zoneID;

/**
 *  Name of the zone.
 */
@property (nonatomic, copy, readonly) NSString *name;

/**
 *  List of tags assigned to the zone. Array of `NSString`.
 *  Usage of those tags is at your discretion.
 */
@property (nonatomic, copy, readonly) NSArray *tags;

/**
 *  Size of the zone.
 */
@property (nonatomic, readonly) CGSize size;

/**
 *  Origin of the zone on the map.
 */
@property (nonatomic, readonly) CGPoint origin;

/**
 *  Initialize a newly created zone object.
 *
 *  @param zoneID Identifier of the zone.
 *  @param name   Name of the zone.
 *  @param tags   Tags assigned to the zone.
 *  @param origin Origin of the zone rectangle.
 *  @param size   Size of the zone rectangle.
 *
 *  @return A zone initialized with its identifier, name, tags and rectangular zone.
 */
- (instancetype)initWithZoneID:(NSNumber *)zoneID
                          name:(NSString *)name
                          tags:(NSArray *)tags
                        origin:(CGPoint)origin
                          size:(CGSize)size;

/**
 *  Computes the minimum distance between given point and the zone side closest to this point.
 *
 *  @param point Given point to which the distance is computed.
 *
 *  @return Minimum distance between zone and given point.
 */
- (CGFloat)distanceToPoint:(CGPoint)point;

@end
