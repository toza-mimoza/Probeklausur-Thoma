#include "eBook.h"
#include <iostream>

using namespace std;

EBook::EBook() : title(""), content("") {};

EBook::EBook(string title, string content) : title(title), content(content) {};

void EBook::setTitle(string title) {
	if (title != "") {
		this->title = title;
	} else {
		cout << "Title not set!" << endl;
	}
}

string EBook::getTitle() const {
	return this->title;
}

void EBook::setContent(string content) {
	if (content != "") {
		this->content = content;
	} else {
		cout << "Content not set!" << endl;
	}
}

string EBook::getContent() const {
	return this->content;
}

void EBook::print() const {
	cout << "Title: " << this->title << '\n';
	cout << "Content: " << this->content << '\n';
}

ostream & operator<<(ostream &output, const EBook &book) {
	book.print();
	return output;
}
