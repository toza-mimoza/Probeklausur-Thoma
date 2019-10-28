#include "Circle.h"

void Circle::SetUpBox()
{
	this->box.SetXMax(this->radius);

	this->box.SetXMin(-this->radius);

	this->box.SetYMax(this->radius);

	this->box.SetYMin(-this->radius);
}

void Circle::Move(double dX, double dY)
{
	Form::Move(dX, dY);
	MoveBox(dX, dY);
}

void Circle::MoveBox(double dX, double dY)
{
	this->box.SetXMax(box.GetXMax() + dX);

	this->box.SetXMin(box.GetXMin() + dX);

	this->box.SetYMax(box.GetYMax() + dY);

	this->box.SetYMin(box.GetYMin() + dY);
}

