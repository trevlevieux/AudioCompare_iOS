/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartMarker.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartModel.h"
#import "NChartBrush.h"


/**
 * The NChartMarker class provides methods to display markers in the points of the chart. 
 * <br>
 * Each series, that can display markers, has the property default marker. If you set it to series, this will be a 
 * default for all the points. However you can set the marker for the point and those values, that you set to this 
 * marker, will override the corresponding values from the default marker. For example, if you set the marker for series
 * and change its size, shape and resolution, and after that set another marker to some point and change its size, all
 * points will have the markers with shape and resolution from the default marker. The size of all points except the one
 * you modified will also be the same (obtained from default marker too). And the modified point will differ in size.
 */
@interface NChartMarker : NSObject

/**
 * Shape of the marker. There are predefined shapes and <code>NChartMarkerShapeModel</code> that requires the model to
 * be set.
 * @see NChartMarkerShape.
 */
@property (nonatomic, assign) NChartMarkerShape shape;

/**
 * Model of the marker. This property is nil by default. By setting this property, shape is automatically set to
 * <code>NChartMarkerShapeModel</code>. If the shape is not <code>NChartMarkerShapeModel</code>, this property has no
 * effect, even if it is not nil. If the shape is <code>NChartMarkerShapeModel</code> and model is nil, it is equivalent
 * to the shape set to <code>NChartMarkerShapeNone</code>, so no marker is displayed.
 * @see NChartModel.
 */
@property (nonatomic, retain) NChartModel *model;

/**
 * Brush that fills the marker.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *brush;

/**
 * Brush of the marker's border. Please note, that only markers with predefined shapes have borders. If you use model,
 * border's properties are ignored.
 * @see NChartBrush.
 */
@property (nonatomic, retain) NChartBrush *borderBrush;

/**
 * Thickness of the marker's border in pixels. Please note, that only markers with predefined shapes have borders.
 * If you use a model, the border's properties are ignored.
 */
@property (nonatomic, assign) float borderThickness;

/**
 * Rotation of the marker around the X-axis in radians. This property is used for "volumetric" markers only,
 * this means for those that are not plain.
 */
@property (nonatomic, assign) float angleX;

/**
 * Rotation of the marker around the Y-axis in radians. This property is used for "volumetric" markers only,
 * this means for those that are not plain.
 */
@property (nonatomic, assign) float angleY;

/**
 * Rotation of the marker around the Z-axis in radians. This property is used for "volumetric" markers only,
 * this means for those that are not plain.
 */
@property (nonatomic, assign) float angleZ;

/**
 * Size of the marker.
 * <br>. The size can be in any unit you want. It is rescaled to pixels with the help of
 * <code>NChartSizeAxis</code>. If no data source is set for size axis, units are interpreted as pixels.
 * @see NChartSizeAxis.
 */
@property (nonatomic, assign) float size;

/**
 * Size of the marker's touch area (the area you can touch to select the corresponding chart point).
 * If this size is zero, touch area has the size of marker (that is set with <size> property).
 * The default value is 0.0f.
 * <br>. Use this property if you want to make touch area more or less then the marker size.
 * The size can be in any unit you want. It is rescaled to pixels with the help of
 * <code>NChartSizeAxis</code>. If no data source is set for size axis, units are interpreted as pixels.
 * @see NChartSizeAxis.
 */
@property (nonatomic, assign) float selectionSize;

/**
 * Resolution of the marker. Resolution is the amount of vertices that build the circle (sphere). It is used if marker's
 * shape is <code>NChartMarkerShapeCircle</code> or <code>NChartMarkerShapeSphere</code>.
 * @note This value cannot be less than 3 and greater than 32.
 * @see shape.
 */
@property (nonatomic, assign) uint resolution;

@end
