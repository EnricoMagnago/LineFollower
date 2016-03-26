//
// Created by enrico on 25/03/16.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "MoveFirstSelection.h"


using namespace cv;
using namespace std;


int main() {
	char imagePath[100] = "/home/valerio/Desktop/FrontCam/LineFollower/Data/1/frame05.jpg";
	Mat1b image;
	image = imread(imagePath, CV_LOAD_IMAGE_GRAYSCALE);
	if (!image.data) {
		cout << "No image data" << endl;
		return -1;
	}

	// Display image
	namedWindow("Image grayScale", WINDOW_AUTOSIZE);
	imshow("Image grayScale", image);

	Canny(image, image, 90, 90 * 3, 3);


	// Display image
	namedWindow("canny filter", WINDOW_AUTOSIZE);
	imshow("canny filter", image);

	Pixel start;
	start[0] = 432;
	start[1] = 420;


	waitKey(0);

	return 0;
}