/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartModel.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import <Foundation/Foundation.h>


/**
 * The NChartModel provides the container for the 3D model that can be loaded from file and then be displayed as a marker
 * \(see <NChartMarker> for details\).
 * PLY (<a href="http://en.wikipedia.org/wiki/PLY_%28file_format%29">http://en.wikipedia.org/wiki/PLY_(file_format)</a>) with triangles and geometry of 3DS
 * (<a href="http://en.wikipedia.org/wiki/.3ds">http://en.wikipedia.org/wiki/.3ds</a>) are supported.
 */
@interface NChartModel : NSObject

/**
 * Create model with data.
 *
 * @param data - data containing the model.
 * @return a new instance of the model.
 */
+ (NChartModel *)modelWithData:(NSData *)data;

/**
 * Create model with contents of file.
 *
 * @param filePath - path to file containing the model.
 * @return a new instance of the model.
 */
+ (NChartModel *)modelWithContentsOfFile:(NSString *)filePath;

/**
 * Init model with data.
 *
 * @param data - data containing the model.
 * @return the initialized instance of a model.
 */
- (id)initWithData:(NSData *)data;

/**
 * Init model with contents of file.
 *
 * @param filePath - path to file containing the model.
 * @return the initialized instance of a model.
 */
- (id)initWithContentsOfFile:(NSString *)filePath;

/**
 * Number of vertices in the model.
 */
@property (nonatomic, readonly) NSInteger vertexCount;

/**
 * Number of triangles in the model.
 */
@property (nonatomic, readonly) NSInteger trianglesCount;

@end
