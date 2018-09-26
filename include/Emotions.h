#ifndef EMOTIONS
#define EMOTIONS
	//Main Reg Function
	void emot_reg();
	//The Function that sets the main flags
	void check();
	//The function to outline the face
	void detectAndDraw(Mat& img, CascadeClassifier& cascade,CascadeClassifier& nestedCascade,double scale, bool tryflip);
#endif