//
// Created by valerio on 25/03/16.
//

#ifndef LINEFOLLOWER_PIXEL_H
#define LINEFOLLOWER_PIXEL_H


class Pixel {
private:
	int x, y;
public:
	// Init default
	Pixel();

	// Init with 2 values
	Pixel(int _x, int _y);

	// Set value of X and Y
	void setX(int _x);
	void setY(int _y);

	// Get X and Y
	int getX();
	int getY();
};


#endif //LINEFOLLOWER_PIXEL_H
