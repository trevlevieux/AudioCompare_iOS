/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartRadarSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartAreaSeries.h"


/**
 * The NChartRadarSeries class provides methods to display radar series.
 */
@interface NChartRadarSeries : NChartAreaSeries

@end

/**
 * The NChartRadarSeriesSettings class provides global settings for <NChartRadarSeries>.
 */
@interface NChartRadarSeriesSettings : NChartSeriesSettings

/**
 * Flag determining if axes grid should be smoothed, so it should appear as a circle, not as polygon (YES) or not (NO).
 */
@property (nonatomic, assign) BOOL shouldSmoothAxesGrid;

@end
