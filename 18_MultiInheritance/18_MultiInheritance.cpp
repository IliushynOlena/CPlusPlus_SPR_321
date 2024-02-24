#include <iostream>
using namespace std;

class Car
{
protected:
    string model;
public:
    void Drive()
    {
        cout << "I can drive " << endl;
    }
    void Wash()
    {
        cout << "I wash my car " << endl;
    }
};
class Airplane
{
protected:
    string model;
public:
    void Fly()
    {
        cout << "I can fly " << endl;
    }
    void Wash()
    {
        cout << "I wash my aiplane " << endl;
    }
};
class FlyingCar: public Car, public Airplane
{
public:
    FlyingCar(string model)
    {
       Car::model = model;
       Airplane::model = model;
    }

};
class A
{
public:
    static int value;
};
class B : public A{};//int value;
class C : public A{};//int value;
class D: public B, public C
{
    //int value;
    //int value;
public:
    int GetValue() {
        return B::value;
        return B::A::value;
        return C::value;
        return C::A::value;
    }
};

int main()
{
    D d;
    //d.value = 10;//error
    D::B::value = 100;
    D::B::A::value = 99;
    D::C::A::value = 98;
    D::C::value = 97;


    d.GetValue();

   /* Car car;
    car.Drive();

    Airplane air;
    air.Fly();

    FlyingCar fc("FlyingCar");
    fc.Drive();
    fc.Fly();
    ((Car)fc).Wash();
    ((Airplane)fc).Wash();*/
}

