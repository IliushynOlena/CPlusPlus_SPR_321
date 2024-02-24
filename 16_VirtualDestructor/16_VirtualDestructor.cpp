#include <iostream>
using namespace std;

class Person 
{
	//protected
private:
	string name;
	string spetialization;
	int* marks;
	int countMark;
public:
	Person():name("no name"), spetialization("none"),marks(nullptr), countMark(0) {}
	Person(string name, string spetialization):name( name),
		spetialization(spetialization)
	{
		countMark = rand() % 10 + 1;//rand() % 0......9 
		marks = new int[countMark];
		for (int i = 0; i < countMark; i++)
		{
			marks[i] = rand() % 5 + 8;//8......12
			//rand() % x  - 0...x
			// x....y  8-12
			//rand() % (y-x) + x
			//rand() % 4 - 0....4
		}
	}
	virtual void Print()const
	{
		cout << "Student : " << name << endl;
		cout << "Spetialization : " << spetialization << endl;
		cout << "Counr marks : " << countMark << endl;
		cout << "Marks : ";
		for (int i = 0; i < countMark; i++)
		{
			cout << marks[i] << " ";
		}
		cout << endl;
		cout << "======================================" << endl;
	}
	virtual ~Person()
	{
		if (marks != nullptr)
			delete[]marks;
	}
};
class Aspirant : public Person
{
	string *subjects;
	int countSubjects;
public:
	Aspirant(string name, string spet, initializer_list<string> subjs)://4
		Person(name,spet)
	{

		this->countSubjects = subjs.size();
		this->subjects = new string[countSubjects];
		int i = 0;
		for (string sub : subjs)
		{
			this->subjects[i] = sub;
			i++;
		}
		//for (int i = 0; i < countSubjects; i++)
		//{
		//	this->subjects[i] = subjects[i];
		//}
	}
	void Print() const override
	{
		Person::Print();
		cout << "Subjects : " ;
		for (int i = 0; i < countSubjects; i++)
		{
			cout << subjects[i] << endl;
		}
		cout << "======================================" << endl;
	}
	~Aspirant()
	{
		if (subjects != nullptr)
			delete[]subjects;
	}
};



int main()
{
	srand(time(0));
	Person student("Vasia","Programmer");
	student.Print();

	//Aspirant as("Oleg","Foreign language", "British English");
	Aspirant as("Oleg", "Foreign language", { "British English" ,"History England"});
	as.Print();

	Person* group[3]{
		new Person("Vasia","Programmer"),
		new Aspirant("Oleg", "Foreign language", { "British English" ,"History England"}),
		new Aspirant("Ivanka", "UI/UX Design", { "Main page" ,"User experience","Trends in UI/UX"})
	};

	for (int i = 0; i < 3; i++)
	{
		group[i]->Print();
		delete group[i];
	}
   
}

