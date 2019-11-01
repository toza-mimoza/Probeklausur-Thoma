#include "Rectangle.h"

Rectangle::Rectangle() : width(0.0), height(0.0) {
	Form();
	this->box.setXMax(0.0);
	this->box.setXMin(0.0);
	this->box.setYMax(0.0);
	this->box.setYMin(0.0);
}

Rectangle::Rectangle(double h, double w) : width(w), height(h) {

}

void Rectangle::move(double dX, double dY)
{
	Form::move(dX, dY);
	moveBox(dX, dY);
}

void Rectangle::moveBox(double dX, double dY) {
	this->box.setXMax(box.getXMax()+dX);
	this->box.setXMin(box.getXMin()+dX);
	this->box.setYMax(box.getYMax()+dY);
	this->box.setYMin(box.getYMin()+dY);
}

void Rectangle::initBox() {
	this->box.setXMax(width / 2);
	this->box.setXMin(-width / 2);
	this->box.setYMax(height / 2);
	this->box.setYMin(-height / 2);
}
