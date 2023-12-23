#include "Book.h"

Book::Book()
{
	author = "no author";
	pages = 0;
	year = 0;
	title = "no title";
	genre = None;
}

void Book::ShowInfo() const {
	cout << "Author : " << author << endl;
	cout << "Pages : " << pages << endl;
	cout << "Year : " << year << endl;
	cout << "Title : " << title << endl;
	cout << "Genre : " << " ";
	switch (genre)
	{
	case None:cout << "None" << endl; break;
	case History:cout << "History" << endl;	break;
	case Drama:cout << "Drama" << endl;	break;
	case Horror:cout << "Horror" << endl; break;
	case Adventure:cout << "Adventure" << endl;	break;
	case Roman:cout << "Roman" << endl;	break;
	case Science:cout << "Science" << endl;	break;
	case Fantasy:cout << "Fantasy" << endl;	break;
	case Detective:cout << "Detective" << endl;	break;
	}
	cout << "__________________________" << endl;
}
