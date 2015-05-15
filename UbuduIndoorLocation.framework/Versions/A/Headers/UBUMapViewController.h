//
//  UBUMapViewController.h
//  UbuduIndoorLocation
//
//  Created by Jean-Baptiste Quesney on 01/09/2014.
//  Copyright (c) 2014 Ubudu. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <UbuduIndoorLocation/UBUIndoorLocationManager.h>

@interface UBUMapViewController : UIViewController

@property (weak, nonatomic) IBOutlet UIView *mapPlaceholderView;

@property (nonatomic, strong) UBUIndoorLocationManager *locationManager;

@end
