//
//  UBUMap.h
//  UbuduIndoorLocation
//
//  Created by ubudu imac on 27/04/15.
//  Copyright (c) 2015 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

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
 *  Initialize a newly created map object.
 *
 *  @param size Size of the map.
 *
 *  @return <#return value description#>
 */
- (instancetype)initWithSize:(CGSize)size;

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

@end
