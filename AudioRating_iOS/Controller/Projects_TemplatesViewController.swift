//
//  Projects_TemplatesViewController.swift
//  AudioRating
//
//  Created by Trevor LeVieux on 7/23/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit
import CloudKit

class Projects_TemplatesViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout {
    
    var templatesArray : Array = ["Custom", "Top 40 Compare", "Same Song Compare", "Rock Compare", "Album Compare"]
    @IBOutlet var collectionView: UICollectionView!

    override func viewDidLoad() {
        super.viewDidLoad()
        
        self.collectionView.register(UINib.init(nibName: "ProjectCollectionViewCell", bundle: nil), forCellWithReuseIdentifier: "cell_project")
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    @IBAction func cancelPressed() {
        self.navigationController?.dismiss(animated: true, completion: nil)
    }
    
    func saveTemplate() {
        
        let project = CKRecord(recordType: "Project")
        project["name"] = "New Project" as CKRecordValue
        
        let defaultContainer = CKContainer(identifier: "iCloud.LeVieux.AudioCompare")
        let publicDB = defaultContainer.privateCloudDatabase
        
        publicDB.save(project) { (record, error) -> Void in
            guard let record = record else {
                print("Error saving record: ", error!)
                return
            }
            print("Successfully saved record: ", record)
            
            let predicate = NSPredicate(format: "TRUEPREDICATE")
            let query = CKQuery(recordType: "Project", predicate: predicate)
            publicDB.perform(query, inZoneWith: nil) {
                (records, error) -> Void in
                guard let records = records else {
                    print("Error querying records: ", error!)
                    return
                }
                print("Found \(records.count) records matching query")
            }
        }
        
        
        
        self.navigationController?.dismiss(animated: true, completion: nil)
    }
    
    //--------------------Collection Delegate
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        numberOfItemsInSection section: Int) -> Int {
        return templatesArray.count
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell_project", for: indexPath) as! ProjectCollectionViewCell
        cell.imageView?.layer.cornerRadius = 8
        
        cell.label?.text = templatesArray[indexPath.row]
        
        return cell
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        layout collectionViewLayout: UICollectionViewLayout,
                        sizeForItemAt indexPath: IndexPath) -> CGSize
    {
        let projectAspectRatio = 0.8 as CGFloat
        if (UIDevice.current.userInterfaceIdiom == UIUserInterfaceIdiom.pad)
        {
            return CGSize.init(width: 300, height: 300 * projectAspectRatio)
        }
        let width = collectionView.frame.size.width - 40
        return CGSize.init(width: width, height: (width * projectAspectRatio))
    }
    
    func collectionView(_ collectionView: UICollectionView, didSelectItemAt indexPath: IndexPath)
    {
        saveTemplate()
    }
}

