/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartTouchAreaSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSeries.h"
#import "NChartPoint.h"
#import "NChartBrush.h"


/**
 * The NChartTouchAreaSeries class provides methods to display fullscreen billboard with touch areas.
 */
@interface NChartTouchAreaSeries : NChartSeries

@end

/**
 * The NChartTouchAreaSeriesSettings class provides global settings for <NChartTouchAreaSeries>.
 */
@interface NChartTouchAreaSeriesSettings : NChartSeriesSettings

/**
 * Background image to display on the screen.
 */
@property (nonatomic, retain) NChartBrush *background;

/**
 * Flag allowing you to highlight touch ares with red for debug reasons (if YES). The default value is NO.
 */
@property (nonatomic, assign) BOOL areasDebugMode;

@end

/**
 * The NChartTouchArea class provides methods to define touch area for <NChartTouchAreaSeries>.
 * Area is defined in relative coordinates that should be in [0, 1]x[0, 1] and relates to the size of background set 
 * through <NChartTouchAreaSeriesSettings>. (0, 0) corresponds to the top-left corner of the background image, (1, 1) -
 * to the bottom-right.
 */
@interface NChartTouchArea : NChartPoint

/**
 * Create touch area with given area.
 *
 * @param area - area for touch area.
 * @param series - series for touch area.
 * @return new instance of touch area.
 */
+ (NChartTouchArea *)touchAreaWithArea:(CGRect)area forSeries:(NChartSeries *)series;

/**
 * Initialize touch area with given area.
 *
 * @param area - area for touch area.
 * @param series - series for touch area.
 * @return initialized instance of touch area.
 */
- (id)initWithArea:(CGRect)area forSeries:(NChartSeries *)series;

/**
 * Touch area rect.
 */
@property (nonatomic, assign) CGRect area;

@end
