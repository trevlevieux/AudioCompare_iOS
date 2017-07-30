/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPlaced.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartObject.h"
#import "NChartBrush.h"


/**
 * The NChartPlaced class provides basic methods for objects displaying some textual information on the screen.
 */
@interface NChartPlaced : NChartObject

/**
 * Brush filling the background of the text container.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *background;

/**
 * Color of the border that is drawn around the text container.
 */
@property (nonatomic, retain) UIColor *borderColor;

/**
 * Corner rounding radius (in pixels) of the border that is drawn around the text container.
 */
@property (nonatomic, assign) float borderRadius;

/**
 * Thickness of the border (in pixels) that is drawn around the text container.
 */
@property (nonatomic, assign) float borderThickness;

/**
 * Margin of the text container in pixels (spacing from the bounds of the enclosing area).
 */
@property (nonatomic, assign) NChartMargin margin;

/**
 * Padding of the text container in pixels (spacing to sub-areas).
 */
@property (nonatomic, assign) NChartMargin padding;

/**
 * Opacity of the text container. Value should be in 0..1. The default value is 1.
 */
@property (nonatomic, assign) float opacity;


@end
