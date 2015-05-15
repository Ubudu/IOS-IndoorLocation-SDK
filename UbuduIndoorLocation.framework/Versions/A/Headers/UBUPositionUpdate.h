//
//  UBUPositionUpdate.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 4/25/14.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

#import <UbuduIndoorLocation/UBUBeacon.h>
#import <UbuduIndoorLocation/UBUZone.h>

@interface UBUPositionUpdate : NSObject

/*
 * The raw estimated position of the device on the map.
 */
@property (nonatomic, readonly) CGPoint estimatedPosition;

/*
 * Position smoothed over N last estimated positions.
 */
@property (nonatomic, readonly) CGPoint smoothedPosition;

/*
 * The closest navigable point from the current position.
 */
@property (nonatomic, readonly) CGPoint closestNavigablePoint;

/*
 * The closest beacon from the current navigable position.
 */
@property (nonatomic, strong, readonly) UBUBeacon *closestBeacon;

/*
 * The closest zone from the current navigable position.
 */
@property (nonatomic, strong, readonly) UBUZone *closestZone;

- (instancetype)initWithEstimatedPosition:(CGPoint)estimatedPosition
                         smoothedPosition:(CGPoint)smoothedPosition
                    closestNavigablePoint:(CGPoint)closestNavigablePoint
                            closestBeacon:(UBUBeacon *)closestBeacon
                              closestZone:(UBUZone *)closestZone;

- (instancetype)initWithEstimatedPosition:(CGPoint)estimatedPosition;

- (NSDictionary*)dictionary;

@end
