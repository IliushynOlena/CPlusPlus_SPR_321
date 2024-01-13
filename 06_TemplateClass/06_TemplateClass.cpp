#include <iostream>
using namespace std;
/*
int GetMax(int *arr, int size)
{
	int max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
long GetMax(long* arr, int size)
{
	long max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
short GetMax(short* arr, int size)
{
	short max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
float GetMax(float* arr, int size)
{
	float max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}
*/
template<typename T_arr>
T_arr GetMax(T_arr* arr, int size)
{
	T_arr max = arr[0];
	for (int i = 0; i < size; i++)
	{
		if (arr[i] > max)
			max = arr[i];
	}
	return max;
}

//template<typename T_coll,typename T_value >
template<class T_coll,class T_value >
class MyClass
{
	T_coll* collection;
	int size;
	T_value point;
public:
	MyClass()
	{
		collection = nullptr;
		size = 0;
		point = 0;
	}
	MyClass(T_coll* coll, T_value value) :collection(coll), point(value) {}
	~MyClass()
	{
		if (collection != nullptr)
			delete[]collection;
	}
	void SetCollection(T_coll* coll);//address	
	void SetValue(T_value value);
	void Print()
	{
		cout << "Collection : " << collection << endl;
		cout << "Value : " << point << endl;
	}

};
template<class T_coll, class T_value >
void MyClass<T_coll, T_value>::SetCollection(T_coll* coll)//address
{
	collection = coll;//address = address
}

template<class T_coll, class T_value >
void MyClass<T_coll, T_value>::SetValue(T_value value)
{
	point = value;
}
template<typename T_coord>
class Point
{
private:
	T_coord x;
	T_coord y;
public:
	Point()
	{
		x = 0;
		y = 0;
	}
	Point(T_coord value)//8
	{
		x = y = value;//<---------
	}
	Point(T_coord x, T_coord y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()
	{
		cout << " X : " << x << " Y :" << y << endl;
	}
	void SetNewCoords(T_coord newX, T_coord newY)
	{
		this->x = newX;
		this->y = newY;
	}
};
template<typename T_X, typename T_Y>
class PointNew
{
private:
	T_X x;
	T_Y y;
public:
	PointNew()
	{
		x = 0;
		y = 0;
	}
	PointNew(T_X x, T_Y y)
	{
		this->x = x;
		this->y = y;
	}
	void Print()
	{
		cout << " X : " << x << " Y :" << y << endl;
	}
	void SetNewCoords(T_X newX, T_Y newY)
	{
		this->x = newX;
		this->y = newY;
	}
};
int main()
{
	Point<int> p1(15, 36);
	p1.Print();

	p1.SetNewCoords(7, 77);
	p1.Print();

	Point<float> p2(0.336, 0.147);
	p2.Print();

	PointNew<int, float> p3(15, 3.36);
	p3.Print();

	/*long* arr_long = new long[4];
	for (int i = 0; i < 4; i++)
	{
		arr_long[i] = i + 1;
		cout << arr_long[i] << " ";
	}
	cout << endl;

	char* arr_char = new char[4];
	for (int i = 0; i < 4; i++)
	{
		arr_char[i] = i + 'a';
		cout << arr_char[i] << " ";
	}
	cout << endl;
	MyClass<long,string> cl1(arr_long, "Class with long collection");
	MyClass<char,string> cl2(arr_char, "Class with char collection");
	cl1.Print();
	cl2.Print();*/
	//delete[]arr_long;
	//delete[]arr_char;

	//const int size = 10;
	//int numbers[size] = { 5,8.9,9,6,12,4,7,3,11,25 };
	//cout << numbers << endl;
	//cout<< "Max : "<< GetMax(numbers, size);
	//short numbers1[size] = { 5,8.9,9,6,12,4,7,3,11,25 };
	//cout << "Max : " << GetMax(numbers1, size);
	//long numbers2[size] = { 5,8.9,9,6,12,4,7,3,11,25 };
	//cout << "Max : " << GetMax(numbers2, size);
	//float numbers3[size] = { 5.2,8.9,9,6,12.4,4,7,3,11,25.99 };
	//cout << "Max : " << GetMax(numbers3, size);
	//string colors[6] = { "red", "green","white", "pink","Black","blue" };
	//cout << "Max : " << GetMax(colors, 6);
	//cout << numbers[0] << endl;
	//int* parr = &numbers[0];
	//cout << parr << endl;

   
}

