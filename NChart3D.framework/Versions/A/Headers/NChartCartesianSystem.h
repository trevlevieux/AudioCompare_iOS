/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartCartesianSystem.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartCoordSystem.h"
#import "NChartValueAxis.h"
#import "NChartAxesPlane.h"
#import "NChartAxisGrid.h"
#import "NChartCrosshair.h"


/**
 * The NChartCartesianSystem class provides methods for managing the chart's cartesian coordinate system.
 */
@interface NChartCartesianSystem : NChartCoordSystem

/**
 * X-axis of the cartesian coordinate system.
 * @see NChartValueAxis.
 */
@property (nonatomic, readonly) NChartValueAxis *xAxis;

/**
 * Secondary X-axis of the cartesian coordinate system.
 * @see NChartValueAxis.
 */
@property (nonatomic, readonly) NChartValueAxis *sxAxis;

/**
 * Y-axis of the cartesian coordinate system.
 * @see NChartValueAxis.
 */
@property (nonatomic, readonly) NChartValueAxis *yAxis;

/**
 * Secondary Y-axis of the cartesian coordinate system.
 * @see NChartValueAxis.
 */
@property (nonatomic, readonly) NChartValueAxis *syAxis;

/**
 * Z-axis of the cartesian coordinate system.
 * @see NChartValueAxis.
 */
@property (nonatomic, readonly) NChartValueAxis *zAxis;

/**
 * Secondary Z-axis of the cartesian coordinate system.
 * @see NChartValueAxis.
 */
@property (nonatomic, readonly) NChartValueAxis *szAxis;

/**
 * XY-axes plane of the cartesian coordinate system.
 * @see NChartAxesPlane.
 */
@property (nonatomic, readonly) NChartAxesPlane *xyPlane;

/**
 * XZ-axes plane of the cartesian coordinate system.
 * @see NChartAxesPlane.
 */
@property (nonatomic, readonly) NChartAxesPlane *xzPlane;

/**
 * YZ-axes plane of the cartesian coordinate system.
 * @see NChartAxesPlane.
 */
@property (nonatomic, readonly) NChartAxesPlane *yzPlane;

/**
 * Grid that goes from the X-axis along the Y-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *xAlongY;

/**
 * Grid that goes from the X-axis along the Z-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *xAlongZ;

/**
 * Grid that goes from secondary the X-axis along the Y-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *sxAlongY;

/**
 * Grid that goes from secondary the X-axis along the Z-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *sxAlongZ;

/**
 * Grid that goes from the Y-axis along the X-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *yAlongX;

/**
 * Grid that goes from the Y-axis along the Z-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *yAlongZ;

/**
 * Grid that goes from secondary the Y-axis along the X-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *syAlongX;

/**
 * Grid that goes from secondary the Y-axis along the Z-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *syAlongZ;

/**
 * Grid that goes from the Z-axis along the X-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *zAlongX;

/**
 * Grid that goes from the Z-axis along the Y-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *zAlongY;

/**
 * Grid that goes from secondary the Z-axis along the X-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *szAlongX;

/**
 * Grid that goes from secondary the Z-axis along the Y-axis.
 * @see NChartAxisGrid.
 */
@property (nonatomic, readonly) NChartAxisGrid *szAlongY;

/**
 * Type of axes. You may use additional and percent axes only if you provide ticks for category axes. For example, if
 * you are about to display additional columns, you should provide ticks for the X and Z axes. If you are about to
 * display additional bars, you should provide ticks for Y and Z axes respectively (because bars are stretched along
 * the X-axis).
 * If you didn't provide ticks for category axes, changing the type to additional or percent takes no effect for the
 * series displayed even though states of their points are aligned to the grid (see <NChartPointState> for details).
 * @see NChartValueAxesType.
 */
@property (nonatomic, assign) NChartValueAxesType valueAxesType;

/**
 * Flag that determines if the border around the cartesian coordinate system is visible (YES) or not (NO).
 */
@property (nonatomic, assign) BOOL borderVisible;

/**
 * Color of the border around the cartesian coordinate system.
 */
@property (nonatomic, retain) UIColor *borderColor;

/**
 * Thickness of the border around the cartesian coordinate system.
 */
@property (nonatomic, assign) float borderThickness;

/**
 * Add crosshair to the cartesian system.
 *
 * @param crosshair - crosshair to add.
 * @see NChartCrosshair.
 */
- (void)addCrosshair:(NChartCrosshair *)crosshair;

/**
 * Remove crosshair from the cartesian system.
 *
 * @param crosshair - crosshair to remove.
 * @see NChartCrosshair.
 */
- (void)removeCrosshair:(NChartCrosshair *)crosshair;

/**
 * Remove all crosshairs from the cartesian system.
 */
- (void)removeAllCrosshairs;

/**
 * Force crosshairs to be updated.
 * <br> Use this method if you changed values of crosshairs and want to apply them without calling
 * <code>updateData</code> of the chart. If crosshairs are the only changed chart items, this is much more efficient way
 * to make the changes visible than updating entire chart.
 */
- (void)updateCrosshairs;

/**
 * Flag determining if auto zoom mode is on (YES), or off (NO). The default value is NO.
 * <br> In auto zoom mode, the axis set to be auto-zoomed by the <autoZoomAxes> property is zoomed
 * automatically so that the visible part of the chart is fit to the plot area.
 * @note This property takes effect in 2D mode only.
 */
@property (nonatomic, assign) BOOL shouldAutoZoom;

/**
 * The axes kind (normal, secondary or both) to be auto-zoomed. The default value is <code>NChartAutoZoomNormalAxis</code>.
 * <br> The axes set to be auto-zoomed are zoomed by panning so that the visible part of the chart is fit to the
 * plot area, if <shouldAutoZoom> is YES. If axes are not swapped (you are not using bar series), the axes to zoom are
 * Y and SY. In other case, they are X and SX.
 * @note This property takes effect in 2D mode only.
 * @note It is strongly recommended to disable the user interactions related to the direction of the axes which should be
 * zoomed automatically. For example, if you set <code>autoZoomAxes</code> to <code>NChartAutoZoomNormalAxis</code>,
 * and the axis are not swapped (you are not using bar series, so the axes to zoom are Y and SY), you are recommended
 * to disable proportional zoom, vertical zoom and vertical pan:
 * <code>m_view.chart.userInteractions = (m_view.chart.userInteractionMode) ^ (NChartUserInteractionProportionalZoom | NChartUserInteractionVerticalZoom | NChartUserInteractionVerticalMove);</code>,
 * as well as to set the <code>zoomMode</code> to directional:
 * <code>m_view.chart.zoomMode = NChartZoomModeDirectional;</code>
 * @see NChartAutoZoomAxes.
 */
@property (nonatomic, assign) NChartAutoZoomAxes autoZoomAxes;

@end
