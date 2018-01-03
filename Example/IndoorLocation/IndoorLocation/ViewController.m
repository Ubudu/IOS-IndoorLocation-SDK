//
//  ViewController.m
//  IndoorLocation
//
//  Created by zioolek on 07/09/16.
//  Copyright © 2016 ubudu. All rights reserved.
//

#import "ViewController.h"
#import <MapKit/MapKit.h>
#import <UbuduIndoorLocation/UbuduIndoorLocation.h>

@interface ViewController () <UBUIndoorLocationManagerDelegate, MKMapViewDelegate>

@property (strong, nonatomic) MKPointAnnotation *userPoint;
@property (strong, nonatomic) UBUIndoorLocationManager *locationManager;
@property (weak, nonatomic) IBOutlet MKMapView *mapView;

@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self setupLocationManager];
}

- (void)didReceiveMemoryWarning {
    [super didReceiveMemoryWarning];
}

#pragma mark - Private methods

- (void)setupLocationManager
{
    NSString *namespace = @"1e2b9aa914c308b4c7387b1fd9f290968d4f57d8";
    
    self.locationManager = [UBUIndoorLocationManager sharedInstance];
    self.locationManager.delegate = self;

    UBUIndoorLocationConfiguration *ilConfig = [[UBUIndoorLocationConfiguration alloc] initWithAppNamespace:namespace];
    ilConfig.motionFiltering = YES;
    ilConfig.updateHeading = YES;
    ilConfig.localizationMode = kBLEMode;
    
    self.locationManager.configuration = ilConfig;
    
    [self.locationManager startWithCompletionBlock:^(NSError *error) {
        
        if(error != nil) {
            NSLog(@"Error while loading application for namespace: %@", error.localizedDescription);
            return;
        }
     
        NSLog(@"location manager started");
    }];
    
}
#pragma mark - Private properties

- (MKPointAnnotation *)userPoint
{
    if (_userPoint == nil) {
        _userPoint = [[MKPointAnnotation alloc] init];
        _userPoint.coordinate = CLLocationCoordinate2DMake(0.0, 0.0);
    }
    return _userPoint;
}

#pragma mark - Indoor location delegate

- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangePosition:(UBUPositionUpdate *)positionUpdate
{
    // Update position
    CLLocationCoordinate2D location = positionUpdate.estimatedCoordinate;

    if (self.mapView.annotations.count == 0) {
        self.userPoint.coordinate = location;
        [self.mapView addAnnotation:self.userPoint];
    } else {
        ViewController __weak *weakSelf = self;
        [UIView animateWithDuration:0.3
                         animations:^{
                             weakSelf.userPoint.coordinate = location;
                         }];
    }
    
}

- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateBeacons:(NSArray *)beaconsUpdates
{
    NSLog(@"did update beacons: %@", beaconsUpdates);
}

@end
