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

/**
 *  `UBUIndoorLocationManager` class contains the main interface to use Ubudu Indoor Location SDK.
 *
 *  You typically use this class to load the map of a venue and receive position updates.
 *  You should have only one instance of this class inside your application.
 */
@interface UBUIndoorLocationManager : NSObject

/**
 *  The Ubudu IL namespace of the application.
 *
 *  Need to be set to the value provided by the Ubudu manager platform in order to retrieve the venues you defined for your application.
 */
@property (nonatomic, strong, readonly) NSString *appNamespace;

/**
 *  The delegate object that receives events from the location manager, like position update events.
 */
@property (nonatomic, weak) id<UBUIndoorLocationManagerDelegate> delegate;

/**
 *  Is the location manager currently started.
 */
@property (nonatomic, readonly, getter=isRunning) BOOL running;

/**
 *  The proximity UUID of the beacons to monitor.
 */
@property (nonatomic, copy, readonly) NSString *proximityUUID;

/**
 *  The current map used in which to compute device position.
 */
@property (nonatomic, strong, readonly) UBUMap *currentMap;

/*
 *  The flag indicates if the manager should use rectified or non-rectified map. It is YES by default.
 */
@property (nonatomic) BOOL useRectifiedMaps;

/**
 *  Last known position.
 */
@property (nonatomic, strong, readonly) UBUPositionUpdate *lastPosition;

/**
 *  The flag indicates if Indoor Location Manager is using motion filtering to improve stability of positioning
 */
@property (nonatomic, getter=isUsingMotionMonitorFiltering) BOOL motionFiltering;

/**
 *  The flag indicates if indoor location manager shoould updates heading. Default is NO.
 */
@property (nonatomic, getter=isUpdateheadingEnabled) BOOL updateHeading;

/**
 *  The flag indicates when "transition" zones are used to switch between maps.
 */
@property (nonatomic, getter=isTransitionZonesModeEnabled) BOOL transitionZonesMode;

/**
 *  The current heading of the device
 */
@property (nonatomic) CLHeading *currentHeading;

/**
 *  The accuracy treshold. Ranged beacons with accuracy higher than this treshold will not be used to estimate the position.
 *  By default, the accuracy treshold is set to 15.0.
 *
 *  DO NOT CHANGE THIS VALUE UNTIL YOU ARE SURE WHAT YOU ARE DOING.
 *  CHANGING THIS VALUE MAY REDUCE THE ACCURACY OF THE ESTIMATED POSITION.
 */
@property (nonatomic) double accuracyTreshold;

/**
 *  The flag indicates if location manager should automatically change the map or not. YES by default.
 */
@property (nonatomic) BOOL automaticFloorSwitching;

/**
 *  Motion manager used to analyze user's movement
 */
@property (nonatomic, strong, readonly) CMMotionManager *motionManager;

/**
 *  Version of the SDK.
 */
@property (nonatomic, readonly) NSString *version;

/**
 *  Version of the SDK.
 */
+ (NSString *)version;

/**
 *  Singleton of indoor location manager
 */
+ (instancetype)sharedInstance;

/**
 * This method allows you to preload ubudu map data for your namespace.
 * @discussion To prepare a data for preloading - launch your app and fetch latest map data.
 * Plug your iOS device to your mac and in xcode open devices window and download a container for your app.
 * From documents/ubudu directory copy the folder named with your namespace to your xcode project and add it to
 * Copy Bundle Resources in Build Phases. Then call this method before starting IL.
 *
 * @param foldername - the name of the folder in the bundle’s subdirectory containing resources. it should be named with the application's namespace
 * @return return YES if resources with map were preloaded properly and returns NO if there are already some data in the folder.
 */
+ (BOOL)preloadMapDataFromSourceFolder:(NSString *)folderName;

/**
 *  This method returns TRUE if user is walking or was walking in past few seconds.
 */
- (BOOL)isMoving;

- (instancetype)init __attribute__((unavailable("This method is not available. Please use sharedInstance instead.")));

/**
 *  The Ubudu namespace of the application. Must be set before starting the SDK.
 *  This method fetches all needed data (maps, images) if needed. Otherwise load locally.
 *  @param appNamespace The unique identifier of your application, as indicated on the manager platform.
 *  @param successBlock A block invoked when the application is successfully loaded.
 *  @param failureBlock A block invoked if the application can't be loaded.
 */
- (void)loadApplicationForNamespace:(NSString *)appNamespace
                            success:(void(^)())successBlock
                            failure:(void(^)(NSError *error))failureBlock;

/**
 *  The Ubudu namespace of the application. Must be set before starting the SDK. 
 *  This method fetches all needed data (maps, images) if needed. Otherwise load locally.
 *  @param appNamespace The unique identifier of your application, as indicated on the manager platform.
 *  @param shouldDownloadImagesForMaps a BOOL indicates if sdk should download images of the maps
 *  @param successBlock A block invoked when the application is successfully loaded.
 *  @param failureBlock A block invoked if the application can't be loaded.
 */
- (void)loadApplicationForNamespace:(NSString *)appNamespace
                     downloadImages:(BOOL)shouldDownloadImagesForMaps
                            success:(void(^)())successBlock
                            failure:(void(^)(NSError *error))failureBlock;


/**
 *  Start computing the device position.
 */
- (BOOL)start:(NSError **)error;

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

@end
