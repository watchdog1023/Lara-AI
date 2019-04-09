#include<opencv2/opencv.hpp>  
#include<iostream>  
#include<stdio.h>  
#include<opencv2/core/core.hpp>
#include<opencv2/opencv.hpp>
#include<opencv2/objdetect.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc.hpp>
#include<time.h>
#include<algorithm>
#include<vector>
#include<stdio.h>
#include<iostream>
//Threading
#include<limits.h>
#include<boost/thread.hpp>
#include<boost/chrono.hpp>
#include<boost/atomic.hpp>
#include<boost/bind.hpp>
#ifdef __linux__
	#include<pthread.h>
#endif
#include "Emotions.h"

using namespace std;
using namespace cv;

int pubcheck;
string cascadeName;
string nestedCascadeName;

void detectAndDraw( Mat& img, CascadeClassifier& cascade,CascadeClassifier& nestedCascade,double scale, bool tryflip)
{
    vector<Rect> faces, faces2;
    const static Scalar colors[] ={Scalar(255,0,0),Scalar(255,128,0),Scalar(255,255,0),Scalar(0,255,0),Scalar(0,128,255),Scalar(0,255,255),Scalar(0,0,255),Scalar(255,0,255)};
    Mat gray, smallImg;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    double fx = 1 / scale;
    resize(gray, smallImg, Size(), fx, fx, INTER_LINEAR_EXACT);
    equalizeHist(smallImg, smallImg);

    cascade.detectMultiScale(smallImg, faces,1.1, 2, 0|CASCADE_SCALE_IMAGE,Size(30, 30));
    if(tryflip)
	    {
	        flip(smallImg, smallImg, 1);
	        cascade.detectMultiScale(smallImg, faces2,1.1, 2, 0|CASCADE_SCALE_IMAGE,Size(30, 30));
	        for(vector<Rect>::const_iterator r = faces2.begin();r != faces2.end();++r)
		        {
		            faces.push_back(Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
		        }
		}
    for(size_t i = 0;i < faces.size();i++)
	    {
	        Rect r = faces[i];
	        Mat smallImgROI;
	        vector<Rect> nestedObjects;
	        Point center;
	        Scalar color = colors[i%8];
	        int radius;
	
	        double aspect_ratio = (double)r.width/r.height;
	        if(0.75 < aspect_ratio && aspect_ratio < 1.3)
		        {
		            center.x = cvRound((r.x + r.width * 0.5) * scale);
		            center.y = cvRound((r.y + r.height * 0.5) * scale);
		            radius = cvRound((r.width + r.height) * 0.25 * scale);
		            circle(img, center, radius, color, 3, 8, 0);
		        }
	        else
	            rectangle(img, Point(cvRound(r.x*scale), cvRound(r.y*scale)),Point(cvRound((r.x + r.width-1)*scale), cvRound((r.y + r.height-1)*scale)),color, 3, 8, 0);

	        const int half_height = cvRound((float)r.height/2);
	        r.y = r.y + half_height;
	        r.height = half_height - 1;
	        smallImgROI = smallImg(r);
	        nestedCascade.detectMultiScale(smallImgROI, nestedObjects,1.1, 0, 0|CASCADE_SCALE_IMAGE,Size(30, 30));
	
	        const int smile_neighbors = (int)nestedObjects.size();
	        static int max_neighbors = -1;
	        static int min_neighbors = -1;
	        if (min_neighbors == -1) min_neighbors = smile_neighbors;
		        max_neighbors = MAX(max_neighbors, smile_neighbors);

	        // Draw rectangle on the left side of the image reflecting smile intensity
	        float intensityZeroOne = ((float)smile_neighbors - min_neighbors) / (max_neighbors - min_neighbors + 1);
	        int rect_height = cvRound((float)img.rows * intensityZeroOne);
	        Scalar col = Scalar((float)255 * intensityZeroOne, 0, 0);
	        rectangle(img, Point(0, img.rows), Point(img.cols/10, img.rows - rect_height), col, -1);
			pubcheck = rect_height;
		}
    imshow( "result", img );
}

void check()
{
	for(;;)
		{
			while(pubcheck > 200)
				{
					system("cls");
					cout << "happy" << endl;
				}
			
		}
}

void emot_reg()
{
	boost::thread tu{&check};
    VideoCapture capture;
    Mat frame, image;
    string inputName;
    bool tryflip;
    CascadeClassifier cascade, nestedCascade;
    double scale;
    cascadeName = "data/haarcascade_frontalface_alt.xml";
    nestedCascadeName = "data/haarcascade_smile.xml";
    tryflip = false;
    inputName = "0";
    scale = 2.5;
	
    if(!cascade.load(cascadeName))
		{
		    cerr << "ERROR: Could not load face cascade" << endl;
		    return -1;
		}
    if(!nestedCascade.load( nestedCascadeName))
		{
		    cerr << "ERROR: Could not load smile cascade" << endl;
		    return -1;
		}
    if(inputName.empty() || (isdigit(inputName[0]) && inputName.size() == 1))
		{
		    int c = inputName.empty() ? 0 : inputName[0] - '0' ;
		    if(!capture.open(c))
		        cout << "Capture from camera #" <<  c << " didn't work" << endl;
		}
    else if(inputName.size())
		{
		    if(!capture.open(inputName))
		        cout << "Could not read " << inputName << endl;
		}

    if(capture.isOpened())
		{
		    for(;;)
			    {
			        capture >> frame;
			        if(frame.empty())
			            break;
			        Mat frame1 = frame.clone();
			        detectAndDraw( frame1, cascade, nestedCascade, scale, tryflip );
			        char c = (char)waitKey(10);
			        if(c == 27 || c == 'q' || c == 'Q')
			            break;
			    }
			}
	else
		{
		    cerr << "ERROR: Could not initiate capture" << endl;
		    return -1;
		}
}
