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
