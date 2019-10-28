#include <iostream>
#include <string>
#include "Circle.h"
#include "Rectangle.h"
using namespace std; 
bool InputIsCircle(string); //checks if the user typed 'circle', returns bool
bool InputIsRect(string);	//checks if the user typed 'rectangle', returns bool
Circle* CircleCreator(bool isTrue); //asks for needed values and calls circle constructor
Rectangle* RectCreator(bool isTrue);//asks for needed values and calls rectangle constructor
Circle* CleanCircles(Circle* circle1, Circle* circle2);	//cleans pointers that are not needed after the prompt
Rectangle* CleanRectangles(Rectangle* rect1, Rectangle* rect2);

int main() {

	double movX, movY;	//arguments for Move(...) function
	
	string prompt="";
	
	std::cout << "_______________________________________" << endl; 

	Circle *circle1=NULL;
	Rectangle *rect1=NULL;

	cout << "Enter first form (rectangle or circle): ";
	cin >> prompt;
	
	if (InputIsCircle(prompt))
	{
		circle1 = CircleCreator(InputIsCircle(prompt));
		circle1->GetBoxRef().print();

		cout << "Move Circle in X direction for: ";
		cin >> movX;
		cout << "Move Circle in Y direction for: ";
		cin >> movY;
		
		circle1->Move(movX, movY);
		cout << "After Move is called: " << endl;
		circle1->GetBoxRef().print();

	}
	else if (InputIsRect(prompt))
	{
		rect1 = RectCreator(InputIsRect(prompt));
		rect1->GetBoxRef().print();

		cout << "Move Rectangle in X direction for: ";
		cin >> movX;
		cout << "Move Rectangle in Y direction for: ";
		cin >> movY;
		
		rect1->Move(movX, movY);
		cout << "After Move is called: " << endl;
		rect1->GetBoxRef().print();
	}
	
	Circle *circle2 = NULL;
	Rectangle *rect2 = NULL;
	cout << "Enter second form (rectangle or circle): ";
	cin >> prompt;
	if (InputIsCircle(prompt))
	{
		circle2 = CircleCreator(InputIsCircle(prompt));
		circle2->GetBoxRef().print();

		cout << "Move Circle in X direction for: ";
		cin >> movX;
		cout << "Move Circle in Y direction for: ";
		cin >> movY;

		circle2->Move(movX, movY);
		cout << "After Move is called: " << endl;
		circle2->GetBoxRef().print();

	}
	else if (InputIsRect(prompt))
	{
		rect2 = RectCreator(InputIsRect(prompt));
		rect2->GetBoxRef().print();

		cout << "Move Rectangle in X direction for: ";
		cin >> movX;
		cout << "Move Rectangle in Y direction for: ";
		cin >> movY;

		rect2->Move(movX, movY);
		cout << "After Move is called: " << endl;
		rect2->GetBoxRef().print();

	}
	
	

	//ADD BOUNDING BOXES AND PRODUCE NEW ONE AS SUM

	Circle* circle = CleanCircles(circle1, circle2);
	Rectangle* rect = CleanRectangles(rect1, rect2);

	Box boundingBox = circle->GetBoxRef() + rect->GetBoxRef();
	cout << "Bounding Box: " << endl; 
	boundingBox.print();
	cout << "_______________________________________" << endl;

	delete circle, rect; 

	return 0; 
}
Circle* CleanCircles(Circle* circle1, Circle* circle2)
{
	if (circle1 == NULL)
	{
		delete circle1;
	}
	else
	{
		Circle*& circle = circle1;
		return circle; 
	}
	if (circle2 == NULL)
	{
		delete circle2;
	}
	else
	{
		Circle*& circle = circle2;
		return circle;
	}
	
}
Rectangle* CleanRectangles(Rectangle* rect1, Rectangle* rect2) 
{
	if (rect1 == NULL)
	{
		delete rect1;
	}
	else
	{
		Rectangle*& rect = rect1;
		return rect;
	}
	if (rect2 == NULL)
	{
		delete rect2;
	}
	else
	{
		Rectangle*& rect = rect2;
		return rect;
	}
}
bool InputIsCircle(string prompt)  {
	string circle = "circle";
	bool result = false; 
	if (prompt.compare(circle) == 0)
	{
		result = true; 
		
	}
	else
	{
		return result; 
	}
}
bool InputIsRect(string prompt) {
	string rect = "rectangle";
	bool result = false;
	if (prompt.compare(rect) == 0)
	{
		result = true; 
		
	}
	else
	{
		return result;
	}
}
Circle* CircleCreator(bool isTrue) {
	if (isTrue)
	{
		double rad;
		
		cout << "Enter radius: ";
		cin >> rad;
		Circle *circle=new Circle(rad);
		circle->SetUpBox();
		return circle;
	}
	else
	{
		return NULL; 
	}

}
Rectangle* RectCreator(bool isTrue) {
	if (isTrue)
	{
		double h, w;
		cout << "Enter height: ";
		cin >> h;
		cout << "Enter width: ";
		cin >> w;
		Rectangle *rect=new Rectangle(h, w);
		rect->SetUpBox();
		return rect; 
	}
	else
	{
		return NULL;
	}
}
