/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartPointState.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartMarker.h"


/**
 * The NChartPointState class provides methods to store state of a point. The state of a point is a complex of parameters
 * such as position, brush used etc. for a particular period for a particular point. Each chart point should have at
 * least one state representing the data from the data source for this point, but it can have multiple states. This
 * allows the animation of a chart through time, while each NChartPointState represents the state of the point in a
 * particular time tick. The transition from one state to another is animated automatically by linear interpolation of
 * parameters stored in the states.
 */
@interface NChartPointState : NSObject

/**
 * Brush that fills the point.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *brush;

/**
 * Brush of the point's border.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *borderBrush;

/**
 * Marker of the point.
 * @see NChartMarker.
 */
@property (nonatomic, retain) NChartMarker *marker;

/**
 * Create a point state representing the point that is aligned to the X grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 2D.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXWithX:(NSInteger)x Y:(double)y;

/**
 * Create a point state representing the point that is aligned to the X date grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 2D.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXWithDateX:(NSDate *)x Y:(double)y;

/**
 * Create a point state representing the point that is aligned to the XZ grid. This is a typical state for column,
 * area, line and ribbon series if drawn in 3D. This can also be used for a surface.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - integer value on the Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithX:(NSInteger)x Y:(double)y Z:(NSInteger)z;

/**
 * Create a point state representing the point that is aligned to the XZ date grid. This is a typical state for column,
 * area, line and ribbon series if drawn in 3D. This can also be used for a surface.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - date value on the Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithDateX:(NSDate *)x Y:(double)y dateZ:(NSDate *)z;

/**
 * Create a point state representing the point that is aligned to the X date grid and Z grid. This is a typical state for column,
 * area, line and ribbon series if drawn in 3D. This can also be used for a surface.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - integer value on the Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithDateX:(NSDate *)x Y:(double)y Z:(NSInteger)z;

/**
 * Create a point state representing the point that is aligned to the X grid and Z date grid. This is a typical state for column,
 * area, line and ribbon series if drawn in 3D. This can also be used for a surface.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - date value on the Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithX:(NSInteger)x Y:(double)y dateZ:(NSDate *)z;

/**
 * Create a point state representing the point that is aligned to the Y grid. This is a typical state for bar series
 * if drawn in 2D.
 *
 * @param x - double value on X axis that represents the height value.
 * @param y - integer value on Y axis that represents the first category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYWithX:(double)x Y:(NSInteger)y;

/**
 * Create a point state representing the point that is aligned to the Y date grid. This is a typical state for bar series
 * if drawn in 2D.
 *
 * @param x - double value on X axis that represents the height value.
 * @param y - date value on Y axis that represents the first category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYWithX:(double)x dateY:(NSDate *)y;

/**
 * Create a point state representing the point that is aligned to the YZ grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on X axis that represents the height value.
 * @param y - integer value on Y axis that represents the first category.
 * @param z - integer value on Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYZWithX:(double)x Y:(NSInteger)y Z:(NSInteger)z;

/**
 * Create a point state representing the point that is aligned to the YZ date grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on X axis that represents the height value.
 * @param y - date value on Y axis that represents the first category.
 * @param z - date value on Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYZWithX:(double)x dateY:(NSDate *)y dateZ:(NSDate *)z;

/**
 * Create a point state representing the point that is aligned to the Y date grid and Z grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on X axis that represents the height value.
 * @param y - date value on Y axis that represents the first category.
 * @param z - integer value on Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYZWithX:(double)x dateY:(NSDate *)y Z:(NSInteger)z;

/**
 * Create a point state representing the point that is aligned to the Y grid and Z date grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on X axis that represents the height value.
 * @param y - integer value on Y axis that represents the first category.
 * @param z - date value on Z axis that represents the second category.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYZWithX:(double)x Y:(NSInteger)y dateZ:(NSDate *)z;

/**
 * Create a point state representing the point that is aligned to the concentric circles. This is a typical state for
 * pie series if drawn in 2D.
 *
 * @param circle - number of circle among concentric circles that represents the category.
 * @param value - value of the state that affects the angle of the sector. The angle will represent the percent of the
 * value among all values in the circle this state belongs to.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateWithCircle:(NSInteger)circle value:(double)value;

/**
 * Create a point state representing the point that is aligned to the concentric circles and has the height. This is a
 * typical state for pie series if drawn in 3D.
 *
 * @param circle - number of circle among concentric circles that represents the category.
 * @param value - value of the state that affects the angle of the sector. The angle will represent the percent of the
 * value among all values in the circle this state belongs to.
 * @param height - height of sector. The height should be in interval 0..1. It is not connected to any axis, so the
 * value is not mapped. You may use it to visually group sectors or to stress some of them.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateWithCircle:(NSInteger)circle value:(double)value height:(double)height;

/**
 * Create free (not aligned) 3D-space point state. This is a typical state for bubble or surface series. But you may use
 * this for other series types too.
 *
 * @param x - double value on the X axis that represents the abscissa of a position.
 * @param y - double value on the Y axis that represents the ordinate of a position.
 * @param z - double value on the Z axis that represents the applicate of a position.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateWithX:(double)x Y:(double)y Z:(double)z;

/**
 * Create a point state that is aligned to the X grid and has low, open, close and high values. This is a typical
 * state for candlestick series drawn in 2D.
 *
 * @param x - integer value on the X axis that represents the category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the  Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXWithX:(NSInteger)x low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Create a point state that is aligned to the X date grid and has low, open, close and high values. This is a typical
 * state for candlestick series drawn in 2D.
 *
 * @param x - date value on the X axis that represents the category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the  Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXWithDateX:(NSDate *)x low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Create a point state that is aligned to the Y grid and has open and close values. This is the a typical
 * state for a sequence series drawn in 2D.
 *
 * @param y - integer value on the Y axis that represents the category.
 * @param open - double value on the X axis that represents the "open" value.
 * @param close - double value on the X axis that represents the "close" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYWithY:(NSInteger)y open:(double)open close:(double)close;

/**
 * Create a point state that is aligned to the Y date grid and has open and close values. This is the a typical
 * state for a sequence series drawn in 2D.
 *
 * @param y - date value on the Y axis that represents the category.
 * @param open - double value on the X axis that represents the "open" value.
 * @param close - double value on the X axis that represents the "close" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToYWithDateY:(NSDate *)y open:(double)open close:(double)close;

/**
 * Create a point state that is aligned to the X grid and has low and high values. This is the a typical
 * state for a band series drawn in 2D.
 *
 * @param x - integer value on the X axis that represents the category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXWithX:(NSInteger)x low:(double)low high:(double)high;

/**
 * Create a point state that is aligned to the X date grid and has low and high values. This is the a typical
 * state for a band series drawn in 2D.
 *
 * @param x - date value on the X axis that represents the category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXWithDateX:(NSDate *)x low:(double)low high:(double)high;

/**
 * Create a point state that is aligned to the XZ grid and has low, open, close and high values. This is a typical
 * state for candlestick series drawn in 3D.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param z - integer value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithX:(NSInteger)x Z:(NSInteger)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Create a point state that is aligned to the XZ date grid and has low, open, close and high values. This is a typical
 * state for candlestick series drawn in 3D.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param z - date value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithDateX:(NSDate *)x dateZ:(NSDate *)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Create a point state that is aligned to the X date grid and Z grid and has low, open, close and high values. This is a typical
 * state for candlestick series drawn in 3D.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param z - integer value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithDateX:(NSDate *)x Z:(NSInteger)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Create a point state that is aligned to the X grid and Z date grid and has low, open, close and high values. This is a typical
 * state for candlestick series drawn in 3D.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param z - date value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateAlignedToXZWithX:(NSInteger)x dateZ:(NSDate *)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Create free (not aligned) 2D-space point state with value. This is a typical state for heatmap series.
 *
 * @param x - double value on the X axis that represents the abscissa of a position.
 * @param y - double value on the Y axis that represents the ordinate of a position.
 * @param value - value of the state that represents the amount of entity displayed by series.
 * @return a new instance of the point state.
 */
+ (NChartPointState *)pointStateWithX:(double)x Y:(double)y Value:(double)value;

/**
 * Init a point state representing the point that is aligned to the X grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 2D.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXWithX:(NSInteger)x Y:(double)y;

/**
 * Init a point state representing the point that is aligned to the X date grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 2D.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXWithDateX:(NSDate *)x Y:(double)y;

/**
 * Init a point state representing the point that is aligned to the XZ grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 3D. It can also be used for a surface series.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - integer value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithX:(NSInteger)x Y:(double)y Z:(NSInteger)z;

/**
 * Init a point state representing the point that is aligned to the XZ date grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 3D. It can also be used for a surface series.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - date value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithDateX:(NSDate *)x Y:(double)y dateZ:(NSDate *)z;

/**
 * Init a point state representing the point that is aligned to the X date grid and Z grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 3D. It can also be used for a surface series.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - integer value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithDateX:(NSDate *)x Y:(double)y Z:(NSInteger)z;

/**
 * Init a point state representing the point that is aligned to the X grid and Z date grid. This is a typical state for column, area,
 * line and ribbon series if drawn in 3D. It can also be used for a surface series.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param y - double value on the Y axis that represents the height value.
 * @param z - date value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithX:(NSInteger)x Y:(double)y dateZ:(NSDate *)z;

/**
 * Init a point state representing the point that is aligned to the the Y grid. This is a typical state for bar series
 * if drawn in 2D.
 *
 * @param x - double value on the X axis that represents the height value.
 * @param y - integer value on the Y axis that represents the first category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYWithX:(double)x Y:(NSInteger)y;

/**
 * Init a point state representing the point that is aligned to the the Y date grid. This is a typical state for bar series
 * if drawn in 2D.
 *
 * @param x - double value on the X axis that represents the height value.
 * @param y - date value on the Y axis that represents the first category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYWithX:(double)x dateY:(NSDate *)y;

/**
 * Init a point state representing the point that is aligned to the YZ grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on the X axis that represents the height value.
 * @param y - integer value on the Y axis that represents the first category.
 * @param z - integer value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYZWithX:(double)x Y:(NSInteger)y Z:(NSInteger)z;

/**
 * Init a point state representing the point that is aligned to the YZ date grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on the X axis that represents the height value.
 * @param y - date value on the Y axis that represents the first category.
 * @param z - date value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYZWithX:(double)x dateY:(NSDate *)y dateZ:(NSDate *)z;

/**
 * Init a point state representing the point that is aligned to the Y date grid and Z grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on the X axis that represents the height value.
 * @param y - date value on the Y axis that represents the first category.
 * @param z - integer value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYZWithX:(double)x dateY:(NSDate *)y Z:(NSInteger)z;

/**
 * Init a point state representing the point that is aligned to the Y grid and Z date grid. This is a typical state for bar series
 * if drawn in 3D.
 *
 * @param x - double value on the X axis that represents the height value.
 * @param y - integer value on the Y axis that represents the first category.
 * @param z - date value on the Z axis that represents the second category.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYZWithX:(double)x Y:(NSInteger)y dateZ:(NSDate *)z;

/**
 * Init a point state representing the point that is aligned to the concentric circles. This is a typical state for
 * pie series if drawn in 2D.
 *
 * @param circle - number of circle among concentric circles that represents the category.
 * @param value - value of the state that affects the angle of the sector. The angle will represent the percent of the
 * value among all values in the circle this state belongs to.
 * @return the initialized instance of a point state.
 */
- (id)initWithCircle:(NSInteger)circle value:(double)value;

/**
 * Init a point state representing the point that is aligned to the concentric circles and has the height. This is a
 * typical state for pie series if drawn in 3D.
 *
 * @param circle - number of circle among concentric circles that represents the category.
 * @param value - value of the state that affects the angle of the sector. The angle will represent the percent of the
 * value among all values in the circle this state belongs to.
 * @param height - height of sector. The height should be in interval 0..1. It is not connected to any axis, so the
 * value is not mapped. You may use it to visually group sectors or to stress some of them.
 * @return the initialized instance of a point state.
 */
- (id)initWithCircle:(NSInteger)circle value:(double)value height:(double)height;

/**
 * Init a free (not aligned) 3D-space point. This is a typical state for bubble or surface series, but you may use
 * this for other series types too.
 *
 * @param x - double value on the X axis that represents the abscissa of a position.
 * @param y - double value on the Y axis that represents the ordinate of a position.
 * @param z - double value on the Z axis that represents the applicate of a position.
 * @return the initialized instance of a point state.
 */
- (id)initWithX:(double)x Y:(double)y Z:(double)z;

/**
 * Init a point state that is aligned to the X grid and has low, open, close and high values. This is a typical state
 * for candlestick series drawn in 2D.
 *
 * @param x - integer value on the X axis that represents the category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXWithX:(NSInteger)x low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Init a point state that is aligned to the X date grid and has low, open, close and high values. This is a typical state
 * for candlestick series drawn in 2D.
 *
 * @param x - date value on the X axis that represents the category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXWithDateX:(NSDate *)x low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Init a point state that is aligned to the Y grid and has open and close values. This is a typical state
 * for a sequence series drawn in 2D.
 *
 * @param y - integer value on the Y axis that represents the category.
 * @param open - double value on the X axis that represents the "open" value.
 * @param close - double value on the X axis that represents the "close" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYWithY:(NSInteger)y open:(double)open close:(double)close;

/**
 * Init a point state that is aligned to the Y date grid and has open and close values. This is a typical state
 * for a sequence series drawn in 2D.
 *
 * @param y - date value on the Y axis that represents the category.
 * @param open - double value on the X axis that represents the "open" value.
 * @param close - double value on the X axis that represents the "close" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToYWithDateY:(NSDate *)y open:(double)open close:(double)close;

/**
 * Init a point state that is aligned to the XZ grid and has low, open, close and high values. This is a typical state
 * for candlestick series drawn in 3D.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param z - integer value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithX:(NSInteger)x Z:(NSInteger)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Init a point state that is aligned to the XZ date grid and has low, open, close and high values. This is a typical state
 * for candlestick series drawn in 3D.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param z - date value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithDateX:(NSDate *)x dateZ:(NSDate *)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Init a point state that is aligned to the X date grid and Z grid and has low, open, close and high values. This is a typical state
 * for candlestick series drawn in 3D.
 *
 * @param x - date value on the X axis that represents the first category.
 * @param z - integer value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithDateX:(NSDate *)x Z:(NSInteger)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Init a point state that is aligned to the X grid and Z date grid and has low, open, close and high values. This is a typical state
 * for candlestick series drawn in 3D.
 *
 * @param x - integer value on the X axis that represents the first category.
 * @param z - date value on the Z axis that represents the second category.
 * @param low - double value on the Y axis that represents the "low" value.
 * @param open - double value on the Y axis that represents the "open" value.
 * @param close - double value on the Y axis that represents the "close" value.
 * @param high - double value on the Y axis that represents the "high" value.
 * @return the initialized instance of a point state.
 */
- (id)initAlignedToXZWithX:(NSInteger)x dateZ:(NSDate *)z low:(double)low open:(double)open close:(double)close high:(double)high;

/**
 * Init a free (not aligned) 2D-space point state with value. This is a typical state for heatmap series.
 *
 * @param x - double value on the X axis that represents the abscissa of a position.
 * @param y - double value on the Y axis that represents the ordinate of a position.
 * @param value - value of the state that represents the amount of entity displayed by series.
 * @return the initialized instance of a point state.
 */
- (id)initWithX:(double)x Y:(double)y Value:(double)value;

/**
 * Integer X value of a point state.
 */
@property (nonatomic, assign) NSInteger intX;

/**
 * Double X value of a point state.
 */
@property (nonatomic, assign) double doubleX;

/**
 * Date X value of a point state.
 * @note This property does not store the object of NSDate, but you can still query the date through this property and
 * obtain newly created and autoreleased NSDate object.
 */
@property (nonatomic, assign) NSDate *dateX;

/**
 * Integer Y value of a point state.
 */
@property (nonatomic, assign) NSInteger intY;

/**
 * Double Y value of a point state.
 */
@property (nonatomic, assign) double doubleY;

/**
 * Date Y value of a point state.
 * @note This property does not store the object of NSDate, but you can still query the date through this property and
 * obtain newly created and autoreleased NSDate object.
 */
@property (nonatomic, assign) NSDate *dateY;

/**
 * Integer Z value of a point state.
 */
@property (nonatomic, assign) NSInteger intZ;

/**
 * Double Z value of a point state.
 */
@property (nonatomic, assign) double doubleZ;

/**
 * Date Z value of a point state.
 * @note This property does not store the object of NSDate, but you can still query the date through this property and
 * obtain newly created and autoreleased NSDate object.
 */
@property (nonatomic, assign) NSDate *dateZ;

/**
 * Circle of a point state. See <code>initWithCircle: value:</code> for details.
 */
@property (nonatomic, assign) NSInteger circle;

/**
 * Value of a point state. See <code>initWithCircle: value:</code> for details.
 */
@property (nonatomic, assign) double value;

/**
 * Height of a point state. See <code>initWithCircle: value: height:</code> for details.
 */
@property (nonatomic, assign) double height;

/**
 * Low value of a point state. See <code>initAlignedToXWithX: low: open: close: high:</code> for details.
 */
@property (nonatomic, assign) double low;

/**
 * Close value of a point state. See <code>initAlignedToXWithX: low: open: close: high:</code> for details.
 */
@property (nonatomic, assign) double close;

/**
 * Open value of a point state. See <code>initAlignedToXWithX: low: open: close: high:</code> for details.
 */
@property (nonatomic, assign) double open;

/**
 * High value of a point state. See <code>initAlignedToXWithX: low: open: close: high:</code> for details.
 */
@property (nonatomic, assign) double high;

@end
