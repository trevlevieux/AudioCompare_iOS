/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartBezierInterpolator.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartInterpolator.h"


/**
 * The NChartBezierInterpolator class provides bezier interpolator. If it is used, the animated values will changed in
 * time as follows: v(t) = (1 - t)^2 * v_from + 2 * t * (1 - t) * v_c + t^2 * v_from, where v_from, v_to are
 * respectively the start and end values, v_c is control point and t is the time.
 */
@interface NChartBezierInterpolator : NChartInterpolator

/**
 * Create the bezier interpolator with given control point.
 *
 * @param controlPoint - control point. Very often it makes sense when the control point is equal to the end value of
 * animated property.
 * @return new instance of bezier interpolator.
 */
+ (id)bezierInterpolatorWithControlPoint:(float)controlPoint;

/**
 * Initialize the bezier interpolator with given control point.
 *
 * @param controlPoint - control point. Very often it makes sense when the control point is equal to the end value of
 * animated property.
 * @return initialized instance of bezier interpolator.
 */
- (id)initWithControlPoint:(float)controlPoint;

/**
 * Control point of bezier interpolator.
 */
@property (nonatomic, assign) float controlPoint;

@end
