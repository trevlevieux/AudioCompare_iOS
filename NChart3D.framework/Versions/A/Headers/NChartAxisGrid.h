/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartAxisGrid.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartObject.h"
#import "NChartLineDash.h"


/**
 * The NChartAxisGridLine class provides methods to control particular grid lines of the chart's axis.
 */
@interface NChartAxisGridLines : NChartObject

/**
 * Color of the grid lines.
 */
@property (nonatomic, retain) UIColor *color;

/**
 * Thickness of the grid lines in pixels. The default value is 1.
 */
@property (nonatomic, assign) float thickness;

/**
 * Dash of the grid lines.
 * @see NChartLineDash.
 */
@property (nonatomic, retain) NChartLineDash *lineDash;

@end

/**
 * The NChartAxisGrid class provides storage for grid lines associated with the particular chart's axis.
 */
@interface NChartAxisGrid : NChartObject

/**
 * Grid lines of the major ticks.
 */
@property (nonatomic, readonly) NChartAxisGridLines *majorGridLines;

/**
 * Grid lines of the minor ticks.
 */
@property (nonatomic, readonly) NChartAxisGridLines *minorGridLines;

/**
 * Grid lines of the tiny ticks.
 */
@property (nonatomic, readonly) NChartAxisGridLines *tinyGridLines;

/**
 * Color of grid lines.
 * <br> If you set a color value to this property, this value is set to all grid lines (majorGridLines,
 * minorGridLines and tinyGridLines). If you read a value of this property, color of majorGridLines is returned.
 */
@property (nonatomic, retain) UIColor *color;

/**
 * Thickness of grid lines.
 * <br> If you set a thickness value to this property, this value is set to all grid lines (majorGridLines,
 * minorGridLines and tinyGridLines). If you read a value of this property, thickness of majorGridLines is returned.
 */
@property (nonatomic, assign) float thickness;

/**
 * Dash of the grid lines.
 * <br> If you set a dash value to this property, this value is set to all grid lines (majorGridLines,
 * minorGridLines and tinyGridLines). If you read a value of this property, thickness of majorGridLines is returned.
 * @see NChartLineDash.
 */
@property (nonatomic, retain) NChartLineDash *lineDash;

/**
 * Array of brushes for interlaced background. If nil, no interlaced background is displayed. The default value is nil.
 * <br> Interlaced background means that the space between axis grid lines is filled with the colors that are
 * consecutively taken from this array. The array is looped, so if there are less elements then spaces between grid
 * lines, the sequence of colors is multiplied. The elements of the array should be objects NChartSolidColorBrush.
 * @note Only NChartSolidColorBrush is supported, all other brushes (or other objects will be skipped).
 */
@property (nonatomic, retain) NSArray *interlacedBackground;

@end
