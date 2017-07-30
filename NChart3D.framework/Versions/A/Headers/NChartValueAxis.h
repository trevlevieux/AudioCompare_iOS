/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartValueAxis.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartAxis.h"
#import "NChartAxisTick.h"
#import "NChartLabel.h"
#import "NChartValueAxisMark.h"
#import "NChartLineDash.h"
#import "NChartAxisPositionCoord.h"


@class NChartValueAxis;

/**
 * The NChartValueAxisDataSource protocol provides methods to control data displayed on value axis.
 */
@protocol NChartValueAxisDataSource <NSObject>

@optional

/**
 * Get the name that is displayed in the axis' caption.
 *
 * @param axis - axis to get the name for.
 * @return the name of the axis.
 * @see NChartValueAxis.
 */
- (NSString *)valueAxisDataSourceNameForAxis:(NChartValueAxis *)axis;

/**
 * Get the minimal value for the axis. If there is no implementation, the axis is assumed to be discrete and you should
 * provide an array of ticks. If neither min and max nor an array of ticks are provided, the axis is assumed to be
 * continuous and both min and max are calculated automatically based on the values for the series.
 *
 * @param axis - axis to get minimal value for.
 * @return the minimal value for the axis. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSNumber *)valueAxisDataSourceMinForValueAxis:(NChartValueAxis *)axis;

/**
 * Get the maximal value for the axis. If there is no implementation, the axis is assumed to be discrete and you should
 * provide an array of ticks. If neither min and max nor an array of ticks are provided, the axis is assumed to be
 * continuous and both min and max are calculated automatically based on the values for the series.
 *
 * @param axis - axis to get the maximal value for.
 * @return the maximal value for the axis. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSNumber *)valueAxisDataSourceMaxForValueAxis:(NChartValueAxis *)axis;

/**
 * Get step value for axis. If there is no implementation, the step, min and max values are beautified.
 *
 * @param axis - axis to get the step value for.
 * @return the step value for the axis. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSNumber *)valueAxisDataSourceStepForValueAxis:(NChartValueAxis *)axis;

/**
 * Get array of ticks for the discrete axis. You should provide it if min and max are not implemented. If they are
 * implemented, the array of ticks is ignored. If neither min and max nor the array of ticks are provided, axis is
 * assumed to be continuous and both min and max are calculated automatically based on the values for the series.
 *
 * @param axis - axis to get an array of ticks for.
 * @return an array of strings that represent the ticks. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSArray *)valueAxisDataSourceTicksForValueAxis:(NChartValueAxis *)axis;

/**
 * Get array of extra ticks for discrete axis.
 * <br> Use this method to provide additional ticks for axis. This method is called after you call
 * <code>extendData</code> of <code>NChart</code>.
 * @note The ticks from the array returned are _added_ to the axis' array of ticks, so axis will have more data.
 * The maximal length of ticks array is determined by <code>pointsHistoryLength</code> property of <code>NChart</code>.
 * @note Due to performance reasons you won't have access to the newly created ticks through the <code>ticks</code>
 * method of the <code>NChartValueAxis</code>.
 * @see NChart.
 *
 * @param axis - axis to obtain the extra ticks for.
 * @return array of extra ticks.
 */
- (NSArray *)valueAxisDataSourceExtraTicksForValueAxis:(NChartValueAxis *)axis;

/**
 * Get length of axis in 3D scene units. If there is no implementation, 1 is used. See length of <NChartValueAxis> for
 * details.
 *
 * @param axis - axis to get the length for.
 * @return the length of the axis. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSNumber *)valueAxisDataSourceLengthForValueAxis:(NChartValueAxis *)axis;

/**
 * Convert double value to string.
 *
 * @param value - value to convert.
 * @param axis - axis to convert value for.
 * @return string representation of the value.
 * @see NChartValueAxis.
 */
- (NSString *)valueAxisDataSourceDouble:(double)value toStringForValueAxis:(NChartValueAxis *)axis;

/**
 * Get the minimal date for the axis. If there is no implementation, both min and max are calculated automatically based
 * on the date from the series.
 * @note This method is called in date mode of the value axis only. See <code>hasDates</code> method of the
 * <code>NChartValueAxis</code> for details.
 *
 * @param axis - axis to get minimal date for.
 * @return the minimal date for the axis. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSDate *)valueAxisDataSourceMinDateForValueAxis:(NChartValueAxis *)axis;

/**
 * Get the maximal date for the axis. If there is no implementation, both min and max are calculated automatically based
 * on the date from the series.
 * @note This method is called in date mode of the value axis only. See <code>hasDates</code> method of the
 * <code>NChartValueAxis</code> for details.
 *
 * @param axis - axis to get maximal date for.
 * @return the maximal date for the axis. It may be nil that is equivalent to the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSDate *)valueAxisDataSourceMaxDateForValueAxis:(NChartValueAxis *)axis;

/**
 * Get date step value for axis. If there is no implementation, the step, min and max values are beautified.
 * @note This method is called in date mode of the value axis only. See <code>hasDates</code> method of the
 * <code>NChartValueAxis</code> for details.
 *
 * @param axis - axis to get the step value for.
 * @return number representing time interval of the date step value for the axis. It may be nil that is equivalent to
 * the absence of implementation.
 * @see NChartValueAxis.
 */
- (NSNumber *)valueAxisDataSourceDateStepForValueAxis:(NChartValueAxis *)axis;

/**
 * Convert date to string.
 *
 * @param date - date to convert.
 * @param tickInterval - time interval between neighbor ticks in seconds.
 * @param axis - axis to convert value for.
 * @return string representation of the date.
 */
- (NSString *)valueAxisDataSourceDate:(NSDate *)date tickInterval:(NSTimeInterval)tickInterval toStringForAxis:(NChartValueAxis *)axis;

@end

/**
 * The NChartValueAxisDelegate protocol provides methods to handle user interactions with value axis.
 */
@protocol NChartValueAxisDelegate <NSObject>

@optional

/**
 * Handle tick label tap.
 *
 * @param axis - axis the tapped tick belongs to.
 * @param text - string representation of the tick (that is shown on the chart).
 * @param value - value of the tapped tick (the actual number behind the string).
 */
- (void)valueAxisDelegateTickTappedWithText:(NSString *)text value:(double)value ofAxis:(NChartValueAxis *)axis;

@end

/**
 * The NChartValueAxis class provides methods to display the value axis of the chart.
 */
@interface NChartValueAxis : NChartAxis

/**
 * Kind of axis.
 * @see NChartValueAxisKind.
 */
@property (nonatomic, readonly) NChartValueAxisKind kind;

/**
 * Minimal value on the axis. It is obtained from the data source and, if needed, processed to look more beautiful.
 */
@property (nonatomic, readonly) double minValue;

/**
 * Maximal value on the axis. It is obtained from the data source and, if needed, processed to look more beautiful.
 */
@property (nonatomic, readonly) double maxValue;

/**
 * Step from one tick to another. It is either obtained from the data source or, if not provided, calculated according
 * to the <minValue> and <maxValue> to look beautiful.
 */
@property (nonatomic, readonly) double step;

/**
 * Minimal date on the axis. It is obtained from the data source and, if needed, processed to look more beautiful.
 * @note This property works in date mode only, if <hasDates> is YES. Otherwise it returns nil.
 */
@property (nonatomic, readonly) NSDate *minDate;

/**
 * Maximal date on the axis. It is obtained from the data source and, if needed, processed to look more beautiful.
 * @note This property works in date mode only, if <hasDates> is YES. Otherwise it returns nil.
 */
@property (nonatomic, readonly) NSDate *maxDate;

/**
 * Time interval from one date tick to another. It is either obtained from the data source or, if not provided,
 * calculated according to the <minDate> and <maxDate> to look beautiful.
 * @note This property works in date mode only, if <hasDates> is YES. Otherwise it returns 0.
 */
@property (nonatomic, readonly) NSTimeInterval dateStep;

/**
 * Array of strings that are displayed as ticks on the axis. It is obtained from the data source or nil if not provided.
 */
@property (nonatomic, readonly) NSArray *ticks;

/**
 * Number of ticks on the axis. It is the number of ticks in an array or the number of values between
 * <minValue> and <maxValue> through <step>.
 */
@property (nonatomic, readonly) NSInteger tickCount;

/**
 * Length of axis in 3D scene units. This value is obtained from the data source or, if not provided, is assigned to 1.
 * It has an effect for axes being displayed in 3D only. In 2D this value is ignored because axes fill the whole area
 * available on the screen. One 3D scene unit is equal to half a screen size by initial zoom (so space of the 3D scene
 * is actually nonlinear respective to the screen). Therefore, by default all axes have equal length and form a kind of
 * cube in 3D that is centered on the screen and is as big as half of the biggest screen's dimension. However, if you
 * want, for example, to make the Z-axis shorter than the others, you can provide a length of 0.5 for it. It will
 * therefore be twice as short as the others.
 */
@property (nonatomic, readonly) double length;

/**
 * Color of the axis line.
 */
@property (nonatomic, retain) UIColor *color;

/**
 * Font for the ticks' labels.
 */
@property (nonatomic, retain) UIFont *font;

/**
 * Color of the text for the ticks' labels.
 */
@property (nonatomic, retain) UIColor *textColor;

/**
 * Flag that determines if there should be an offset on the axis. The offset is the spacing from the beginning of the
 * axis to the first tick and from the last tick to the end of the axis. If this flag is YES, the spacing is half a step.
 * If NO, spacing is zero.
 */
@property (nonatomic, assign) BOOL hasOffset;

/**
 * Minimal spacing between neighbor ticks in pixels (the tick is the center place of the timestamp title, a kind of
 * milestone on the axis). According to this value some timestamps can be hidden, if there are too many of them.
 */
@property (nonatomic, assign) float minTickSpacing;

/**
 * Maximal allowed label length in pixels. If 0, maximal label width is calculated automatically according to the length
 * between neighbor ticks. The default value is 0.
 */
@property (nonatomic, assign) float maxLabelLength;

/**
 * Line break mode for axis labels. The default value is NSLineBreakByWordWrapping.
 */
@property (nonatomic, assign) NSLineBreakMode labelsLineBreakMode;

/**
 * Thickness of the axis' line in pixels.
 */
@property (nonatomic, assign) float thickness;

/**
 * Dash of the axis' line.
 * @see NChartLineDash.
 */
@property (nonatomic, retain) NChartLineDash *lineDash;

/**
 * Major ticks of the axis. Major ticks are spread from the <minValue> to the <maxValue> through <step> or, if no
 * <minValue> and <maxValue> are provided but a ticks array is provided, the whole axis length is divided by the number
 * of ticks and for each tick there is a major tick displayed. Major ticks can be labeled.
 * @see NChartAxisTick.
 */
@property (nonatomic, readonly) NChartAxisTick *majorTicks;

/**
 * Minor ticks of the axis. Minor ticks are displayed in the middle between two neighbor major ticks. See majorTicks
 * for details.
 * @see NChartAxisTick.
 */
@property (nonatomic, readonly) NChartAxisTick *minorTicks;

/**
 * Tiny ticks of the axis. Tiny ticks are displayed between consecutive major ticks. However there is a gap in tiny
 * ticks where tiny ticks potentially overlap with major/minor ticks (even if major/minor ticks are switched off).
 * See majorTicks, minorTicks and tinyTickIntervalsPerInterval for details.
 * @see NChartAxisTick.
 */
@property (nonatomic, readonly) NChartAxisTick *tinyTicks;

/**
 * Number of tiny intervals the interval between two consecutive major ticks is split up into. Tiny intervals are
 * bounded with the tiny ticks. The default value is 0, which means no tiny ticks are displayed.
 * <br> If for example this value is 10, that means each interval between two labels is split up into 10
 * sub-intervals and therefore should have 11 tiny ticks inside.
 * However, only 8 tiny ticks will be visible, and 1th, 6th and 11th ticks will be discarded, because they potentially
 * overlap with major/minor ticks (even if major/minor ticks are switched off).
 */
@property (nonatomic, assign) NSInteger tinyTickIntervalsPerInterval;

/**
 * Caption of the axis.
 * @see NChartLabel.
 */
@property (nonatomic, readonly) NChartLabel *caption;

/**
 * Flag that determines if the labels of ticks are visible (YES) or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL labelsVisible;

/**
 * Flag that determines if the line of the axis is visible (YES) or not (NO). The default value is NO.
 */
@property (nonatomic, assign) BOOL lineVisible;

/**
 * Flag that determines whether zero is always on the axis. This flag makes sense if <minValue> and <maxValue> are both
 * less or greater than zero and are beautified according to the data source. In this case, if this flag is false, it
 * may happen, that no zero will be on the axis (for example, if <minValue> = 11.5 and <maxValue> = 19, the axis will
 * probably start with 10 and end with 20, having 4 steps). With this flag set to true, zero will always be on the axis,
 * so even with <minValue> = 11.5 and <maxValue> = 19 the axis will start with 0 and end with 20 having probably 5 steps
 * or so. The default value is NO.
 */
@property (nonatomic, assign) BOOL alwaysShowZero;

/**
 * Flag that determines whether the axis labels are in "perspective" screen (YES) or are projected in the 2D screen (NO).
 * This flag only affects 3D-charts. The default value is YES.
 */
@property (nonatomic, assign) BOOL labelsIn3D;

/**
 * Flag that determines whether the axis caption is in "perspective" screen (YES) or is projected in the 2D screen (NO).
 * This flag only affects 3D-charts. The default value is YES.
 */
@property (nonatomic, assign) BOOL captionIn3D;

/**
 * Flag that determines whether min and max values on the axis should be beautified in case they are calculated (YES)
 * or not (NO). The default value is YES.
 */
@property (nonatomic, assign) BOOL shouldBeautifyMinAndMax;

/**
 * Axis labels' rotation angle.
 * @see NChart, property drawIn3D.
 * @see labelsIn3D.
 */
@property (nonatomic, assign) float labelsAngle;

/**
 * Alignment of the axis labels relative to the axis ticks. The default value is NChartAxisLabelsAlignmentCenter.
 */
@property (nonatomic, assign) NChartAxisLabelsAlignment labelsAlignment;

/**
 * Data source of the axis.
 * @see NChartValueAxisDataSource.
 */
@property (nonatomic, assign) id<NChartValueAxisDataSource> dataSource;

/**
 * Delegate of the axis.
 * @see NChartValueAxisDelegate.
 */
@property (nonatomic, assign) id<NChartValueAxisDelegate> delegate;

/**
 * Zoom to given region by specifying the least and the greatest values that should be visible on the axis. If the
 * axis has array of ticks, indices in this array can be used. Use this method after you updated data of the chart
 * with <code>[chart updateData]</code> call.
 *
 * @param startValue - least value that should be visible.
 * @param endValue - greatest value that should be visible.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)zoomToRegionFrom:(float)startValue to:(float)endValue duration:(float)duration delay:(float)delay;

/**
 * Zoom to given region by specifying the earliest and the latest dates that should be visible on the axis.
 * This method works in date mode only, if <hasDates> is YES.
 * Use this method after you updated data of the chart with <code>[chart updateData]</code> call.
 *
 * @param startDate - earliest date that should be visible.
 * @param endDate - latest date that should be visible.
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)zoomToDateRegionFrom:(NSDate *)startDate to:(NSDate *)endDate duration:(float)duration delay:(float)delay;

/**
 * Array of axis marks.
 * @see NChartValueAxisMark.
 */
@property (nonatomic, readonly) NSArray *marks;

/**
 * Add axis mark.
 * @see NChartValueAxisMark.
 *
 * @param mark - mark to add.
 */
- (void)addMark:(NChartValueAxisMark *)mark;

/**
 * Remove axis mark.
 * @see NChartValueAxisMark.
 *
 * @param mark - mark to remove.
 */
- (void)removeMark:(NChartValueAxisMark *)mark;

/**
 * Remove all axis marks.
 * @see NChartValueAxisMark.
 */
- (void)removeAllMarks;

/**
 * Calculate optimal value for <minTickSpacing>.
 * <br> Use this method if you want to get <minTickSpacing> that corresponds to the actual lengths of axis ticks'
 * labels.
 * @note You should call this method _after_ the <code>updateData</code> call of the chart, because this method operates
 * with the data obtained from data source. If you call it before the data are updated, the result will be wrong.
 */
- (void)calcOptimalMinTickSpacing;

/**
 * Fit the zoom according to the current <minTickSpacing>.
 * <br> Use this method if you want to zoom the chart so that the maximal number of points is visible with no
 * skipping of ticks on the axis.
 * @note This method requires frame of the chart to be determined. So if you call this method before the chart's layout,
 * it will fail. If you want the axes to be automatically zoomed according to the <minTickSpacing>, use the flag
 * <shouldAutoFitZoomByMinTickSpacing>.
 *
 * @param duration - duration of the animation in seconds.
 * @param delay - delay of animation in seconds.
 */
- (void)fitZoomByMinTickSpacingWithDuration:(float)duration delay:(float)delay;

/**
 * Flag determining if zoom of the axis should be automatically fit according to the current <minTickSpacing> (YES) or
 * not (NO). The default value is NO.
 * <br> Set this flag to YES if you want to zoom the chart so that the maximal number of points is visible with
 * no skipping of ticks on the axis. Best practice is to set this flag and call <calcOptimalMinTickSpacing>.
 * @note If this flag is set to YES, zoom of the axis is changed automatically by each chart's layout. Zoom you set
 * manually before layout will be ignored.
 * @note Auto fitting works in 2D mode only.
 */
@property (nonatomic, assign) BOOL shouldAutoFitZoomByMinTickSpacing;

/**
 * Flag indicating if axis displays dates instead of values (YES) or regular values (NO). The default value is NO.
 */
@property (nonatomic, assign) BOOL hasDates;

/**
 * Flag determining if axis has logarithmic scale (YES) or linear scale (NO). The default value is NO. The base of
 * scale's logarithm is controlled by <logarithmBase> property.
 */
@property (nonatomic, assign) BOOL isLogarithmic;

/**
 * Base of logarithm for logarithmic scale. The default value is 10.
 * @note This property takes effect if <isLogarithmic> is set to YES only.
 */
@property (nonatomic, assign) double logarithmBase;

/**
 * Coordinate controlling horizontal position of the axis.
 * @see NChartAxisPositionCoord.
 */
@property (nonatomic, readonly) NChartAxisPositionCoord *positionX;

/**
 * Coordinate controlling vertical position of the axis.
 * @see NChartAxisPositionCoord.
 */
@property (nonatomic, readonly) NChartAxisPositionCoord *positionY;

/**
 * Coordinate controlling depth position of the axis.
 * @see NChartAxisPositionCoord.
 */
@property (nonatomic, readonly) NChartAxisPositionCoord *positionZ;

@end
