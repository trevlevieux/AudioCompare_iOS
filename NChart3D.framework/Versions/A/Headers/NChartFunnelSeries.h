/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartFunnelSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"


/**
 * The NChartFunnelSeries class provides methods to display funnel series. 
 * <br> This chart type has some specialties:
 * - All axes are ignored, so it is reasonable to hide the axes by displaying funnel chart.
 * - Only the first point from each series, all other points are ignored.
 * - Only Y-value from the point is used, all the other values are ignored.
 */
@interface NChartFunnelSeries : NChartSolidSeries

/**
 * Bottom radius of the series in interval [0, 1]. The default value is 0.5.
 */
@property (nonatomic, assign) float bottomRadius;

/**
 * Top radius of the series in interval [0,1]. The default value is 0.5.
 */
@property (nonatomic, assign) float topRadius;

@end

/**
 * The NChartFunnelSeriesSettings class provides global settings for <NChartFunnelSeries>.
 */
@interface NChartFunnelSeriesSettings : NChartSeriesSettings

/**
 * The sum of gaps between the points in the funnel chart in interval [0, 1]. The default value is 0.
 * <br> Actual gap between the points is calculated as <code>gapSum / (countOfPoints - 1)</code> and 1
 * corresponds to the height of the chart's plot area.
 */
@property (nonatomic, assign) float gapSum;

/**
 * The resolution of funnel. Resolution is the amount of vertices that build the circle. For example if you want to
 * get a square funnel, you should set resolution to 4. If you want to get a cylindrical funnel, you may set a larger
 * value. But the larger is the resolution, the more memory is used and the slower the rendering will be, so you should
 * find out the minimal acceptable value. A good value for funnel is 80 or 160. The default value is 120.
 * @note This value cannot be less than 3 and greater than 360.
 */
@property (nonatomic, assign) NSUInteger resolution;

/**
 * Flag that determines if funnel should appear smooth (YES) of faced (NO). Generally if you specify low resolution
 * \(see <resolution> for details\) when the individual faces are still visible, it is a good idea to have
 * funnel faced and vice versa. The default value is NO.
 * @note If funnel are faced, it consumes more memory than if they don't by the same resolution.
 */
@property (nonatomic, assign) BOOL shouldSmooth;

@end
