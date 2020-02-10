//
//  UBUPositionLog.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 19/07/2017.
//  Copyright © 2017 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "UBUPositionUpdate.h"

@class UBUDeviceInfo;

@interface UBUPositionLog : NSObject

@property (nonatomic, strong, readonly) NSString        *ilSDKVersion;
@property (nonatomic, strong, readonly) NSString        *appNamesapce;
@property (nonatomic, strong, readonly) NSString        *uuid;              // string?
@property (nonatomic, strong, readonly) NSString        *mapUUID;           // string?
@property (nonatomic, strong, readonly) NSString        *timestamp;         // string, because we want a forced format of that string
@property (nonatomic, strong, readonly) NSArray         *zones;
@property (nonatomic, strong, readonly) UBUDeviceInfo   *deviceInfo;
@property (nonatomic, readonly) PositionSource          origin;
@property (nonatomic, readonly) CLLocationCoordinate2D  locationCoordinate;

+ (UBUPositionLog *)logWithNamespace:(NSString *)appNamespace
                                uuid:(NSString *)uuid
                             mapUUID:(NSString *)mapUUID
                  locationCoordinate:(CLLocationCoordinate2D)coordinate
                              origin:(PositionSource)positionSource
                               zones:(NSArray *)zones;

+ (UBUPositionLog *)logWithDictionary:(NSDictionary *)logDictionary;

- (NSDictionary *)descriptionDictionary;

@end
