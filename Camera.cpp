//
// Created by enrico on 26/03/16.
//

#include "Camera.h"
#include <fstream>
#include <iostream>

void readMatrix(float matrix[3][3], ifstream &input) {
	char delimiter;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			input >> matrix[i][j];
			input >> delimiter; //column/row delimiter, if end of row is row delimiter. 1, 2, 3, 4;
		}

}

void readVector(float *vector, int nRows, ifstream &input) {
	char delimiter;
	for (int j = 0; j < nRows; j++) {
		input >> vector[j];
		input >> delimiter; //row delimiter, if end of row is row delimiter. 1, 2, 3, 4;
	}
}

Camera::Camera(string confFilePath) {
	ifstream file;
	file.open(confFilePath, ifstream::in);

	if (!file.is_open()) {
		cout << "ERROR: can not open the file: " << confFilePath << "\n";
		exit(1);
	}

	string parameterName;
	file >> parameterName;

	if (parameterName.compare("Cov_px") == 0)
		readVector(variance, 2, file);
	else if (parameterName.compare("car2img.R") == 0)
		readMatrix(car2img.R, file);
	else if (parameterName.compare("car2img.T") == 0)
		readVector(car2img.T, 3, file);
	else if (parameterName.compare("img2car.R") == 0)
		readMatrix(img2car.R, file);
	else if (parameterName.compare("img2car.T") == 0)
		readVector(img2car.T, 3, file);
	else if (parameterName.compare("m_bordo") == 0)
		file >> this->resize_m;
	else if (parameterName.compare("q_bordo") == 0)
		file >> this->resize_q;

	this->maxRow = MAX_ROW;
	this->moveSelectionParameters.dx = -1;
	this->moveSelectionParameters.leftMove = 0;
	this->moveSelectionParameters.rightMove = 0;
	this->moveSelectionParameters.selectionDimension = 120;
	this->moveSelectionParameters.pStart[0] = 0;
	this->moveSelectionParameters.pStart[1] = 0;
	file.close();
}

void Camera::projectImg2Car(const Pixel imgPoint, CarPlanePoint carPoint) {
	//rotate imgPoint, z = 1.
	carPoint[0] = img2car.R[0][0] * imgPoint[0] + img2car.R[0][1] * imgPoint[1] + img2car.R[0][2] * 1;
	carPoint[1] = img2car.R[1][0] * imgPoint[0] + img2car.R[1][1] * imgPoint[1] + img2car.R[1][2] * 1;
	float aux = img2car.R[2][0] * imgPoint[0] + img2car.R[2][1] * imgPoint[1] + img2car.R[2][2] * 1;

	float scale = -img2car.T[2] / aux;
	//translate.
	carPoint[0] = scale * carPoint[0] + img2car.T[0];
	carPoint[1] = scale * carPoint[1] + img2car.T[1];
}

void Camera::projectCar2Img(const CarPlanePoint carPoint, Pixel imgPoint) {
	//rotate and translate.
	imgPoint[0] = car2img.R[0][0] * carPoint[0] + car2img.R[0][1] * carPoint[1] + car2img.R[0][2] * 1 + car2img.T[0];
	imgPoint[1] = car2img.R[1][0] * carPoint[0] + car2img.R[1][1] * carPoint[1] + car2img.R[1][2] * 1 + car2img.T[1];
	float aux = car2img.R[2][0] * carPoint[0] + car2img.R[2][1] * carPoint[1] + car2img.R[2][2] * 1 + car2img.T[2];
	//scale.
	imgPoint[0] = imgPoint[0] / aux;
	imgPoint[1] = imgPoint[1] / aux;
}




