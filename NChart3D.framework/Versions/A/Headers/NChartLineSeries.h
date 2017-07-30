/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartLineSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"
#import "NChartMarker.h"
#import "NChartLineDash.h"


/**
 * The NChartLineSeries class provides methods to display line series.
 */
@interface NChartLineSeries : NChartSolidSeries

/**
 * Color of the line in the points with no data.
 */
@property (nonatomic, retain) UIColor *noDataColor;

/**
 * Thickness of the line in pixels. The default value is 2.
 */
@property (nonatomic, assign) float lineThickness;

/**
 * Dash of the line.
 * @see NChartLineDash.
 */
@property (nonatomic, retain) NChartLineDash *lineDash;

/**
 * Marker that is shown on the points. This is nil by default (no marker is displayed).
 * @see NChartMarker.
 */
@property (nonatomic, retain) NChartMarker *marker;

@end

/**
 * The NChartLineSeriesSettings class provides global settings for <NChartLineSeries>.
 */
@interface NChartLineSeriesSettings : NChartSeriesSettings

/**
 * Animation type of the transition. The default value is <code>Chart3DLineAnimationTypeGrowUp</code>.
 */
@property (nonatomic, assign) NChartLineAnimationType animationType;

@end
