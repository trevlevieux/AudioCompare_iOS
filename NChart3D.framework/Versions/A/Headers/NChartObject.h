/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartObject.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import <Foundation/Foundation.h>
#import "NChartTypes.h"


@class NChart;

/**
 * The NChartObject class provides common methods for all the objects on the chart.
 */
@interface NChartObject : NSObject

/**
 * Flag that determines if the object is visible (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL visible;

/**
 * Chart the object belongs to.
 * <br> This property is assigned automatically whenever the object is assigned to the chart.
 */
@property (nonatomic, readonly) NChart *chart;

@end
