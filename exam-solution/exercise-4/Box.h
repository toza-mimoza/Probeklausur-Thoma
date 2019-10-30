#ifndef _BOX_H_
#define _BOX_H_
class Box
{
private:
	double xMin, xMax, yMin, yMax;
public:
	
	Box():xMin{ 0.0 }, xMax{ 0.0 }, yMin{ 0.0 }, yMax{ 0.0 }{}
	double GetXMin() const { return xMin; }
	double GetXMax() const { return xMax; }
	double GetYMin() const { return yMin; }
	double GetYMax() const { return yMax; }
	void SetXMax(double val);
	void SetXMin(double val);
	void SetYMin(double val);
	void SetYMax(double val);
	friend Box operator+(Box left, Box right);
	void print(); 
};

#endif // !_BOX_H_