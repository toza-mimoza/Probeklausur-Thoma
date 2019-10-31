#ifndef _EBOOK_H_
#define _EBOOK_H_

#include <string>
#include <iostream>

using namespace std;

class EBook {
private:
	string title, content; 
public:
	EBook();
	EBook(string title, string content);
	void setTitle(string title);
	string getTitle() const;
	void setContent(string content);
	string getContent() const;
	void print() const;
	friend ostream &operator<<(ostream &output, const EBook &book);
};

#endif
