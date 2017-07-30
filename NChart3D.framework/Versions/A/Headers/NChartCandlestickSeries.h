/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartCandlestickSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartOHLCSeries.h"


/**
 * The NChartCandlestickSeries class provides methods to display candlestick series.
 */
@interface NChartCandlestickSeries : NChartOHLCSeries

/**
 * Color for the border of positive candles.
 */
@property (nonatomic, retain) UIColor *positiveBorderColor;

/**
 * Color for the border of negative candles.
 */
@property (nonatomic, retain) UIColor *negativeBorderColor;

@end

/**
 * The NChartCandlestickSeriesSettings class provides global settings for <NChartCandlestickSeries>.
 */
@interface NChartCandlestickSeriesSettings : NChartOHLCSeriesSettings

/**
 * The resolution of cylinders. Resolution is the amount of vertices that build the circle. 
 * For example if you want to get a square candlestick, you should set resolution to 4. If you want to get a cylindrical
 * candlestick, you may set a larger value. But the larger is the resolution, the more memory is used and the slower the
 * rendering will be, so you should find out the minimal acceptable value. A good value for cylinder is 16 or 20.
 * The default value is 20.
 * @note This value cannot be less than 3 and greater than 32.
 */
@property (nonatomic, assign) NSUInteger cylindersResolution;

/**
 * Flag determining whether horizontal lines on the ending of lower and upper candlestick shadows are shown (YES) or
 * hidden (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL showShadowEndingLines;

@end
