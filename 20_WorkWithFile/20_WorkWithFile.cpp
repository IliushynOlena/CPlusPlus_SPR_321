#include <iostream>
using namespace std;
//class Book{};
//class List
//{
//private:
//    int size;
//public:
//	List():size(0){}
//	List(int s):size(s){}
//
//	Book GetPosition(int pos)
//	{
//		if (size == 0) return 1 ;//return = break;
//		if (pos < 0 || pos > size) return 2;
//
//		return Book();//2
//	}
//};
float Divide(float a, float b)
{
    float res = 0;
    //exception ex("Can't divide by zero ! You neeed study math!!!");
    if (b == 0)
    {
        //throw ex;
        throw exception("Can't divide by zero ! You neeed study math!!!");
    }
    if (b == 1)
    {
        throw 404;
    }
    if (b == 2)
    {
        throw "Divide by 2";
    }
    else
    {
       
        res = a / b;
        cout << "Res : " << res << endl;
        return res;
    }    
}

class PasswordInvalidException : public exception
{
public:
    PasswordInvalidException(const char* message) : exception(message) {}
};
class PasswordIsSmallException : public exception
{
    int lenght;
public:
    PasswordIsSmallException(const char* message, int length) :lenght(lenght),
        exception(message) {}
    void Message()const
    {
        cout << what() << endl;
        cout << "Actual length : " << lenght << endl;
    }
};
void Login(const char* login, const char* password)
{
    if (strlen(password) < 6)
        throw PasswordIsSmallException( "To small password", strlen(password));
    if (!isalpha(password[0]) || !islower(password[0]))
        throw PasswordInvalidException("Password is invalid" );
    if (!isalpha(login[0]) || !isupper(login[0]))
        throw exception("Login is invalid" );
    cout << "Loading.........." << endl;
}

int main()
{
    char login[100];
    char password[100];
    for (int i = 0; i < 5; i++)
    {
        try
        {
            cout << "Enter login : ";
            cin >> login;
            cout << "Enter password : ";
            cin >> password;
            Login(login, password);
        }       
        catch (PasswordInvalidException ex)
        {
            cout << "Invalid .... do something....." << endl;
            cout << ex.what() << endl;
            cout << " You need to use : a-z, 0-9" << endl;
        }
        catch (PasswordIsSmallException ex)
        {
            cout << "Small .... do something....." << endl;
            cout << ex.what() << endl;
            cout << " You need to use length > 6" << endl;
        }
        catch (const exception ex)
        {
            cout << ex.what() << endl;
        }
        catch (...)
        {
            cout << "Unknown exception";
        }
       
    }
    /*
    string name;
    float a, b;
    cout << "Enter numbers : ";
    cin >> a >> b;
    try
    {
        float res = Divide(a, b);
        cout << "Res from function : " << res << endl;
    }
    catch (const exception ex)
    {
        cout << ex.what() << endl;
    }
    catch (int ex)
    {
        cout << ex << endl;

    }
    catch (const char * ex)
    {
        cout << ex << endl;
    }
    catch (...)
    {
        cout << "Unknown exception";
    }
    
   //try   catch throw
   */
}

