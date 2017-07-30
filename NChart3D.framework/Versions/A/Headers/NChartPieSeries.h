/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPieSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"
#import "NChartTooltip.h"


/**
 * The NChartPieSeries class provides methods to display pie series.
 */
@interface NChartPieSeries : NChartSolidSeries

/**
 * Color of the bevel effect. This property is supported in 2D mode only. The default value is nil (that means no bevel).
 * <br> Use this property to add a bevel effect to the series. You can achieve different effects with different
 * colors. For example, to add a shadow inside the pie circle, set the color like
 * <code>[UIColor colorWithRed:0.0f green:0.0f blue:0.0f alpha:0.25f]</code>.
 * You also have to set <code>bevelRatio</code> for <NChartPieSeriesSettings> to get the bevel effect.
 */
@property (nonatomic, retain) UIColor *bevelColor;

@end

/**
 * The NChartPieSeriesSettings class provides global settings for <NChartPieSeries>.
 */
@interface NChartPieSeriesSettings : NChartSolidSeriesSettings

/**
 * Hole radius ratio that determines size of the hole for pie series relatively to the whole pie radius. The default
 * value 0.1.
 * @note This value cannot be less than 0 and greater than 1.0.
 */
@property (nonatomic, assign) float holeRatio;

/**
 * Bevel effect ratio that determines size of the bevel for pie series relatively to the whole pie radius.
 * This property is supported in 2D mode only. The default value is 0.0 (that means no bevel).
 * @note This value cannot be less than 0.0 and greater than 1.0.
 * <br> You also have to set <code>bevelColor</code> for <NChartPieSeries> to get the bevel effect.
 */
@property (nonatomic, assign) float bevelRatio;

/**
 * Caption that appears in the center of pie.
 * @see NChartTooltip.
 */
@property (nonatomic, retain) NChartTooltip *centerCaption;

@end
