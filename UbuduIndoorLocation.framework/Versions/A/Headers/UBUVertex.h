//
//  UBUVertex.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 02/09/2014.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <CoreGraphics/CoreGraphics.h>

@interface UBUVertex : NSObject

@property (nonatomic, readonly) CGFloat x;
@property (nonatomic, readonly) CGFloat y;

@property (nonatomic, readonly) CGPoint point;

- (instancetype)initWithX:(CGFloat)x y:(CGFloat)y;

@end
