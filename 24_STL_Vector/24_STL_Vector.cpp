#include <iostream>
#include <vector>
using namespace std;
//STL -  Standard Template Library

void Print(vector<int> v)
{
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}
int main()
{
    vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    vector<int> v2 = { 10,11,12,13,14 };

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
	for (int item : v)
	{
		cout << item << " ";
	}
	cout << endl;

	//delete elements
	
	v.erase(v.begin() + 9);
	Print(v);
	v.erase(v.begin() + 5, v.end()-1);
	Print(v);

	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	//insert elements
	v.insert(v.begin(), { 77,88,99 });
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin() + 5, 10, 9);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.begin(),100);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.insert(v.end(), v2.begin(), v2.end());
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v[0] = 999;
	Print(v);

	v.push_back(100);
	v.push_back(200);
	v.push_back(300);
	v.push_back(400);
	v.push_back(500);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.pop_back();
	v.pop_back();
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	//Print(v);
	//Print(v2);
	//v.swap(v2);
	//Print(v);
	//Print(v2);
	cout << "Front element "<<  v.front() << endl;
	cout << "Back element "<<  v.back() << endl;

	v.resize(10);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;
	v.shrink_to_fit();
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

	v.push_back(100);
	v.push_back(200);
	v.push_back(300);
	v.push_back(400);
	v.push_back(500);
	Print(v);
	cout << "Size : " << v.size() << endl;
	cout << "Capacity : " << v.capacity() << endl;

}

