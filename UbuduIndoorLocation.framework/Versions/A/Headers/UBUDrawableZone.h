//
//  UBUDrawableZone.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 07/12/2014.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <UIKit/UIKit.h>

#import <UbuduIndoorLocation/UBUPolygon.h>
#import <UbuduIndoorLocation/UBUZone.h>

@interface UBUDrawableZone : UBUPolygon

@property (nonatomic, copy, readonly) NSNumber *zoneID;
@property (nonatomic, copy, readonly) NSString *zoneName;

@property (nonatomic, readonly) CGRect zoneRect;

@property (nonatomic, strong) UIColor *fillColor;
@property (nonatomic, strong) UIColor *borderColor;

+ (UBUDrawableZone *)drawableZoneWithZone:(UBUZone *)zone;

- (instancetype)initWithZone:(UBUZone *)zone;

@end
