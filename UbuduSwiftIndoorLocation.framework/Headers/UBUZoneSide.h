//
//  UBUZoneSide.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 29/09/15.
//  Copyright © 2015 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreGraphics/CoreGraphics.h>

@interface UBUZoneSide : NSObject

@property (nonatomic, readonly) CGPoint start;
@property (nonatomic, readonly) CGPoint end;

- (instancetype)initWithStartPoint:(CGPoint)start endPoint:(CGPoint)end;

@end
