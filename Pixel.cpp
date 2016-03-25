//
// Created by valerio on 25/03/16.
//

#include "Pixel.h"

// Init default
Pixel::Pixel() {
	this->x = 0;
	this->y = 0;
}

// Init with 2 values
Pixel::Pixel(int _x, int _y) {
	this->x = _x;
	this->y = _y;
}

// Set value of X and Y
void Pixel::setX(int _x) { x = _x; }

void Pixel::setY(int _y) { y = _y; }


// Get value of X and Y
int Pixel::getX() { return x; }

int Pixel::getY() { return y; }

