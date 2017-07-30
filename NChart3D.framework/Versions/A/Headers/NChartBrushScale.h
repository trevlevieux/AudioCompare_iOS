/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartBrushScale.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartBrush.h"


/**
 * The NChartBrushScale class provides scale that transforms values into brushes like a step mapping function.
 * <br> The scale contains array of reference values and array of brushes. It returns brush for given value
 * according to these arrays:
 * <pre><code>
 * brushes[n]
 *   values[n - 1]
 * ...
 * brushes[4]
 *   values[3]
 * brushes[3]
 *   values[2]
 * brushes[2]
 *   values[1]
 * brushes[1]
 *   values[0]
 * brushes[0]
 * </code></pre>
 * This is equivalent to the following pseudo code:
 * <pre><code>
 * if value <= values[0] return brushes[0];
 * if value > values[i] and value <= values[i + 1] return brush[i + 1];
 * if value > values[last] return brush[last]
 * </code></pre>
 * So the array of brushes should contain n elements and array of values should contain n - 1. Values should be sorted
 * (NChartBrushScale does not sort them automatically). If they are not, it can lead to strange results. If brush index goes
 * out of range, nil is returned.
 */
@interface NChartBrushScale : NSObject

/**
 * Create new instance of NChartBrushScale with arrays of brushes and values.
 *
 * @param brushes - array of brushes represented with <NChartBrush>.
 * @param values - array of values represented with NSNumber.
 * @return a new instance of NChartBrushScale.
 */
+ (NChartBrushScale *)brushScaleWithBrushes:(NSArray *)brushes andValues:(NSArray *)values;

/**
 * Init new instance of NChartBrushScale with arrays of brushes and values.
 *
 * @param brushes - array of brushes represented with <NChartBrush>.
 * @param values - array of values represented with NSNumber.
 * @return initialized instance of NChartBrushScale.
 */
- (id)initWithBrushes:(NSArray *)brushes andValues:(NSArray *)values;

/**
 * Array of brushes.
 */
@property (nonatomic, readonly) NSArray *brushes;

/**
 * Array of values.
 */
@property (nonatomic, readonly) NSArray *values;

/**
 * Flag determining if scale can return gradient colors. The default value is YES.
 * <br> The gradient scale assumes that the array of brushes contains instances of <NChartSolidColorBrush> and
 * linearly interpolates colors that correspond to the neighbor values.
 */
@property (nonatomic, assign) BOOL isGradient;

/**
 * Get value for brush.
 *
 * @param value - value to get brush for.
 * @return brush for given value.
 */
- (NChartBrush *)brushForValue:(NSNumber *)value;

@end
