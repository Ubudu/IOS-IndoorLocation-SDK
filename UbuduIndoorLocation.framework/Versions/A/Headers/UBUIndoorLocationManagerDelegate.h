//
//  UBUIndoorLocationManagerDelegate.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 23/05/2014.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UbuduIndoorLocation/UBUBeacon.h>
#import <UbuduIndoorLocation/UBUZone.h>
#import <UbuduIndoorLocation/UBUBeaconUpdate.h>
#import <UbuduIndoorLocation/UBUPositionUpdate.h>

@class UBUIndoorLocationManager;

/**
 * The `UBUIndoorLocationManagerDelegate` protocol defines the methods you can implement to receive event from the `UBUIndoorLocationManager`.
 */
@protocol UBUIndoorLocationManagerDelegate <NSObject>
@optional

// TODO rename locationManager into indoorLocationManager in all methods

/**
 *  Invoked when the location manager receive an update from beacons nearby the device.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param beaconsUpdates  NSArray of `UBUBeaconUpdate` representing the beacons visible around the device and involved in the map configuration.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateBeacons:(NSArray *)beaconsUpdates;

/**
 *  Invoked when the position of the device changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the estimated position and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager positionDidChange:(UBUPositionUpdate *)positionUpdate;

/**
 *  Invoked when the closest navigable point from the estimated position changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the closest navigable point and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestNavigablePointDidChange:(UBUPositionUpdate *)positionUpdate;

/**
 *  Invoked when the closest beacon from the estimated position changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the closest beacon and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestBeaconDidChange:(UBUPositionUpdate *)positionUpdate;

/**
 *  Invoked when the closest zone from the estimated position changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the closest zone and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestZoneDidChange:(UBUPositionUpdate *)positionUpdate;

@end
