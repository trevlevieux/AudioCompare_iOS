/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPoint.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartPointState.h"
#import "NChartSeries.h"
#import "NChartTooltip.h"


/**
 * The NChartPoint class provides methods to manage chart's points.
 */
@interface NChartPoint : NSObject

/**
 * Create point with an array of states.
 *
 * @param states - the array of point states. See <NChartPointState> for details.
 * @param series - the series the point belongs to.
 * @return a new instance of the point.
 */
+ (NChartPoint *)pointWithArrayOfStates:(NSArray *)states forSeries:(NChartSeries *)series;

/**
 * Create point with a single state.
 *
 * @param state - the state if point. See <NChartPointState> for details.
 * @param series - the series the point belongs to.
 * @return a new instance of the point.
 */
+ (NChartPoint *)pointWithState:(NChartPointState *)state forSeries:(NChartSeries *)series;

/**
 * Init point with an array of states.
 *
 * @param states - the array of point states. See <NChartPointState> for details.
 * @param series - the series the point belongs to.
 * @return the initialized instance of a point.
 * @see NChartSeries.
 */
- (id)initWithArrayOfStates:(NSArray *)states forSeries:(NChartSeries *)series;

/**
 * Init point with a single state.
 *
 * @param state - the state if point. See <NChartPointState> for details.
 * @param series - the series the point belongs to.
 * @return the initialized instance of a point.
 * @see NChartSeries.
 */
- (id)initWithState:(NChartPointState *)state forSeries:(NChartSeries *)series;

/**
 * Series the point belongs to.
 * @see NChartSeries.
 */
@property (nonatomic, assign) NChartSeries *series;

/**
 * Array of states. See <NChartPointState> for details. If a point was created with a single state, the array of states
 * is not allocated and this property returns nil.
 */
@property (nonatomic, readonly) NSArray *states;

/**
 * Index of current state. If a point was created with a single state, this property always returns 0.
 */
@property (nonatomic, readonly) NSInteger currentStateIndex;

/**
 * Direct access to current state. This is a bit faster and more convenient than a query element of the states' array by
 * <currentStateIndex>. If a point was created with a single state, this property is the only way to access it.
 * @see NChartPointState.
 */
@property (nonatomic, readonly) NChartPointState *currentState;

/**
 * Tooltip that is shown on the point. It is nil by default. The tooltip is just a label, it does not change its content
 * automatically. By altering its text, you can display any information you want, but you should do it yourself.
 * Tooltip is similar to <label>, but it is placed in the center of the point by default. You can have <code>tooltip</code> and
 * <label> simultaneously displaying different information.
 * @see NChartTooltip.
 */
@property (nonatomic, retain) NChartTooltip *tooltip;

/**
 * Label that is shown near the point. It is nil by default. The label does not change its content automatically.
 * By altering its text, you can display any information you want, but you should do it yourself.
 * Label is similar to <tooltip>, but it is placed in the top of the point by default. You can have <tooltip> and
 * <code>label</code> simultaneously displaying different information.
 * @see NChartTooltip.
 */
@property (nonatomic, retain) NChartTooltip *label;

/**
 * Highlight color. Some points can be highlighted by color, for example in column, pie or bubble
 * (where the points are individual objects). In series like line and area the color highlight can be applied to the
 * markers, so for these series this property has effect only if the marker is set.
 */
@property (nonatomic, retain) UIColor *highlightColor;

/**
 * Highlight shift. Some points can be highlighted by shift, for example in pie. The shift is set in scene units.
 * For example, the radius of pie is 1 scene unit, so you can use this value as a reference.
 */
@property (nonatomic, assign) float highlightShift;

/**
 * Highlight point using the highlight settings done by <highlightColor> and <highlightShift> properties.
 *
 * @param mask - mask of highlighting. See <NChartHighlightType> enum for details. You may use multiple constants
 * concatenated with bitwise OR.
 * @param duration - duration of highlighting animation in seconds.
 * @param delay - delay to start of highlighting animation in seconds.
 * @see NChartHighlightType.
 */
- (void)highlightWithMask:(NSUInteger)mask duration:(float)duration delay:(float)delay;

/**
 * Tag of the point. You may use it as you want.
 */
@property (nonatomic, assign) NSInteger tag;

@end
