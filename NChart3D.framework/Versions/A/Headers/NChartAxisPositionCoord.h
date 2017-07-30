/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartAxisPositionCoord.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartTypes.h"


/**
 * The NChartAxisPositionCoord class provides methods to control the position of the chart axis.
 * Each Cartesian system axis has properties for X, Y and Z coordinates, but for every particular axis only two of them
 * are meaningful. For example, for the X-Axis only Y and Z take effect, for Y-Axis only X and Z and so on. Each coordinate
 * is associated with particular direction: X-coordinate is tied to the horizontal direction, Y to the vertical and
 * Z to the depth. According to <valueType>, <value> and <hostsOnSAxis> of the coordinate, actual position in the 
 * corresponding direction is determined.<br/>
 * For example, to place Y-Axis so, that it intersects X-Axis in the value 10, use the following code:<br/>
 * <code>m_view.chart.cartesianSystem.yAxis.positionX.value = 10.0;</code><br/>
 * If you need Y-Axis to intersect SX-Axis in the value 10 instead, add the following:<br/>
 * <code>m_view.chart.cartesianSystem.yAxis.positionX.hostsOnSAxis = YES;</code><br/>
 * The next code line added to the previous settings will make Y-Axis to intersect SX-Axis in its maximal value:<br/>
 * <code>m_view.chart.cartesianSystem.yAxis.positionX.valueType = NChartAxisPositionCoordValueMaximum;</code>
 */
@interface NChartAxisPositionCoord : NSObject

/**
 * Type of the coordinate value. 
 * @note If this property is set to <code>NChartAxisPositionCoordValueCustom</code>, position is calculated based on
 * <value>. If <code>NChartAxisPositionCoordValueMinimum</code> or <code>NChartAxisPositionCoordValueMaximum</code>
 * is set, position is calculated based on the corresponding axis' minimum or maximum respectively. The axis for the 
 * coordinate is chosen according to the actual property <code>NChartAxisPositionCoord</code> is assigned to and 
 * <hostsOnSAxis>.
 * @see NChartAxisPositionCoordValue.
 */
@property (nonatomic, assign) NChartAxisPositionCoordValue valueType;

/**
 * Value of the coordinate. The default value is 0.
 * @note this property takes effect if <valueType> is set to <code>NChartAxisPositionCoordValueCustom</code> only. 
 * If some value is assigned to this property, <valueType> is set to <code>NChartAxisPositionCoordValueCustom</code>
 * automatically.
 */
@property (nonatomic, assign) double value;

/**
 * Flag determining if the position is calculated according to the secondary axis (YES) or not (NO).
 */
@property (nonatomic, assign) BOOL hostsOnSAxis;

@end
