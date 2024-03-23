#include <iostream>
#include <map>
#include <iomanip>
using namespace std;

map<string, int>::iterator findByValue(map<string, int>& m, int value)
{
    for (map<string,int>::iterator i = m.begin(); i != m.end(); i++)
    {
        if (i->second == value)
        {
            return i;
        }
    }
    return m.end();
}

struct ID
{
    int id;
    string name;

    ID() {}
    ID(int id, string name) : id(id), name(name) {}

    void Show() const
    {
        cout << "ID: " << id << endl;
        cout << "Name: " << name << endl;
    }
    bool operator < (const ID& other)const
    {
        return this->name < other.name;
    }

};

int main()
{

    map<ID, int> myMap;

    ID id(1, "Taras");
    pair<ID, int> p1(id, 10);
    myMap.insert(p1);

    myMap.insert(make_pair(ID(2, "Anna"), 5));
    myMap.insert(make_pair(ID(5, "Tom"), 8));
    myMap.insert(make_pair(ID(3, "Jack"), 2));

    for (auto el : myMap)
    {
        el.first.Show();
        cout << "Value : " << el.second << endl;
        cout << "__________________________" << endl;
    }
    cout << endl;
    myMap[ID(7, "Anna")] = 15;

    for (auto el : myMap)
    {
        el.first.Show();
        cout << "Value : " << el.second << endl;
        cout << "__________________________" << endl;
    }


    /*

    map<string, int> m;
    m.insert(pair<string, int>("Olga", 5));
    pair<string, int> p("Pavlo", 6);
    m.insert(p);

    m.insert(make_pair("Mukola", 7));

    for (auto item : m)
    {
        cout << left<<setw(10) <<"Key : "<< setw(10) << item.first << setw(10) << " Value : "<< setw(10) << item.second << endl;
    }
    cout << "_________________________________" << endl;
     auto res =  m.insert(make_pair("Ivanka", 9));
     if (res.second)
     {
         cout << "Added!" << endl;
     }
     else
     {
         cout << "This key is in list " << endl;
     }

    for (auto item : m)
    {
        cout << left << setw(10) << "Key : " << setw(10) << item.first << setw(10) << " Value : " << setw(10) << item.second << endl;
    }

    cout << "Value : " << m["Olga"] << endl;
    cout << "Value : " << m["Ivanka"] << endl;

    map<string, int>::iterator it = m.find("Olga");
    if (it == m.end())
    {
        cout << "Not found " << endl;
    }
    else
    {
        cout << "Found !" << endl;
        cout << left << setw(10) << "Key : " << setw(10) << it->first << setw(10) 
            << " Value : " << setw(10) << it->second << endl;

        //it->first = "Anna";//error
        it->second = 55;

        cout << left << setw(10) << "Key : " << setw(10) << it->first << setw(10)
            << " Value : " << setw(10) << it->second << endl;

    }


    it =  findByValue(m, 9);
    if (it != m.end())
    {
        cout << left << setw(10) << "Key : " << setw(10) << it->first << setw(10)
            << " Value : " << setw(10) << it->second << endl;
    }
    cout << "_________________________________" << endl;

    for (auto item : m)
    {
        cout << left << setw(10) << "Key : " << setw(10) << item.first << setw(10) << " Value : " << setw(10) << item.second << endl;
    }

    if (it != m.end())
        m.erase(it);

    cout << "_________________________________" << endl;

    for (auto item : m)
    {
        cout << left << setw(10) << "Key : " << setw(10) << item.first << setw(10) << " Value : " << setw(10) << item.second << endl;
    }
    m["Oleksandr"] = 444;
    m["Mukola"] = 444;
    cout << m["Oleksandr"] << endl;
    cout << m["Mukola"] << endl;
   

    cout << "_________________________________" << endl;

    for (auto item : m)
    {
        cout << left << setw(10) << "Key : " << setw(10) << item.first << setw(10) << " Value : " << setw(10) << item.second << endl;
    }

    */

}

