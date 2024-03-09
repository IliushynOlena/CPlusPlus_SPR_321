#include <iostream>
using namespace std;

//class Stack
//{
//    enum {EMPTY = -1, FULL = 9};
//    int arr[FULL + 1];//10
//    int topIndex;
//public:
//    Stack()
//    {
//        topIndex = EMPTY;
//    }
//    ~Stack() = default;
//    Stack(const Stack& other) = delete;
//    bool Push(int element)
//    {
//        if (!IsFull())
//        {
//            arr[++topIndex] = element;
//            return true;
//        }
//        return false;
//    }
//    bool IsFull()const
//    {
//        return topIndex == FULL;
//    }
//    bool IsEmpty()const
//    {
//        return topIndex == EMPTY;
//    }
//    int Pop()
//    {
//        if (!IsEmpty())
//            return arr[topIndex--];       
//    }
//    int GetCount()const
//    {
//        return topIndex+1;
//    }
//    void Clear()
//    {
//        topIndex = EMPTY;
//    }   
//    void Print()const
//    {
//        for (int i = 0; i <= topIndex; i++)
//        {
//            cout << arr[i] << " ";
//        }
//    }
//};
class Stack
{
	enum { EMPTY = -1 };
	int size;
	int* arr;
	int top;
public:
	Stack() = delete;

	Stack(int size) :size(size)//-20
	{
		arr = new int[size];//20
		top = EMPTY;
	}
	bool IsFull()const
	{
		return top == size - 1;
	}
	bool Push(int element)
	{
		if (IsFull())Resize();
		if (!IsFull())
		{
			arr[++top] = element;
			return true;
		}
		else {
			//throw
		    return false;
		}
	}
	bool IsEmpty()const
	{
		return top == EMPTY;
	}
	int Pop()
	{
		if (!IsEmpty())
			return arr[top--];
		else {
			//throw
		}
	}
	int Peek()const
	{
		if (!IsEmpty())
			return arr[top];
		else {
			//throw
		}
	}
	int GetCount()
	{
		return top + 1;
	}
	void Clear()
	{
		top = EMPTY;
	}
	void Print()const
	{
		for (int i = 0; i <= top; i++)
		{
			cout << arr[i] << " ";
		}
	}
	~Stack()
	{
		delete[]arr;
	}
	void Resize()
	{
		size *= 2;
		int* temp = new int[size];
		for (int i = 0; i <= top; i++)
		{
			temp[i] = arr[i];
		}
		delete[]arr;
		arr = temp;
	}
};
bool IsValidCode(string code)
{
	Stack st(10);
	for (char symbol : code)
	{
		if (symbol == '{')
		{
			st.Push(1);
		}
		if (symbol == '}')
		{
			if (st.IsEmpty())return false;
			st.Pop();
		}
	}
	return st.IsEmpty();
}
int main()
{
	string code = "class Stack{ void Print(){for(.....){if(.....){{{.....}}}};";
	if (IsValidCode(code))
		cout << "Valid code" << endl;
	else
		cout << "Invalid code" << endl;

	Stack st(10);
	st.Push(10);
	cout << "Count : " << st.GetCount() << endl;
	st.Push(5);
	st.Push(7);
	st.Push(9);
	st.Push(41);
	st.Push(42);
	st.Push(43);
	st.Push(44);
	st.Push(45);
	st.Push(12);
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	st.Push(5);
	st.Push(7);
	st.Push(9);
	cout << "Count : " << st.GetCount() << endl;
	st.Print();
	cout << "\nElement : " << st.Pop() << endl;
	st.Print();
	while (!st.IsEmpty())
	{
		cout << "\nElement : " << st.Pop() << endl;
	}
	cout << "Count : " << st.GetCount() << endl;
	//Stack s(st);

}
