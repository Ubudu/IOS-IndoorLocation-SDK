#import "MarkerImage.h"

@implementation MarkerImage

+ (UIImage *)markerImage
{
    return [self markerImageWithScale:1.0];
}

+ (UIImage *)markerImageWithScale:(CGFloat)scale
{
    return [self markerImageWithScale:scale andColor:[UIColor blueColor]];
}

+ (UIImage *)markerImageWithScale:(CGFloat)scale andColor:(UIColor *)color
{
    CGSize size = CGSizeMake(35 * scale, 34 * scale);
    UIGraphicsBeginImageContextWithOptions(size, NO, 0.0f);
    
    //// General Declarations
    CGContextRef context = UIGraphicsGetCurrentContext();
    
    //// Color Declarations
    UIColor* fillColor = color;
    UIColor* strokeColor = [UIColor colorWithRed: 1 green: 1 blue: 1 alpha: 1];
    UIColor* shadowColor2 = [UIColor colorWithRed: 0 green: 0 blue: 0 alpha: 1];
    
    //// Shadow Declarations
    UIColor* shadow = [shadowColor2 colorWithAlphaComponent: 0.8];
    CGSize shadowOffset = CGSizeMake(0.1, -0.1);
    CGFloat shadowBlurRadius = 6 * scale;
    UIColor* shadow2 = shadowColor2;
    CGSize shadow2Offset = CGSizeMake(0.1, -0.1);
    CGFloat shadow2BlurRadius = 3 * scale;
    
    //// Disc Drawing
    UIBezierPath* discPath = [UIBezierPath bezierPathWithOvalInRect: CGRectMake(6.5 * scale, 6 * scale, 21 * scale, 21 * scale)];
    CGContextSaveGState(context);
    CGContextSetShadowWithColor(context, shadowOffset, shadowBlurRadius, shadow.CGColor);
    [fillColor setFill];
    [discPath fill];
    
    ////// Disc Inner Shadow
    CGRect discBorderRect = CGRectInset([discPath bounds], -shadow2BlurRadius, -shadow2BlurRadius);
    discBorderRect = CGRectOffset(discBorderRect, -shadow2Offset.width, -shadow2Offset.height);
    discBorderRect = CGRectInset(CGRectUnion(discBorderRect, [discPath bounds]), (-1) * scale, (-1) * scale);
    
    UIBezierPath* discNegativePath = [UIBezierPath bezierPathWithRect: discBorderRect];
    [discNegativePath appendPath: discPath];
    discNegativePath.usesEvenOddFillRule = YES;
    
    CGContextSaveGState(context);
    {
        CGFloat xOffset = shadow2Offset.width + round(discBorderRect.size.width);
        CGFloat yOffset = shadow2Offset.height;
        CGContextSetShadowWithColor(context,
                                    CGSizeMake(xOffset + copysign(0.1, xOffset), yOffset + copysign(0.1, yOffset)),
                                    shadow2BlurRadius,
                                    shadow2.CGColor);
        
        [discPath addClip];
        CGAffineTransform transform = CGAffineTransformMakeTranslation(-round(discBorderRect.size.width), 0);
        [discNegativePath applyTransform: transform];
        [[UIColor grayColor] setFill];
        [discNegativePath fill];
    }
    CGContextRestoreGState(context);
    
    CGContextRestoreGState(context);
    
    [strokeColor setStroke];
    discPath.lineWidth = 2 * scale;
    [discPath stroke];
    
    UIImage *markerImage = UIGraphicsGetImageFromCurrentImageContext();
    UIGraphicsEndImageContext();
    
    return markerImage;
}



@end
