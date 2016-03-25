//
// Created by enrico on 25/03/16.
//

#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;
using namespace std;

int main() {
	char imagePath[30] = "Data/1/frame1.jpg";
	Mat1b image;
	image = imread(imagePath, CV_LOAD_IMAGE_GRAYSCALE);

	Canny(image, image, 90, 90 * 3, 3);

	namedWindow("Display window", WINDOW_AUTOSIZE);
	imshow("Display window", image);

	waitKey(0);

	return 0;
}