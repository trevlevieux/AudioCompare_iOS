/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartSizeAxis.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartAxis.h"


@class NChartSizeAxis;

/**
 * The NChartSizeAxisDataSource protocol provides methods to control data on the size axis.
 */
@protocol NChartSizeAxisDataSource <NSObject>

@required

/**
 * Get minimal size of markers on the screen in pixels.
 *
 * @param sizeAxis - the size axis to obtain the minimal size for.
 * @return the minimal size of the markers on the screen in pixels.
 * @see NChartSizeAxis.
 */
- (float)sizeAxisDataSourceMinSizeForSizeAxis:(NChartSizeAxis *)sizeAxis;

/**
 * Get maximal size of markers on the screen in pixels.
 *
 * @param sizeAxis - the size axis to obtain the maximal size for.
 * @return the maximal size of the markers on the screen in pixels.
 * @see NChartSizeAxis.
 */
- (float)sizeAxisDataSourceMaxSizeForSizeAxis:(NChartSizeAxis *)sizeAxis;

@optional

/**
 * Get minimal value of markers' sizes. If no implementation is provided, the minimal size is calculated according to
 * the data.
 *
 * @param sizeAxis - the size axis to obtain the minimal value for.
 * @return the minimal value of markers' sizes. It may be nil that is equivalent to the absence of implementation.
 * @see NChartSizeAxis.
 */
- (NSNumber *)sizeAxisDataSourceMinForSizeAxis:(NChartSizeAxis *)sizeAxis;

/**
 * Get maximal value of markers' sizes. If no implementation is provided, the maximal size is calculated according to
 * the data.
 *
 * @param sizeAxis - the size axis to obtain the maximal value for.
 * @return the maximal value of the markers' sizes. It may be nil that is equivalent to the absence of implementation.
 * @see NChartSizeAxis.
 */
- (NSNumber *)sizeAxisDataSourceMaxForSizeAxis:(NChartSizeAxis *)sizeAxis;

@end

/**
 * The NChartSizeAxis class provides methods to scale the sizes of <NChartMarker> objects. The idea is to map the value
 * of marker's size that is assumed to be in (<minValue>, <maxValue>) to the (<minSize>, <maxSize>). For example if a
 * particular marker has size 0.3555, <minValue> = 0, <maxValue> = 1, <minSize> = 10 (pixels) and <maxSize> = 100
 * (pixels), the actual size of the marker on the screen will be 42 pixels.
 */
@interface NChartSizeAxis : NChartAxis

/**
 * Minimal value of the markers' sizes.
 */
@property (nonatomic, readonly) double minValue;

/**
 * Maximal value of the markers' sizes.
 */
@property (nonatomic, readonly) double maxValue;

/**
 * Minimal size of the markers on the screen in pixels.
 */
@property (nonatomic, readonly) float minSize;

/**
 * Maximal size of the markers on the screen in pixels.
 */
@property (nonatomic, readonly) float maxSize;

/**
 * Flag determining if markers should ignore chart's zoom (YES) or not (NO). The default value is NO.
 * <br> If this flag is set to YES, markers are not zoomed with the chart and remain in their size
 * (value of their <code>size</code> property).
 * Otherwise, size of markers corresponds to their <code>size</code> property when zoom is 1.0 only.
 */
@property (nonatomic, assign) BOOL shouldIgnoreZoom;

/**
 * Data source of the axis
 * @see NChartSizeAxisDataSource.
 */
@property (nonatomic, assign) id<NChartSizeAxisDataSource> dataSource;

@end
