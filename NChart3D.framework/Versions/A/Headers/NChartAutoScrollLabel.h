/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartAutoScrollLabel.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartLabel.h"


/**
 * The NChartAutoScrollLabel provides methods to control the label that is shown whenever auto scroll mode of chart is
 * toggled.
 */
@interface NChartAutoScrollLabel : NChartLabel

/**
 * Create auto scroll label instance.
 *
 * @return new auto scroll label instance.
 */
+ (NChartAutoScrollLabel *)autoScrollLabel;

/**
 * Text that should appear on the label whenever auto scroll is ON. The default value is nil.
 */
@property (nonatomic, retain) NSString *onText;

/**
 * Text that should appear on the label whenever auto scroll is OFF. The default value is nil.
 */
@property (nonatomic, retain) NSString *offText;

/**
 * Fade time of the label (in seconds). The default value is 0.25.
 */
@property (nonatomic, assign) float fadeTime;

/**
 * Time the label is visible (in seconds). The default value is 1.
 */
@property (nonatomic, assign) float visibleTime;

@end
