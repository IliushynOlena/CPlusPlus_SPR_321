#include <iostream>
using namespace std;

class MyArr
{
private:
	int* arr;
	int size;
public:
	MyArr(int size = 10) : size(size)
	{
		arr = new int[size];
	}
	~MyArr()
	{
		delete[] arr;
	}
	// execption: out_of_range - Index is less that 0 or more than size
	int& operator[](int index)
	{
		if (index >= size || index < 0)
			throw out_of_range("Index is less that 0 or more than size");
		else
			return arr[index];
	}

	void CheckLenght(int len)
	{
		if (len < 0)
			throw length_error("Some Length error...\n");

		cout << "Lenght valid!\n";
	}

	void SetSize(int newSize)
	{
		if (newSize <= 0)
			throw invalid_argument("New size is less than 0");
		else
		{
			int* new_arr = new int[newSize];
			for (int i = 0; i < newSize && i < size; ++i)
			{
				new_arr[i] = arr[i];
			}
			delete[]arr;
			arr = new_arr;
			size = newSize;
		}
	}
};

void MyQuit()
{
	cout << "Goodbye!";
	//exit(5);
}

int main()
{
	// встановлення функції, яка буде викликатися при необробленому exception
	//set_terminate(MyQuit);


	MyArr myArr(5);//5

	//myArr[100] = 777;

	try
	{
		//myArr[20] = 777;//0 1 2 3 4 ---- 15x  25x
		//cout << myArr[20] << endl;
		//myArr[100] = 777;
		//cin.get();

		//myArr.CheckLenght(-1);
		myArr.SetSize(-7);

	}
	catch (out_of_range& e)
	{
		cout << "Out of range...\n";
		cout << e.what() << endl;
	}
	catch (invalid_argument& e)
	{
		cout << "Invalid argument...\n";
		cout << e.what() << endl;
	}
	catch (logic_error& e)
	{
		cout << "Logic error...\n";
		cout << e.what() << endl;
	}
	catch (exception& e)
	{
		cout << "Exception...\n";
		cout << e.what() << endl;
	}
	catch (...)
	{
		cout << "Unknown error...\n";
	}


}
