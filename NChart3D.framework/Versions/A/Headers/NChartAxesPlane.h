/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartAxesPlane.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartObject.h"


/**
 * The NChartAxesPlane class provides methods to display the axes plane for the cartesian system.
 */
@interface NChartAxesPlane : NChartObject

/**
 * Color of axes plane.
 */
@property (nonatomic, retain) UIColor *color;

/**
 * Width of the axes plane in 3D scene units. Actually, one 3D scene unit is equal to half a screen size by the initial
 * zoom (therefore the space of 3D scene is actually nonlinear respectively to the screen). Of course you can try to
 * calculate out the value you need, but you would find it out easier experimentally. The default value is 0.05.
 */
@property (nonatomic, assign) float width;

@end
