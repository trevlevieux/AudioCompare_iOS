/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartValueAxisMark.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartLabel.h"
#import "NChartAxisTick.h"


/**
 * The NChartValueAxisMark class provides methods to handle marks on the value axes.
 */
@interface NChartValueAxisMark : NChartLabel

/**
 * Create new mark instance.
 *
 * @return new mark instance.
 */
+ (NChartValueAxisMark *)mark;

/**
 * Value of the mark.
 */
@property (nonatomic, assign) double value;

/**
 * Tick of the mark. It is invisible by default.
 */
@property (nonatomic, readonly) NChartAxisTick *tick;

@end
