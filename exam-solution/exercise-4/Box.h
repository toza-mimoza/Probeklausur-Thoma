#ifndef _BOX_H_
#define _BOX_H_

class Box {
private:
	double xMin, xMax, yMin, yMax;
public:
	
	Box();
	double getXMin() const;
	double getXMax() const;
	double getYMin() const;
	double getYMax() const;
	void setXMax(double val);
	void setXMin(double val);
	void setYMin(double val);
	void setYMax(double val);
	friend Box operator+(Box left, Box right);
	void print() const;
};

#endif
