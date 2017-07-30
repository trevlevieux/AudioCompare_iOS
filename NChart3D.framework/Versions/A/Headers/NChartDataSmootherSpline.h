/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartDataSmootherSpline.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartDataSmoother.h"


/**
 * The NChartDataSmootherSpline class provides data smoother based on cubic defect 1 splines used to create smooth lines
 * on the charts by only a few points. Typically this smoother is used for line and area series.
 * @note This smoother ensures the best smoothing in comparison with <NChartDataSmootherTBezier> and
 * <NChartDataSmootherSBezier>, but has large deviation from the linear data interpolation and can produce large fake 
 * extremums. 
 */
@interface NChartDataSmootherSpline : NChartDataSmoother

@end
