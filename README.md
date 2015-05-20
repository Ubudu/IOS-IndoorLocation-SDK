# Ubudu Indoor Location SDK for iOS

The Indoor location SDK provides a solution that allows mobile devices to estimate their position within an indoor venue. The position is computed in real time based on the beacons placed inside the venue and from which the device receives signal broadcasts.

The solution allows users to create their maps on the Ubudu manager platform. A map is attached to a particular venue previously created in the manager. Then various entities can be defined and positioned on the map:

##### Beacons
This is the most important part. Correctly positioning the beacons on the map, and then deploying them accordingly in the venue, is the key to perform accurate indoor positioning. User has to place beacons on the map in a way that the entire surface where indoor location should work is covered. To achieve best positioning precision at least four beacons should always be on the line of sight of the mobile device and sufficiently close from it.

##### Map zones
Zones are rectangular areas positioned on the map. They are useful to define zones of interest for which we would like to detect presence or distance. The mobile device can access all the zones defined of a given map through the SDK API and also retrieve the currently closest zone, or compute the distance to any zone.

##### Non-navigable areas
These areas inside a venue indicarte the zones inaccessible to people. They can be defined when editing a map. You should mark all the walls and/or big obstacles that are inaccessible to people and so in which the mobile device cannot be, and through which it cannot "cross instantly" as well (an obstacle needs to be walked around to go from one side to another). Defining those non-navigable zones lets the indoor location SDK achieve better accuracy and will provide a better experience.

### System and hardware requirements

* iOS 7.0 or higher.
* iPhone 4S / iPad 3rd generation / iPad mini / iPod touch 5th generation, or any more recent device.


## I. Adding the Ubudu SDK to a project.

### Using CocoaPods

This is the prefered and simplest way to get started. Just add the following line to your Podfile:

`pod 'UbuduIndoorLocation'`

and execute `pod install`

If you are not already using CocoaPods for your project you can get started by reading the [CocoaPods documentation](https://guides.cocoapods.org/).


### Manually

If you don't want or cannot use CocoaPods you can install the SDK manually by following the instructions bellow.

1. Drag & drop the **UbuduIndoorLocation.framework** folder into the **Frameworks** folder of your project in XCode. Check the **"Copy items into destination group's folder (if needed)"** option.

2. Add the following list of frameworks and libraries to your project if they are not already present. *(dont forget __libc++.dylib__ !)*
	- Foundation
	- CoreGraphics
	- UIKit
	- CoreLocation
	- ImageIO
	- libc++.dylib
	
	Your framework folder should look like this: 
	
	![illustration_frameworkfolder](http://puu.sh/hRJYi/eb6ac1e3f3.png)
	
	_[Instructions](https://developer.apple.com/library/ios/recipes/xcode_help-project_editor/Articles/
	AddingaLibrarytoaTarget.html#//apple_ref/doc/uid/TP40010155-CH17) on how to add an Apple framework to your project._
	
3. In the project settings go to:
`"General"->"Your Target"->"Build Settings"->"(All)"->"Other Linker Flags"` and add the following flags: **-ObjC**


## II. Project configuration

### Location authorization (required)

Since iOS 8.0 it is required to add an entry to the _Info.plist_ file that indicates wich location authorization is required by your app:

- To use the "**Always**" mode add the `NSLocationAlwaysUsageDescription` key.
- To use the "**When In Use**" mode then add the `NSLocationWhenInUseUsageDescription` key.

The Indoor Location SDK can work with both mode as it based on iBeacon ranging, which is basically a foreground only feature.

![illustration_entry](https://github.com/Ubudu/IOS-SDK/blob/master/__media-files/images/location_authorization_info_plist_key.png?raw=true)

You also need to call the corresponding CoreLocation method **before** starting the Ubudu Indoor Location manager.

* **When In Use** mode: `[CLManager requestWhenInUseAuthorization];`
* **Always** mode: `[CLManager requestAlwaysAuthorization];`

See [Apple CoreLocation documentation](https://developer.apple.com/library/ios/documentation/CoreLocation/Reference/CLLocationManager_Class/index.html#//apple_ref/doc/uid/TP40007125-CH3-SW62) for more details.


## III. Setup the Indoor Location SDK

First of all you need a configured map. To create and configure a map go on the [manager plateform](https://manager.ubudu.com/) 

- Select a venue into **Venues & indoor maps**.
- Click on the **Maps** button and click **Add**.

Then once the map properties are configured, the manager provide you the unique key of the map.

- Import the header in your view controller `#import <UbuduIndoorLocation/UbuduIndoorLocation.h>`
- Instanciate an `UbuduIndoorLocationManager` object.
- Load your map using the method `loadMapWithKey:success:failure:`
- Implement the protocol `UbuduIndoorLocationManagerDelegate` in your view controller.
- Finally call `start` on your indoor position manager to start receiving position updates. 

A `stop` method exists as well, don't forget to call it when you don't need the position inside the venue anymore.

Here is an example on how to initialize and start the SDK:

```
- (void)viewDidLoad
{
    [super viewDidLoad];
    [self initIndoorLocationManager];
}

- (void)initIndoorLocationManager
{
	NSString *mapKey = @"1eff16a0d6c80132a0ef0a824b34cee9";
	
	self.locationManager = [[UBUIndoorLocationManager alloc] init];
    self.locationManager.delegate = self;

	[self.locationManager loadMapWithKey:mapKey success:^{
        NSLog(@"Map loading success");
        [self.locationManager start]; // start only on success callback
        
    } failure:^(NSError *error)
        NSLog(@"Map loading failure: %@", error);
    }];
}

```


## IV. Location Manager delegate

The `UbuduIndoorLocationManagerDelegate` provides callback methods which you can implement to receive events from the indoor location manager.

Implement any of the methods below to receive events that are of any interest for your application:

```
- (void)locationManager:(UBUIndoorLocationManager *)locationManager didUpdateBeacons:(NSArray *)beaconsUpdates; 

- (void)locationManager:(UBUIndoorLocationManager *)locationManager positionDidChange:(UBUPositionUpdate *)positionUpdate;

- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestNavigablePointDidChange:(UBUPositionUpdate *)positionUpdate;

- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestBeaconDidChange:(UBUPositionUpdate *)positionUpdate;

- (void)locationManager:(UBUIndoorLocationManager *)locationManager closestZoneDidChange:(UBUPositionUpdate *)positionUpdate;
```


## V. Map Rendering

The Ubudu Indoor Location SDK provides a simple view controller that can display a map, the zones you defined and your position on the map.

On your **header** file you can declare `@class UBUMapViewController;`

And a **property** : `@property(strong, nonatomic) UBUMapViewController * mapViewController;`

Based on the previous code snippet _(cf : III Get Start With the SDK)_, here is an example of how to display the map view controller.

```
- (void)viewDidLoad
{
    [super viewDidLoad];
    [self initIndoorLocationManager];
}
- (void)viewDidAppear:(BOOL)animated
{
    [super viewDidAppear:animated];
    // Subscribe as delegate everytime we appear because mapViewController sets itself as location manager delegate when presented
    self.locationManager.delegate = self;
}
- (void)initIndoorLocationManager
{
	NSString *mapKey = @"1eff16a0d6c80132a0ef0a824b34cee9";
	
	self.locationManager = [[UBUIndoorLocationManager alloc] init];
	 [self.locationManager loadMapWithKey:mapKey success:^{
        NSLog(@"Map loading success");
        [self.locationManager start];
        
        // Push the map view conroller once the map is loaded
		[self showMap]
    } failure:^(NSError *error) {
        NSLog(@"Map loading failure: %@", error);
    }];
}
- (void)showMap
{
    self.mapViewController = [[UBUMapViewController alloc] init];
    self.mapViewController.locationManager = self.locationManager;
    [self presentViewController:self.mapViewController animated:YES completion:NULL];
} 

```
