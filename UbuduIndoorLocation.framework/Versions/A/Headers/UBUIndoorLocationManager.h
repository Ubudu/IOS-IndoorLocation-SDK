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
@property (nonatomic, strong, readwrite) UBUMap *currentMap;

/**
 *  Last known position.
 */
@property (nonatomic, strong, readonly) UBUPositionUpdate *lastPosition;

/**
 *  The flag indicates if Indoor Location Manager is using motion filtering to improve stability of positioning
 */
@property (nonatomic, getter=isUsingMotionMonitorFiltering) BOOL motionFiltering;

/**
 *  The accuracy treshold. Ranged beacons with accuracy higher than this treshold will not be used to estimate the position.
 *  By default, the accuracy treshold is set to 15.0.
 *
 *  DO NOT CHANGE THIS VALUE UNTIL YOU ARE SURE WHAT YOU ARE DOING.
 *  CHANGING THIS VALUE MAY REDUCE THE ACCURACY OF THE ESTIMATED POSITION.
 */
@property (nonatomic) double accuracyTreshold;

/**
 *  Version of the SDK.
 */
@property (nonatomic, readonly) NSString *version;

/**
 *  Singleton of indoor location manager
 */
+ (instancetype)sharedInstance;

/**
 *  Load application for namespace, fetch all needed data (maps, images) if needed, Otherwise load locally
 */
- (void)loadApplicationForNamespace:(NSString *)appNamespace
                            success:(void(^)())successBlock
                            failure:(void(^)(NSError *error))failureBlock;

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
 *  Load a map from the Ubudu manager platform.
 *
 *  @param mapKey       They unique identifier of your map, as indicated on the manager platform.
 *  @param successBlock A block invoked when the map is successfully loaded. It returns a map assigned to currentMap
 *  @param failureBlock A block invoked if the map can't be loaded.
 */
- (void)loadMapWithKey:(NSString *)mapKey
               success:(void(^)(UBUMap* map))successBlock
               failure:(void(^)(NSError* error))failureBlock;

/**
 *  Load a map from a file containing a JSON representation of the map configuration.
 *
 *  @param configFilePath Path of the file to load.
 *
 *  @return YES if the map was successfully loaded, NO otherwise.
 */
- (UBUMap *)loadMapFromFile:(NSString *)configFilePath;

/**
 *  Load a map from a JSON configuration already loaded in memory.
 *
 *  @param jsonConfig The map JSON representation.
 *
 *  @return YES if the map was successfully loaded, NO otherwise.
 */
- (UBUMap *)loadMapFromJSON:(NSDictionary *)config;

/**
 * @param point a point on the map.
 * @return geographical coordinates (latitude, longitude) for the given point.
 */
- (CLLocationCoordinate2D)geoCoordinateForPoint:(CGPoint)point;

- (UIImage *)mapOverlayForCurrentMap;

- (NSArray *)loadAllStoredMaps;

@end
