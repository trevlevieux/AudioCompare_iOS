/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPeakDetector.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartPointAnalyzer.h"


/**
 * The NChartPeakDetector class provides methods to detect peak values inside the given point array. The detection is
 * based on the deviation from moving average.
 */
@interface NChartPeakDetector : NChartPointAnalyzer

/**
 * Flag determining if peak detector should find down-peaks (YES), or not (NO). The default value is YES. The down-peaks
 * are defined as peaks laying beneath the moving average inside the search window.
 */
@property (nonatomic, assign) BOOL findMin;

/**
 * Flag determining if peak detector should find up-peaks (YES), or not (NO). The default value is YES. The up-peaks
 * are defined as peaks laying below the moving average inside the search window.
 */
@property (nonatomic, assign) BOOL findMax;

/**
 * Flag determining if <threshold> is absolute (YES) or relative (NO). The default value is NO.
 * Absolute threshold means that it is given in the same units as the values in the analyzed points.
 * Relative threshold represents a fraction of |max - min|, where max is the maximal value in the given points array and
 * min is the minimal one.
 * So if, for example, min = 0, max = 10, threshold is set to 0.3 and this flag is YES, then the actual threshold the 
 * peaks will be search according to will be 0.3.
 * But if this flag is NO, the actual threshold will be 0.3 * (10 - 0) = 3.
 * Normally it's reasonable to use relative threshold if you don't know the bounds of your values. However, this will 
 * mean an additional scan through the points to determine min and max values, so the processing will take a bit more
 * time.
 */
@property (nonatomic, assign) BOOL absoluteThreshold;

/**
 * Threshold to search the peaks according to. The default value is 0.3. See <absoluteThreshold> for details about how
 * this value is interpreted.
 */
@property (nonatomic, assign) double threshold;

/**
 * Width (in number of points) of the search window needed to calculate moving average. The default value is 5.
 */
@property (nonatomic, assign) NSUInteger windowWidth;

@end
