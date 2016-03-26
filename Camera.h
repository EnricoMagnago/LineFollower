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
		float R[3][3];
		float T[3];
	};

	struct MoveSelectionParameters {
		int dx;
		int rightMove;
		int leftMove;
		Pixel pStart;
		int selectionDimension;
	};

	int maxRow;
	float variance[2];
	float mapx[MAX_ROW][MAX_COLUMN];
	RotoTraslation car2img;
	RotoTraslation img2car;
	float resize_m;
	float resize_q;
	MoveSelectionParameters moveSelectionParameters;

public:
	//loads configuration from the specified file.
	Camera(string confFilePath);

	//projects Pixel from picture in CarPlanePoint.
	void projectImg2Car(const Pixel imgPoint, CarPlanePoint carPoint);

	//projects CarPlanePoint from picture in Pixel.
	void projectCar2Img(const CarPlanePoint carPoint, Pixel imgPoint);

};


#endif //LINEFOLLOWER_CAMERA_H
