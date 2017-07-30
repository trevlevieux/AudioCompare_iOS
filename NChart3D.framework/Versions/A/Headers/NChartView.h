/**
 * This file is the part of NChart3D Framework
 * http://www.nchart3d.com
 *
 * File: NChartView.h
 * Version: "2.9.1"
 *
 * Copyright (C) 2017 Nulana LTD. All Rights Reserved.
 */

#import <UIKit/UIKit.h>
#import "NChart.h"


/**
 * The NChartView class provides a view to display the chart. This view can be added anywhere to view the hierarchy of
 * the app.
 */
@interface NChartView : UIView

/**
 * Get chart instance. It is created with the view's creation and destroyed with its destruction.
 * @see NChart.
 */
@property (nonatomic, readonly) NChart *chart;

/**
 * Flag determining if view is allowed to recreate internal rendering data structures (YES) or not (NO). The default
 * value is YES.
 * <br> Use this flag to temporary lock the updating of the view. You may need to lock it (by setting NO to this
 * property) in viewWillDisappear of your view controller and unlock it (by setting YES) in viewWillAppear. This kind of
 * locking helps to avoid troubles related to the updating of invisible OpenGLES-based views (because in iOS 8+ such
 * updating leads to OpenGLES crash).
 */
@property (nonatomic, assign) BOOL isUpdatingEnabled;

/**
 * Wait for rendering (by pausing calling thread until rendering thread does its job).
 * <br> Use this method whenever you want to  guarantee the settings you made in your objects are reflected on 
 * the view (for example, by hiding settings screen to guarantee user wont see the last frame of old data).
 * @note You do not need to call <code>flushChanges</code> method of the <code>NChart</code> object if you use this
 * method: the data are synced automatically.
 * @see NChart.
 */
- (void)waitForUpdating;

/**
 * Capture screenshot of the chart to context.
 *
 * @return new context with the screenshot.
 */
- (CGContextRef)captureScreenshotToContext;

/**
 * Capture screenshot of the chart to image.
 *
 * @return new image with the screenshot.
 */
- (UIImage *)captureScreenshot;

@end
