#include <iostream>
using namespace std;

class Person//abstract claas
{
private:
	string name;
public:
	Person() :name("no name"){}
	Person(string name) :name(name) {}
	virtual void Print()const
	{
		cout << "Name : " << name << endl;
	}
	//pure virtual destructor
	virtual ~Person() = 0 {}

};
class Aspirant : public Person
{
	string* subjects;
	int countSubjects;
public:
	Aspirant(string name, initializer_list<string> subjs) ://4
		Person(name)
	{
		this->countSubjects = subjs.size();
		this->subjects = new string[countSubjects];
		int i = 0;
		for (string sub : subjs)
		{
			this->subjects[i] = sub;
			i++;
		}
	}
	void Print() const override
	{
		Person::Print();
		cout << "Subjects : ";
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
	/*Person student("Vasia");
	student.Print();*/

	//Aspirant as("Oleg","Foreign language", "British English");
	Aspirant as("Oleg",{ "British English" ,"History England" });
	as.Print();

	Person* group[2]{
		new Aspirant("Oleg", { "British English" ,"History England"}),
		new Aspirant("Ivanka", { "Main page" ,"User experience","Trends in UI/UX"})
	};

	for (int i = 0; i < 2; i++)
	{
		group[i]->Print();
		delete group[i];
	}

}

