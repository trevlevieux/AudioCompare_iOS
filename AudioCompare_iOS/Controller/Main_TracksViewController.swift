//
//  Main_TracksViewController.swift
//  AudioCompare_iOS
//
//  Created by Trevor LeVieux on 7/23/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit

class Main_TracksViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource {
    
    @IBOutlet var collectionView: UICollectionView!

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    //--------------------Collection Delegate
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 2
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        numberOfItemsInSection section: Int) -> Int {
        if section == 0 {
            return 25
        }
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell_track", for: indexPath) as! TrackCollectionViewCell
        cell.layer.cornerRadius = 8
        
        if indexPath.section == 0 {
            cell.label?.text = "Test Track"
        }
        else {
            cell.label?.text = "Add Track"
        }
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        sizeForItemAt indexPath: IndexPath) -> CGSize
    {
        return CGSize.init(width: collectionView.frame.size.width - 40, height: 60)
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath)
    {
        if indexPath.section == 0 {
            if (UIDevice.current.userInterfaceIdiom == UIUserInterfaceIdiom.pad)
            {
                // Update data graph
            }
            else
            {
                // Update data graph
                self.performSegue(withIdentifier: "segue_dataGraph", sender: nil)
            }
        }
        else {
            let addTrackStoryBoard = UIStoryboard.init(name: "AddTrack_Universal", bundle: nil) as UIStoryboard
            let addTrackViewController = addTrackStoryBoard.instantiateInitialViewController()
            self.present(addTrackViewController!, animated: true, completion: nil)
        }
    }
}

