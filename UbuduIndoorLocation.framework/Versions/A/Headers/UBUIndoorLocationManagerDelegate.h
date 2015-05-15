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

@protocol UBUIndoorLocationManagerDelegate <NSObject>
@optional

- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateBeacons:(NSArray *)beaconsUpdates; // NSArray of UBUBeaconUpdate

- (void)locationManager:(UBUIndoorLocationManager *)locationManager positionDidChange:(UBUPositionUpdate *)positionUpdate;

- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestNavigablePointDidChange:(UBUPositionUpdate *)positionUpdate;

- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestBeaconDidChange:(UBUPositionUpdate *)positionUpdate;

- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestZoneDidChange:(UBUPositionUpdate *)positionUpdate;

@end
