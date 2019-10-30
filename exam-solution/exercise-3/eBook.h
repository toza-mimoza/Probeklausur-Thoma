#ifndef _EBOOK_H_
#define _EBOOK_H_
#include <string>
#include <iostream>
using namespace std;
class EBook
{
private:
	string title, content; 
public:
	EBook() :title{ "" }, content{ "" } {};
	EBook(string title, string content) :title{ title }, content{ content }{};
	void SetTitle(string title);
	string GetTitle()const;
	void SetContent(string content);
	string GetContent()const;
	void print();
	friend ostream &operator<<(ostream &output, const EBook& book);
};


#endif // !_EBOOK_H_

