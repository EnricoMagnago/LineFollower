//
// Created by enrico on 26/03/16.
//

#include "Camera.h"
/*
Camera::Camera(string confFilePath){
	//TODO: read the configuration from file at confFilePath.

}*/

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




