/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartObject.h"
#import "NChartDataSmoother.h"
#import "NChartBrushScale.h"


@class NChartSeries;

/**
 * The NChartSeriesDataSource protocol provides methods to obtain data for the series.
 */
@protocol NChartSeriesDataSource <NSObject>

@required

/**
 * Get array of points for the series.
 *
 * @param series - series to obtain the points for.
 * @return an array of <NChartPoint> instances where the data is stored.
 * @see NChartSeries.
 */
- (NSArray *)seriesDataSourcePointsForSeries:(NChartSeries *)series;

/**
 * Get name for the series.
 *
 * @param series - series to obtain the name for.
 * @return the name for the series.
 * @see NChartSeries.
 */
- (NSString *)seriesDataSourceNameForSeries:(NChartSeries *)series;

@optional

/**
 * Get image for the series that is displayed in the legend. If nil is returned or method is not implemented, the default
 * image is used.
 *
 * @param series - series to get image for.
 * @return the image for the series.
 * @see NChartSeries.
 */
- (UIImage *)seriesDataSourceImageForSeries:(NChartSeries *)series;

/**
 * Extend array of points in series.
 * <br> Use this method to provide additional data for series. This method is called after you call
 * <code>extendData</code> of <code>NChart</code>.
 * @note The points from the array returned are _added_ to the series' array of points, so series will have more data.
 * The maximal length of data array is determined by <code>pointsHistoryLength</code> property of <code>NChart</code>.
 * @see NChart.
 *
 * @param series - series to obtain the extra points for.
 * @return array of extra points.
 */
- (NSArray *)seriesDataSourceExtraPointsForSeries:(NChartSeries *)series;

@end

/**
 * The NChartSeries class provides common methods for the series of the chart.
 */
@interface NChartSeries : NChartObject

/**
 * Create instance of series.
 *
 * @return an autoreleased instance of the series.
 */
+ (id)series;

/**
 * Array of points.
 */
@property (nonatomic, readonly) NSArray *points;

/**
 * Name of the series.
 */
@property (nonatomic, readonly) NSString *name;

/**
 * Image that is displayed in the legend. This property returns the image only if it was provided by the data source.
 * If the default image is used, nil is returned.
 */
@property (nonatomic, readonly) UIImage *image;

/**
 * Size of default series' marker in legend in pixels. The default value is 20.
 */
@property (nonatomic, assign) float legendMarkerSize;

/**
 * Brush scale of the series used to color the map.
 */
@property (nonatomic, retain) NChartBrushScale *scale;

/**
 * Tag of the series. You may use it as you want.
 */
@property (nonatomic, assign) NSInteger tag;

/**
 * Flag that determines if the series is hosted on the secondary X-axis. If YES, it will be drawn according to the
 * secondary X-axis, if NO according to the normal X-axis. The secondary axis appears opposite the normal axis and is
 * managed separately: it can have its own min and max; its own color settings and so on.
 */
@property (nonatomic, assign) BOOL hostsOnSX;

/**
 * Flag that determines if the series is hosted on the secondary Y-axis. If YES, it will be drawn according to the
 * secondary Y-axis, if NO according to the normal Y-axis. The secondary axis appears opposite the normal axis and is
 * managed separately: it can have its own min and max; its own color settings and so on.
 */
@property (nonatomic, assign) BOOL hostsOnSY;

/**
 * Flag that determines if the series is hosted on the secondary Z-axis. If YES, it will be drawn according to the
 * secondary Z-axis, if NO according to the normal Z-axis. The secondary axis appears opposite the normal axis and is
 * managed separately: can have its own min and max; its own color settings and so on.
 */
@property (nonatomic, assign) BOOL hostsOnSZ;

/**
 * Data source for the series.
 * @see NChartSeriesDataSource.
 */
@property (nonatomic, assign) id<NChartSeriesDataSource> dataSource;

/**
 * Data smoother used. The default value is nil (no data smoother used).
 * @see NChartDataSmoother.
 */
@property (nonatomic, retain) NChartDataSmoother *dataSmoother;

@end

/**
 * The NChartSeriesSettings class provides basic container for settings that are to be applied for all the series of
 * particular type that are added to the chart. For different types of series there are different classes of containers
 * that are inherited from NChartSeriesSettings. You can add the settings to the chart via <code>addSeriesSettings:</code> method
 * of <NChart>. The settings are applied to the series while <updateData> call of <NChart>.
 */
@interface NChartSeriesSettings : NSObject

/**
 * Create instance of settings.
 *
 * @return an autoreleased instance of the series.
 */
+ (id)seriesSettings;

/**
 * Flag determining if rudiment is allowed. The default value is YES.
 * <br> Rudiment is a part of series that remains unused from the previous displayed data set and disappears
 * by the animated transition.
 *
 * @return YES if rudiment is enabled, NO if not.
 */
@property (nonatomic, assign) BOOL isRudimentEnabled;

@end
