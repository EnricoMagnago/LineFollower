//
// Created by enrico on 26/03/16.
//

#ifndef LINEFOLLOWER_CAMERA_H
#define LINEFOLLOWER_CAMERA_H

#include <string>
#include "Common.h"

using namespace std;

class Camera {
private:
	struct RotoTraslation {
		const float R[3][3];
		const float T[3];
	};
	const float intrinsicMatrix[3][3];
	const float rotationMatrix[3][3];
	const float tralationVector[3];
	const float focalLengthVector[2];
	const float covarianceMatrix[2][2];
	const float mapx[MAX_ROW][MAX_COLUMN];
	const RotoTraslation car2img;
	const RotoTraslation img2car;
	const float resize_m;
	const float resize_q;

public:
	//loads configuration from the specified file.
	Camera(string confFilePath);

	//projects Pixel from picture in CarPlanePoint.
	void projectImg2Car(const Pixel imgPoint, CarPlanePoint carPoint);

	//projects CarPlanePoint from picture in Pixel.
	void projectCar2Img(const CarPlanePoint carPoint, Pixel imgPoint);

};


#endif //LINEFOLLOWER_CAMERA_H
