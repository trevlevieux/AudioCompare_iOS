/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartDataSmootherTBezier.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartDataSmoother.h"


/**
 * The NChartDataSmootherTBezier class provides data smoother based on bezier interpolation 
 * (with control points calculated according to tangents to the curve being smoothed)
 * used to create smooth lines on the charts by only a few points. 
 * Typically this smoother is used for line and area series.
 * @note This smoother ensures minimal deviation from the linear data interpolation (in comparison with
 * <NChartDataSmootherSpline>, <NChartDataSmootherLagrange> and <NChartDataSmootherSBezier>) and guarantees the absence
 * of fake extremums.
 */
@interface NChartDataSmootherTBezier : NChartDataSmoother

@end
