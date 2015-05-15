//
//  UBUZone.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 21/06/2014.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

@interface UBUZone : NSObject

@property (nonatomic, copy, readonly) NSNumber *zoneID;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSArray *tags;

@property (nonatomic, readonly) CGSize size;
@property (nonatomic, readonly) CGPoint origin;

- (instancetype)initWithZoneID:(NSNumber *)zoneID
                          name:(NSString *)name
                          tags:(NSArray *)tags
                        origin:(CGPoint)origin
                          size:(CGSize)size;

- (CGFloat)distanceToPoint:(CGPoint)point;

@end
