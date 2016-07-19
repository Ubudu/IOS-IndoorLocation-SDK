//
//  UBUIndoorLocationManagerDelegate.h
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

#import <Foundation/Foundation.h>

#import <UbuduIndoorLocation/UBUBeacon.h>
#import <UbuduIndoorLocation/UBUZone.h>
#import <UbuduIndoorLocation/UBUPositionUpdate.h>
#import <UbuduIndoorLocation/UBUMotion.h>
#import <CoreMotion/CoreMotion.h>

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
 *  @param beaconsUpdates  NSArray of `UBUBeacon` representing the beacons visible around the device and involved in the map configuration.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateBeacons:(NSArray *)beaconsUpdates;

/**
 *  Invoked when the position of the device changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the estimated position and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangePosition:(UBUPositionUpdate *)positionUpdate;

/**
 *  Invoked when the closest navigable point from the estimated position changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the closest navigable point and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangeClosestNavigablePoint:(UBUPositionUpdate *)positionUpdate;

/**
 *  Invoked when the closest beacon from the estimated position changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the closest beacon and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangeClosestBeacon:(UBUPositionUpdate *)positionUpdate;

/**
 *  Invoked when the closest zone from the estimated position changes.
 *
 *  @param locationManager The location manager that generated the event.
 *  @param positionUpdate  The position update object containing the closest zone and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangeClosestZone:(UBUPositionUpdate *)positionUpdate;

/**
 * Invoked when current zones from the estimated position changes.
 * @param positionUpdate  The position update object containing current zones and other related info.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangeZones:(UBUPositionUpdate *)positionUpdate;

/**
 * Invoked when heading changes.
 * @param newHeading    Object containing new heading.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateHeading:(CLHeading *)newHeading;

/**
 * Invoked when indoor location failed with error.
 */
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didFailWithError:(nonnull NSError *)error;

- (void)locationManager:(nonnull UBUIndoorLocationManager *)locationManager didUpdateParticles:(NSArray *)particles;

@end
