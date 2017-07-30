/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPolarSystem.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartCoordSystem.h"
#import "NChartValueAxis.h"
#import "NChartAxisGrid.h"


/**
 * The NChartPolarSystem class provides methods for managing the chart's polar coordinate system.
 */
@interface NChartPolarSystem : NChartCoordSystem

/**
 * Azimuth-Axis of the polar coordinate system.
 */
@property (nonatomic, readonly) NChartValueAxis *azimuthAxis;

/**
 * Radius-Axis of the polar coordinate system.
 */
@property (nonatomic, readonly) NChartValueAxis *radiusAxis;

/**
 * Grid of the polar coordinate system.
 */
@property (nonatomic, readonly) NChartAxisGrid *grid;

/**
 * Flag that determines if the border around the polar coordinate system is visible (YES) or not (NO).
 */
@property (nonatomic, assign) BOOL borderVisible;

/**
 * Color of the border around the polar coordinate system.
 */
@property (nonatomic, retain) UIColor *borderColor;

/**
 * Thickness of the border around the polar coordinate system.
 */
@property (nonatomic, assign) float borderThickness;

@end
