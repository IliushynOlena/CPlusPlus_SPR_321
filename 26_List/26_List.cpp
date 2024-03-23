#include <iostream>
#include <list>
#include <iomanip>
using namespace std;

void ShowList(list<int> l1, list<int> l2)
{
	list<int>::iterator iter;
	cout << "List 1 : ";
	for (iter = l1.begin(); iter != l1.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;
	cout << "List 2 : ";
	for (iter = l2.begin(); iter != l2.end(); ++iter)
	{
		cout << *iter << " ";
	}
	cout << endl;

}


struct Book
{
	string name;
	string author;
	int pages;
};
bool CompareBookByName(const Book& book1, const Book& book2)
{
	return book1.name < book2.name;
}
bool CompareBookByAuthor(const Book& book1, const Book& book2)
{
	return book1.author < book2.author;
}
bool CompareBookByPages(const Book& book1, const Book& book2)
{
	return book1.pages < book2.pages;
}

int main()
{
	list<Book> library;
	library.assign(
		{
		Book{"Night", "Gogol", 786},
		Book{"Maria", "Kotliarevsruy", 400},
		Book{"Harry Potter", "Royling", 800}
		}
	);
	cout << "--------------------- Original list ----------------" << endl;
	for ( Book b : library)
	{
		cout << setw(15)<< left <<  b.name << setw(15) << b.author << setw(7) << b.pages << endl;
		//cout <<   b.name <<" " << b.author << " " << b.pages << endl;
	}

	cout << "--------------------- Sorted list by name ----------------" << endl;
	library.sort(CompareBookByName);

	for (Book b : library)
	{
		cout << setw(15) << left << b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}
	cout << "--------------------- Sorted list by author ----------------" << endl;
	library.sort(CompareBookByAuthor);
	for (Book b : library)
	{
		cout << setw(15) << left << b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}
	cout << "--------------------- Sorted list by pages ----------------" << endl;
	library.sort(CompareBookByPages);

	for (Book b : library)
	{
		cout << setw(15) << left << b.name << setw(15) << b.author << setw(7) << b.pages << endl;
	}



 //   list<int> l1, l2;

	//for (int i = 0; i < 10; i++)
	//{
	//	l1.push_back(i);
	//	l2.push_front(i);
	//}
	//ShowList(l1, l2);

	//l1.assign({ 1,2,3,4,5,6,77 });
	//ShowList(l1, l2);

	//cout << "First element : " << l1.front()  << endl;
	//auto iter = l1.begin();
	//iter++;
	//cout << "Second element : " << *iter  << endl;


	//l1.erase(l1.begin());
	//ShowList(l1, l2);
	//iter = l1.end();
	//iter--;
	//l1.erase(iter);
	//ShowList(l1, l2);
	//cout << "***************************" << endl;
	//l1.push_back(2);
	//l1.push_back(2);
	//l1.push_back(2);
	//ShowList(l1, l2);

	//l1.remove(2);
	//ShowList(l1, l2);

	//l1.insert(l1.begin(), 9);
	//ShowList(l1, l2);
	//l1.insert(l1.end(), { 10,20,30 });
	//ShowList(l1, l2);

	//l1.insert(l1.begin(), l2.begin(), l2.end());
	//ShowList(l1, l2);

	//l1.insert(l1.end(), 5, 77);
	//ShowList(l1, l2);


	//cout << "Size : " << l1.size() << endl;

	////l1.resize(40);
	//l1.resize(40, 5);
	//ShowList(l1, l2);
	//cout << "Size : " << l1.size() << endl;

	//l1.push_back(22);
	//ShowList(l1, l2);

	//l1.splice(l1.end(), l2, l2.begin());
	//ShowList(l1, l2);

	//l1.reverse();
	//ShowList(l1, l2);

	//l1.sort();
	//l2.sort();
	//ShowList(l1, l2);

	//l1.merge(l2);
	//ShowList(l1, l2);

	//l1.unique();
	//ShowList(l1, l2);

	//l1.swap(l2);
	//ShowList(l1, l2);


}

