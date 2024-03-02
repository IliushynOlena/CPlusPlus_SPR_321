#include <iostream>
using namespace std; 
//class Procesor{};
//class Camera{};
//class Batery{};
//class Sensor{};
//
//class Phone	{
//	Procesor pr;
//	Camera c;
//	Batery b;
//	Sensor s;
//};

class Document
{
private:
	string name;
	string format;
	int pages;
public:
	Document() :name("no name"), format("no format"), pages(0) {}
	Document(string name, string format, int pages) :name(name), format(format)
	{
		this->pages = (pages > 0) ? pages : 0;
	}
	void ShowInfo()const
	{
		cout << "____________________Document " << name << "______________" << endl;
		cout << "Format : " << format << endl;
		cout << "Pages : " << pages << endl;
	}


};
class Cartridge
{
public:
	enum Type { Standart, XL, XXL, S, M, L };	
private:
	string color;
	float volume;
	Type type;
public:
	Cartridge():color("no color"),volume(0),type(XL){}
	Cartridge(string color, float volume, Type t):color( color),volume(volume),type(t){}
	void ShowInfo()const
	{
		cout << "Color : " << color <<" Volume : "<< volume << " ";
		cout << "Type : ";
		switch (type)
		{
		case Cartridge::Standart:cout << "Standart" << endl;break;
		case Cartridge::XL:cout << "XL" << endl;break;
		case Cartridge::XXL:cout << "XXL" << endl;break;
		case Cartridge::S:cout << "S" << endl;break;
		case Cartridge::M:cout << "M" << endl;break;
		case Cartridge::L:cout << "L" << endl;	break;
		}
	}
};
class Scanner
{
private:
	float scanResolution;
	float height, width;
public:
	Scanner():scanResolution(0),height(0),width(0){}
	Scanner(float sR, float h, float w):scanResolution(sR),height(h),width(w){}
	void ShowInfo()const
	{
		cout << "Scan resolution : " << scanResolution <<" dpi" << endl;
		cout << "Scan Area : " << height << " mm, Width : " << width << " mm" << endl;
	}

};
class Printer 
{
	string model;
	Cartridge* cartridges;
	int countCartridge;
	Scanner scanner;//default constructor
	Document* doc;//pointer - address
public:
	Printer():model("no model"), cartridges(nullptr), countCartridge(0), doc(nullptr){}
	Printer(string model, float scanRes, float h, float w):doc(nullptr)
	{
		this->model = model;
		scanner = Scanner(scanRes, h, w);//parametrized constructor

		countCartridge = 4;
		cartridges = new Cartridge[countCartridge];

		cartridges[0] = Cartridge("black", 300, Cartridge::XL);
		cartridges[1] = Cartridge("Red", 200, Cartridge::L);
		cartridges[2] = Cartridge("Green", 200, Cartridge::L);
		cartridges[3] = Cartridge("Blue", 200, Cartridge::L);
	}
	void PrintDocument()
	{

		if (doc == nullptr)
		{
			cout << "No document to print " << endl;
		}
		else
		{

			doc->ShowInfo();
		}
	}
	void Cancel()
	{
		doc = nullptr;
	}
	void ShowProperties()
	{
		cout << "Printing properties......" << endl;
		for (int i = 0; i < countCartridge; i++)
		{
			cartridges[i].ShowInfo();
		}
	}
	void Scan()
	{
		cout << "Scanning......" << endl;
		scanner.ShowInfo();
	}
	void AddToQueue(Document* currentDoc)//pointer - address
	{
		//address = address;
		doc = currentDoc;
	}
	~Printer()
	{
		if (cartridges != nullptr)
			delete[]cartridges;
	}
};


int main()
{
	Printer printer("Canon",300,500,300);
	printer.PrintDocument();
	printer.Scan();


	Document doc1("passport.pdf", "A5", 7);
	Document doc2("C++ for beginner.pdf", "A4", 1200);

	printer.AddToQueue(&doc1);
	printer.PrintDocument();

	printer.AddToQueue(&doc2);
	printer.Cancel();
	printer.PrintDocument();


	/*
	one to one 1....1
	one to many 1....*
	many to many *.....*
	*/
	


	
}

