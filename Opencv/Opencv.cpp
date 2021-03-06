// Opencv.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;


float xd[] = { 0,0,1,0,1,1,1,0,1,1,1,1 };
float yd[] = { 0,1,1,1 };

Mat  X(4, 3, CV_32FC1, xd);
Mat  Y(4, 1, CV_32FC1, yd);

Mat W(3, 1, CV_32FC1);


Mat sigmod(Mat I) {

	auto a= I.begin<float>();
	auto end = I.end<float>();

	for (; a != end; a++) {
		*a = 1.0f / (1.0f + exp(-(*a)));
	}
	return I;
}

Mat predict() {
	return sigmod(X*W);
}


Mat Dsigmod(Mat I) {
	auto a = I.begin<float>();
	auto end = I.end<float>();

	for (; a != end; a++) {
		
		*a = (1.0f / (1.0f + exp(-(*a)))) * (1 - (1.0f / (1.0f + exp(-(*a)))));
	}
	return I;
}
void sept() {
	Mat Y_ = predict();
	Mat e_ = Y - Y_;
	Mat D_W = e_.mul(Dsigmod(Y_));
	W = W + X.t()*D_W;
}
int main(int argc, char** argv)
{	
	RNG rng;
	rng.fill(W, RNG::UNIFORM,0,1);
	cout << W << endl;
	
	for (int i = 0; i < 1000000; i++) {
		sept();
	}
	cout << W << endl;
	cout << predict()<< endl;
	getchar();
	waitKey(0); // Wait for a keystroke in the window
	return 0;
}