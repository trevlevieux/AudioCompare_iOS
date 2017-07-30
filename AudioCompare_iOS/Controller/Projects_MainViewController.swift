//
//  Projects_MainViewController.swift
//  AudioCompare_iOS
//
//  Created by Trevor LeVieux on 7/23/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit

class Projects_MainViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource {

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
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
    
    func collectionView(_ collectionView: UICollectionView,
                        numberOfItemsInSection section: Int) -> Int
    {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell_project", for: indexPath)
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        sizeForItemAt indexPath: IndexPath) -> CGSize
    {
        return CGSize.init(width: 300, height: 160)
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath)
    {
        self.performSegue(withIdentifier: "segue_project", sender: nil)
    }
}

