//
// Created by valerio on 26/03/16.
//

#ifndef LINEFOLLOWER_MOVEFIRSTSELECTION_H
#define LINEFOLLOWER_MOVEFIRSTSELECTION_H

#include "Common.h"

/*
 * This class is generated to move the selection on the edges of the immage.
 * The function getNextArea give back the corners of the selection
 */
class MoveFirstSelection {
	int dx;
	int rightMove;
	int leftMove;
	const int selectionDimension;
	const float resize_m;
	const float resize_q;
	const int maxRow;
	const int maxColumn;
	Pixel pStart;

	// Init to default values.
	MoveFirstSelection();

	// Set the starting point.
	void setStartPoint(Pixel _pStart);


};


#endif //LINEFOLLOWER_MOVEFIRSTSELECTION_H
