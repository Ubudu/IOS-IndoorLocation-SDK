//
//  UBUIndoorLocationManager.h
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

#import <UbuduIndoorLocation/UBUIndoorLocationManagerDelegate.h>
#import <UbuduIndoorLocation/UBUMap.h>
#import <UbuduIndoorLocation/UBUPositionUpdate.h>

@protocol UBULogger;
@class UBUIndoorLocationConfiguration;
/**
 *  `UBUIndoorLocationManager` class contains the main interface to use Ubudu Indoor Location SDK.
 *
 *  You typically use this class to load the map of a venue and receive position updates.
 *  You should have only one instance of this class inside your application.
 */
@interface UBUIndoorLocationManager : NSObject


/**
 *  This is the configuration for Indoor Location manager. Pass the proper configuration before starting IL.
 *  See UbuduIndoorLocationConfiguration for more details.
 */
@property (nonatomic, strong) UBUIndoorLocationConfiguration *configuration;

/**
 *  The delegate object that receives events from the location manager, like position update events.
 */
@property (nonatomic, weak) id<UBUIndoorLocationManagerDelegate> delegate;

/**
 *  Is the location manager currently started.
 */
@property (nonatomic, readonly, getter=isRunning) BOOL running;

/**
 *  The current map used in which to compute device position.
 */
@property (nonatomic, strong, readonly) UBUMap *currentMap;

/**
 *  Last known position.
 */
@property (nonatomic, strong, readonly) UBUPositionUpdate *lastPosition;

/**
 *  The current heading of the device
 */
@property (nonatomic) CLHeading *currentHeading;

/**
 *  Motion manager used to analyze user's movement
 */
@property (nonatomic, strong, readonly) CMMotionManager *motionManager;

/**
 *  Version of the SDK.
 */
@property (nonatomic, readonly) NSString *version;

/**
 *  Custom logger for indoor location.
 */
@property (nonatomic) id <UBULogger> customLogger;

/**
 *  Version of the SDK.
 */
+ (NSString *)version;

/**
 *  Singleton of indoor location manager
 */
+ (instancetype)sharedInstance;

/**
 *  This method returns TRUE if user is walking or was walking in past few seconds.
 */
- (BOOL)isMoving;

- (instancetype)init __attribute__((unavailable("This method is not available. Please use sharedInstance instead.")));

/**
 *  Start computing the device position.
 *  If IL started succesfully, the completion block is called with nil.
 */
- (void)startWithCompletionBlock:(void(^)(NSError *error))completionBlock;

/**
 *  Resume IL after stopping it
 */
- (void)resume:(NSError **)error;

/**
 *  Stop computing the device position.
 */
- (void)stop;

/**
 *  Loads a stored map for specific map uuid. This method also set the map as a current map.
 *  returns a UBUMap or nil if failed.
 */
- (UBUMap *)loadMapForUUID:(NSString *)mapUUID;


/**
 *  The method to force to switch the current map.
 *  @param the map to wich we are going to switch.
 */
- (void)forceToSwtichCurrentMap:(UBUMap *)map;

/**
 * @param point a point on the map.
 * @return geographical coordinates (latitude, longitude) for the given point.
 */
- (CLLocationCoordinate2D)geoCoordinateForPoint:(CGPoint)point;

/**
 * @param coordinate a geo coordinate of the position.
 * @return Point in cartesian (XY) coordinates for the given geographical coordinates (latitude, longitude).
 */
- (CGPoint)pointForGeoCoordinate:(CLLocationCoordinate2D)coordinate;

- (UIImage *)mapOverlayForCurrentMap;

- (UIImage *)mapOverlayForMap:(UBUMap *)map;

/**
 *  The method return uuids of the stored local maps.
 */
- (NSArray *)storedMapUUIDs;

- (NSArray *)loadAllStoredMaps;

/**
 *  Default real time logger.
 */
- (id <UBULogger>)defaultRealTimeLogger;

@end
