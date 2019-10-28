#include "eBook.h"
#include <iostream>
using namespace std;
void EBook::SetTitle(string title)
{
	if (title!="")
	{
		this->title = title;
	}
	else
	{
		cout << "Title not set!" << endl;
	}
}

string EBook::GetTitle() const
{
	return this->title;
}

void EBook::SetContent(string content)
{
	if (content != "")
	{
		this->content = content;
	}
	else
	{
		cout << "Content not set!" << endl;
	}
}

string EBook::GetContent() const
{
	return this->content;
}

void EBook::print()
{
	cout << "Title: " << this->title << '\n';
	cout << "Content: " << '\n' <<this->content << '\n';

}

ostream & operator<<(ostream & output, const EBook & book)
{
	output << "Title: " << book.title << '\n' << "Content: " << book.content << '\n';
	//or alternatively 

	//output<<book.print()<<'\n';
	return output;
}
