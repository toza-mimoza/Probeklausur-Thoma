#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_
#include "Form.h"
class Rectangle: public Form
{
private:
	double width, height; 

public:
	Rectangle() 
	{
		Form();
		this->box.SetXMax(0.0);
		this->box.SetXMin(0.0);
		this->box.SetYMax(0.0);
		this->box.SetYMin(0.0);

	}
	Rectangle(double h, double w):height{h},width{w}{}
	//MOVE FOR RECT
	void Move(double dX, double dY); 
	void SetUpBox();
private:
	void MoveBox(double dX = 0, double dY = 0);
	
};



#endif // !_RECTANGLE_H_
