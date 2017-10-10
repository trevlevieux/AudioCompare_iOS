//
//  Projects_MainViewController.swift
//  AudioRating
//
//  Created by Trevor LeVieux on 7/23/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit

class Projects_MainViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout {

    var projectsArray : Array = ["1", "2", "3"]
    @IBOutlet var collectionView: UICollectionView!
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.collectionView.register(UINib.init(nibName: "ProjectCollectionViewCell", bundle: nil), forCellWithReuseIdentifier: "cell_project")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func newProjectPressed() {
        
        let addProjectStoryBoard = UIStoryboard.init(name: "AddProject_Universal", bundle: nil) as UIStoryboard
        let addProjectViewController = addProjectStoryBoard.instantiateInitialViewController()
        self.present(addProjectViewController!, animated: true, completion: nil)
    }
    
    //--------------------Collection Delegate
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        numberOfItemsInSection section: Int) -> Int {
        return projectsArray.count + 1
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell_project", for: indexPath) as! ProjectCollectionViewCell
        cell.imageView?.layer.cornerRadius = 8
        
        if indexPath.row < projectsArray.count {
            cell.label?.text = projectsArray[indexPath.row]
        }
        else {
            cell.label?.text = "Add Project"
            cell.imageView?.image = UIImage.init(named: "icon_add")
            cell.imageView?.contentMode = UIViewContentMode.center
            cell.imageView?.tintColor = UIColor.gray
        }
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        sizeForItemAt indexPath: IndexPath) -> CGSize
    {
        let projectAspectRatio = 0.78 as CGFloat
        if (UIDevice.current.userInterfaceIdiom == UIUserInterfaceIdiom.pad)
        {
            return CGSize.init(width: 300, height: 300 * projectAspectRatio)
        }
        let width = collectionView.frame.size.width - 40
        return CGSize.init(width: width, height: (width * projectAspectRatio))
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath)
    {
        if indexPath.row < projectsArray.count {
            self.performSegue(withIdentifier: "segue_project", sender: nil)
        }
        else {
            newProjectPressed()
        }
    }
}

