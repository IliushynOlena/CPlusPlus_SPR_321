
#include <iostream>
using namespace std;
class Point {
private:
    int x;
    int y;
public:
    Point() : x(0), y(0) {}
    Point(int x_val, int y_val) : x(x_val), y(y_val) {}
    void Print() const {
        cout << "Point(" << x << ", " << y << ")" << endl;
    }
    Point operator--() {
        --x;
        --y;
        return *this;
    }
    Point operator++() {
        ++x;
        ++y;
        return *this;
    }
    bool operator<(const Point& other) {
        return (this->x + this->y ) < (other.x + other.y);
    }

    bool operator>(const Point& other) const {
        return (this->x + this->y) > (other.x + other.y);
    }
    Point operator!() {
        x = -x;
        y = -y;
        return *this;
    }


};

int main() {
    Point p1(1, 1);
    Point p2(5, 6);

    p1.Print();
    p2.Print();
    --p1;
    p1.Print();

    ++p2;
    p2.Print();


    p1.Print();
    p2.Print();
    bool isCloser = p1 < p2;
    cout << boolalpha << isCloser << endl;
    p1.Print();
    p2.Print();
    bool further = p1 > p2;
    cout << further << endl;

   

    return 0;
}
