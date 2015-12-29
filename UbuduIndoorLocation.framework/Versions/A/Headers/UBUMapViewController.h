//
//  UBUMapViewController.h
//  UbuduIndoorLocation
//
// Copyright (c) 2014, UBUDU SAS
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

#import <UIKit/UIKit.h>

#import <UbuduIndoorLocation/UBUIndoorLocationManager.h>

/**
 *  A view controller that can be used as-is to display a map and your current position.
 *
 *  Can be useful for development and debug purpose, but you may need a more advance and complete
 *  map drawing solution if you plan on displaying a map for indoor location in your application.
 *  
 *  For example navigation and path drawing are not handled, and entities that can be drawn on the map are pretty limited.
 */
@interface UBUMapViewController : UIViewController

/**
 *  A UIView IBOutlet that will be used a the map view container is connected to a view.
 *  If nil then the root view is used as the map view container.
 */
@property (weak, nonatomic) IBOutlet UIView *mapPlaceholderView;

/**
 *  The location manager to which subscribe for location update events.
 *  The map that is displayed will be the map currently loaded in the location manager.
 */
@property (nonatomic, strong) UBUIndoorLocationManager *locationManager;


/*
 *
 */
- (instancetype)init;

/**
 * 
 */
- (void)setPathFindingDisplay:(BOOL)status;

/**
 * Allow to enable or disable zones overlay display on Map
 * status : YES to display zone overlay , NO to disable zone overlay display
 */
- (void)setZoneDisplay:(BOOL)status;

/**
 * Allow to enable or disable the event to highlight the closest zones overlay on Map
 * status : YES to enable event highlight , NO to disable event highlight
 */
- (void)setHighLightClosestZone:(BOOL)status;

/**
 * Provide properties to Draw a Zone on Map
 *
 * # zoneToHighlight : an array of UBUZone object to highlight at start, can be nil in that case no zone highlight
 * # defaultColor : custom zone overlay background color. A value for colorWithAlphaComponent of 0.2 is applied. Default color is lightgray for nil parameter.
 * # highlightColor : custom zone overlay highlight background color. A value for colorWithAlphaComponent of 0.2 is applied. Default color is red for nil parameter.
 * # borderColor : custom zone overlay border color. Default color is black for nil parameter.
 */
- (void)setupZoneWith:(NSArray *)zoneToHighlight
         defaultColor:(UIColor *)defaultColor
       highLightColor:(UIColor *)highlightColor
          borderColor:(UIColor *)borderColor;


@end
