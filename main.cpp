/*
 * Ejemplos en /usr/local/share/OpenCV/samples
 */

#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/nonfree/features2d.hpp>

using namespace cv;
using namespace std;
 
int main(int argc, char **argv) {
  
    vector<KeyPoint> imageKeypoints;
    Mat imageDescriptors;
    string workDirectory="images/";
    string fileName="cokecan.jpg";
    
    cout << "Reading image: " << fileName << endl;
    
    Mat image = imread(workDirectory+fileName);
    imshow("Original", image);
   
    //Version 2.4.9  (Crear el detector)
    //int minHessian = 400;
    //SurfFeatureDetector detector( minHessian );
    SiftFeatureDetector detector;
    detector.detect(image, imageKeypoints);
    cout << "Puntos de interés: " << imageKeypoints.size() << endl;
    
    //Otras versiones (Crear el detector)
    //Ptr<FeatureDetector> detector;
    //detector = FeatureDetector::create("SIFT"); // Dense FAST GFTT MSER ORB SIFT STAR SURF BRISK HARRIS SimpleBlob
    //detector->detect(image, imageKeypoints);
    
    Ptr<DescriptorExtractor> extractor;
    extractor = DescriptorExtractor::create("SIFT"); // BRIEF ORB SIFT SURF BRISK FREAK
    extractor->compute(image, imageKeypoints, imageDescriptors);
    cout << "Descriptores: " << imageDescriptors.rows << endl;
    
    Mat imageOutput;
    drawKeypoints( image, imageKeypoints, imageOutput, Scalar::all(-1), DrawMatchesFlags::DEFAULT );
    imshow("Descriptors", imageOutput);
    waitKey(0);
  
    cout << "End" << endl;
    return 0;
}
