#include <iostream>
using namespace std;
class Square;
class Rectangle
{
private:
    int height;//garbage
    int width;//garbage
public:
    Rectangle() : height(2), width(2) {}
    Rectangle(int value) : height(value), width(value) {}
    Rectangle(int h, int w) :height(h), width(w) {}
    void Show()const
    {
        cout << "Height : " << height << "  ";
        cout << "Width : " << width << endl;
    }
    //operator typename() {}
    //operator typename()const {}
    //explicit operator typename()const {}
    explicit operator int()const
    {
        return width * height;
    }
    operator Square();
   

};

class Square
{
private:
    int side;
public:
    Square() :side(2) {}
    Square(int s) :side(s) {}
    void Show()const
    {
        cout << "Side  : " << side << "  ";
        cout << "Side : " << side << endl;
    }
    explicit operator Rectangle()
    {
        Rectangle rect(side, side + 20);
        return rect;
    }
};

Rectangle::operator Square()
{
    return Square(height + width);
}
int main()
{
    //imlicit
    int a = 5;//int -> int
    float b = a;//int -> float = 5.00000000  //з стандарного до стандартного
    double c = b;//float -> double = 5.0000000000000000 //з стандарного до стандартного
    int d = 3.33;//double -> int = 3 //з стандарного до стандартного

    Rectangle rect;//default constructor
    rect.Show();
    Rectangle rect1(10);//default constructor //з стандарного до абстрактного
    rect1.Show();
    Rectangle rect2(15,36);//default constructor //з стандарного до абстрактного
    rect2.Show();
    //explicit
    a = (int) rect;//Rectangle -> int  //з абстрактного  до стандарного
    cout << "Square rectangle = " << a << endl;

    Square sq(55);
    sq.Show();
    //imlicit
    rect = (Rectangle) sq;//Square -> Rectangle //з абстрактного  до абстрактного
    rect.Show();
    sq = rect;
    sq.Show();


}

