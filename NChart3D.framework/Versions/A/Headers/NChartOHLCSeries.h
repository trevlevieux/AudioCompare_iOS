/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartOHLCSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"


/**
 * The NChartOHLCSeries class provides methods to display OHLC series.
 */
@interface NChartOHLCSeries : NChartSolidSeries

/**
 * Color for positive candles.
 */
@property (nonatomic, retain) UIColor *positiveColor;

/**
 * Color for negative candles.
 */
@property (nonatomic, retain) UIColor *negativeColor;

@end

/**
 * The NChartOHLCSeries class provides global settings for <NChartOHLCSeries>.
 */
@interface NChartOHLCSeriesSettings : NChartSolidSeriesSettings

@end
