//
//  UBUPoi.h
//  UbuduIndoorLocation
//
//  Created by ➖ on 29/09/15.
//  Copyright © 2015 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>
#import <CoreLocation/CoreLocation.h>

@interface UBUPoi : NSObject

@property (nonatomic, copy, readonly) NSNumber *poiID;
@property (nonatomic, copy, readonly) NSString *poiDescription;
@property (nonatomic, copy, readonly) NSString *name;
@property (nonatomic, copy, readonly) NSURL *link;
@property (nonatomic, copy, readonly) NSArray *tags;
@property (nonatomic, copy, readonly) NSString *type;
@property (nonatomic, readonly) CGPoint point2D;


- (instancetype)initWithDictionary:(NSDictionary *)dict;

@end
