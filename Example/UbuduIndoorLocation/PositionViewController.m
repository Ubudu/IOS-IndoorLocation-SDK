//
//  PositionViewController.m
//  UbuduIndoorLocation
//
//  Created by Jean Felix Tran on 18/05/15.
//  Copyright (c) 2015 Ubudu. All rights reserved.
//

#import "PositionViewController.h"

@interface PositionViewController () <UBUIndoorLocationManagerDelegate>

@property (weak, nonatomic) IBOutlet UIButton *showMapButton;

@end

@implementation PositionViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initIndoorLocationManager];
}

- (void)viewWillAppear:(BOOL)animated
{
    [super viewWillAppear:animated];
    
    // Here the delegate is set everytime on willAppear
    // So UBUMapViewController can sets itself as delegate of the location manager.
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
    UIAlertView *alert = [[UIAlertView alloc] initWithTitle:@"Error"
                                                    message:[NSString stringWithFormat:@"Couldn't load map: %@", error]
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
