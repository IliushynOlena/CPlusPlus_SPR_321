#include"Library.h"

Library ShowLibrary(Library &lib)//copy
{
    Book book1("C++ for Begginers", "Stiven Prata", 2000, 1500, Science);
    Library temp ;//operator = 
    temp.AddNewBook(book1);
    //write code....add element... delete element
    return temp;//copy constructor
}
class Test
{
    //default costructor
    //destructor
    //constructor copy
    //operator =
};



int main()
{


    Book book1("C++ for Begginers", "Stiven Prata", 2000, 1500, Science);
      Book book2("Harry Potter", "J.K.Rowling", 1997, 800, Fantasy);
      Book book3("Sherlock Holmes", "Arthur Conan Doyle", 1887,  2000, Genre::Detective);
      Book book4("Java for kids", "Morgan Nick", 2015, 408, Science);
      Book book5("Mowgli", "Pantera", 1893,500, Genre::Fantasy);
      Book book6("Financier", "Dreiser Theodore", 1911,  377, Genre::Science);
    //book1.ShowInfo();

      Library lib("Library ", "Kyivska 16");
      lib.AddNewBook(book1);
      lib.AddNewBook(book2);
      lib.AddNewBook(book3);
      lib.AddNewBook(book4);
      lib.Show();


      Library copy(lib);//copy costructor
      copy.Show();

      copy = lib;//operator =
      Library testLb =  ShowLibrary(lib);

      Library test;
      test = copy= lib ;

      int a = 5, b = 7, c = 10;
      a = b = c;

}

