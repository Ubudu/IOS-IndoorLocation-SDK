//
//  UBUBeaconUpdate.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 4/23/14.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

@class UBUBeacon;

/**
 *  Contains the data for a specific beacon as seen at a given moment in time.
 */
@interface UBUBeaconUpdate : NSObject

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
 *  Proximity of the beacon in this update. This value is computed by CoreLocation.
 */
@property (nonatomic, readonly) CLProximity proximity;

/**
 *  Accuracy of the beacon update. This value is computed by CoreLocation.
 */
@property (nonatomic, readonly) CLLocationAccuracy accuracy;

/**
 *  The strenght of the signal receive from the beacon. This value is computed by CoreLocation.
 */
@property (nonatomic, readonly) NSInteger rssi;

/**
 *  Initialize a newly created beacon update object from a beacon on the map and a corresponding CLBeacon seen around the device.
 *
 *  @param beacon   Beacon positioned on the map.
 *  @param clBeacon Corresponding CLBeacon seen around the device.
 *
 *  @return A beacon update initiliazed with beacon identifying values, position and signal data.
 */
- (instancetype)initWithBeacon:(UBUBeacon *)beacon CLBeacon:(CLBeacon *)clBeacon;

/**
 *  Serializes the beacon update to `NSDictionary`.
 *
 *  @return A beacon update represented as a `NSDictionary`.
 */
- (NSDictionary*)dictionary;

@end
