//
//  UBUPolygon.h
//  UbuduIndoorLocation
//
//  Created by ubudu imac on 15/05/15.
//  Copyright (c) 2015 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <UbuduIndoorLocation/UBUVertex.h>

@interface UBUPolygon : NSObject

@property (nonatomic, strong, readonly) NSArray *vertices; // NSArray of UBUVextex

- (instancetype)initWithVertices:(NSArray *)vertices;

@end
