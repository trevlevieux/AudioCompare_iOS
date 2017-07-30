/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartLineDash.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import <Foundation/Foundation.h>


/**
 * The NChartLineDash class provides methods to set up the dash pattern for lines drawn on the chart.
 */
@interface NChartLineDash : NSObject

/**
 * Create new line dash instance.
 *
 * @param pattern - pattern of the line dash.
 * @return new line dash instance.
 */
+ (NChartLineDash *)lineDashWithPattern:(NSArray *)pattern;

/**
 * Create new line dash instance.
 *
 * @param pattern - pattern of the line dash.
 * @param phase - phase of the line dash.
 * @return new line dash instance.
 */
+ (NChartLineDash *)lineDashWithPattern:(NSArray *)pattern andPhase:(float)phase;

/**
 * Init line dash instance.
 *
 * @param pattern - pattern of the line dash.
 * @return initialized instance of the line dash.
 */
- (id)initWithPattern:(NSArray *)pattern;

/**
 * Init line dash instance.
 *
 * @param pattern - pattern of the line dash.
 * @param phase - phase of the line dash.
 * @return initialized instance of the line dash.
 */
- (id)initWithPattern:(NSArray *)pattern andPhase:(float)phase;

/**
 * Array representing the line dash as the lengths (in pixels) of the painted and unpainted segments, respectively. 
 * If the values is nil or an array has no elements, dash is not applied and the line is drawn continuous. 
 * The default values is nil.
 * <br> For example, if the array <code>@[@10, @15]</code> is set, the line will alternate between 10 pixels 
 * drawn segment and 15 pixels gap. If <code>@[@10, @5, @15, @8]</code> is set, the line will be a looped pattern
 * of 10 pixels drawn segment, followed by 5 pixels gap, followed by 15 pixels drawn segment, followed by 8 pixels gap.
 */
@property (nonatomic, retain) NSArray<NSNumber *> *pattern;

/**
 * Value specifying how far (in pixels) into the dash pattern the line starts.
 * The default value is 0 which means to start interpreting the pattern from the beginning.
 * <br> For example, if 10 is set, the line is drawn with the dash pattern starting at 10 pixels from its 
 * beginning.
 */
@property (nonatomic, assign) float phase;

@end
