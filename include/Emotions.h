#ifndef EMOTIONS
#define EMOTIONS
	#include<opencv2/core/core.hpp>
	#include<opencv2/opencv.hpp>
	#include<opencv2/objdetect.hpp>
	#include<opencv2/highgui.hpp>
	#include<opencv2/imgproc.hpp>

	//Main Reg Function
	void emot_reg();
	//The Function that sets the main flags
	void check();
	//The function to outline the face
	void detectAndDraw(cv::Mat& img, cv::CascadeClassifier& cascade,cv::CascadeClassifier& nestedCascade,double scale, bool tryflip);
#endif