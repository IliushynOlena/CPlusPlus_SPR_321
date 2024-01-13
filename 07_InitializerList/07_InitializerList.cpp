#include <iostream>
using namespace std;

class Array
{
    int* arr;
    int size;
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
        /*for (int i = 0; i < size; i++)
        {
            arr[i] = 0;
        }*/
    }
    Array(const initializer_list<int> &list)
    {
        this->size = list.size();
        arr = new int[size];
        int i = 0;
        for (int elem : list)
        {
            arr[i++] = elem;
        }
        /*for (int i = 0; i < size; i++)
        {
            arr[i] = list[i];
        }*/
    }
    void Fill(const initializer_list<int>& list)
    {
        if (arr != nullptr)delete[]arr;
        this->size = list.size();
        arr = new int[size];
        int i = 0;
        for (int elem : list)
        {
            arr[i++] = elem;
        }
    }
    void Print()
    {
        cout << "Size : " << size << endl;
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
    ~Array()
    {
        if (arr != nullptr)
            delete[]arr;
    }
    int BinarySearch(int key)
    {
        int B = 0, E = size - 1;
        while (true)
        {
            int p = (B + E) / 2;
            if (key > arr[p])
                B = p + 1;
            else if (key < arr[p])
                E = p - 1;
            else if (key == arr[p])
                return p;

            if (B > E)return -1;
        }
    }
};

int main()
{
    Array arr(7);//constructor parametrized
    arr.Print();

   /* Array arr3 = 10;
    arr3.Print();*/

    Array arr2({ 6, 7, 8, 9,10,15,14,78,96});
    arr2.Print();
    arr2.Fill({ 9 });
    arr2.Print();

    int static_arr[5] = { 1,2,3,4,5 };
    int* dynam_arr = new int[5] {6, 7, 8, 9, 10};




    delete[]dynam_arr;
    
}

