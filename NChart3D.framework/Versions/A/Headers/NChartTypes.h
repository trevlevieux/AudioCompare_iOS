/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartTypes.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

/**
 * The NChartMargin struct stores the spacing of chart's elements.
 */
typedef struct
{
    /**
     * Spacing from the left side in pixels.
     */
    float left;
    
    /**
     * Spacing from the right side in pixels.
     */
    float right;
    
    /**
     * Spacing from the bottom side in pixels.
     */
    float bottom;
    
    /**
     * Spacing from the top side in pixels.
     */
    float top;
} NChartMargin;

/**
 * Create NChartMargin with given parameters.
 *
 * @param left - spacing from the left side in pixels.
 * @param right - spacing from the right side in pixels.
 * @param bottom - spacing from the bottom side in pixels.
 * @param top - spacing from the top side in pixels.
 * @return the margin.
 */
CG_INLINE NChartMargin NChartMarginMake(float left, float right, float bottom, float top)
{
    NChartMargin result;
    result.left = left;
    result.right = right;
    result.bottom = bottom;
    result.top = top;
    return result;
};

/**
 * The NChartVector3 struct stores 3-dimensional coordinates.
 */
typedef struct
{
    /**
     * X coordinate.
     */
    float x;
    
    /**
     * Y coordinate.
     */
    float y;
    
    /**
     * Z coordinate.
     */
    float z;
} NChartVector3;

/**
 * Create NChartVector3 with given coordinates.
 *
 * @param x - X coordinate.
 * @param y - Y coordinate.
 * @param z - Z coordinate.
 * @return the vector.
 */
CG_INLINE NChartVector3 NChartVector3Make(float x, float y, float z)
{
    NChartVector3 result;
    result.x = x;
    result.y = y;
    result.z = z;
    return result;
};

/**
 * The NChartZoomMode enum provides constants for different zoom modes.
 */
typedef NS_ENUM(NSInteger, NChartZoomMode)
{
    /**
     * Zoom is disabled.
     */
    NChartZoomModeNone,
    
    /**
     * Zoom is enabled and is always proportional.
     */
    NChartZoomModeProportional,
    
    /**
     * Zoom is enabled and is directional, so the user can zoom separately in the horizontal and vertical direction. By
     * diagonal direction zoom is proportional. Direction is determined as a vector that connects the user's fingers
     * during the pinch gesture.
     */
    NChartZoomModeDirectional
};

/**
 * The NChartUserInteraction enum provides constants to control available user interaction. You can use them to build
 * the mask of interactions availability by concatenating the needed ones with bitwise OR.
 */
typedef NS_ENUM(NSUInteger, NChartUserInteraction)
{
    /**
     * No interactions are available.
     */
    NChartUserInteractionNone = 0,
    
    /**
     * Vertical moving is available.
     */
    NChartUserInteractionVerticalMove = 1,
    
    /**
     * Horizontal moving is available.
     */
    NChartUserInteractionHorizontalMove = 2,
    
    /**
     * Rotation by vertical moving is available.
     */
    NChartUserInteractionVerticalRotate = 4,
    
    /**
     * Rotation by horizontal moving is available.
     */
    NChartUserInteractionHorizontalRotate = 8,
    
    /**
     * Vertical zoom is available.
     */
    NChartUserInteractionVerticalZoom = 16,
    
    /**
     * Horizontal zoom is available.
     */
    NChartUserInteractionHorizontalZoom = 32,
    
    /**
     * Proportional zoom is available.
     */
    NChartUserInteractionProportionalZoom = 64,
    
    /**
     * Tap is available.
     */
    NChartUserInteractionTap = 128,
    
    /**
     * All interactions are available.
     */
    NChartUserInteractionAll = 255
};

/**
 * The NChartAxisTickType enum provides constants to determine the ticks' layout on the axes.
 */
typedef NS_ENUM(NSInteger, NChartAxisTickType)
{
    /**
     * Ticks are on the inner side of the axis.
     */
    NChartAxisTickTypeInner,
    
    /**
     * Ticks are on the outer side of the axis.
     */
    NChartAxisTickTypeOuter,
    
    /**
     * Ticks are both on the inner and outer sides of the axis.
     */
    NChartAxisTickTypeBoth
};

/**
 * The NChartShadingModel provides constants for shading models used to shade 3D-objects.
 */
typedef NS_ENUM(NSInteger, NChartShadingModel)
{
    /**
     * Plain shading model, just filling with the corresponding color / gradient / texture / etc.
     */
    NChartShadingModelPlain,
    
    /**
     * Phong's shading model, filling with the corresponding color / gradient / texture / etc while shaded.
     */
    NChartShadingModelPhong
};

/**
 * The NChartLegendBlockAlignment enum provides constants for different predefined positions of the legend on the screen.
 */
typedef NS_ENUM(NSInteger, NChartLegendBlockAlignment)
{
    /**
     * Legend is in the top left corner of the screen.
     */
    NChartLegendBlockAlignmentTopLeft,
    
    /**
     * Legend is in the center on the top of the screen.
     */
    NChartLegendBlockAlignmentTopCenter,
    
    /**
     * Legend is in the top right corner of the screen.
     */
    NChartLegendBlockAlignmentTopRight,
    
    /**
     * Legend is on the left in the middle of the screen.
     */
    NChartLegendBlockAlignmentCenterLeft,
    
    /**
     * Legend is in the center of the screen.
     */
    NChartLegendBlockAlignmentCenterCenter,
    
    /**
     * Legend is on the right in the middle of the screen.
     */
    NChartLegendBlockAlignmentCenterRight,
    
    /**
     * Legend is in the bottom left corner of the screen.
     */
    NChartLegendBlockAlignmentBottomLeft,
    
    /**
     * Legend is in the center on the bottom of the screen.
     */
    NChartLegendBlockAlignmentBottomCenter,
    
    /**
     * Legend is in the bottom right corner of the screen.
     */
    NChartLegendBlockAlignmentBottomRight,
    
    /**
     * Legend fills the whole left area of the screen.
     */
    NChartLegendBlockAlignmentLeft,
    
    /**
     * Legend fills the whole right area of the screen.
     */
    NChartLegendBlockAlignmentRight,
    
    /**
     * Legend fills the whole bottom area of the screen.
     */
    NChartLegendBlockAlignmentBottom,
    
    /**
     * Legend fills the whole top area of the screen.
     */
    NChartLegendBlockAlignmentTop
};

/**
 * The NChartLegendOrientation enum provides constants for different legend docking modes.
 */
typedef NS_ENUM(NSInteger, NChartLegendOrientation)
{
    /**
     * Legend is fixed, you cannot alter the legend's origin, because it will be ignored.
     */
    NChartLegendOrientationFixed,
    
    /**
     * Legend is fixed by the Y-Axis, but free by the X-Axis, so you can alter the x-value of the origin and the y-value
     * will be ignored.
     */
    NChartLegendOrientationFreeHorizontal,
    
    /**
     * Legend is fixed by the X-Axis, but free by the Y-Axis, so you can alter the y-value of the origin and the x-value
     * will be ignored.
     */
    NChartLegendOrientationFreeVertical,
    
    /**
     * Legend is free by the X- and Y-Axis, so you can alter the origin.
     */
    NChartLegendOrientationFreeFloat
};

/**
 * The NChartLegendContentAlignment enum provides constants to align the legend's content in the legend area.
 */
typedef NS_ENUM(NSInteger, NChartLegendContentAlignment)
{
    /**
     * Align the content of the legend left.
     */
    NChartLegendContentAlignmentLeft,
    
    /**
     * Align the content of the legend to the center.
     */
    NChartLegendContentAlignmentCenter,
    
    /**
     * Align the content of the legend justified.
     */
    NChartLegendContentAlignmentJustified
};

/**
 * The NChartMarkerShape enum provides constants for markers' shapes.
 */
typedef NS_ENUM(NSInteger, NChartMarkerShape)
{
    /**
     * Do not display the marker.
     */
    NChartMarkerShapeNone,
    
    /**
     * Display a plain circle.
     */
    NChartMarkerShapeCircle,
    
    /**
     * Display a volumetric sphere.
     */
    NChartMarkerShapeSphere,
    
    /**
     * Display a custom 3D model.
     */
    NChartMarkerShapeModel
};

/**
 * The NChartTimeAxisTickShape enum provides constants to control the shape of ticks on the time axis.
 */
typedef NS_ENUM(NSInteger, NChartTimeAxisTickShape)
{
    /**
     * Ticks in the shape of a line.
     */
    NChartTimeAxisTickShapeLine,
    
    /**
     * Ticks in the shape of a triangle.
     */
    NChartTimeAxisTickShapeTriangle
};

/**
 * The NChartTimeAxisLabelsLayout enum provides constants to control the label's layout on the time axis.
 */
typedef NS_ENUM(NSInteger, NChartTimeAxisLabelsLayout)
{
    /**
     * Show all labels.
     */
    NChartTimeAxisShowAllLabels = 0,
    
    /**
     * Show the first and the last labels only.
     */
    NChartTimeAxisShowFirstLastLabelsOnly = 1
};

/**
 * The NChartTimeAxisLabelsPosition enum provides constants to the control label's positions on the time axis.
 */
typedef NS_ENUM(NSInteger, NChartTimeAxisLabelsPosition)
{
    /**
     * Place labels above the time axis.
     */
    NChartTimeAxisLabelsAbove,
    
    /**
     * Place labels beneath the time axis.
     */
    NChartTimeAxisLabelsBeneath
};

/**
 * The NChartValueAxesType enum provides constants of value axes types.
 */
typedef NS_ENUM(NSInteger, NChartValueAxesType)
{
    /**
     * Absolute type.
     */
    NChartValueAxesTypeAbsolute,
    
    /**
     * Additional type.
     */
    NChartValueAxesTypeAdditive,
    
    /**
     * Percent type.
     */
    NChartValueAxesTypePercent
};

/**
 * The NChartValueAxisKind enum provides constants to indicate the value axes.
 */
typedef NS_ENUM(NSInteger, NChartValueAxisKind)
{
    /**
     * X-axis.
     */
    NChartValueAxisX,
    
    /**
     * Secondary X-axis.
     */
    NChartValueAxisSX,
    
    /**
     * Y-axis.
     */
    NChartValueAxisY,
    
    /**
     * Secondary Y-axis.
     */
    NChartValueAxisSY,
    
    /**
     * Z-axis.
     */
    NChartValueAxisZ,
    
    /**
     * Secondary Z-axis.
     */
    NChartValueAxisSZ,
    
    /**
     * Azimuth-Axis.
     */
    NChartValueAxisAzimuth,
    
    /**
     * Radius-Axis.
     */
    NChartValueAxisRadius
};

/**
 * The NChartHighlightType enum provides constants to highlight points. You may use them to build a bitmask of highlight.
 * This means you may specify NChartHighlightTypeColor | NChartHighlightTypeShift to get highlight by color and highlight
 * by shift at the same time.
 */
typedef NS_ENUM(NSUInteger, NChartHighlightType)
{
    /**
     * No highlight.
     */
    NChartHighlightTypeNone = 0,
    
    /**
     * Highlight by color.
     */
    NChartHighlightTypeColor = 1,
    
    /**
     * Highlight by shift.
     */
    NChartHighlightTypeShift = 2,
    
    /**
     * Drop previous highlights. Add this to your highlight type combination if you do not want the highlights to
     * accumulate. This means, if there are some highlights queued by delay or not fully animated, they will be
     * cancelled.
     */
    NChartHighlightDrop = 4
};

/**
 * The NChartTooltipVerticalAlignment enum provides constants for vertical alignment of the tooltip.
 */
typedef NS_ENUM(NSUInteger, NChartTooltipVerticalAlignment)
{
    /**
     * Align tooltip on the top of it's pivot (the point it is connected with).
     */
    NChartTooltipVerticalAlignmentTop,
    
    /**
     * Align tooltip with it's pivot (the point it is connected with) in the center.
     */
    NChartTooltipVerticalAlignmentCenter,
    
    /**
     * Align tooltip on the bottom of it's pivot (the point it is connected with).
     */
    NChartTooltipVerticalAlignmentBottom
};

/**
 * The NChartTexturePosition enum provides constants that control position of texture.
 */
typedef NS_ENUM(NSUInteger, NChartTexturePosition)
{
    /**
     * Position texture in the top left corner of the area.
     */
    NChartTexturePositionTopLeftCorner,
    
    /**
     * Position texture at the center of the area.
     */
    NChartTexturePositionCenter,
    
    /**
     * Scale texture to fill the whole area.
     */
    NChartTexturePositionScale,
    
    /**
     * Scale texture keeping aspect so, that it fits in the area.
     */
    NChartTexturePositionScaleKeepMinAspect,
    
    /**
     * Scale texture keeping aspect so, that it covers the whole area.
     */
    NChartTexturePositionScaleKeepMaxAspect
};

/**
 * The NChartAnimationType enum provides constants to indicate different animations of the chart objects.
 */
typedef NS_ENUM(NSUInteger, NChartAnimationType)
{
    /**
     * Animation of transition from the one data set to the other.
     */
    NChartAnimationTypeTransition,
    
    /**
     * Animation of point highlighting.
     */
    NChartAnimationTypeHighlight,
    
    /**
     * Animation of zoom.
     */
    NChartAnimationTypeZoom,
    
    /**
     * Animation of pan.
     */
    NChartAnimationTypePan,
    
    /**
     * Animation of pie and polar coordinate system rotation.
     */
    NChartAnimationTypeWheel
};

/**
 * The NChartEventState enum provides constants to indicate different phases of chart events.
 */
typedef NS_ENUM(NSUInteger, NChartEventPhase)
{
    /**
     * Beginning phase of the event.
     */
    NChartEventPhaseBegan,
    
    /**
     * Changing phase of the event.
     */
    NChartEventPhaseChanged,
    
    /**
     * Ending phase of the event.
     */
    NChartEventPhaseEnded
};

/**
 * The NChartCaptionBlockAlignment enum provides constants to control position of the caption's block.
 */
typedef NS_ENUM(NSUInteger, NChartCaptionBlockAlignment)
{
    /**
     * Align caption in the top left corner.
     */
    NChartCaptionBlockAlignmentTopLeft,
    /**
     * Align caption at the center on the top of the screen.
     */
    NChartCaptionBlockAlignmentTopCenter,
    /**
     * Align caption in the top right corner.
     */
    NChartCaptionBlockAlignmentTopRight,
    /**
     * Align caption in the bottom left corner.
     */
    NChartCaptionBlockAlignmentBottomLeft,
    /**
     * Align caption at the center on the bottom of the screen.
     */
    NChartCaptionBlockAlignmentBottomCenter,
    /**
     * Align caption in the bottom right corner.
     */
    NChartCaptionBlockAlignmentBottomRight
};

/**
 * The NChartValue enum provides constants to indicate values from the point states.
 */
typedef NS_ENUM(NSUInteger, NChartValue)
{
    /**
     * X value.
     */
     NChartValueX,
    
    /**
     * Y value.
     */
     NChartValueY,
    
    /**
     * Z value.
     */
     NChartValueZ,
    
    /**
     * Open value.
     */
    NChartValueOpen,
    
    /**
     * High value.
     */
    NChartValueHigh,
    
    /**
     * Low value.
     */
    NChartValueLow,
    
    /**
     * Close value.
     */
    NChartValueClose
};

/**
 * The NChartAxisLabelsAlignment enum provides constants to align labels relative to the axes' thicks.
 */
typedef NS_ENUM(NSUInteger, NChartAxisLabelsAlignment)
{
    /**
     * Align labels centered.
     */
    NChartAxisLabelsAlignmentCenter,
    
    /**
     * Align labels left.
     */
    NChartAxisLabelsAlignmentLeft,
    
    /**
     * Align labels right.
     */
    NChartAxisLabelsAlignmentRight
};

/**
 * The NChartColumnAnimationType enum provides constants to control transition animation of column series.
 */
typedef NS_ENUM(NSUInteger, NChartColumnAnimationType)
{
    /**
     * Animate all series simultaneously.
     */
    NChartColumnAnimationTypeSimultaneously,
    
    /**
     * Animate series one by one.
     */
    NChartColumnAnimationTypeOneByOne
};

/**
 * The NChartLineAnimationType enum provides constants to control transition animation of line series.
 */
typedef NS_ENUM(NSUInteger, NChartLineAnimationType)
{
    /**
     * Make lines grow upwards.
     */
    NChartLineAnimationTypeGrowUp,
    
    /**
     * Make lines grow from the left to the right.
     */
    NChartLineAnimationTypeGrowRight
};

/**
 * The NChartCrosshairTooltipPosition enum provides constants to control position of crosshair's tooltips.
 */
typedef NS_ENUM(NSUInteger, NChartCrosshairTooltipPosition)
{
    /**
     * Tooltip near the minimum of the corresponding axis.
     */
    NChartCrosshairTooltipPositionByMin,
    
    /**
     * Tooltip near the maximum of the corresponding axis.
     */
    NChartCrosshairTooltipPositionByMax
};

/**
 * The NChartCalloutLineToLabelConnectionPos enum provides constants to determine the position where the line connects
 * to the label in the callout.
 */
typedef NS_ENUM(NSUInteger, NChartCalloutLineToLabelConnectionPos)
{
    /**
     * Detect the position automatically.
     */
    NChartCalloutLineToLabelConnectionPosAutodetect,
    
    /**
     * Connect in the bottom left corner.
     */
    NChartCalloutLineToLabelConnectionPosBottomLeft,
    
    /**
     * Connect in the center of the bottom edge.
     */
    NChartCalloutLineToLabelConnectionPosBottomCenter,
    
    /**
     * Connect in the bottom right corner.
     */
    NChartCalloutLineToLabelConnectionPosBottomRight,
    
    /**
     * Connect in the center of the left edge.
     */
    NChartCalloutLineToLabelConnectionPosCenterLeft,
    
    /**
     * Connect in the center of the right edge.
     */
    NChartCalloutLineToLabelConnectionPosCenterRight,
    
    /**
     * Connect in the top left corner.
     */
    NChartCalloutLineToLabelConnectionPosTopLeft,
    
    /**
     * Connect in the center of the top edge.
     */
    NChartCalloutLineToLabelConnectionPosTopCenter,
    
    /**
     * Connect in the top right corner.
     */
    NChartCalloutLineToLabelConnectionPosTopRight
};

/**
 * The NChartCalloutLineType enum provides constants to determine the appearance of the callout line.
 */
typedef NS_ENUM(NSUInteger, NChartCalloutLineType)
{
    /**
     * Straight line.
     */
    NChartCalloutLineTypeStraight,
    
    /**
     * Broken line.
     */
    NChartCalloutLineTypeBroken
};

/**
 * The NChartTooltipArrowOrientation enum provides constants to control direction of tooltip's arrow.
 */
typedef NS_ENUM(NSUInteger, NChartTooltipArrowOrientation)
{
    /**
     * No arrow.
     */
    NChartTooltipArrowOrientationNone,
    
    /**
     * Direct arrow to the left.
     */
    NChartTooltipArrowOrientationLeft,
    
    /**
     * Direct arrow to the right.
     */
    NChartTooltipArrowOrientationRight,
    
    /**
     * Direct arrow to the bottom.
     */
    NChartTooltipArrowOrientationBottom,
    
    /**
     * Direct arrow to the top.
     */
    NChartTooltipArrowOrientationTop
};

/**
 * The NChartAutoZoomAxes enum provides constants to determine which axes should be zoomed automatically.
 */
typedef NS_ENUM(NSUInteger, NChartAutoZoomAxes)
{
    /**
     * Zoom normal axis.
     */
    NChartAutoZoomNormalAxis,
    
    /**
     * Zoom secondary axis.
     */
    NChartAutoZoomSecondaryAxis,
    
    /**
     * Zoom both normal and secondary axes.
     */
    NChartAutoZoomBothAxes
};

/**
 * The NChartAxisPositionCoordValue enum provides constants to determine which value should be used to calculate the
 * position coordinate of the particular axis.
 */
typedef NS_ENUM(NSUInteger, NChartAxisPositionCoordValue)
{
    /**
     * The value is set by user.
     */
    NChartAxisPositionCoordValueCustom,
    
    /**
     * Minimal value of the axis is obtained.
     */
    NChartAxisPositionCoordValueMinimum,
    
    /**
     * Maximal value of the axis is obtained.
     */
    NChartAxisPositionCoordValueMaximum
};
