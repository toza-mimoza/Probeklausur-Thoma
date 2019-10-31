#ifndef _CIRCLE_H_
#define _CIRCLE_H_

#include "Form.h"

class Circle : public Form
{
private: 
	double radius; 
public:
	Circle();
	Circle(double rad);
	void move(double dX, double dY);
	void setUpBox();
private:
	void moveBox(double dX = 0, double dY = 0);
};

#endif
