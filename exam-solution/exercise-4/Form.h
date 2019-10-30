#ifndef _FORM_H_
#define _FORM_H_
#include "Box.h"
class Form
{
private:
	double xCenter, yCenter;  
protected:	
	Box box; 
	
public:
	Form()
	{
		this->xCenter = 0.0;
		this->yCenter = 0.0;
	}
	
	void Move(double dX, double dY) {
		this->xCenter += dX;
		this->yCenter += dY;
		
	}
	Box & GetBoxRef() { //how to get const ref???
		return box; 
	}
};

#endif // !_FORM_H_

