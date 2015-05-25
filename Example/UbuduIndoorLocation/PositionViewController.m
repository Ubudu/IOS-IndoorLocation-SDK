//
//  PositionViewController.m
//  UbuduIndoorLocation
//
// Copyright (c) 2015, UBUDU SAS
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// * Redistributions of source code must retain the above copyright notice, this
// list of conditions and the following disclaimer.
//
// * Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
// DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
// FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
//         SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#import <CoreLocation/CoreLocation.h>

#import "PositionViewController.h"

@interface PositionViewController () <UBUIndoorLocationManagerDelegate>

@property(strong, nonatomic) UBUIndoorLocationManager *locationManager;

@property (weak, nonatomic) IBOutlet UIButton *showMapButton;

@end

@implementation PositionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    
    // Request location permission
    CLLocationManager *coreLocationManager = [[CLLocationManager alloc] init];
    if ([coreLocationManager respondsToSelector:@selector(requestWhenInUseAuthorization)]) {
        [coreLocationManager requestWhenInUseAuthorization];
    }
    
    [self initIndoorLocationManager];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    // Set the delegate everytime the view appears
    // because UBUMapViewController sets itself as the delegate of the location manager when presented,
    // so we need to re-subscribe to the events.
    self.locationManager.delegate = self;
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

- (void)initIndoorLocationManager
{
    // Ubudu Indoor Location SDK init
    self.locationManager = [[UBUIndoorLocationManager alloc] init];
    self.locationManager.delegate = self;
    
    // Load the map using the key provided by Ubudu platform
    NSString *mapKey = @"1eff16a0d6c80132a0ef0a824b34cee9";
    [self.locationManager loadMapWithKey:mapKey success:^{
        NSLog(@"Map loading success");
        
        [self.locationManager start];
        [self.showMapButton setEnabled:YES];
        
    } failure:^(NSError *error) {
        NSLog(@"Map loading failure: %@", error);
        
        [self displayError:error];
        [self.showMapButton setEnabled:NO];
    }];
}

- (void)displayError:(NSError *)error
{
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Couldn't load map"
                                                    message:error.description
                                                   delegate:nil
                                          cancelButtonTitle:@"OK"
                                          otherButtonTitles:nil];
    [alert show];
}

// Storyboard button action
- (IBAction)buttonClicked:(id)sender
{
    UBUMapViewController *mapViewController = [[UBUMapViewController alloc] init];
    mapViewController.locationManager = self.locationManager;
    mapViewController.navigationItem.title = @"Map Rendering";
    [self.navigationController pushViewController:mapViewController animated:YES];
}

#pragma mark - UBUIndoorLocationManagerDelegate

- (void)locationManager:(UBUIndoorLocationManager *)locationManager positionDidChange:(UBUPositionUpdate *)positionUpdate
{
    NSLog(@"positionDidChange: position = (%f ; %f)", positionUpdate.estimatedPosition.x, positionUpdate.estimatedPosition.y);
}

@end
