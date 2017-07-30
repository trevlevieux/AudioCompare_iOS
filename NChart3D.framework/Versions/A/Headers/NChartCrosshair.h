/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartCrosshair.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartPoint.h"
#import "NChartLineDash.h"


@class NChartCrosshair;

/**
 * The NChartCrosshairDelegate protocol provides methods to handle crosshair movements.
 */
@protocol NChartCrosshairDelegate <NSObject>

@optional

/**
 * Report beginning of crosshair movements.
 *
 * @param crosshair - pointer to the crosshair object that did begin moving.
 */
- (void)crosshairDelegateCrosshairDidBeginMoving:(NChartCrosshair *)crosshair;

/**
 * Report crosshair movement.
 *
 * @param crosshair - pointer to the crosshair object that did move.
 */
- (void)crosshairDelegateCrosshairDidMove:(NChartCrosshair *)crosshair;

/**
 * Report ending of crosshair movements.
 *
 * @param crosshair - pointer to the crosshair object that did end moving.
 */
- (void)crosshairDelegateCrosshairDidEndMoving:(NChartCrosshair *)crosshair;

@end

/**
 * The NChartHair class provides methods to control the single line within crosshair.
 * @see NChartCrosshair.
 */
@interface NChartHair : NSObject

/**
 * Flag determining if hair is visible (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL visible;

/**
 * Flag determining if hair is hosted on secondary axis (YES) or not (NO). The default value is NO.
 */
@property (nonatomic, assign) BOOL hostsOnSAxis;

/**
 * Value the hair intersects its axis in. The default value is 0.
 */
@property (nonatomic, assign) double value;

/**
 * The color of the first half of hair. If <code>nil</code>, not displayed. The default value is <code>nil</code>.
 * <br> The color of the hairs part from the axis to the point it marks.
 */
@property (nonatomic, retain) UIColor *firstHalfColor;

/**
 * The color of the second half of hair. If <code>nil</code>, not displayed. The default value is <code>nil</code>.
 * <br> The color of the hairs part from the the point it marks to the end of chart plot area.
 */
@property (nonatomic, retain) UIColor *secondHalfColor;

/**
 * Set color for both halves of hair.
 * @see firstHalfColor, secondHalfColor.
 *
 * @param color - color to set.
 */
- (void)setColor:(UIColor *)color;

/**
 * Flag determining if hair can be dragged (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL isDraggable;

/**
 * Flag determining if hair should snap to major ticks while moving. The default value is NO.
 */
@property (nonatomic, assign) BOOL snapToMajorTicks;

/**
 * Flag determining if hair should snap to minor ticks while moving. The default value is NO.
 */
@property (nonatomic, assign) BOOL snapToMinorTicks;

/**
 * Tooltip of the hair. The default value is nil.
 * <br> To display tooltip you should set it before your <code>updateData</code> call.
 */
@property (nonatomic, retain) NChartTooltip *tooltip;

/**
 * Position of the hair's tooltip. The default value is <code>NChartCrosshairTooltipPositionByMax</code>.
 * @see NChartCrosshairTooltipPosition.
 */
@property (nonatomic, assign) NChartCrosshairTooltipPosition tooltipPosition;

@end

/**
 * The NChartCrosshair class provides methods to control crosshairs - lines that are perpendicular to the axes and are
 * to mark some position on the chart. Single chart can have multiple crosshairs either connected to the chart points or
 * free (with user defined coordinates).
 */
@interface NChartCrosshair : NChartObject

/**
 * Create crosshair.
 *
 * @return new instance of crosshair.
 */
+ (NChartCrosshair *)crosshair;

/**
 * Create crosshair with color, thickness and target point.
 *
 * @param color - color of the crosshair.
 * @param thickness - thickness of the crosshair.
 * @param targetPoint - tracking point of the crosshair.
 * @return new instance of crosshair.
 */
+ (NChartCrosshair *)crosshairWithColor:(UIColor *)color thickness:(float)thickness andTargetPoint:(NChartPoint *)targetPoint;

/**
 * Init crosshair with color, thickness and target point.
 *
 * @param color - color of the crosshair.
 * @param thickness - thickness of the crosshair.
 * @param targetPoint - target point of the crosshair.
 * @return initialized instance of crosshair.
 */
- (id)initWithColor:(UIColor *)color thickness:(float)thickness andTargetPoint:(NChartPoint *)targetPoint;

/**
 * Hair for X-Axis.
 */
@property (nonatomic, readonly) NChartHair *xHair;

/**
 * Hair for Y-Axis.
 */
@property (nonatomic, readonly) NChartHair *yHair;

/**
 * Hair for Z-Axis.
 */
@property (nonatomic, readonly) NChartHair *zHair;

/**
 * Target point for the crosshair.
 * <br> Use this property to set crosshair to track chart point. The point is _not_ retained by the crosshair.
 */
@property (nonatomic, assign) NChartPoint *targetPoint;

/**
 * Thickness of the crosshair in pixels. The default value is 1.
 */
@property (nonatomic, assign) float thickness;

/**
 * Dash of the crosshair.
 * @see NChartLineDash.
 */
@property (nonatomic, retain) NChartLineDash *lineDash;

/**
 * Flag determining if the crosshair should move to the touch wherever the touch location is. The default value is NO.
 * <br> If this flag is YES, all the touches are catched by the topmost crosshair (the one that was last added to
 * the cartesian system of the chart). So no other user interactions like pan and point selection are possible in the
 * chart.
 */
@property (nonatomic, assign) BOOL shouldJumpToTouch;

/**
 * Image that is displaying in the crosshair. The default value is nil.
 */
@property (nonatomic, retain) UIImage *image;

/**
 * Offset in pixels of the image from the crosshair's center. The default value is (0,0).
 */
@property (nonatomic, assign) CGPoint imageOffset;

/**
 * Crosshair delegate.
 */
@property (nonatomic, assign) id<NChartCrosshairDelegate> delegate;

@end
