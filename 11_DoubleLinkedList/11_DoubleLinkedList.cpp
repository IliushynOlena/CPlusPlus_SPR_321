#include <iostream>
using namespace std;


template<typename T_data>
class List
{
    struct Node
    {
        Node* prev;
        T_data value;
        Node* next;
        Node(Node* prev, T_data value, Node* next) :prev(prev), value(value), next(next) {}

    };
private:
    Node* head;
    Node* tail;
    int size;
public:
    List()
    {
        head  = nullptr;
        tail = nullptr;
        size = 0;
    }
    List(const List &other)
    {
        for (Node * current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
    } 
    List& operator= (const List& other)
    {
        Clear();
        for (Node* current = other.head; current != nullptr; current = current->next)
        {
            this->AddToTail(current->value);
        }
        return *this;
    }
    void Clear()
    {
        Node* current = nullptr;
        while (head != nullptr)
        {
            current = head;
            head = head->next;
            delete current;
        }
        size = 0;
    }
    bool IsEmpty()
    {
        return head == nullptr;
    }
    void AddToHead(T_data value)
    {
        Node* newNode = new Node(nullptr, value, head);  
        if (IsEmpty())
        {
            head = tail = newNode;
        }
        head->prev = newNode;
        head = newNode;
        //head->next->prev = newNode;
        size++;
    }
    void Print()
    {
        
        for (Node* i = head; i != nullptr; i = i->next)
        {
            cout << i->value << " ";
        }
        cout << endl;
    }
    ~List()
    {
        Clear();
    }
    void AddToTail(T_data value)
    {
        Node* newNode = new Node(tail, value, nullptr);

        if (head == nullptr)
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }
    T_data GetElement(int pos)
    {
        Node* current = head;
        int i = 1;

        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    T_data operator[](int pos)
    {
        Node* current = head;
        int i = 1;

        while (current != nullptr)
        {
            if (pos == i) return current->value;
            current = current->next;
            i++;
        }
    }
    void DeleteFromTail()
    {
        if (IsEmpty())return;
        if (head->next == nullptr)
        {
            delete head;
            head = tail = nullptr;
            return;
        }
        else
        {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr;
        }
        size--;

    }
    void DeleteByPosition(int pos)
    {
      
        if (pos < 1 || pos > size)return;
        else if (pos == 1)
        {
            //DeleteFromHead();return;
        }
        else if (pos == size)
        {
            DeleteFromTail(); return;
        }
        else
        {
            Node* current = head;
            for (int i = 1; i < pos; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }       
    }
};

class Point
{
private:
    int x, y;

public:
  
    Point(int x = 0, int y = 0) : x(x), y(y) {}
    int GetX() const { return x; }
    int GetY() const { return y; }
};
ostream& operator << (ostream& out, const Point& point)
{
    out << "X : " << point.GetX() << " . Y : " << point.GetY() << endl;
    return out;
}
class Vector
{
private:
    //Point* points;   
    List<Point> points;//default constructor
    int countPoint;
public:
    Vector(int size = 5)
    {
        //points = new Point[size];
        countPoint = 0;
    }
    Vector(const Vector & other ): points(other.points)//copy constructor
    {
        //this->points = other.points;//operator = 
        this->countPoint = other.countPoint;
    }
    void AddNewPointToHead(Point p)
    {
        points.AddToHead(p);
        countPoint++;
    }
    void AddNewPointToTail(Point p)
    {
        points.AddToTail(p);
        countPoint++;
    }
    void Print()
    {
        points.Print();
    }
    void DeleteByPosition(int pos)
    {
        points.DeleteByPosition(pos);
    }
  
};
int main()
{
    Vector v;//constructor default
    v.AddNewPointToHead(Point(5, 9));
    v.AddNewPointToHead(Point(15, 4));
    v.AddNewPointToHead(Point(3, 7));
    v.AddNewPointToHead(Point(33, 47));
    v.AddNewPointToHead(Point(5, 19));
    v.Print();

    //Vector copy(v);//copy constructor
    v.DeleteByPosition(5);
    v.Print();

    //copy = v;
  
    //List<int> l;
    //for (int i = 0; i < 10; i++)
    //{
    //    l.AddToHead(i);
    //}
    ////l.Print();

   /* l.AddToTail(100);
    l.AddToTail(200);
    l.AddToTail(300);
    l.Print();

    cout << "Element [3] : " << l.GetElement(3) << endl;
    cout << "Element [3] : " << l[3] << endl;

    l.DeleteFromTail();
    l.DeleteFromTail();
    l.DeleteFromTail();
    l.Print();*/

}

