/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPointAnalyzer.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartPoint.h"


/**
 * The NChartPointAnalyzer provides basic methods to scan the given array of chart points and perform some analytics.
 */
@interface NChartPointAnalyzer : NSObject

/**
 * Create instance of point analyzer.
 *
 * @return an authoreleased instance of point analyzer.
 */
+ (id)pointAnalyzer;

/**
 * Perform the analytics on an array of points. This method is implemented in subclasses. It takes into account all the
 * states inside the points given.
 *
 * @param points - array of points to analyze.
 * @return array of result points. Note, that these points can be obtained from the array given, but also generated anew,
 * or both according to the logic of particular point analyzer.
 */
- (NSArray *)analyzePoints:(NSArray *)points;

/**
 * Perform the analytics on an array of points. This method is implemented in subclasses. It takes into account the
 * point states with given index only.
 *
 * @param points - array of points to analyze.
 * @param stateIndex - index of point state to take into account.
 * @return array of result points. Note, that these points can be obtained from the array given, but also generated anew,
 * or both according to the logic of particular point analyzer.
 */
- (NSArray *)analyzePoints:(NSArray *)points withStateIndex:(NSUInteger)stateIndex;

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
