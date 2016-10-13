//
//  UBUMap.h
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
#import <CoreLocation/CoreLocation.h>

#import <UbuduIndoorLocation/UBUBeacon.h>
#import <UbuduIndoorLocation/UBUZone.h>

/**
 *  Represent a physical venue in which you can get position updates.
 *  Contains all entities involved in indoor location and that are positioned in space, like beacons. `UBUMap` objects are immutable.
 */
@interface UBUMap : NSObject

/**
 *  Dimmensions of the physical venue represented by this map.
 */
@property (nonatomic, readonly) CGSize size;

/**
 *  The beacons positioned inside the venue. NSArray of `UBUBeacon`.
 */
@property (nonatomic, strong, readonly) NSArray *beacons;

/**
 *  The zones defined inside the venue. NSArray of `UBUZone`.
 */
@property (nonatomic, strong, readonly) NSArray *zones;

/**
 *  The non walkable zones defined inside the venue. NSArray of `UBUZone`.
 */
@property (nonatomic, strong, readonly) NSArray *nonWalkableZones;

/**
 *  Points of interest
 */
@property (nonatomic, strong, readonly) NSArray *pois;

@property (nonatomic, strong) NSString *uuid;

/**
 *  Level of the map
 */
@property (nonatomic) NSInteger level;

/**
 *  External level id. You may use it to link the level form ubudu BO with external map provider.
 */
@property (nonatomic) NSString *extLevel;

/**
 *  Initializes a newly created map object.
 *
 *  @param Size of the map.
 *
 *  @return Value description
 */
- (instancetype)initWithSize:(CGSize)size;

/**
 * The url to the map image file
 */
@property (nonatomic, strong) NSString *imageUrl;


/**
 * The url of the map tiles
 */
@property(nonatomic, strong) NSString *tilesUrl;

/**
 *  Retrieve a zone by its identifier.
 *
 *  @param zoneID The identifier of the zone to retrieve.
 *
 *  @return The matching `UBUZone` if found with the given identifier, nil otherwise.
 */
- (UBUZone *)getZoneByID:(NSNumber *)zoneID;

/**
 *  Filters zones by tag.
 *
 *  @param tag The tag to use to filter zones.
 *
 *  @return The `UBUZone` containing the given tag.
 */
- (NSArray *)getZonesByTag:(NSString *)tag;

/**
 *
 * @return geographical coordinates of the top left anchor of the map.
 */
- (CLLocationCoordinate2D)topLeftAnchorCoordinates;

/**
 *
 * @return geographical coordinates of the bottom right anchor of the map.
 */
- (CLLocationCoordinate2D)bottomRightAnchorCoordinates;

@end
