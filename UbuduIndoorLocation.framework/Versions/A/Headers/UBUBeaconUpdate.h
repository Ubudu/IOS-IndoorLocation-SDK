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

@interface UBUBeaconUpdate : NSObject

@property (nonatomic, copy, readonly) NSNumber *major;
@property (nonatomic, copy, readonly) NSNumber *minor;

@property (nonatomic, readonly) CGPoint position;

@property (nonatomic, readonly) CLProximity proximity;
@property (nonatomic, readonly) CLLocationAccuracy accuracy;
@property (nonatomic, readonly) NSInteger rssi;

- (instancetype)initWithBeacon:(UBUBeacon *)beacon CLBeacon:(CLBeacon *)clBeacon;

- (NSDictionary*)dictionary;

@end
