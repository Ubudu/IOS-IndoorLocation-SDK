//
//  UBUBeacon.h
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

/**
 *  Represents a beacon placed on a map. Immutable object.
 */
@interface UBUBeacon : NSObject <NSCopying>

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
 *  Accuracy of the beacon update. This value is computed by CoreLocation.
 */
@property (nonatomic, readonly) CLLocationAccuracy accuracy;

/**
 *  The strenght of the signal receive from the beacon. This value is computed by CoreLocation.
 */
@property (nonatomic, readonly) NSInteger rssi;

/**
 *  The flag indicates if that beacon was used to calculate the position
 */
@property (nonatomic, readonly) BOOL wasUsedForPositionCalculation;

/**
 *  Initializes a newly created beacon object.
 *
 *  @param major    Beacon major.
 *  @param minor    Beacon minor.
 *  @param position Beacon position.
 *
 *  @return A beacon initialized with its major minor and position.
 */
- (instancetype)initWithMajor:(NSNumber *)major
                        minor:(NSNumber *)minor
                     position:(CGPoint)position;

/**
 *  Initializes a newly created beacon object with data from CLBeacon (RSSI, accuracy)
 *
 *  @param major    Beacon major.
 *  @param minor    Beacon minor.
 *  @param position Beacon position.
 *  @param clBeacon CLBeacon
 *  @param proximityUUID proximity UUID of the beacon 
 *
 *  @return A map initialized with its major, minor, position, proximity UUID and CLBeacon.
 */

- (instancetype)initWithMajor:(NSNumber *)major
                        minor:(NSNumber *)minor
                     position:(CGPoint)position
                     CLBeacon:(CLBeacon *)clBeacon
                proximityUUID:(NSUUID *)proximityUUID;


@end
