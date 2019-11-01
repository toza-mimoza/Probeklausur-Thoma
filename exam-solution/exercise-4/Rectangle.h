#ifndef _RECTANGLE_H_
#define _RECTANGLE_H_

#include "Form.h"

class Rectangle: public Form {
private:
	double width, height; 

public:
	Rectangle();
	Rectangle(double h, double w);
	void move(double dX, double dY);
	void initBox();
private:
	void moveBox(double dX = 0, double dY = 0);
	
};

#endif
