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
	Box newLeft, newRight;
	if (left.GetXMax()>right.GetXMax())
	{
		newLeft = right;
		newRight = left;
	}
	else
	{
		newLeft = left;
		newRight = right;
	}
	Box result; 
	if (right.GetXMin() < left.GetXMax() && right.GetYMin() < left.GetYMax()) //check if the boxes collide 
	{
		
		result.SetXMin(min(newLeft.GetXMin(), newRight.GetXMin()));
		result.SetXMax(max(newLeft.GetXMax(), newRight.GetXMax()));
		result.SetYMin(min(newLeft.GetYMin(), newRight.GetYMin()));
		result.SetYMax(max(newLeft.GetYMax(), newRight.GetYMax()));
		return result;
	}
	else
	{
		cout << "The boxes of these two objects don't collide." << '\n';
	}
	 
}
