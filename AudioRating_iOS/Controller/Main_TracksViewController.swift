//
//  Main_TracksViewController.swift
//  AudioRating
//
//  Created by Trevor LeVieux on 7/23/17.
//  Copyright © 2017 LeVieux. All rights reserved.
//

import UIKit
import AVFoundation
//import AudioKit

class Main_TracksViewController: UIViewController, UICollectionViewDelegate, UICollectionViewDataSource, UICollectionViewDelegateFlowLayout, UIDocumentPickerDelegate {

    var tracksArray: [[String : Any]] = []
    @IBOutlet var collectionView: UICollectionView!
    
    var audioPlayer = AVAudioPlayer()
    
    let bufferSize: UInt32 = 512
    //var fft: EZAudioFFT?
    //var fftData = [Double]()

    override func viewDidLoad() {
        super.viewDidLoad()
        // Do any additional setup after loading the view, typically from a nib.
    }

    override func didReceiveMemoryWarning() {
        super.didReceiveMemoryWarning()
        // Dispose of any resources that can be recreated.
    }
    
    //--------------------Document Picker Delegate
    
    func documentPicker(_ controller: UIDocumentPickerViewController, didPickDocumentsAt urls: [URL]) {
        if controller.documentPickerMode == UIDocumentPickerMode.import {
            
            for url in urls {
                
                let audioData = NSData.init(contentsOf: url)
                let audioName = url.deletingPathExtension().lastPathComponent
                
                var trackDictionary : [String : Any] = [:]
                trackDictionary["url"] = url
                trackDictionary["data"] = audioData
                trackDictionary["name"] = audioName
                
                /*let audioFile = try? AKAudioFile(readFileName: "Three_60.wav", baseDir: .resources)
                let fft = AKFFTTap
                
                audioFile.
                
                let audioNode = AKNode.init(avAudioNode: audioFile)
                
                
                let fftTap = AKFFTTap.init(<#T##input: AKNode##AKNode#>)
                
                
                tracksArray.append(trackDictionary)
                collectionView.reloadData()*/
            }
        }
    }
    
    //--------------------Collection Delegate
    
    func numberOfSections(in collectionView: UICollectionView) -> Int {
        return 1
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        numberOfItemsInSection section: Int) -> Int {
        return tracksArray.count + 2
    }
    
    func collectionView(_ collectionView: UICollectionView,
                        cellForItemAt indexPath: IndexPath) -> UICollectionViewCell
    {
        let cell = collectionView.dequeueReusableCell(withReuseIdentifier: "cell_track", for: indexPath) as! TrackCollectionViewCell
        cell.layer.cornerRadius = 8
        
        if indexPath.row < tracksArray.count {
            cell.label?.text = tracksArray[indexPath.row]["name"] as? String
            cell.backgroundColor = UIColor.blue
        }
        else if indexPath.row == tracksArray.count {
            cell.label?.text = "Add Track"
            cell.backgroundColor = UIColor.gray
        }
        else if indexPath.row == tracksArray.count+1 {
            cell.label?.text = "Add Average"
            cell.backgroundColor = UIColor.gray
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
        if indexPath.row < tracksArray.count {
            if (UIDevice.current.userInterfaceIdiom == UIUserInterfaceIdiom.pad)
            {
                do {
                    let trackData = tracksArray[indexPath.row]["data"] as? Data
                    try AVAudioSession.sharedInstance().setCategory(AVAudioSessionCategoryPlayback)
                    try AVAudioSession.sharedInstance().setActive(true)
                    try audioPlayer = AVAudioPlayer.init(data: trackData!)
                    audioPlayer.prepareToPlay()
                    audioPlayer.play()
                } catch {
                    print(error)
                }
            }
            else
            {
                // Update data graph
                self.performSegue(withIdentifier: "segue_dataGraph", sender: nil)
            }
        }
            
        //Add Track
        else if indexPath.row == tracksArray.count {
            
            let documentPicker: UIDocumentPickerViewController = UIDocumentPickerViewController(documentTypes: ["public.audio"], in: UIDocumentPickerMode.import)
            documentPicker.delegate = self
            documentPicker.modalPresentationStyle = UIModalPresentationStyle.fullScreen
            documentPicker.allowsMultipleSelection = true
            self.present(documentPicker, animated: true, completion: nil)
        }
            
        //Add Average
        else if indexPath.row == tracksArray.count+1 {
            
        }
    }
}

