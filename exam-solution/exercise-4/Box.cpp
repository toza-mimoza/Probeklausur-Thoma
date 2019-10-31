#include "Box.h"
#include <iostream>
#include <algorithm>

using namespace std;

Box::Box() : xMin(0.0), xMax(0.0), yMin(0.0), yMax(0.0) {

}

double Box::getXMin() const {
	return xMin;
}

void Box::setXMax(double val) {
	this->xMax = val;
}

double Box::getXMax() const {
	return xMax;
}

void Box::setXMin(double val) {
	this->xMin = val; 
}

double Box::getYMin() const {
	return yMin;
}

void Box::setYMin(double val) {
	this->yMin = val;
}

double Box::getYMax() const {
	return yMax;
}

void Box::setYMax(double val) {
	this->yMax = val; 
}

void Box::print() const {
	cout << "xMax: " << xMax << endl; 
	cout << "xMin: " << xMin << endl;
	cout << "yMax: " << yMax << endl;
	cout << "yMin: " << yMin << endl;
}

Box operator+(Box left, Box right) {
	Box newLeft, newRight;
	if (left.getXMax() > right.getXMax()) {
		newLeft = right;
		newRight = left;
	} else {
		newLeft = left;
		newRight = right;
	}

	Box result; 

	//check if the boxes collide
	if (right.getXMin() < left.getXMax() && right.getYMin() < left.getYMax()) {
		result.setXMin(min(newLeft.getXMin(), newRight.getXMin()));
		result.setXMax(max(newLeft.getXMax(), newRight.getXMax()));
		result.setYMin(min(newLeft.getYMin(), newRight.getYMin()));
		result.setYMax(max(newLeft.getYMax(), newRight.getYMax()));
		return result;
	} else {
		cout << "The boxes of these two objects don't collide." << '\n';
	}
	 
}
