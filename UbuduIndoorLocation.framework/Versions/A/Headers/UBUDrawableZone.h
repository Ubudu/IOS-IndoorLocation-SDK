//
//  UBUDrawableZone.h
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

#import <UIKit/UIKit.h>

#import <UbuduIndoorLocation/UBUPolygon.h>
#import <UbuduIndoorLocation/UBUZone.h>

/**
 *  An entity allowing a `UBUMapViewController` to draw an `UBUZone` on the map.
 */
@interface UBUDrawableZone : UBUPolygon

/**
 *  The ID of the zone.
 */
@property (nonatomic, copy, readonly) NSNumber *zoneID;

/**
 *  The name of the zone.
 */
@property (nonatomic, copy, readonly) NSString *zoneName;

/**
 *  The bounding box of the zone.
 */
@property (nonatomic, readonly) CGRect zoneRect;

/**
 *  Filling color for the zone when drawn on the map.
 */
@property (nonatomic, strong) UIColor *fillColor;

/**
 *  Border color for the zone when drawn on the map.
 */
@property (nonatomic, strong) UIColor *borderColor;

/**
 *  Creates a new drawable zone with a `UBUZone`.
 *
 *  @param zone The zone to be drawn.
 *
 *  @return A drawable zone initialized to draw the given zone.
 */
+ (UBUDrawableZone *)drawableZoneWithZone:(UBUZone *)zone;

/**
 *  Initializes a newly created drawable zone object.
 *
 *  @param zone The zone to draw on the map.
 *
 *  @return A drawable zone initialized to draw the given zone.
 */
- (instancetype)initWithZone:(UBUZone *)zone;

@end
