#include <iostream>

using namespace std;

class BirthdayDate {
private:
	int day;
	int month;
	int year;

public:

	BirthdayDate() : day(0), month(0), year(0) {}

	BirthdayDate(int day, int month, int year) : day{ day }, month{ month }, year{ year } {}

	void setDay(int day) {
		this->day = day;
	}

	void setMonth(int month) {
		this->month = month;
	}

	void setYear(int year) {
		this->year = year;
	}

	int getDay() {
		return day;
	}

	int getMonth() {
		return month;
	}

	int getYear() {
		return year;
	}

	void bDate() {
		cout << "Enter your birthday day: ";
		cin >> day;
		setDay(day);

		cout << "Enter your birthday month: ";
		cin >> month;
		setDay(month);

		cout << "Enter your birthday year: ";
		cin >> year;
		setDay(year);
	}
};

class Human {
private:
	int id;
	char* name;
	char* surname;
	char* fathersName;
	int age;
	BirthdayDate birthDate;//default
	static int count;

public:
	static int GetCount()
	{
		return count;
	}
	Human() : id(0), name(nullptr), surname(nullptr), fathersName(nullptr), age(0) { count++; }

	Human(int id, const char* name, const char* surname, const char* fathersName, int age,
		BirthdayDate birthDate)
		: id{ id }, name{ new char[50] }, surname{ new char[50] }, fathersName{ new char[50] }, age{ age }, birthDate{ birthDate }
	{
		this->id = id;
		strcpy_s(this->name, 50, name);
		strcpy_s(this->surname, 50, surname);
		strcpy_s(this->fathersName, 50, fathersName);
		this->age = age;
		count++;
	}

	~Human() {
		delete[] name;
		delete[] surname;
		delete[] fathersName;
	}

	void setId(int id) {
		this->id = id;
	}

	void setName(const char* name) {

		if (this->name != nullptr) {
			delete[] this->name;
		}
		this->name = new char[50];

		strcpy_s(this->name, 50, name);
	}


	void setSurname(const char* surname) {

		if (this->surname != nullptr) {
			delete[] this->surname;
		}
		this->surname = new char[50];

		strcpy_s(this->surname, 50, surname);
	}

	void setFathersName(const char* fathersName) {
		if (this->fathersName != nullptr) {
			delete[] this->fathersName;
		}
		this->fathersName = new char[50];

		strcpy_s(this->fathersName, 50, fathersName);
	}

	void setAge(int age) {
		this->age = age;
	}

	int getId() {
		return id;
	}

	const char* getName() {
		return name;
	}

	/*void getName() {
		for (int i = 0; i < 50; i++) {
			if (name[i] == '\0') {
				break;
			}
			cout << name[i];
		}
	}*/

	const char* getSurname() {
		return surname;
	}

	const char* getFathersName() {
		return fathersName;
	}

	int getAge() {
		return age;
	}

	void createPerson() {
		char name[20];
		char surname[20];
		char fathersName[20];

		cout << "Enter your id: ";
		cin >> id;
		setId(id);

		cout << "Enter your name: ";
		cin >> name;
		//const char* NAME = name.c_str();
		setName(name);

		cout << "Enter your surname: ";
		cin >> surname;
		//const char* SURNAME = surname.c_str();
		setSurname(surname);


		cout << "Enter your father's name: ";
		cin >> fathersName;
		//const char* FNAME = fathersName.c_str();
		setFathersName(fathersName);


		cout << "Enter your age: ";
		cin >> age;
		setAge(age);

		birthDate.bDate();
	}


	void showPerson() {
		cout << "Id: " << getId() << endl;
		cout << "Full name: " << getName() << " " << getSurname();
		cout << "Father's name: " << getFathersName() << endl;
		cout << "Age: " << getAge() << endl;
		cout << "Birthday date: " << birthDate.getDay() << "." << birthDate.getMonth() << "." << birthDate.getYear() << endl;
	}
};

int Human::count = 0;
/*
void addPerson(Human*& people, int& size,  Human *newHuman) {

	Human* tmp = new Human[size + 1];
	for (int i = 0; i < size; i++) {
		tmp[i] = people[i];
	}
	tmp[size] = *newHuman;
	delete[] people;
	people = tmp;
	size++;
}

void howManyPeople(int& size) {

	cout << "\nYou create: " << size << " people\n\n";
}

void showAll(Human*& people, int& size) {
	for (int i = 0; i < size; i++) {
		people[i].showPerson();
		cout << endl;
	}
}
*/


int main()
{
	int choice;
	int size = 0;
	Human people;
	people.createPerson();
	people.showPerson();

	Human h2;
	h2.setAge(10);

	cout<< Human::GetCount();


	cout << "WELCOME TO PROGRAM";
	cout << endl;

	//while (true) {
	//	cout << "\n1. Create a new person";
	//	cout << "\n2. Show how many people have been created";
	//	cout << "\n3. Show all people";
	//	cout << "\n4. Quit";
	//	cout << "\nEnter your choice: ";
	//	cin >> choice;
	//	cout << endl;

	//	
	//	switch (choice) {
	//	case 1:
	//	{
	//		Human newPerson;
	//		//newPerson = new Human();
	//		newPerson.createPerson();
	//		addPerson(people, size, newPerson);
	//		break;
	//	}
	//	case 2:
	//		howManyPeople(size);
	//		break;

	//	case 3:
	//		showAll(people, size);
	//		break;

	//	case 4:
	//		//delete[] people;
	//		return 0;

	//	default:
	//		cout << "Invalid choice" << endl;
	//		break;
	//	}
	//}

	//

}


