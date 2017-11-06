//
//  UBUIndoorLocationConfiguration.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 05/10/2017.
//  Copyright © 2017 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UBUIndoorLocationConfiguration : NSObject

/**
 *  The Ubudu IL namespace of the application.
 *
 *  Need to be set to the value provided by the Ubudu manager platform in order to retrieve the venues you defined for your application.
 */
@property (nonatomic, strong, readonly)                         NSString *appNamespace;

/**
 *  The flag indicates if indoor location manager shoould updates heading. Default is NO.
 */
@property (nonatomic, getter=isUpdateheadingEnabled)            BOOL updateHeading;

/**
 *  The flag indicates if Indoor Location Manager is using motion filtering to improve stability of positioning
 */
@property (nonatomic, getter=isUsingMotionMonitorFiltering)     BOOL motionFiltering;

/**
 *  The flag indicates when "transition" zones are used to switch between maps.
 */
@property (nonatomic, getter=isTransitionZonesModeEnabled)      BOOL transitionZonesMode;

/**
 *  The flag indicates if location manager should automatically change the map or not. YES by default.
 */
@property (nonatomic, getter=isUsingAutomaticFloorSwitching)    BOOL automaticFloorSwitching;

/**
 *  The accuracy treshold. Ranged beacons with accuracy higher than this treshold will not be used to estimate the position.
 *  By default, the accuracy treshold is set to 15.0.
 *
 *  DO NOT CHANGE THIS VALUE UNTIL YOU ARE SURE WHAT YOU ARE DOING.
 *  CHANGING THIS VALUE MAY REDUCE THE ACCURACY OF THE ESTIMATED POSITION.
 */
@property (nonatomic)                                           double accuracyTreshold;

/**
 *  A method to init a configuration with a namespaceslack
 
 */
-(instancetype)initWithAppNamespace:(NSString *)appNamespace;

@end

