#include <iostream>
using namespace std;

struct Date
{
    int day;
    int month;
    int year;
};
//private
class Point
{
private:
    int x;
    int y ;
public:
    Point()
    {
        x = 0;
        y = 0;
    }
    Point(int value)//8
    {
        x = y = value;//<---------
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()
    {
        cout << " X : " << x << " Y :" <<y << endl;
    }
    ~Point()
    {
        //cout << "Destructor " << x << " "<< y << endl;
    }
    Point Plus(const Point &other)
    {
        Point res(this->x + other.x, this->y + other.y);
        /*Point res;
        res.x = this->x + other.x;
        res.y = this->y + other.y;*/
        return res;

    }
    Point Minus(const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;

    }
    Point operator+(const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator-(const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator*(const Point& other)
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator/(const Point& other)
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
    Point operator+=(const Point& other)
    {
        //this - address
        this->x += other.x;
        this->y += other.y;
        return *this;
    }
    Point operator-()
    {
        /* Point res(this->x*-1, this->y * -1);
         return res;*/
        return Point(this->x * -1, this->y * -1);
    }
    Point operator=(const Point& other)
    {
        //this - address
        this->x = other.x;//22 = 6
        this->y = other.y;//22 = 9
        return *this;
    }
    bool operator>(const Point& other)
    {
       /* if ((this->x + this->y) > (other.x + other.y))
            return true;
        else
            return false;*/

        return (this->x + this->y) > (other.x + other.y);
    }
    bool operator<(const Point& other)
    {
        return (this->x + this->y)<(other.x + other.y);
    }
    bool operator>=(const Point& other)
    {
        return (this->x + this->y) >= (other.x + other.y);
    }
    bool operator<=(const Point& other)
    {
        return (this->x + this->y) <= (other.x + other.y);
    }
    bool operator==(const Point& other)
    {
        return (this->x == other.x  ) && (this->y == other.y);
    }
    bool operator!=(const Point& other)
    {
        //return (this->x != other.x) && (this->y != other.y);
        return !(*this == other);
    }
};

int Plus(int a, int b)
{
    return a + b;
}
int main()
{


    int a = 5;
    a++;
    ++a;
    a--;
    --a;
    int b = 15;

    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;
    a += 100;

    Point point;//default c-tor
    point.Print();

    Point point2(22);
    point2.Print();

    Point point3(6, 9);
    point3.Print();


    Point res = point2.Plus(point3);
    cout << "Res : "; res.Print();

    res = point2.Minus(point3);
    cout << "Res : "; res.Print();
    //point2 + point3;
    cout << "Point 2 : "; point2.Print();
    cout << "Point 3 : "; point3.Print();

    res = point2 + point3;//res = point2.operator+(point3);
    cout << "Res : "; res.Print();
    res = point2 - point3;//res = point2.operator-(point3);
    cout << "Res : "; res.Print();
    res = point2 * point3;//res = point2.operator*(point3);
    cout << "Res : "; res.Print();
    res = point2 / point3;//res = point2.operator/(point3);
    cout << "Res : "; res.Print();

    point2 += point3;
    cout << "Point 2 : "; point2.Print();
    cout << "Point 3 : "; point3.Print();

    res = -point2;
    cout << "Res : "; res.Print();


    point2 = point3;
    cout << "Point 2 : "; point2.Print();
    cout << "Point 3 : "; point3.Print();


    if (point2 > point3)
    {
        cout << "Point 2 is more than Point 3" << endl;
    }
    else
    {
        cout << "Point 2 is small than Point 3" << endl;
    }
    if (point2 != point3)
    {
        cout << "Point 2 != Point 3" << endl;
    }
    else
    {
        cout << "Point 2 == Point 3" << endl;
    }

   //// 5555 = 1год 32хв 35сек
   //    int hour = 5555/3600 = 1
   //    int minute = 5555/60%60 = 32
   //    int second = 5555%60

   //        5555/60 = 92...
   //        92*60 = 5520
   //        5555-5520 = 32

   //        7 32 15 + 14 25 36 = 21 57 51
}