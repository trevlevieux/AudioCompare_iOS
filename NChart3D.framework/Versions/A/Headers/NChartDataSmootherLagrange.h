/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartDataSmootherLagrange.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartDataSmoother.h"


/**
 * The NChartDataSmootherLagrange class provides data smoother based on Lagrange polynoms used to create smooth lines
 * on the charts by only a few points. Typically this smoother is used for line and area series.
 * @note This smoother ensures the best smoothing in comparison with <NChartDataSmootherTBezier> and
 * <NChartDataSmootherSBezier>, but has large deviation from the linear data interpolation (even larger than 
 * <NChartDataSmooterSpline>) and can produce large fake extremums. It may be good for some, but generally it's
 * recommended to use <NChartDataSmootherTBezier> instead.
 */
@interface NChartDataSmootherLagrange : NChartDataSmoother

@end
