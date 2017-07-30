/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChart.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartBrush.h"
#import "NChartSeries.h"
#import "NChartPoint.h"
#import "NChartCartesianSystem.h"
#import "NChartPolarSystem.h"
#import "NChartSizeAxis.h"
#import "NChartTimeAxis.h"
#import "NChartScaleLegend.h"
#import "NChartCaption.h"
#import "NChartAutoScrollLabel.h"
#import "NChartInterpolator.h"


@class NChart;

/**
 * The NChartDelegate protocol provides methods to reflect changes which have appeared in the chart.
 */
@protocol NChartDelegate <NSObject>

@optional

/**
 * Report that the time index on time axis was changed. A change may appear if the user moves the handler on the time
 * axis, plays back the time axis or if someone changed the current time index of time axis (see <NChartTimeAxis> for
 * details).
 *
 * @param chart - pointer to the chart instance.
 * @param timeIndex - new time index.
 */
- (void)chartDelegateTimeIndexOfChart:(NChart *)chart changedTo:(double)timeIndex;

/**
 * Report that user selected a chart point.
 *
 * @param chart - pointer to the chart instance.
 * @param point - point that was selected. May be nil, which will tell that the user tapped an empty space of the chart.
 * @see NChartPoint.
 */
- (void)chartDelegatePointOfChart:(NChart *)chart selected:(NChartPoint *)point;

/**
 * Report that animation of chart object is done.
 *
 * @param chart - pointer to the chart instance.
 * @param object - pointer to the chart object instance.
 * @param animation - type of animation that is done.
 * @see NChartAnimationType
 */
- (void)chartDelegateChart:(NChart *)chart object:(id)object didEndAnimating:(NChartAnimationType)animation;

/**
 * Report that zoom of the chart has changed its phase.
 *
 * @param chart - pointer to the chart instance.
 * @param phase - phase of the zoom.
 * @see NChartEventPhase.
 */
- (void)chartDelegateChart:(NChart *)chart didChangeZoomEventPhase:(NChartEventPhase)phase;

@end

/**
 * The NChart class provides a container for the chart.
 */
@interface NChart : NSObject

/**
 * Array of series.
 */
@property (nonatomic, readonly) NSArray *series;

/**
 * Add series to chart.
 *
 * @param series - series to add.
 * @see NChartSeries.
 */
- (void)addSeries:(NChartSeries *)series;

/**
 * Remove series from chart.
 *
 * @param series - series to remove.
 * @see NChartSeries.
 */
- (void)removeSeries:(NChartSeries *)series;

/**
 * Remove all series from chart.
 */
- (void)removeAllSeries;

/**
 * Add global settings for the series. If you previously set some settings, they will be overwritten by new ones.
 *
 * @param settings - settings for the series.
 * @see NChartSeriesSettings.
 */
- (void)addSeriesSettings:(NChartSeriesSettings *)settings;

/**
 * Remove all the global settings for the series by given class.
 *
 * @param settingsClass - class of the series settings to remove.
 */
- (void)removeSeriesSettings:(Class)settingsClass;

/**
 * Remove all the global settings for the series.
 */
- (void)removeAllSeriesSettings;

/**
 * Get settings of given settings class. If there were no settings set, default settings container for the given
 * type is returned.
 *
 * @param settingsClass - class of the series settings to search for.
 * @return settings of the given class.
 * @see NChartSeriesSettings.
 */
- (NChartSeriesSettings *)seriesSettings:(Class)settingsClass;

/**
 * Force chart to be updated. Call this method when you want to reload data from the data source and rebuild the chart.
 * Data are processed by this call and minimums / maximums on axes are calculated.
 */
- (void)updateData;

/**
 * Force chart to extend the points arrays of series. Only newly added data are processed by this call.
 * Minimums and maximums may change.
 * <br> Call this method always you want to extend the data array without changing old data. This method causes
 * series to query new portion of data through <code>- (NSArray *)seriesDataSourceExtraPointsForSeries:(NChartSeries *)series;</code>
 * call of their data sources. But you cannot extend the array of points forever, so there is a property
 * <pointsHistoryLength> that determines the length of history.
 * @note The difference with <updateData> is that only newly added points are processed and the array of these points is
 * queried through <code>- (NSArray *)seriesDataSourceExtraPointsForSeries:(NChartSeries *)series;</code> call of
 * <code>NChartSeriesDataSource</code>. This can save you time by updating large data sets.
 * @see NChartSeriesDataSource.
 */
- (void)extendData;

/**
 * Property that determines the maximal length of series' points array. The default value is 1000.
 * <br> The array of points in series is determined after <updateData> call (by querying points from series'
 * data sources) and then can be extended after <extendData> call. The property <code>pointsHistoryLength</code>
 * takes effect by using <extendData> only. The new points are added to the end of the points' array of the
 * series and if the array exceeds the given length, first n points are deleted, where
 * <code>n = array.length - pointsHistoryLength</code>.
 */
@property (nonatomic, assign) NSUInteger pointsHistoryLength;

/**
 * Force series to rebuild by reloading data from data source. Call this method when you know that the chart layout
 * (including layout of axes, so min and max values) has not changed, but the data in series have. This method invokes
 * <updateSeries> automatically. Data are not processed by this call, so values on axes remain unchanged. Use this method
 * if you are absolutely sure minimums and maximums have not changed!
 */
- (void)rebuildSeries;

/**
 * Force series to be updated without reloading data from data source. Call this method when you want to reflect
 * some changes you made in the visual appearance of a series (brush, etc.). A call of <rebuildSeries> invokes
 * <code>updateSeries</code> automatically.
 */
- (void)updateSeries;

/**
 * Flag determining if streaming mode is enabled. The default value is NO.
 * @note If streaming mode is set to YES, pointSelectionEnabled is automatically set to NO to boost the performance of data updating.
 * @see streamData.
 * @see pointSelectionEnabled
 */
@property (nonatomic, assign) BOOL streamingMode;

/**
 * Stream the data. This causes the updating of chart to display new states of points. The data are going to be
 * processed, so minimum and maximum on the axes may change. Use this method in the following use-case: if your set
 * of points was not changed, but the values in the states of points do, you can update the chart through this method
 * much faster than through regular <updateData>.
 * @note The difference with <rebuildSeries> is that <code>streamData</code> _does not_ reload data from data source,
 * but _does_ the optimized data processing (it's faster than regular data processing). Series will use the points they
 * already have (the points are mutable, so you can change their data anywhere you want).
 * @note The difference with <updateSeries> is that <code>streamData</code> is even faster and _does_ the optimized data
 * processing. So use it to reflect some realtime "streaming" changes of data.
 * @note This method requires <streamingMode> to be on, use <code>streamingMode = YES</code> for this.
 * @note The first appearance of series should be initialized by the <updateData> call. <code>streamData</code> is to
 * change the already displayed series only.
 * @note If you want to change the data in separate thread, you should wrap all the data changing routines in the
 * <beginTransaction> and <endTransaction> calls.
 */
- (void)streamData;

/**
 * Incremental minimum and maximum calculation mode. This mode makes sense in streaming mode only. If the incremental
 * mode is on, new minimum cannot be greater and new maximum cannot be less than the ones calculated on the previous
 * datasets. The default value is NO.
 */
@property (nonatomic, assign) BOOL incrementalMinMaxMode;

/**
 * Synchronize all the changes with visual appearance. You may call this method after all your data is updated (it means
 * after you called <updateData> and <code>playTransition:reverse:</code> because <code>playTransition:reverse:</code>
 * only says that transition should start playing and does not wait till it plays completely) to ensure that the visual
 * appearance will be updated as soon as possible.
 * You may call this method on the big dataset to reduce lag between your <updateData> call and actual updating.
 * Alternatively, you may call
 * <code>[[NSRunLoop currentRunLoop] runUntilDate:[NSDate dateWithTimeIntervalSinceNow:0.1]];</code>
 * but this will affect your runloop, while <code>flushChanges</code> will not.
 */
- (void)flushChanges;

/**
 * Force chart to relayout. Call this method if you made some changes but do not want to update data. A call of
 * <updateData> invokes relayout automatically.
 */
- (void)relayout;

/**
 * Change position so that the chart is aligned to the center of the screen. This method takes effect in 3D mode only.
 *
 * @param duration - duration of the animation in seconds.
 */
- (void)alignCenter:(float)duration;

/**
 * Change zoom and position so that the chart fits the screen (with current rotation, if in 3D).
 *
 * @param duration - duration of the animation in seconds.
 */
- (void)fitToScreen:(float)duration;

/**
 * Zoom of the chart. The default zoom is 1 which corresponds to the fitting the chart to screen (both in 2D and 3D).
 * The zooming is proportional. If you want non-proportional zoom in 2D mode, you should use
 * <code>zoomToRegionFrom</code> method of <NChartValueAxis>.
 * @note If you want to alter the initial zoom, you should change the value of this property <b>after</b>
 * <code>updateData</code> call.
 */
@property (nonatomic, assign) float zoom;

/**
 * Set zoom for the chart with animation. The zooming is proportional. If you want non-proportional zoom in 2D mode,
 * you should use <code>zoomToRegionFrom</code> method of <NChartValueAxis>.
 * @note If you want to alter the initial zoom, you should change the value of this property <b>after</b>
 * <code>updateData</code> call.
 *
 * @param zoom - new zoom of the chart.
 * @param duration - duration of animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)zoomTo:(float)zoom duration:(float)duration delay:(float)delay;

/**
 * Minimal zoom of the chart. After this zoom is reached by user interactions, chart starts bouncing zoom.
 * The minimal zoom differs in 2D and 3D mode. In 3D mode the default value is 0.5. In 2D it is 1.
 */
@property (nonatomic, assign) float minZoom;

/**
 * Maximal zoom of the chart. After this zoom is reached by user interactions, chart starts bouncing zoom.
 * The maximal zoom differs in 2D and 3D mode. In 2D mode the default value is recalculated each time the chart is
 * laid out (by changing of the frame or by updating data) according to the data on the axes in case
 * <shouldCalculate2DZoomBoundsAutomatically> flag is set to YES. In 3D the default value is 2.
 */
@property (nonatomic, assign) float maxZoom;

/**
 * Flag determining if zoom in 2D mode should be calculated automatically (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL shouldCalculate2DZoomBoundsAutomatically;

/**
 * Pivot of the chart in the internal chart scene coordinates.
 * <br> Use this property if you want to save and than restore position of the chart. This property works for 2D
 * and 3D modes. Theoretically you can use this property to pan the chart programmatically, however it is better to use
 * <code>zoomToRegionFrom</code> method of <NChartValueAxis>.
 */
@property (nonatomic, assign) CGPoint pivot;

/**
 * Rotate chart around the Y-Axis (vertical axis) with animation (has effect in 3D mode only).
 *
 * @param angle - angle around the Y-Axis in radians.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)rotateAroundYToAngle:(float)angle duration:(float)duration delay:(float)delay;

/**
 * Rotate chart around the Y-Axis (vertical axis) with animation (has effect in 3D mode only).
 *
 * @param angle - angle around the Y-Axis in radians.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 * @param interpolator - interpolator that controls the angle changing over the time.
 *
 * @see NChartInterpolator.
 */
- (void)rotateAroundYToAngle:(float)angle duration:(float)duration delay:(float)delay interpolator:(NChartInterpolator *)interpolator;

/**
 * Rotation angle around the Y-Axis (vertical axis) in radians (has effect in 3D mode only).
 * The default value is 3.93 (225 degrees).
 */
@property (nonatomic, assign) float yAngle;

/**
 * Initial rotation angle around the Y-Axis (vertical axis) in radians (has effect in 3D mode only).
 * The default value is 3.93 (225 degrees).
 * <br> This is the angle the chart is rotated back to if you call <code>resetTransformations:</code> method.
 */
@property (nonatomic, assign) float initialYAngle;

/**
 * Flag determining if permanent rotation around Y-Axis is on (YES), or off (NO). The default value is NO.
 * Use this flag if you want the chart to rotate around Y-Axis without any interactions. This property takes effect in
 * 3D mode only.
 */
@property (nonatomic, assign) BOOL permanentRotationY;

/**
 * Speed of permanent rotation around Y-Axis (in radians per second). The default value is 0.
 * See <permanentRotationY> for more info about permanent rotation.
 */
@property (nonatomic, assign) float permanentRotationYSpeed;

/**
 * Rotate chart around the X-Axis (horizontal axis) with animation (has effect in 3D mode only).
 *
 * @param angle - angle around the X-Axis in radians.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)rotateAroundXToAngle:(float)angle duration:(float)duration delay:(float)delay;

/**
 * Rotate chart around the X-Axis (horizontal axis) with animation (has effect in 3D mode only).
 *
 * @param angle - angle around the X-Axis in radians.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 * @param interpolator - interpolator that controls the angle changing over the time.
 *
 * @see NChartInterpolator.
 */
- (void)rotateAroundXToAngle:(float)angle duration:(float)duration delay:(float)delay interpolator:(NChartInterpolator *)interpolator;

/**
 * Rotation angle around the X-Axis (horizontal axis) in radians (has effect in 3D mode only).
 * The default value is -0.87 (-50 degrees).
 */
@property (nonatomic, assign) float xAngle;

/**
 * Initial rotation angle around the X-Axis (horizontal axis) in radians (has effect in 3D mode only).
 * The default value is -0.87 (-50 degrees).
 * <br> This is the angle the chart is rotated back to if you call <code>resetTransformations:</code> method.
 */
@property (nonatomic, assign) float initialXAngle;

/**
 * Flag determining if permanent rotation around X-Axis is on (YES), or off (NO). The default value is NO.
 * Use this flag if you want the chart to rotate around X-Axis without any interactions. This property takes effect in
 * 3D mode only.
 */
@property (nonatomic, assign) BOOL permanentRotationX;

/**
 * Speed of permanent rotation around X-Axis (in radians per second). The default value is 0.
 * See <permanentRotationX> for more info about permanent rotation.
 */
@property (nonatomic, assign) float permanentRotationXSpeed;

/**
 * Rotate polar coordinate system with animation (has effect in 2D mode only).
 *
 * @param angle - angle of the polar coordinate system in radians.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)rotatePolarToAngle:(float)angle duration:(float)duration delay:(float)delay;

/**
 * Rotate polar coordinate system with animation (has effect in 2D mode only).
 *
 * @param angle - angle of the polar coordinate system in radians.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 * @param interpolator - interpolator that controls the angle changing over the time.
 */
- (void)rotatePolarToAngle:(float)angle duration:(float)duration delay:(float)delay interpolator:(NChartInterpolator *)interpolator;

/**
 * Rotation angle of the polar coordinate system in radians (has effect in 2D mode only).
 * The default value is 0 (0 degrees).
 */
@property (nonatomic, assign) float polarAngle;

/**
 * Initial rotation angle of the polar coordinate system in radians (has effect in 2D mode only).
 * The default value is 0 (0 degrees).
 * <br> This is the angle the chart is rotated back to if you call <code>resetTransformations:</code> method.
 */
@property (nonatomic, assign) float initialPolarAngle;

/**
 * Brush that fills the chart's background.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *background;

/**
 * Flag that determines if a chart should be drawn in 3D (YES) or in 2D (NO). The default value is NO.
 */
@property (nonatomic, assign) BOOL drawIn3D;

/**
 * Flag that determines if a chart use parallel projection (YES) or perspective projection (NO) in 3D-mode. The default
 * value is NO.
 * @note This flag takes effect in 3D-mode only.
 */
@property (nonatomic, assign) BOOL useParallelProjection;

/**
 * Cartesian coordinates system used to store value axes and supplementary visual items.
 * @see NChartCartesianSystem.
 */
@property (nonatomic, readonly) NChartCartesianSystem *cartesianSystem;

/**
 * Polar coordinates system used to store value axes and supplementary visual items.
 * @see NChartPolarSystem.
 */
@property (nonatomic, readonly) NChartPolarSystem *polarSystem;

/**
 * Size axis used to scale the sizes of markers.
 * @see NChartSizeAxis.
 */
@property (nonatomic, readonly) NChartSizeAxis *sizeAxis;

/**
 * Time axis used to navigate through the time ticks.
 * @see NChartTimeAxis.
 */
@property (nonatomic, readonly) NChartTimeAxis *timeAxis;

/**
 * Flag determining if the chart points can be selected by tap (YES) or not (NO). The default value is YES. If you do
 * not want to select points by tap, it is better to disable selection, because it will save memory and boost the data
 * updating.
 */
@property (nonatomic, assign) BOOL pointSelectionEnabled;

/**
 * Reset all transformations to initial values.
 *
 * @param duration - duration of animation from current transformations to the beginning.
 */
- (void)resetTransformations:(float)duration;

/**
 * Play animated transition from old state to new one. The old state is cached automatically, so the only thing you need
 * to do for animation is to change the series (by calling <addSeries:> / <removeSeries:> / <removeAllSeries>) or data in
 * the series (by updating data source and calling <updateData>) and than call <code>playTransition:reverse:</code>.
 * State is cached when <updateData> is called.
 *
 * @param duration - duration of transition's animation in seconds.
 * @param reverse - flag determining if animation should be played in reverse.
 */
- (void)playTransition:(float)duration reverse:(BOOL)reverse;

/**
 * Reset transition by cleaning up the cache made from the previous <updateData> call. Call this method if you want to
 * see animation from the default start positions as if you just started the app.
 */
- (void)resetTransition;

/**
 * Check if transition is playing.
 *
 * @return YES if playing, NO if not.
 */
- (BOOL)isTransitionPlaying;

/**
 * Stop transition. This will stop all the transition animations, even if they are not played till the end or if they
 * where delayed and did not even start animating.
 */
- (void)stopTransition;

/**
 * Legend of the chart.
 * @see NChartLegend.
 */
@property (nonatomic, readonly) NChartLegend *legend;

/**
 * Scale legends array. It's empty by default.
 * @see NChartScaleLegend.
 */
@property (nonatomic, readonly) NSArray *scaleLegends;

/**
 * Add scale legend.
 * @param scaleLegend - scale legend to add.
 * @see NChartScaleLegend.
 */
- (void)addScaleLegend:(NChartScaleLegend *)scaleLegend;

/**
 * Remove scale legend.
 * @param scaleLegend - scale legend to remove.
 * @see NChartScaleLegend.
 */
- (void)removeScaleLegend:(NChartScaleLegend *)scaleLegend;

/**
 * Remove all scale legends.
 * @see NChartScaleLegend.
 */
- (void)removeAllScaleLegends;

/**
 * Caption of the chart.
 * @see NChartCaption.
 */
@property (nonatomic, readonly) NChartCaption *caption;

/**
 * Margin of the chart that determines how far the content of chart starts from view's bounds. The default margin is
 * zero on all sides.
 */
@property (nonatomic, assign) NChartMargin margin;

/**
 * Flag that determines if FPS rate should be displayed (YES) or not (NO). You may use this for debug purposes
 * or if you are just curious, but it's a very bad idea to show FPS in production code, because it results in continuous
 * rendering that loads CPU and consumes power. If FPS is off, the picture is re-rendered only if it's really needed.
 * The default value is NO.
 */
@property (nonatomic, assign) BOOL showFPS;

/**
 * Flag that determines if the image should be anti-aliased (YES) or not (NO). Antialiasing makes the picture smoother,
 * but impacts performance. The default value is NO.
 */
@property (nonatomic, assign) BOOL shouldAntialias;

/**
 * Flag that determines if anti-aliasing is adaptive (YES) or not (NO). Adaptivity means that it is switched off
 * automatically for the time-critical periods like user interactions or animation playing. This property takes effect
 * if <shouldAntialias> is YES only. The default value is YES.
 */
@property (nonatomic, assign) BOOL adaptiveAntialiasing;

/**
 * Zoom mode used in chart. The default is <code>NChartZoomModeProportional</code>.
 * @see NChartZoomMode.
 */
@property (nonatomic, assign) NChartZoomMode zoomMode;

/**
 * Flag that determines if chart is zoomed to the cursor (YES) or to the screen center (NO). The default value is NO.
 */
@property (nonatomic, assign) BOOL zoomToPointMode;

/**
 * Flag that determines if zoom should bounce (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL shouldBounceZoom;

/**
 * Flag that determines if pan should bounce (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL shouldBouncePan;

/**
 * Interaction mode used in the chart. The default is <code>NChartUserInteractionAll</code>.
 * @note You can use multiple interactions concatenated with bitwise OR to specify the mask of what is available.
 * @see NChartUserInteraction
 */
@property (nonatomic, assign) NSUInteger userInteractionMode;

/**
 * Shading model that is used in 3D mode. The default value is NChartShadingModelPhong.
 * @note This property controls shading for the 3D charts like surfaces, columns, etc.
 * Shading model for point markers is controlled through their brushes.
 * @note This property takes effect in 3D mode only.
 * @see drawIn3D
 * @see NChartMarker
 * @see NChartShadingModel
 */
@property (nonatomic, assign) NChartShadingModel shadingModel;

/**
 * Flag determining if chart content always preserves zoom and position (YES) or not (NO). This flag takes effect in 3D
 * mode only. If this flag is set to NO, when you change the frame of the chart, 3D content will be zoomed and shifted
 * to fit the screen. If this flag is set to YES, you should call <resetTransformations:> to fit the content in the
 * screen manually. The default value is NO.
 * <br> The common use-case for this flag is when you smoothly change the size of the chart. For such resize
 * session you should set this flag to YES, and after the session you should probably call <resetTransformations:>.
 */
@property (nonatomic, assign) BOOL alwaysPreserveZoomAndPosition;

/**
 * Begin data changing transaction. You should call this method before any changes of chart settings/data in separate
 * thread. After the changes are made, you should call <code>endTransaction</code>. The typical use-case of
 * multithreading in NChart3D is the streaming - the realtime data updating.
 * @note there is no sense to call this method in main thread.
 * @see streamingMode.
 */
- (void)beginTransaction;

/**
 * End data changing transaction.
 * @see beginTransaction.
 */
- (void)endTransaction;

/**
 * Flag determining if all zoom should be converted to the allowed zoom modes (YES) or not (NO). The  default value is YES.
 * <br> If this flag is YES, all the zoom directions are converted to the allowed zoom directions. For example,
 * if only horizontal zoom is allowed, and user zooms in diagonal direction, chart is zoomed horizontally with this flag
 * set to YES.
 */
@property (nonatomic, assign) BOOL shouldConvertZoomToAllowed;

/**
 * Flag determining if chart should automatically scroll (YES) or not (NO) to the end if new data are added by the
 * <extendData> call. The default value is NO.
 * <br> This flag takes effect in 2D mode only.
 * @see extendData.
 * @see shouldToggleAutoScrollByPan.
 */
@property (nonatomic, assign) BOOL shouldAutoScroll;

/**
 * Duration of auto scroll in seconds. The default value is 0.25.
 * @see extendData.
 * @see shouldAutoScroll.
 */
@property (nonatomic, assign) float autoScrollDuration;

/**
 * Flag determining if automatical scroll should be automatically toggled by pan (YES) or not (NO). The default value is NO.
 * <br> If this flag is YES, automatical scroll is switched on (<shouldAutoScroll> is set to YES) if user pans
 * to the right-most position of the chart and switched off (<shouldAutoScroll> is set to NO) if user pans left.
 * This flag takes effect in 2D mode only.
 * @see shouldAutoScroll.
 * @see extendData.
 */
@property (nonatomic, assign) BOOL shouldToggleAutoScrollByPan;

/**
 * Label that indicates whenever automatical scroll is switched on or off. The default value is nil.
 * <br> This label takes effect in 2D mode only.
 * @see shouldToggleAutoScrollByPan.
 * @see shouldAutoScroll.
 */
@property (nonatomic, retain) NChartAutoScrollLabel *autoScrollLabel;

/**
 * License key of product.
 */
@property (nonatomic, retain) NSString *licenseKey;

/**
 * Get version info.
 */
@property (nonatomic, readonly) NSString *versionInfo;

/**
 * Chart delegate.
 * @see NChartDelegate.
 */
@property (nonatomic, assign) id<NChartDelegate> delegate;

@end
