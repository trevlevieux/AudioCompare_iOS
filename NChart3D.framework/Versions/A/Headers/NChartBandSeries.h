/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartBandSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartOHLCSeries.h"


/**
 * The NChartBandSeries class provides methods to display band series. This series type is for 2D only.
 */
@interface NChartBandSeries : NChartOHLCSeries

/**
 * Color for the low border.
 */
@property (nonatomic, retain) UIColor *lowBorderColor;

/**
 * Color for the high border.
 */
@property (nonatomic, retain) UIColor *highBorderColor;

@end

/**
 * The NChartBandSeriesSettings class provides global settings for <NChartBandSeries>.
 */
@interface NChartBandSeriesSettings : NChartOHLCSeriesSettings

@end
