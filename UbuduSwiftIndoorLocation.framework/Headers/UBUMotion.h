//
//  UBUMotion.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 07/03/16.
//  Copyright © 2016 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreMotion/CoreMotion.h>
#import <MapKit/MapKit.h>

typedef enum UBUMotionMode : int {
    kUBUMotionModeSwing = 0,
    kUBUMotionModePocket,
    kUBUMotionModeHoldingPortrait,
    kUBUMotionModeHoldingLandscapeXUp,
    kUBUMotionModeHoldingLandscapeXDown,
    kUBUMotionModeTable
}UBUMotionMode;

@interface UBUMotion : NSObject

@property (nonatomic, strong) CMDeviceMotion *deviceMotion;
@property (nonatomic) double verticalAcceleration;
@property (nonatomic) double filteredVerticalAcceleration;
@property (nonatomic) UBUMotionMode motionMode;
@property (nonatomic) NSTimeInterval timestamp;
@property (nonatomic, strong) NSDate *motionDate;

@property (nonatomic, getter = isPeak) BOOL peak;
@property (nonatomic, getter = isTrough) BOOL trough;
@property (nonatomic, getter = isStep) BOOL step;

@property (nonatomic, strong) CLHeading *heading;

+ (UBUMotionMode)determineMotionModeForMotion:(CMAcceleration)gravity;
+ (void)updateStepLength:(double)newStepLength;
+ (double)stepLength;

- (instancetype)initWithDeviceMotion:(CMDeviceMotion *)dm;
- (instancetype)initWithDeviceMotion:(CMDeviceMotion *)dm verticalAcceleration:(double)vc;

@end
