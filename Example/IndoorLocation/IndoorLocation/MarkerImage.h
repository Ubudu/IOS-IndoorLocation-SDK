#import <UIKit/UIKit.h>

@interface MarkerImage : UIImage

+ (UIImage *)markerImage;
+ (UIImage *)markerImageWithScale:(CGFloat)scale;
+ (UIImage *)markerImageWithScale:(CGFloat)scale andColor:(UIColor *)color;
@end
