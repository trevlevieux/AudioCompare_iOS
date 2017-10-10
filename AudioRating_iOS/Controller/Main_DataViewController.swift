//
//  Main_DataViewController.swift
//  AudioRating
//
//  Created by Trevor LeVieux on 7/23/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit

class Main_DataViewController: UIViewController, NChartSeriesDataSource, NChartValueAxisDataSource {
    
    @IBOutlet var chartView: NChartView!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        // Paste your license key here.
        chartView.chart.licenseKey = ""
        
        // Margin to ensure some free space for the iOS status bar.
        chartView.chart.cartesianSystem.margin = NChartMarginMake(10.0, 10.0, 10.0, 20.0)
        
        // Switch 3D on. We will have a kind of fake 3D, because the Z-axis will have no values. Just the columns will be
        // volumetric.
        chartView.chart.drawIn3D = true
        
        // Set the data source for the X- and Z-Axis, because we want custom values on them.
        chartView.chart.cartesianSystem.xAxis.dataSource = self
        chartView.chart.cartesianSystem.zAxis.dataSource = self
        
        // Create series that will be displayed on the chart.
        let series = NChartColumnSeries()
        
        // Set brush that will fill that series with color.
        series.brush = NChartSolidColorBrush(color: UIColor(red: 0.38, green:0.8, blue:0.91, alpha: 1.0))
        
        // Set data source for the series.
        series.dataSource = self
        
        // Add series to the chart.
        chartView.chart.addSeries(series)
        
        // Set data source for the X-Axis to have custom values on them.
        chartView.chart.cartesianSystem.xAxis.dataSource = self
        
        // Update data in the chart.
        chartView.chart.updateData()
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    //---------------------Chart Delegate
    
    func seriesDataSourcePoints(for series: NChartSeries!) -> [Any]! {
        // Create points with some data for the series.
        var result: [NChartPoint] = []
        for i in 0..<5 {
            result.append(NChartPoint(state: NChartPointState(alignedToXZWithX: i, y: Double(arc4random() % 30 + 1),
                                                              z: 0), for: series))
        }
        return result
    }
    
    func seriesDataSourceName(for series: NChartSeries!) -> String! {
        // Get name of the series.
        return nil
    }
    
    // MARK: NChartValueAxisDataSource
    
    func valueAxisDataSourceTicks(for axis: NChartValueAxis!) -> [Any]! {
        // Choose ticks by the kind of axis.
        switch axis.kind {
            
        case .X:
            // Return five tick names, because we have five points in the series.
            return ["Alpha" as AnyObject, "Beta" as AnyObject, "Gamma" as AnyObject, "Delta" as AnyObject, "Epsilon" as AnyObject]
            
        case .Z:
            // Return an array with an empty string to draw noting on the single tick of Z-Axis.
            return ["" as AnyObject]
            
        default:
            // Other axes have no ticks.
            return nil
        }
    }
    
    func valueAxisDataSourceLength(for axis: NChartValueAxis!) -> NSNumber! {
        // Choose length by the kind of axis.
        switch axis.kind {
            
        case .Z:
            // We want Z-Axis to be shorter than the others because it has no values. The default length of axes is 1.0.
            // So let Z-Axis be 0.3 for example.
            return 0.3
            
        default:
            // All other axes should have the default length.
            return nil
        }
    }
}

