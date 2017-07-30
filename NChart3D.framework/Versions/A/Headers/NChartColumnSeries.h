/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartColumnSeries.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartSolidSeries.h"


/**
 * The NChartColumnSeries class provides methods to display column series.
 */
@interface NChartColumnSeries : NChartSolidSeries

@end

/**
 * NChartColumnSeriesSettings class provides global settings for <NChartColumnSeries>.
 */
@interface NChartColumnSeriesSettings : NChartSolidSeriesSettings

/**
 * The resolution of cylinders. Resolution is the amount of vertices that build the circle. For example if you want to 
 * get a square column, you should set resolution to 4. If you want to get a cylindrical column, you may set a larger
 * value. But the larger is the resolution, the more memory is used and the slower the rendering will be, so you should 
 * find out the minimal acceptable value. A good value for cylinder is 16 or 20. The default value is 4.
 * @note This value cannot be less than 3 and greater than 32.
 */
@property (nonatomic, assign) NSUInteger cylindersResolution;

/**
 * Flag that determines if cylinders should appear smooth (YES) of faced (NO).  Generally if you specify low resolution 
 * \(see <cylindersResolution> for details\) when the individual faces are still visible, it is a good idea to have 
 * cylinders faced and vice versa. The default value is NO.
 * @note If cylinders are faced, it consumes more memory than if they don't by the same resolution.
 */
@property (nonatomic, assign) BOOL shouldSmoothCylinders;

/**
 * Flag that determines if columns should be grouped in the coordinate system cells (YES), or not (NO). The default
 * value is YES.
 * <br> If you have a lot of points that share the same cells, it is good idea to set this flag to YES
 * (to let the default), so the columns sharing the cell are distributed in it. However if you have more than one
 * series which points are not sharing the same cells (for example, each series has only one point that monopolizes the
 * cell), it is better to set this flag to NO, so the points are not distributed and each one takes its whole cell.
 */
@property (nonatomic, assign) BOOL shouldGroupColumns;

/**
 * Column group fill ratio for series that determines the amount of place for one column group (for more information
 * about column groups, see <shouldGroupColumns>). For example, if this fill ratio is 1.0, columns in the group are
 * sticked together with no gaps between them. If the fill ratio is 0.5, columns in the group have gaps and the total
 * width of the gaps is equal to the total width all columns in the group. The default value is 1.0.
 * <br> The difference from <code>fillRatio</code> is that <code>fillRatio</code> deals with the gap between column groups and
 * <code>columnGroupFillRatio</code> is responsible for the gap between columns inside the group.
 */
@property (nonatomic, assign) float columnGroupFillRatio;

/**
 * Animation type of the transition. The default value is <code>NChartColumnAnimationTypeSimultaneously</code>.
 */
@property (nonatomic, assign) NChartColumnAnimationType animationType;

/**
 * Corner radius of the columns relative to the actual column width. The default value is 0.
 * <br> If the radius is 0, columns have sharp corners. If the radius is 1, columns have rounded corners with the
 * radius equal to the half of the columns' width.
 */
@property (nonatomic, assign) float cornerRadius;

@end
