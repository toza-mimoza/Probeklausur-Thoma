#ifndef _FORM_H_
#define _FORM_H_

#include "Box.h"

class Form {
private:
	double xCenter, yCenter;  
protected:	
	Box box; 
	
public:
	Form();
	void move(double dX, double dY);
	Box &getBoxRef();
};

#endif
