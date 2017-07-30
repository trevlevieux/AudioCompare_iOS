/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartScaleLegend.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartLegend.h"


@class NChartScaleLegend;

/**
 * The NChartScaleLegendDelegate protocol provides methods to manage the contents of the scale legend.
 */
@protocol NChartScaleLegendDelegate <NSObject>

@optional

/**
 * Get the string representation of the scale legend entry by given values.
 *
 * @param scaleLegend - scale legend to get the entry's string representation for.
 * @param from - value staring the range represented by this entry. For example, if the range is [10; 20], 10 is passed.
 * If the left boundary of the range is open, e.g. (-inf; 20], nil is passed.
 * @param to - value ending the range covered by this entry. For example, if the range is [10; 20], 20 is passed.
 * If the right boundary of the range is open, e.g. [10; +inf), nil is passed.
 * @return string representation of the entry. For example, it may be "10 .. 20", or "10 < x < 20". If nil is returned
 * (or no delegate is attached to the legend, or method is not implemented), the default conversion is used.
 * Assuming the values in the scale are 10, 20, 30, the default conversion looks like this:
 * "> 30", "20 - 30", "10 - 20", "< 10".
 */
- (NSString *)scaleLegendDelegateStringRepresentationOfRangeFrom:(NSNumber *)from to:(NSNumber *)to forScaleLegend:(NChartScaleLegend *)scaleLegend;

@end

/**
 * The NChartScaleLegend class provides methods to display the legend associated with the NChartBrushScale instance.
 */
@interface NChartScaleLegend : NChartLegend

/**
 * Initialize scale legend with given brush scale.
 *
 * @param scale - brush scale for the scale legend.
 * @return initialized instance of scale legend.
 */
- (id)initWithScale:(NChartBrushScale *)scale;

/**
 * Create scale legend with given brush scale.
 *
 * @param scale - brush scale for the scale legend.
 * @return new instance of scale legend.
 */
+ (NChartScaleLegend *)scaleLegendWithScale:(NChartBrushScale *)scale;

/**
 * Brush scale associated with the scale legend. The default value is nil.
 * @see NChartBrushScale.
 */
@property (nonatomic, retain) NChartBrushScale *scale;

/**
 * Flag determining if the lower boundary of the scale should be shown in the scale legend (YES) or not (NO).
 * The default value is YES.
 */
@property (nonatomic, assign) BOOL showLowerBoundary;

/**
 * Flag determining if the upper boundary of the scale should be shown in the scale legend (YES) or not (NO).
 * The default value is YES.
 */
@property (nonatomic, assign) BOOL showUpperBoundary;

/**
 * Flag determining if the middle values of the scale should be shown in the scale legend (YES) or not (NO).
 * The default value is YES.
 */
@property (nonatomic, assign) BOOL showMiddleValues;

/**
 * Flag determining if the values in the scale legend are sorted descending (the largest is on the top, YES) or not
 * (the largest is on the bottom, NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL isDescending;

/**
 * Delegate of the scale legend.
 */
@property (nonatomic, assign) id<NChartScaleLegendDelegate> scaleDelegate;

@end
