/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartDataSmoother.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartTypes.h"


/**
 * The NChartDataSmoother class provides basic data smoother used to create smooth charts by only a few points.
 */
@interface NChartDataSmoother : NSObject

/**
 * Create new instance of data smoother.
 */
+ (id)dataSmoother;

/**
 * Resolution of the spline. Resolution is the number of subdivisions by the step dimension for each segment. 
 * The default value is 32. The allowed value are [2 .. 1024].
 */
@property (nonatomic, assign) NSInteger resolution;

/**
 * Key of the value that should be interpreted as step dimension. Typically it is NChartValueX (which is the default
 * value), however for bar series it should be NChartValueY.
 */
@property (nonatomic, assign) NChartValue stepDimension;

/**
 * Key of the value that should be interpreted as height dimension. Typically it is NChartValueY (which is the default
 * value), however for bar series it should be NChartValueX.
 */
@property (nonatomic, assign) NChartValue valueDimension;

@end
