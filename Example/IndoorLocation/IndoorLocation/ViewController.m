//
//  ViewController.m
//  IndoorLocation
//
//  Created by zioolek on 07/09/16.
//  Copyright © 2016 ubudu. All rights reserved.
//

#import "ViewController.h"
#import <MapKit/MapKit.h>
#import "CachedTileLayer.h"
#import <UbuduIndoorLocation/UbuduIndoorLocation.h>
#import "MarkerImage.h"

@import GoogleMaps;

@interface ViewController () <UBUIndoorLocationManagerDelegate, MKMapViewDelegate>

@property (strong, nonatomic) UBUIndoorLocationManager *locationManager;
@property (nonatomic, strong) UBUMap *currentMap;
@property (strong, nonatomic) GMSMarker *userMarker;
@property (strong, nonatomic) CachedTileLayer *mapOverlay;
@property (weak, nonatomic) IBOutlet GMSMapView *mapView;


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

- (void)prepareMapView
{
    [self.mapView clear];
    // Setup map region
    
    if (self.currentMap == nil) {
        self.userMarker.map = self.mapView;
        return;
    }
    
    CLLocationCoordinate2D topLeftCoordinates = [self.currentMap topLeftAnchorCoordinates];
    CLLocationCoordinate2D bottomRightCoordinates = [self.currentMap bottomRightAnchorCoordinates];
    
    CLLocationDegrees middleLat     = (topLeftCoordinates.latitude + bottomRightCoordinates.latitude) * 0.5;
    CLLocationDegrees middleLong    = (topLeftCoordinates.longitude + bottomRightCoordinates.longitude) * 0.5;
    
    float zoomLevel = 22.0;
    if (self.locationManager.lastPosition) {
        CLLocationCoordinate2D position = [self.locationManager geoCoordinateForPoint:self.locationManager.lastPosition.closestNavigablePoint];

        middleLat = position.latitude;
        middleLong = position.longitude;
        zoomLevel = 22.0;
    }
    
    self.mapView.layer.cameraLatitude = middleLat;
    self.mapView.layer.cameraLongitude = middleLong;
    self.mapView.layer.cameraZoomLevel = zoomLevel;
    self.mapView.buildingsEnabled = NO;
    
    // Remove old map overlay
    self.mapOverlay.map = nil;
    
    // Prepare map overlay
    self.mapOverlay = [self groundOverlayForCurrentMap];
    
    // Add map overlay
    self.mapOverlay.map = self.mapView;
    self.mapOverlay.zIndex = 0;
}

- (CachedTileLayer *)groundOverlayForCurrentMap
{
    CachedTileLayer *tile = [[CachedTileLayer alloc] initWithBaseURL:self.currentMap.tilesUrl
                                                   topLeftCoordinate:self.currentMap.topLeftAnchorCoordinates
                                            andBottomRightCoordinate:self.currentMap.bottomRightAnchorCoordinates];
    return tile;
}
#pragma mark - Private properties

- (void)setCurrentMap:(UBUMap *)currentMap
{
    if (_currentMap != currentMap) {
        _currentMap = currentMap;
        [self prepareMapView];
    }
}

- (GMSMarker *)userMarker
{
    if (!_userMarker) {
        
        CLLocationCoordinate2D position = CLLocationCoordinate2DMake(0.0, 0.0);
        if (self.locationManager.lastPosition) {
            position = [self.locationManager geoCoordinateForPoint:self.locationManager.lastPosition.closestNavigablePoint];
        }
        
        _userMarker = [GMSMarker markerWithPosition:position];
        _userMarker.appearAnimation = kGMSMarkerAnimationPop;
        _userMarker.icon = [MarkerImage markerImage];
        _userMarker.map = self.mapView;
        _userMarker.groundAnchor = CGPointMake(0.5, 0.5);
        _userMarker.zIndex = 1000;
    }
    return _userMarker;
}

#pragma mark - Indoor location delegate

- (void)locationManager:(UBUIndoorLocationManager *)locationManager didChangeClosestNavigablePoint:(UBUPositionUpdate *)positionUpdate
{
    if (positionUpdate.positionSource == kBLEAttractor) { return; }
    
    if (self.locationManager.configuration.automaticFloorSwitching) {
        self.currentMap = locationManager.currentMap;
    }
    
    if (![self.currentMap.uuid isEqualToString:locationManager.currentMap.uuid]) {
        return;
    }
    
    // Show user's marker if is not on a map
    if (self.userMarker.map == nil) { self.userMarker.map = self.mapView; }
    
    // Update position
    CLLocationCoordinate2D location = [self.locationManager geoCoordinateForPoint:positionUpdate.closestNavigablePoint];
    
    self.userMarker.layer.latitude = location.latitude;
    self.userMarker.layer.longitude = location.longitude;
}

- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateBeacons:(NSArray *)beaconsUpdates
{
    NSLog(@"did update beacons: %@", beaconsUpdates);
}

@end
