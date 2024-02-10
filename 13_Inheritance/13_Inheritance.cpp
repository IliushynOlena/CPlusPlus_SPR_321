#include <iostream>
using namespace std;

class Hero
{
    //private  public  protected
protected://private
    string name;
    int health;
    float strength;
public:
    Hero() :name("no name"), health(100), strength(0) {}
    Hero(string n, float s) :name(n), health(100), strength(s) {}
    void Print()const
    {
        cout << "Name : " << name << endl;
        cout << "Health : " << health << "%" << endl;
        cout << "Strength : " << strength << endl;
    }
    void DecreaseHealth(int value)
    {
        //3 - 10
        if (health - value < 0)
            health = 0;
        else
            health -= value;

    }
    bool IsAlive()const
    {
        return health > 0;
    }        
};
//Inheritance
//class Child : [spetificator] Parent
class Dragon : public Hero
{
    float fire;//5
public:
    Dragon():fire(0),Hero(){}
    Dragon(string n, float s, float f):fire(f),Hero(n,s){}

    void Fight(int damage)//20-5 = 15
    {
        cout << "Getting " << damage << " damage......" << endl;
        DecreaseHealth(damage - fire);
        cout << "Health after figth" << health << " %" << endl;
    }
    float Attack()
    {
        cout << "Attacking with strength " << strength << endl;
        return strength;
    }

    void Print()const
    {
        cout << "------------------Dragon----------------------" << endl;
        Hero::Print();
        cout << "Fire : " << fire << endl;
    }


};
class Monster: public Hero
{
    float runSpeed;
public:
    Monster():runSpeed(0),Hero(){}
    Monster(string n, float s, float r):runSpeed(r),Hero(n,s){}

    void Print()const
    {
        cout << "------------------Monster----------------------" << endl;
        Hero::Print();
        cout << "Run Speed : " << runSpeed << endl;
    }
    void Run()
    {
        cout << "I am runiing with speed " << runSpeed << " km/h" << endl;
    }
};
int main()
{
    Dragon boss("Boss",5, 2);
    boss.Print();
    Dragon dragon("Tom", 4, 1);
    dragon.Print();
    int i = 1;
    do
    {
        cout << "----------- Round [" << i << "]---------------" << endl;
        boss.Fight(dragon.Attack());
        cout << endl;
        dragon.Fight(boss.Attack());

        boss.Print();
        dragon.Print();
        i++;

    } while (boss.IsAlive() && dragon.IsAlive());

    
    Monster monster("Zombi", 1, 150);
    monster.Print();
    monster.Run();
}
