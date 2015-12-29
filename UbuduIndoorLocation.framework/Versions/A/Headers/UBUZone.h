//
//  UBUZone.h
//  UbuduIndoorLocation
//
// Copyright (c) 2014, UBUDU SAS
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//         SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <CoreGraphics/CoreGraphics.h>
#import <UbuduIndoorLocation/UBUPolygon.h>
#import <UIKit/UIKit.h>

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


@property (nonatomic, copy, readonly) UIColor *color;

/**
 *  Initializes a newly created zone object.
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
                         shape:(NSDictionary *)shape;


- (instancetype)initWithZoneID:(NSNumber *)zoneID
                          name:(NSString *)name
                          tags:(NSArray *)tags
                         shape:(NSDictionary *)shape
                         color:(UIColor *)color;

/**
 *  Computes the minimum distance between given point and the zone side closest to this point.
 *
 *  @param point Given point to which the distance is computed.
 *
 *  @return Minimum distance between zone and given point.
 */
- (CGFloat)distanceToPoint:(CGPoint)point;


/**
 * Return a UBUPolygon object for this zone
 */
- (UBUPolygon *)polygon;

@end
