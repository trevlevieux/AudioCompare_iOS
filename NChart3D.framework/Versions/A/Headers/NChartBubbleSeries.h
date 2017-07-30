/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartBubbleSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSeries.h"
#import "NChartMarker.h"


/**
 * The NChartBubbleSeries class provides methods to display bubble series.
 */
@interface NChartBubbleSeries : NChartSeries

/**
 * Default marker of the series that is displayed as a bubble. It is nil by default.
 * @see NChartMarker.
 */
@property (nonatomic, retain) NChartMarker *marker;

@end

/**
 * The NChartBubbleSeriesSettings class provides global settings for <NChartBubbleSeries>.
 */
@interface NChartBubbleSeriesSettings : NChartSeriesSettings

@end
