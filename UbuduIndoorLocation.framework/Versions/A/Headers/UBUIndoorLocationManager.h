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

@interface UBUIndoorLocationManager : NSObject

@property (nonatomic, weak) id<UBUIndoorLocationManagerDelegate> delegate;

@property (nonatomic, readonly, getter=isRunning) BOOL running;

@property (nonatomic, copy, readonly) NSString *proximityUUID;

@property (nonatomic, strong, readonly) UBUMap *map;

/* Last known position */
@property (nonatomic, strong, readonly) UBUPositionUpdate *lastPosition;

- (void)loadMapWithKey:(NSString *)mapKey
               success:(void(^)())successBlock
               failure:(void(^)(NSError* error))failureBlock;
- (BOOL)loadMapFromFile:(NSString *)configFilePath;
- (BOOL)loadMapFromJSON:(NSDictionary *)jsonConfig;

- (void)start;
- (void)stop;

@end
