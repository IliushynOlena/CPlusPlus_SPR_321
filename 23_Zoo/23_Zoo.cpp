#include <iostream>
#include <fstream>
#include <string>
using namespace std;


class Animal//abstract class
{
	string name;
	string place;
	float weight;
public:
	Animal() :name("no name"), place("no place"), weight(0) {}
	Animal(string n,  string p, float w) :name(n),place(p) 
	{
		/*if (w > 0)
			weight = w;
		else
		{
			throw invalid_argument("Weight is incorrect");
		}*/

		this->weight = w > 0 ? w : 0;
	}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Place : " << place << endl;
		cout << "Weight : " << weight << endl;
	}
	virtual void Move()const
	{
		cout << "I am moving.........." << endl;
	}
	//friend ostream& operator << (ostream& out, const Animal& animal);
	friend ostream&operator << (ostream& out, const Animal& animal);
	friend istream& operator >> (istream& in, Animal& animal);
};
ostream& operator << (ostream& out, const Animal& animal)//write info to file
{
	out << animal.name << " " << animal.place << " " << animal.weight;
	return out;
}
istream& operator >> (istream& in, Animal& animal)//read from file
{
	in >> animal.name >> animal.place >>animal.weight;
	return in;
}
//ostream& operator << (ostream& out, const Animal& animal)// show info in console
//{
//	out << "Name : " << animal.name << endl;
//	out << "Place : " << animal.place << endl;
//	out << "Weight : " << animal.weight << endl;
//	return out;
//}
class Zoo
{
private:
	string name;
	Animal *animals;//create pointer 
	int countAnimal;
public:
	Zoo(string name) :name(name), animals(nullptr), countAnimal(0) {}
	void AddAnimal(Animal animal)
	{
		Animal* newArr = new Animal[countAnimal + 1];
		for (int i = 0; i < countAnimal; i++)
		{
			newArr[i] = animals[i];
		}
		newArr[countAnimal++] = animal;
		//countAnimal++;
		if (animals != nullptr)
			delete[]animals;

		animals = newArr;
	}
	void PrintInfo()const
	{
		cout << "Name Zoo : " << name << endl;
		for (int i = 0; i < countAnimal; i++)
		{
			animals[i].ShowInfo();
			//cout << animals[i] << endl;
			cout << "____________________" << endl;
		}
	}
	~Zoo()
	{
		if (animals != nullptr)
			delete[]animals;
	}

	void Save()const
	{
		ofstream fileOut("zoo.txt", ios_base::out);
		fileOut << name << endl;
		fileOut << countAnimal << endl;
		for (int i = 0; i < countAnimal; i++)
		{
			fileOut << animals[i] << endl;
		}
		fileOut.close();
		cout << "Zoo save to file " << endl;
	}
	void LoadFromFile()
	{
		ifstream fileIn("zoo.txt", ios_base::in);
		getline(fileIn, name);//fileIn >> name;
		
		fileIn >> countAnimal;

		animals = new Animal[countAnimal];
		for (int i = 0; i < countAnimal; i++)
		{
			fileIn >> animals[i]; 
		};
		fileIn.close();
	}

};

int main()
{
	//Animal cat("Tom", "Flat", 5);
	//cat.ShowInfo();
	//Zoo zoo("Rivne Zoo");
	//zoo.AddAnimal(cat);
	//zoo.AddAnimal(Animal("Lion King", "Africa", 100));
	//zoo.AddAnimal(Animal("Elephant", "Africa", 10000));
	//zoo.AddAnimal(Animal("Puma", "Africa", 200));

	//zoo.PrintInfo();
	//zoo.Save();
	Zoo zoo("Test");
	zoo.PrintInfo();
	zoo.LoadFromFile();
	zoo.PrintInfo();
	//string name;
	//getline(cin, name);//cin >> name;
	//
	//cout << name;

    
}
