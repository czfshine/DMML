// NatureNetwork.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include <opencv2/core.hpp>
#include <opencv2/imgcodecs.hpp>
#include <opencv2/highgui.hpp>
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
int main()
{
	Mat  M(2, 2, CV_8UC3, Scalar(0, 0, 255));
	cout << M << endl;
	getchar();
    return 0;
}

