/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartAxisTick.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartObject.h"


/**
 * The NChartAxisTick class provides methods to manage ticks on the axes.
 */
@interface NChartAxisTick : NChartObject

/**
 * Color of the ticks.
 */
@property (nonatomic, retain) UIColor *color;

/**
 * Length of ticks in pixels. The default value is 10.
 */
@property (nonatomic, assign) float length;

/**
 * Thickness of ticks in pixels. The default value is 1.
 */
@property (nonatomic, assign) float thickness;

/**
 * Type of ticks.
 * @see NChartAxisTickType.
 */
@property (nonatomic, assign) NChartAxisTickType type;

@end
