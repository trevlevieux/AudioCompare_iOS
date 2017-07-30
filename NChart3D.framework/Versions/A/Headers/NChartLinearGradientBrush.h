/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartLinearGradientBrush.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartGradientBrush.h"


/**
 * The NChartLinearGradientBrush class provides a brush that fills the area with a linear gradient.
 */
@interface NChartLinearGradientBrush : NChartGradientBrush

/**
 * Create linear gradient brush with given colors. This is a convenient equivalent to creating stops, arraying them and
 * then setting the array to the new instance of the linear gradient brush.
 *
 * @param color1 - first color of gradient.
 * @param color2 - second color of gradient.
 * @return a new instance of the linear gradient brush.
 */
+ (NChartLinearGradientBrush *)linearGradientBrushFromColor:(UIColor *)color1 toColor:(UIColor *)color2;

/**
 * Init linear gradient brush with given colors. This is a convenient equivalent to creating stops, arraying them and
 * then setting the array to the new instance of the linear gradient brush.
 *
 * @param color1 - first color of gradient.
 * @param color2 - second color of gradient.
 * @return initialized instance of the linear gradient brush.
 */
- (id)initWithFromColor:(UIColor *)color1 toColor:(UIColor *)color2;

/**
 * Starting point of the gradient. It is relative to the area, its value should be in (0..1; 0..1).
 * (0; 0) is the bottom left corner of the area, (1; 1) is the top right corner.
 */
@property (nonatomic, assign) CGPoint startPoint;

/**
 * Ending point of the gradient. It is relative to area, its value should be in (0..1; 0..1).
 * (0; 0) is the bottom left corner of the area, (1; 1) is the top right corner.
 */
@property (nonatomic, assign) CGPoint endPoint;

@end
