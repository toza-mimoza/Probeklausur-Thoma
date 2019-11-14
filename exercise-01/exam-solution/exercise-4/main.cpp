#include <iostream>
#include <string>
#include "Circle.h"
#include "Rectangle.h"

using namespace std; 

//checks if the user typed 'circle', returns bool
bool inputIsCircle(string);

//checks if the user typed 'rectangle', returns bool
bool inputIsRect(string);

//asks for needed values and calls circle constructor
Circle* circleCreator(bool isTrue);

//asks for needed values and calls rectangle constructor
Rectangle* rectCreator(bool isTrue);
Box addBoxes(Circle* c1, Circle* c2, Rectangle* r1, Rectangle* r2); 

int main() {

	//arguments for move(...) function
	double movX, movY;

	string prompt = "";

	std::cout << "_______________________________________" << endl; 

	Circle *circle1 = NULL;
	Rectangle *rect1 = NULL;

	cout << "Enter first form (rectangle or circle): ";
	cin >> prompt;

	if (inputIsCircle(prompt)) {
		circle1 = circleCreator(inputIsCircle(prompt));
		circle1->getBoxRef().print();

		cout << "Move Circle in X direction for: ";
		cin >> movX;
		cout << "Move Circle in Y direction for: ";
		cin >> movY;

		circle1->move(movX, movY);
		cout << "After Move is called: " << endl;
		circle1->getBoxRef().print();
	} else if (inputIsRect(prompt))	{
		rect1 = rectCreator(inputIsRect(prompt));
		rect1->getBoxRef().print();

		cout << "Move Rectangle in X direction for: ";
		cin >> movX;
		cout << "Move Rectangle in Y direction for: ";
		cin >> movY;

		rect1->move(movX, movY);
		cout << "After Move is called: " << endl;
		rect1->getBoxRef().print();
	}

	Circle *circle2 = NULL;
	Rectangle *rect2 = NULL;
	cout << "Enter second form (rectangle or circle): ";
	cin >> prompt;
	if (inputIsCircle(prompt)) {
		circle2 = circleCreator(inputIsCircle(prompt));
		circle2->getBoxRef().print();

		cout << "Move Circle in X direction for: ";
		cin >> movX;
		cout << "Move Circle in Y direction for: ";
		cin >> movY;

		circle2->move(movX, movY);
		cout << "After Move is called: " << endl;
		circle2->getBoxRef().print();
	} else if (inputIsRect(prompt)) {
		rect2 = rectCreator(inputIsRect(prompt));
		rect2->getBoxRef().print();

		cout << "Move Rectangle in X direction for: ";
		cin >> movX;
		cout << "Move Rectangle in Y direction for: ";
		cin >> movY;

		rect2->move(movX, movY);
		cout << "After Move is called: " << endl;
		rect2->getBoxRef().print();
	}

	//ADD BOUNDING BOXES AND PRODUCE NEW ONE AS SUM
	Box boundingBox;

	cout << "Bounding Box: " << endl;
	boundingBox = addBoxes(circle1, circle2, rect1, rect2);
	if (!(boundingBox.getXMax() == 0.0 && boundingBox.getXMin() == 0.0 && boundingBox.getYMin() == 0.0 && boundingBox.getYMax() == 0.0)) {
		boundingBox.print();
	}

	cout << "_______________________________________" << endl;

	delete circle1, rect1, circle2, rect2;

	return 0; 
}

Box addBoxes(Circle* c1, Circle* c2, Rectangle* r1, Rectangle* r2) {

	Box result;
	if (c1 == NULL && c2 == NULL) {
		result = r1->getBoxRef() + r2->getBoxRef();
		return result;
	} else if (c1 == NULL && r2 == NULL) {
		result = r1->getBoxRef()+ c2->getBoxRef();
		return result;
	} else if (r1 == NULL && c2 == NULL) {
		result = c1->getBoxRef()+ r2->getBoxRef();
		return result;
	} else if (r1 == NULL && r2 == NULL) {
		result = c1->getBoxRef() + c2->getBoxRef();
		return result;
	}

	return result;
}

bool inputIsCircle(string prompt) {
	string circle = "circle";
	bool result = false; 
	if (prompt.compare(circle) == 0) {
		result = true;
	} else {
		return result; 
	}
	return result;
}

bool inputIsRect(string prompt) {
	string rect = "rectangle";
	bool result = false;
	if (prompt.compare(rect) == 0) {
		result = true; 
	} else {
		return result;
	}

	return result;
}

Circle* circleCreator(bool isTrue) {
	if (isTrue) {
		double rad;

		cout << "Enter radius: ";
		cin >> rad;
		Circle *circle = new Circle(rad);
		circle->initBox();
		return circle;
	} else {
		return NULL; 
	}
}

Rectangle* rectCreator(bool isTrue) {
	if (isTrue) {
		double h, w;
		cout << "Enter height: ";
		cin >> h;
		cout << "Enter width: ";
		cin >> w;
		Rectangle *rect = new Rectangle(h, w);
		rect->initBox();
		return rect; 
	} else {
		return NULL;
	}
}
