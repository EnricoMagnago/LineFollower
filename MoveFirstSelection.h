//
// Created by valerio on 26/03/16.
//

#ifndef LINEFOLLOWER_MOVEFIRSTSELECTION_H
#define LINEFOLLOWER_MOVEFIRSTSELECTION_H

#include "Pixel.h"

/*
 * This class is generated to move the selection on the edges of the immage.
 * The function getNextAera give back the corners of the selection
 */
class MoveFirstSelection {
	int dx;
	int rightMove;
	int leftMove;
	const int selectionDimension;
	const int resize_m;
	const int resize_q;
	const int maxRow;
	const int maxColumn;

	// Default Initializator
	MoveFirstSelection();

	// Inizializator with a start point
	MoveFirstSelection(Pixel pStart);


};


#endif //LINEFOLLOWER_MOVEFIRSTSELECTION_H
