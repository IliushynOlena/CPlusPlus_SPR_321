#include <iostream>
using namespace std;

class Array
{
private:
    int* arr;
    int size;//11
public:
    Array()
    {
        arr = nullptr;
        size = 0;
    }
    explicit Array(int size)
    {
        this->size = size;
        arr = new int[size] {};
        for (int i = 0; i < size; i++)
        {
            arr[i] = i+1;
        }      
        
    }
    void operator++(int a)
    {
        for (int i = 0; i < size; i++)
        {
            //arr[i]++;
            arr[i] = arr[i] + 1;
        }
    }
    Array(int a, int b)
    {

    }
    ~Array()
    {
        delete[]arr;
    }
    void SetNewSize(int size)
    {
        this->size = size;
    }
    int getSize()const
    {
        return size;
    }
    void Print()const
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    int GetElementById(int index)//40
    {
        if (index < 0 || index >= size) return -1;
        return arr[index];
    }
    int operator[](int index)//40
    {
        if (index < 0 || index >= size) return -1;
        return arr[index];
    }
    void ChangeElement(int number)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += number;
        }
    }
    void operator()(int number)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] += number;
        }
    }
    void operator()(int index , int number)
    {      
        arr[index] += number;
    }
};

void Display(const Array &arr)
{
    arr.Print();

}
void Test(int &a)
{
    a++;
    cout << a << endl;
}

int main()
{
   /* const int a = 10;
    cout << a << endl;
    Test(a);
    cout << a << endl;*/
    //Array arr;//default ctor
    Array arr2(5);//constructor
    arr2.Print();
    arr2++;
    arr2.Print();

    cout << "Element in index [4] = " << arr2.GetElementById(4) << endl;
    cout << "Element in index [2] = " << arr2.GetElementById(2) << endl;
    cout << "Element in index [1] = " << arr2[1] << endl;
    cout << "Element in index [2] = " << arr2[2] << endl;
    cout << "Element in index [4] = " << arr2[4] << endl;

    arr2.ChangeElement(15);
    arr2.Print();
    arr2(10);
    arr2.Print();
    arr2(1, 100);
    arr2.Print();
    //Array arr3;
    //arr3.Print();

    //Display(arr2);
    //cout << "-------------------------" << endl;

    ////imlicit
    //int b = 3.333;//3
    ////explicit
    //int c = (int)3.333;//3
    //imlicit
    //Array test = 15;//int => Array
    //Array != int
     //imlicit
    //Display(10);

   /* Array a1;
    Array a2(6);
    Array a3(6,5);*/

    //Array b1;
    //Array b2= 6;
    //Array b3 = 6, 5;

}

