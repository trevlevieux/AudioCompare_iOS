/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartTooltip.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartLabel.h"


/**
 * The NChartTooltip class provides methods to display the tooltip for the chart's points.
 */
@interface NChartTooltip : NChartLabel

/**
 * Create new tooltip instance.
 *
 * @return new tooltip instance.
 */
+ (NChartTooltip *)tooltip;

/**
 * Change visibility of tooltip animated.
 *
 * @param visible - flag of visibility.
 * @param duration - duration of animation in seconds.
 */
- (void)setVisible:(BOOL)visible animated:(float)duration;

/**
 * Vertical alignment of the tooltip. It is used if tooltip has no arrow presented, otherwise it is ignored.
 * @see NChartTooltipVerticalAlignment.
 */
@property (nonatomic, assign) NChartTooltipVerticalAlignment verticalAlignment;

/**
 * Default orientation of the tooltip's arrow. The default value is NChartTooltipArrowOrientationBottom.
 *
 * <br> The default arrow orientation is the orientation tooltip uses if it's far from plot area borders.
 * If it's close to border and <alwaysInPlotArea> is set to YES, it's arrow orientation is automatically changed to
 * keep tooltip inside the plot area.
 */
@property (nonatomic, assign) NChartTooltipArrowOrientation defaultArrowOrientation;

/**
 * Flag determining if the tooltip should always be inside of the chart's plot area. If YES, the tooltip may be shifted
 * to fit in the plot area when it's pivot is near the border of the chart's plot area. If NO, it is never shifted
 * and can overlap the axis when it's pivot is near the border of the chart's plot area. The default value is YES.
 */
@property (nonatomic, assign) BOOL alwaysInPlotArea;

@end
