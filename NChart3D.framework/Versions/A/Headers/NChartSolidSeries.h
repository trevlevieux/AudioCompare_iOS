/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartSolidSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSeries.h"
#import "NChartBrush.h"

/**
 * The NChartSolidSeries class provides common methods to display series that are filled with some brush and have a border.
 */
@interface NChartSolidSeries : NChartSeries

/**
 * Brush that fills the series.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *brush;

/**
 * Brush of the border that surrounds the series.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *borderBrush;

/**
 * Thickness (in pixels) of the border that surrounds the series.
 */
@property (nonatomic, assign) float borderThickness;

@end

/**
 * The NChartSolidSeriesSettings class provides common settings for <NChartSolidSeries>.
 */
@interface NChartSolidSeriesSettings : NChartSeriesSettings

/**
 * Fill ratio for series that determines the amount of place for one series. For example, if the fill ratio is 1.0 and
 * the column series is displayed, one column (or one group of columns, if there are many series on one chart
 * at the same time) fills the whole area of one tick on the X and Z axes (for bar series -- on the Y and Z
 * respectively, for area -- it's Z-width and so on). If the fill ratio is 0.5, the column fills half the area of one
 * tick and so on. The default value is 0.7.
 */
@property (nonatomic, assign) float fillRatio;

@end
