/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartRibbonSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"
#import "NChartMarker.h"


/**
 * The NChartRibbonSeries class provides methods to display ribbon series. This series type is for 3D only.
 */
@interface NChartRibbonSeries : NChartSolidSeries

/**
 * Color of the ribbon in the points with no data.
 */
@property (nonatomic, retain) UIColor *noDataColor;

/**
 * Marker that is shown on the points. This is nil by default (no marker is displayed).
 * @see NChartMarker.
 */
@property (nonatomic, retain) NChartMarker *marker;

@end

/**
 * The NChartRibbonSeriesSettings class provides global settings for <NChartRibbonSeries>.
 */
@interface NChartRibbonSeriesSettings : NChartSolidSeriesSettings

@end
