//
//  UBUMap.h
//  UbuduIndoorLocation
//
//  Created by ubudu imac on 27/04/15.
//  Copyright (c) 2015 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

#import <UbuduIndoorLocation/UBUBeacon.h>
#import <UbuduIndoorLocation/UBUZone.h>

@interface UBUMap : NSObject

@property (nonatomic, readonly) CGSize size;

@property (nonatomic, strong, readonly) NSArray *beacons; // NSArray of UBUBeacon
@property (nonatomic, strong, readonly) NSArray *zones; // NSArray of UBUZone

- (instancetype)initWithSize:(CGSize)size;

- (UBUZone *)getZoneByID:(NSNumber *)zoneID;
- (NSArray *)getZonesByTag:(NSString *)tag;

@end
