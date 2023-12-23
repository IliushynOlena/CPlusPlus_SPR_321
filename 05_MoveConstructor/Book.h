#pragma once
#include <iostream>
using namespace std;

//const int History = 1;
//const int Drama = 2;
//const int Horror = 3;
//const int Adventure = 4;
//const int Roman = 5;
//const int Science = 6;

enum Genre{ None, History, Drama, Horror, Adventure, Roman, Science, Fantasy, Detective
};


class Book
{
private:
	string title;
	string author;
	int year;
	int pages;
	Genre genre;//22
public:
	Book();
	Book(string t, string a, int y, int p, Genre g):author(a),
		pages(p),year(y),title(t),genre(g){}
	void ShowInfo()const;
};

