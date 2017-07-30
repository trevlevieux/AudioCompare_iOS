/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartAreaSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"
#import "NChartMarker.h"


/**
 * The NChartAreaSeries class provides methods to display area series.
 */
@interface NChartAreaSeries : NChartSolidSeries

/**
 * Marker that is shown on the points. This is nil by default (no marker is displayed).
 * @see NChartMarker.
 */
@property (nonatomic, retain) NChartMarker *marker;

/**
 * Flag determining if, in case of gradient brush, the area should have gradient that is interpolated from minimum to
 * maximum values (YES), or it should be reinterpolated in each value (NO). The default value is NO.
 * <br> If this flag is NO and the area series has gradient brush, the gradient will probably look like a saw
 * repeating the shape of the area. If this flag is YES, the gradient looks linear and do not repeat the shape of the
 * area.
 */
@property (nonatomic, assign) BOOL uniformGradient;

@end

/**
 * The NChartAreaSeriesSettings class provides global settings for <NChartAreaSeries>.
 */
@interface NChartAreaSeriesSettings : NChartSolidSeriesSettings

@end
