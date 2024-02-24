#include <iostream>
using namespace std;

class Animal//abstract class
{
	string name;
	string kind;
	float speed;
	string place;
	float weight;
public:
	Animal() :name("no name"), kind("no kind"), speed(0), place("no place"), weight(0) {}
	Animal(string n, string k,float s, string p, float w) :name(n), kind(k), speed(s), 
		place(p), weight(w) {}
	void ShowInfo()const
	{
		cout << "Name : " << name << endl;
		cout << "Kind : " << kind << endl;
		cout << "Speed : " << speed << endl;
		cout << "Place : " << place << endl;
		cout << "Weight : " << weight << endl;
	}	
	//virtual method
	virtual void Move()const
	{
		cout << "I am moving.........." << endl;
	}
	//virtual - allow change realization in child class
	//pure virtual method
	virtual void MakeSound()const = 0; //{} = X
	
};
class Lion: public Animal//na abstract class
{
	float runSpeed;
public:
	Lion(string n, string k, float s, string p, float w, float r) :runSpeed(r), Animal(n, k, s, p, w) {}
	//перевіряє, чи в батькіському класі є такий метод
	void MakeSound()const override
	{
		cout << "Rrrrrrrrrrrrrrr-rrrrrrrrrrr-rrrrrrrr" << endl;
	}
	void Move()const
	{
		cout << "I am running.........." <<runSpeed <<" km/g" << endl;
	}
};
class Duck : public Animal
{
	float flyHeight;
public:
	Duck(string n, string k, float s, string p, float w, float f) :flyHeight(f), Animal(n, k, s, p, w) {}
	//перевіряє, чи в батькіському класі є такий метод
	void MakeSound()const override
	{
		cout << "Kra-kra-kra-kra" << endl;
	}
	void Move()const
	{
		cout << "I am swimming and  flying up to " << flyHeight << " km/g" << endl;
	}
};
class Reptile: public Animal//abstract class
{
	float swimDeep;
public:
	Reptile(string n, string k, float s, string p, float w, float sw) :swimDeep(sw), Animal(n, k, s, p, w) {}
	//virtual void MakeSound()const = 0;

	void Move()const
	{
		cout << "I am crowling and swimming up to " << swimDeep << " m" << endl;
	}
};
class Frog: public Reptile
{

public:
	Frog(string n, string k, float s, string p, float w, float sw) : Reptile(n, k, s, p, w,sw) {}

	void MakeSound()const override
	{
		cout << "Kva-kva-kva-kva" << endl;
	}

};
void CallAnimal(Animal &animal)
{
	animal.MakeSound();
	animal.Move();
	//animal.ShowInfo();
}

int main()
{
	Frog frog("Crazy Frog", "reptile", 0.2, "boloto", 0.2, 2);
	frog.MakeSound();
	frog.Move();
	Duck duck("Donal Dack", "Bird",2,"Village",3,5);
	duck.MakeSound();
	duck.Move();

	/*Animal animal;
	animal.Move();
	animal.ShowInfo();
	animal.MakeSound();*/
	Lion lion("King Lion","Savets",60, "Africa",100,90);
	lion.MakeSound();
	lion.Move();

	CallAnimal(lion);
	CallAnimal(duck);
	CallAnimal(frog);
  
}

