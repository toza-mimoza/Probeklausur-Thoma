#include "Rectangle.h"

void Rectangle::Move(double dX, double dY)
{
	Form::Move(dX, dY);
	MoveBox(dX, dY);
}

void Rectangle::MoveBox(double dX, double dY)
{
	this->box.SetXMax(box.GetXMax()+dX);

	this->box.SetXMin(box.GetXMin()+dX);

	this->box.SetYMax(box.GetYMax()+dY);

	this->box.SetYMin(box.GetYMin()+dY);
}

void Rectangle::SetUpBox()
{

	this->box.SetXMax(width / 2);

	this->box.SetXMin(-width / 2);

	this->box.SetYMax(height / 2);

	this->box.SetYMin(-height / 2);
}
