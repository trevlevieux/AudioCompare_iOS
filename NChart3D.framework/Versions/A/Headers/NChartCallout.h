/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartCallout.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartTooltip.h"


/**
 * The NChartCallout class provides methods to display tooltips as callouts.
 */
@interface NChartCallout : NChartTooltip

/**
 * Create new callout instance.
 *
 * @return new callout instance.
 */
+ (NChartCallout *)callout;

/**
 * Thickness of the callout line. The default value is 1.
 */
@property (nonatomic, assign) float lineThickness;

/**
 * Color of the callout line. The default value is [UIColor blackColor].
 */
@property (nonatomic, retain) UIColor *lineColor;

/**
 * Position where the line connects to the label. The default value is NChartCalloutLineToLabelConnectionPosAutodetect.
 */
@property (nonatomic, assign) NChartCalloutLineToLabelConnectionPos lineToLabelConnectionPos;

/**
 * Distance from the chart's point to the callout's tooltip in the autodetected direction (in pixels). If this property
 * is 0, <code>margin</code> is used to control this distance (and therefore you control the direction yourself).
 * Otherwise, the direction is detected automatically. In case of pie it's median of the corresponding sector. In case
 * of all other charts it's north-east direction. The default value is 0.
 */
@property (nonatomic, assign) float distance;

/**
 * Type of callout line. The default value is NChartCalloutLineTypeStraight.
 */
@property (nonatomic, assign) NChartCalloutLineType lineType;

/**
 * Flag determining if callout should be located in the position specified by the <origin> property (YES),
 * or according to <distance> and <code>margin</code> properties (NO). The default value is NO.
 * @note If this property is set to YES, <origin> has effect, but <code>margin</code> and <distance> has no effect,
 * and vice versa.
 */
@property (nonatomic, assign) BOOL locateByOrigin;

/**
 * Position of the top left corner of callout in pixels based on view's coordinate system, but with zero point shifted
 * to the top left corner of chart plot area. The default value is {0; 0}.
 * @note This property has effect if <locateByOrigin> is set to YES only.
 */
@property (nonatomic, assign) CGPoint origin;

@end
