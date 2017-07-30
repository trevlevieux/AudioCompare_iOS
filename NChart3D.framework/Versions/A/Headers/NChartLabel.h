/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartLabel.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import "NChartPlaced.h"


/**
 * The NChartLabel class provides methods to display text on the chart.
 */
@interface NChartLabel : NChartPlaced

/**
 * Create new label instance.
 *
 * @return new label instance.
 */
+ (NChartLabel *)label;

/**
 * Font of the label's text.
 */
@property (nonatomic, retain) UIFont *font;

/**
 * Color of the label's text.
 */
@property (nonatomic, retain) UIColor *textColor;

/**
 * Text to display in the label.
 */
@property (nonatomic, retain) NSString *text;

/**
 * Wrapping mode of the label's text.
 */
@property (nonatomic, assign) NSLineBreakMode textWrapping;

/**
 * Alignment of the label's text.
 */
@property (nonatomic, assign) NSTextAlignment textAlignment;

/**
 * Maximal width of the label's text in pixels. If the text is bigger than the given size, lines will be broken
 * according to the wrapping mode. If 0, this option is ignored. The default value is 0.
 */
@property (nonatomic, assign) float maxWidth;

@end
