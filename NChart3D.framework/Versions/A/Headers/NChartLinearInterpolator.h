/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartLinearInterpolator.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartInterpolator.h"


/**
 * The NChartLinearInterpolator class provides linear interpolator. If it is used, the animated values will changed in
 * time as follows: v(t) = (1 - t) * v_from + t * v_to, where v_from, v_to are respectively the start and end values,
 * t is the time.
 */
@interface NChartLinearInterpolator : NChartInterpolator

@end
