#ifndef _CIRCLE_H_
#define _CIRLE_H_
#include "Form.h"
class Circle: public Form
{
private: 
	double radius; 
public:
	Circle() 
	{
		Form();
		this->box.SetXMax(0.0);
		this->box.SetXMin(0.0);
		this->box.SetYMax(0.0);
		this->box.SetYMin(0.0);
	}
	Circle(double rad):radius{rad}{}

	//MOVE FOR CIRCLE
	void Move(double dX, double dY);
	void SetUpBox();
private:
	void MoveBox(double dX = 0, double dY = 0);
	
};

#endif // !_CIRCLE_H_

