#include "Box.h"
#include <iostream>
#include <algorithm>
using namespace std; 

void Box::SetXMax(double val)
{
	this->xMax = val; 

}

void Box::SetXMin(double val)
{
	this->xMin = val; 

}

void Box::SetYMin(double val)
{
	this->yMin = val;
}

void Box::SetYMax(double val)
{
	this->yMax = val; 
}

void Box::print()
{
	cout << "xMax: " << xMax << endl; 
	cout << "xMin: " << xMin << endl;
	cout << "yMax: " << yMax << endl;
	cout << "yMin: " << yMin << endl;

}

Box operator+(Box left, Box right)
{
	Box result; 

	result.SetXMin(min(left.GetXMin(),right.GetXMin()));
	result.SetXMax(max(left.GetXMax(), right.GetXMax()));
	result.SetYMin(min(left.GetYMin(),right.GetYMin()));
	result.SetYMax(max(left.GetYMax(), right.GetYMax()));

	return result; 
}
