//
//  UBUPositionUpdate.h
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

#import <UbuduIndoorLocation/UBUBeacon.h>
#import <UbuduIndoorLocation/UBUZone.h>

typedef enum {
    kBLE = 0,
    kPDR,
    kGPS,
    kUnknownSource,
    kBLEAttractor
} PositionSource;

/**
 *  Contains the estimated position in the map at a given moment.
 */
@interface UBUPositionUpdate : NSObject <NSCopying>

/**
 *  The raw estimated position of the device on the map.
 */
@property (nonatomic, readonly) CGPoint estimatedPosition;

/**
 *  The geocoordinate for the raw estimated position of the device on the georeferenced map.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D estimatedCoordinate;

/**
 * Position smoothed over time.
 */
@property (nonatomic, readonly) CGPoint smoothedPosition;

/**
 *  The geocoordinate smoothed over time.
 */
@property (nonatomic, readonly) CLLocationCoordinate2D smoothedCoordinate;

/**
 * The closest navigable point from the current position.
 */
@property (nonatomic, readonly) CGPoint closestNavigablePoint;

/**
 *  The geocoordinate for the closest navigable point from the current position
 */
@property (nonatomic, readonly) CLLocationCoordinate2D closestNavigablePointCoordinate;

/**
 * The closest beacon from the current navigable position.
 */
@property (nonatomic, strong, readonly) UBUBeacon *closestBeacon;

/**
 * The closest zone from the current navigable position.
 */
@property (nonatomic, strong, readonly) UBUZone *closestZone;

/**
 * Current zones from the current navigable position.
 */
@property (nonatomic, strong, readonly) NSArray *currentZones;

/**
 * Level of the current map.
 */
@property (nonatomic, readonly) NSInteger level;

/**
 *  External level id. You may use it to link the level form ubudu BO with external map provider.
 */
@property (nonatomic) NSString *extLevel;

/**
 *  Date of the position update.
 */
@property (nonatomic, readonly) NSDate *date;

@property (nonatomic, readonly) PositionSource positionSource;

@property (nonatomic, readonly) NSArray *beacons;

/**
 * Initializes a newly created position update object with only estimated coordinate position.
 *
 *  @param estimatedCoordinate The estimated coordinate.
 *
 *  @return A position update initialized with the given estimated coordinate. Other fiedls are nil or CGPointMake(0,0);
 *
 */
- (instancetype)initWithEstimatedCoordinate:(CLLocationCoordinate2D)estimatedCoordinate;

/**
 *  Initializes a newly created position update object with only the estimated position.
 *
 *  @param estimatedPosition The estimated position.
 *
 *  @return A position update initialized with the given estimated position. Other fiedls are nil or CGPointMake(0,0);
 */
- (instancetype)initWithEstimatedPosition:(CGPoint)estimatedPosition;

/**
 *  Initializes a newly created position update object.
 *
 *  @param estimatedPosition     The estimated position.
 *  @param smoothedPosition      The estimated position smoothed over time.
 *  @param closestNavigablePoint The closest navigable point from the estimated position.
 *  @param closestBeacon         The closest beacon from the estimated position.
 *  @param closestZone           The closest zone from the estimated position.
 *
 *  @return A position update initialized with given estimated position and related info.
 */
- (instancetype)initWithEstimatedPosition:(CGPoint)estimatedPosition
                         smoothedPosition:(CGPoint)smoothedPosition
                    closestNavigablePoint:(CGPoint)closestNavigablePoint
                            closestBeacon:(UBUBeacon *)closestBeacon
                              closestZone:(UBUZone *)closestZone;

/**
 *  Initializes a newly created position update object.
 *
 *  @param estimatedPosition     The estimated position.
 *  @param smoothedPosition      The estimated position smoothed over time.
 *  @param closestNavigablePoint The closest navigable point from the estimated position.
 *  @param closestBeacon         The closest beacon from the estimated position.
 *  @param closestZone           The closest zone from the estimated position.
 *  @param currentZones          Current zones which position belongs to.
 *
 *  @return A position update initialized with given estimated position and related info.
 */
- (instancetype)initWithEstimatedPosition:(CGPoint)estimatedPosition
                         smoothedPosition:(CGPoint)smoothedPosition
                    closestNavigablePoint:(CGPoint)closestNavigablePoint
                            closestBeacon:(UBUBeacon *)closestBeacon
                              closestZone:(UBUZone *)closestZone
                             currentZones:(NSArray *)currentZones;

/**
 *  Serializes the position update to `NSDictionary`.
 *
 *  @return A position update represented as a `NSDictionary`.
 */
- (NSDictionary*)dictionary;

@end
