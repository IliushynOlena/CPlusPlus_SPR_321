#include <iostream>
#include<Windows.h>
using namespace std;

class Car
{
    //public private protected
protected:
    string model;
    int speed;
    float volume;
    int year;
public:
    Car() :model("no model"),speed(0),volume(0),year(0){}
    Car(string m, float v, int y) :model(m),speed(0),volume(v),year(y){}
    virtual void Print()const
    {
        cout << "Model : " << model << endl;
        cout << "Speed : " << speed << endl;
        cout << "Volume : " << volume << endl;
        cout << "Year : " << year << endl << endl;
    }
    virtual void Drive()const
    {
        cout << "I am a Car! I can drive with speed  " << speed << " km/h" << endl;
    }
    void SetSpeed(int speed)
    {
        if(speed >= 0)
            this->speed = speed;
    }
};
class PoliceCar : public Car //public private protected
{
    int soundVolume;
public:
    PoliceCar():soundVolume(0),Car(){}
    PoliceCar(string m, float v, int y, int s):soundVolume(s),Car(m,v,y){}
    void Drive()const override
    {
        cout << "I am a Police Car! I can drive with speed  " << speed << " km/h" << endl;
    }
  
    void Print()const override
    {
        Car::Print();
        cout << "Sound volume : " << soundVolume << endl << endl;
    }
    void BeepBeep()
    {
        Beep(1568, 200);
        Beep(1568, 200);
        Beep(1568, 200);
        Beep(1245, 1000);
        Beep(1397, 200);
        Beep(1397, 200);
        Beep(1397, 200);
        Beep(1175, 1000);
        /*  Beep (330,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (330,100);Sleep(300);
        Beep (392,100);Sleep(700);
        Beep (196,100);Sleep(700);
        Beep (262,300);Sleep(300);
        Beep (196,300);Sleep(300);
        Beep (164,300);Sleep(300);
        Beep (220,300);Sleep(100);
        Beep (246,100);Sleep(300);
        Beep (233,200);
        Beep (220,100);Sleep(300);
        Beep (196,100);Sleep(150);
        Beep (330,100);Sleep(150);
        Beep (392,100);Sleep(150);
        Beep (440,100);Sleep(300);
        Beep (349,100);Sleep(100);
        Beep (392,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
        Beep (247,100);Sleep(500);
        Beep (262,300);Sleep(300);
        Beep (196,300);Sleep(300);
        Beep (164,300);Sleep(300);
        Beep (220,300);Sleep(100);
        Beep (246,100);Sleep(300);
        Beep (233,200);
        Beep (220,100);Sleep(300);
        Beep (196,100);Sleep(150);
        Beep (330,100);Sleep(150);
        Beep (392,100);Sleep(150);
        Beep (440,100);Sleep(300);
        Beep (349,100);Sleep(100);
        Beep (392,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
        Beep (247,100);Sleep(900);
        Beep (392,100);Sleep(100);
        Beep (370,100);Sleep(100);
        Beep (349,100);Sleep(100);
        Beep (311,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (207,100);Sleep(100);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(500);
        Beep (392,100);Sleep(100);
        Beep (370,100);Sleep(100);
        Beep (349,100);Sleep(100);
        Beep (311,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (523,100);Sleep(300);
        Beep (523,100);Sleep(100);
        Beep (523,100);Sleep(1100);
        Beep (392,100);Sleep(100);
        Beep (370,100);Sleep(100);
        Beep (349,100);Sleep(100);
        Beep (311,100);Sleep(300);
        Beep (330,100);Sleep(300);
        Beep (207,100);Sleep(100);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (220,100);Sleep(100);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(500);
        Beep (311,300);Sleep(300);
        Beep (296,300);Sleep(300);
        Beep (262,300);Sleep(1300);
        Beep (262,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(300);
        Beep (330,200);Sleep(50);
        Beep (262,200);Sleep(50);
        Beep (220,200);Sleep(50);
        Beep (196,100);Sleep(700);
        Beep (262,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(100);
        Beep (330,100);Sleep(700);
        Beep (440,100);Sleep(300);
        Beep (392,100);Sleep(500);
        Beep (262,100);Sleep(100);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(300);
        Beep (262,100);Sleep(100);
        Beep (294,100);Sleep(300);
        Beep (330,200);Sleep(50);
        Beep (262,200);Sleep(50);
        Beep (220,200);Sleep(50);
        Beep (196,100);Sleep(700);
   
        Beep(330, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(330, 100); Sleep(300);
        Beep(262, 100); Sleep(100);
        Beep(330, 100); Sleep(300);
        Beep(392, 100); Sleep(700);
        Beep(196, 100); Sleep(700);
        Beep(196, 100); Sleep(125);
        Beep(262, 100); Sleep(125);
        Beep(330, 100); Sleep(125);
        Beep(392, 100); Sleep(125);
        Beep(523, 100); Sleep(125);
        Beep(660, 100); Sleep(125);
        Beep(784, 100); Sleep(575);
        Beep(660, 100); Sleep(575);
        Beep(207, 100); Sleep(125);
        Beep(262, 100); Sleep(125);
        Beep(311, 100); Sleep(125);
        Beep(415, 100); Sleep(125);
        Beep(523, 100); Sleep(125);
        Beep(622, 100); Sleep(125);
        Beep(830, 100); Sleep(575);
        Beep(622, 100); Sleep(575);
        Beep(233, 100); Sleep(125);
        Beep(294, 100); Sleep(125);
        Beep(349, 100); Sleep(125);
        Beep(466, 100); Sleep(125);
        Beep(587, 100); Sleep(125);
        Beep(698, 100); Sleep(125);
        Beep(932, 100); Sleep(575);
        Beep(932, 100); Sleep(125);
        Beep(932, 100); Sleep(125);
        Beep(932, 100); Sleep(125);
        Beep(1046, 675);
        */

    }

};
class SportCar : public Car //public private protected
{
    int turboSpeed;
public:
    SportCar() :turboSpeed(0), Car() {}
    SportCar(string m, float v, int y, int t) :turboSpeed(t), Car(m, v, y) {}
    void Drive()const override
    {
        cout << "I am a Sport Car! I can drive with speed  " << speed << " km/h" << endl;
    }
    void Print()const
    {
        Car::Print();
        cout << "Turbo Speed : " << turboSpeed << endl << endl;
    }
    void Nitro()
    {
        speed += turboSpeed;
        cout << "Turbo speed " << speed << " km/h" << endl;
    }

};



//polimorphism = virtual override

void TestDrive(Car &car) {
    car.SetSpeed(70);
    car.Drive();
    
}
void SetA(int a)
{
    a++;
    cout << a << endl;
}

int main()
{
    //int a = 5;
    //cout << a << endl;
    //SetA(a);
    //cout << a << endl;
    Car simpleCar("BMV", 3.5, 2018);
    simpleCar.SetSpeed(300);
    simpleCar.Drive();
    simpleCar.Print();

    PoliceCar police("Prius",2.5,2022,500);
    police.SetSpeed(300);
    //police.BeepBeep();
    police.Drive();
    police.Print();

    SportCar sport("Ford", 2.0, 2022, 40);
    sport.SetSpeed(220);
    sport.Nitro();
    sport.Drive();
    cout << "----------------------" << endl;
    TestDrive(simpleCar);
    TestDrive(police);
    TestDrive(sport);

    Car* carSalon[3]
    {
        new Car("BMV", 3.5, 2018),
        new PoliceCar("Prius",2.5,2022,500),
        new SportCar("Ford", 2.0, 2022, 40)
    };
   
    for (int i = 0; i < 3; i++)
    {
        carSalon[i]->Drive();
        carSalon[i]->Print();
        cout << endl;
    }
    
    for (int i = 0; i < 3; i++)
    {
        delete carSalon[i];
    }
    
}

