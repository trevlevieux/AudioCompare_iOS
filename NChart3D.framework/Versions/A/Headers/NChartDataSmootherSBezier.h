/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartDataSmootherSBezier.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartDataSmoother.h"


/**
 * The NChartDataSmootherSBezier class provides data smoother based on bezier interpolation
 * (with control points calculated to ensure defect 1 spline) used to create smooth lines on the charts by only a few points.
 * Typically this smoother is used for line and area series.
 * @note This smoother ensures better smoothing in comparison with <NChartDataSmootherTBezier>, but has larger deviation 
 * from the linear data interpolation and can produce fake extremums. However, the deviation of the fake extremums is
 * smaller in comparison with <NChartDataSmootherSpline> and <NChartDataSmootherLagrange>.
 */
@interface NChartDataSmootherSBezier : NChartDataSmoother

@end
