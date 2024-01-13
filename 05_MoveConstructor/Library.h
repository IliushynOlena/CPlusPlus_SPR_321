#pragma once
#include"Book.h"
class Library
{
private:
	string name;//User Library
	string address;//Soborna 16
	Book* books;//0x125HGG
	int countBooks;//5
public:
	//inline
	string getName()
	{
		return name;
	}
	Library();
	Library(string name, string address);
	Library(const Library &other);
	Library& operator =(const Library& other);
	Library(Library&& other)
	{
		name = other.name;
		address = other.address;
		countBooks = other.countBooks;
		books = other.books;
		other.books = nullptr;
	}
	void Show()const;
	void AddNewBook(Book book);
	~Library()
	{
		if (books != nullptr)
			delete[]books;
	}
};

