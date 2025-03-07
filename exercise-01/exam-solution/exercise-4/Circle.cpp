#include "Circle.h"

Circle::Circle() : radius(0.0) {
	
}

Circle::Circle(double rad) : radius(rad) {

}

void Circle::initBox() {
	this->box.setXMax(this->radius);
	this->box.setXMin(-this->radius);
	this->box.setYMax(this->radius);
	this->box.setYMin(-this->radius);
}

void Circle::move(double dX, double dY) {
	Form::move(dX, dY);
	moveBox(dX, dY);
}

void Circle::moveBox(double dX, double dY) {
	this->box.setXMax(box.getXMax() + dX);
	this->box.setXMin(box.getXMin() + dX);
	this->box.setYMax(box.getYMax() + dY);
	this->box.setYMin(box.getYMin() + dY);
}
