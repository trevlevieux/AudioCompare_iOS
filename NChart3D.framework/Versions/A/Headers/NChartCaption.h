/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartCaption.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartLabel.h"


/**
 * The NChartCaption class provides methods to display caption of the chart.
 */
@interface NChartCaption : NChartLabel

/**
 * Create caption instance.
 *
 * @return new caption instance.
 */
+ (NChartCaption *)caption;

/**
 * Alignment of the caption. The default value is <code>NChartCaptionBlockAlignmentTopCenter</code>.
 * @see NChartCaptionBlockAlignment.
 */
@property (nonatomic, assign) NChartCaptionBlockAlignment blockAlignment;

@end
