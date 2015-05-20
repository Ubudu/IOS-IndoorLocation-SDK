//
//  UBUIndoorLocationManager.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 4/25/14.
//  Copyright (c) 2014 Ubudu. All rights reserved.
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

/**
 *  Last known position.
 */
@property (nonatomic, strong, readonly) UBUPositionUpdate *lastPosition;

/**
 *  Load a map from the Ubudu manager platform.
 *
 *  @param mapKey       They unique identifier of your map, as indicated on the manager platform.
 *  @param successBlock A block invoked when the map is successfully loaded.
 *  @param failureBlock A block invoked if the map can't be loaded.
 */
- (void)loadMapWithKey:(NSString *)mapKey
               success:(void(^)())successBlock
               failure:(void(^)(NSError* error))failureBlock;

/**
 *  Load a map from a file containing a JSON representation of the map configuration.
 *
 *  @param configFilePath Path of the file to load.
 *
 *  @return YES if the map was successfully loaded, NO otherwise.
 */
- (BOOL)loadMapFromFile:(NSString *)configFilePath;

/**
 *  Load a map from a JSON configuration already loaded in memory.
 *
 *  @param jsonConfig The map JSON representation.
 *
 *  @return YES if the map was successfully loaded, NO otherwise.
 */
- (BOOL)loadMapFromJSON:(NSDictionary *)jsonConfig;

/**
 *  Start computing the device position.
 */
- (void)start;

/**
 *  Stop computing the device position.
 */
- (void)stop;

@end
