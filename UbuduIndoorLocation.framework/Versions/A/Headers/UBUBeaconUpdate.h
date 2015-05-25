//
//  UBUBeaconUpdate.h
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

@class UBUBeacon;

/**
 *  Contains the data of a specific beacon as seen at a given moment in time.
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
 *  Initializes a newly created beacon update object from a beacon on the map and a corresponding CLBeacon seen around the device.
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
