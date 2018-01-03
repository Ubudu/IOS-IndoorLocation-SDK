//
//  UBUAppDataLoader.h
//  UbuduIndoorLocation
//
//  Created by zioolek on 06/10/2017.
//  Copyright © 2017 Ubudu. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface UBUAppDataLoader : NSObject

/**
 * This method allows you to preload ubudu map data for your namespace.
 * @discussion To prepare a data for preloading - launch your app and fetch latest map data.
 * Plug your iOS device to your mac and in xcode open devices window and download a container for your app.
 * From documents/ubudu directory copy the folder named with your namespace to your xcode project and add it to
 * Copy Bundle Resources in Build Phases. Then call this method before starting IL.
 *
 * @param folderName - the name of the folder in the bundle’s subdirectory containing resources. it should be named with the application's namespace
 * @return return YES if resources with map were preloaded properly and returns NO if there are already some data in the folder.
 */
+ (BOOL)preloadMapDataFromSourceFolder:(NSString *)folderName;

@end
