//
//  UBULogger.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 19/07/2017.
//  Copyright © 2017 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>

@class UBUPositionLog;

@protocol UBULogger <NSObject>

@optional

- (void)log:(UBUPositionLog *)positionLog;

@end
