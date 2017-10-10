//
//  ProjectCollectionViewCell.swift
//  AudioRating
//
//  Created by Trevor LeVieux on 8/1/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit

class ProjectCollectionViewCell: UICollectionViewCell {
    
    @IBOutlet weak var label: UILabel?
    @IBOutlet weak var imageView: UIImageView?

    override func awakeFromNib() {
        super.awakeFromNib()
        
        prepareForReuse()
    }

    override func prepareForReuse() {
        
        label?.text = ""
        imageView?.image = UIImage.init(named: "icon_tvOS")
        imageView?.contentMode = UIViewContentMode.scaleToFill
        imageView?.tintColor = nil
    }
}
