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
	char imagePath[30] = "/home/enrico/Pictures/sky.jpg";
	Mat1b image;
	image = imread(imagePath, CV_LOAD_IMAGE_GRAYSCALE);

	Canny(image, image, 90, 90 * 3, 3);
	if (!image.data) {
		cout << "No image data" << endl;
		return -1;
	}
	namedWindow("Display Image", WINDOW_AUTOSIZE);
	imshow("Display Image", image);

	waitKey(0);

	return 0;
}