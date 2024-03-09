#include <iostream>
#include <string>
#include <fstream> // бібліотека класів для роботи з файлами
using namespace std;

// ————————————————————
// Файловий ввід/вивід
// ————————————————————


/*
	Часто виникає потреба зберегти/зчитати якусь інформацію беспосередньо з файла.
	Що таке файл? Це група байтів, збережена на накопичувачу (HDD, SSD, DVD диск і тд.).
	Управлінням файлами займається операційна система, програмі лише потрібен спосіб для роботи з ними.
	Під робото з файлом, мається на увазі відкриття, зчитування його вмісту, створення та запис файлів програмою.

	С++ надає пакет класів, які забеспечують цю роботу (знаходяться вони в бібліотеці fstream):
		ofstream	- об'єкт для запису інформації в файл
		ifstream	- для читання
		fstream		- одночасно як для запису, так і для читання

	Для того, щоб об'єкт працював з якимось конкретним файлом, потрібно викликати метод open
	Метод приймає два параметри:
		1 - повна назва файлу
			Якщо файл знаходиться в проекті, вказуєте лише його зазву, до
			прикладу "..\folder\fileName.txt"
			Якщо поза межами проекту, в іншій папці, тоді повний шлях, до 
			прикладу "C:\Users\Ivan\Documents\fileName.txt"
			! пам'ятайте, щоб ввести символ '\' потріно написати '\\'

		2 - режим відкриття файла
			Перелік режимів відкриття знаходиться в класі ios_base. Ось список:
				ios_base::in		- відкрити файл для читання
				ios_base::out		- відкрити файл для запису
				ios_base::ate		- перейти вкінець файла, після його відкриття
				ios_base::app		- дописувати дані
				ios_base::trunc		- очистити файл, якщо він існує
				ios_base::binary	- бінарний режим

			Режими можна комбінувати ставлячи між ними бітову операцію або '|'

	До того ж для об'єктів ofstream та ifstream останній парамети є не обов'язковим,
	він набуде значення по замовчуванню:
		для ofstream - ios_base::out
		для ifstream - ios_base::in

	Після зв'язування об'єкта з конкретним файлом, за допомогою open, зчитавати чи записувати
	інформацію
	можна так, як би ви працювали з операторами cin та cout
*/

// Описуємо структуру, яку будемо зберігати
struct Product
{
#pragma region Product List
	char name[20];
	double price;
	bool isInStock;
#pragma endregion



};

void main(int argc, char* argv[])
{
#pragma region Write to File
	// Запис інформації в файл, очищаючи перед цим весь вміст
	// ——————————————————————————————————————————————————————

	// Перш за все створюємо об'єкт ofstream
	
	//ofstream fileOut("new_file.txt", ios_base::out);
	////fileOut.open("new_file.txt", ios_base::out);
	//// Зв'язуємо його з конкретним файлом
	//// Якщо такого файла не існує, програма його створить
	////fileOut.open("new_file.txt", ios_base::out); // "C:\\Users\\Guest\\Desktop\\test.txt"

	//// Перевірка чи відкрито файл
	//if (fileOut.is_open())	
	//	cout << "File successfully opened!" << endl;
	//else
	//{
	//	cout << "Error opening file!" << endl;
	//	//exit(0);
	//}
	//cout << "File successfully opened!" << endl;

	//////// //Запис можна провести таким чином як працює cout
	//char c_str[] = "Hello!!!";
	//string str = "Hello!!!";
	//fileOut << "Hello" << endl;
	//fileOut << "kldgdlkhldfkhl fgnjfgjg gh fghfgh f" << endl;
	//fileOut << "First line." << endl;
	//fileOut << "Second line." << str << "\n";
	//fileOut.write(c_str + 2, sizeof(c_str) - 2);
	//fileOut.write(c_str, sizeof(c_str));
	//// Після завершення роботи закриваємо потік
	//cout << sizeof(c_str) << endl;
	//cout << sizeof(int) << endl;
	//cout << sizeof(string) << endl;
	//cout << sizeof(str) << endl;
	//cout << sizeof(Product) << endl;
	//fileOut.close();
	
	//system("pause");
#pragma endregion

#pragma region Read from File
// Зчитування інформації з файлу
// —————————————————————————————

// Створення об'єкта ifstream
//ifstream fileIn;
//ifstream fileIn("new_file.txt", ios_base::in);

// //Зв'язуємо його з конкретним файлом
// //Файл повинен бути створений
//fileIn.open("new_file.txt", ios_base::in);

 //Читання інформації посимвольно
//char symbol;
//
//while (!fileIn.eof())		// перевірка чи не досягнуто кінця файла (end of file)
//{
//	//fileIn.get(symbol);		// читає всі символи без виключення
//	fileIn >> symbol;		// цей варіант ігнорує всі пробільні символи (пробіл, табуляція, новий рядок)			
//	//if(!fileIn.eof())
//	cout << symbol;			// вивід символу на екран
//	//fileOut << symbol << "-";
//}
//fileIn.close();

// Читання інформації цілими словами, до пробільного символа
// " " "\t" "\n" - пробільні символи
/* How are you?
   Second line.
*/
//char word[100];
//string str1;
//
//while (!fileIn.eof())		// перевірка чи не досягнуто кінця файла
//{
//	fileIn >> str1;			// зчитує до першого пробільного символа
//							// пробільні символи також відкидаються
//	
//	cout << str1 << endl;	// вивід cлів з нового рядка
//}


//// Читання інформації цілими рядками
//char str[255];
//string str1;
//cin >> str;
//cout << str << endl;

//cin.getline();
//char name[50];
//cout << "Enter name : ";
//
//cin.getline(name, 50);//cin >> name;
//cout << "Name : " << name << endl;
//while (!fileIn.eof())			// перевірка чи не досягнуто кінця файла
//{
//	//fileIn.getline(str, 255);
//	//fileIn.getline(str, 255);	// зчитує до символу нового рядка
//								// символ нового рядка відкидається
//	getline(fileIn, str1);
//	//fileIn >> str;
//	cout << str1 << "!" << endl;		// вивід зчитаного рядка
//}
//
////////// Закриття потоку
//fileIn.close();

//system("pause");
#pragma endregion

#pragma region Append to File
// Дозапис інформації в файл без очистки вмісту
// ————————————————————————————————————————————

// Можна використати вже створений раніше об'єкт (fileOut),
// який завершив роботу з файлом методом close

// Відкриваємо файл в режимі дозапису
//ofstream fOut("new_file.txt", ios_base::out);
//
//////// //Наступна операція запише відповідний рядок вкінець файлу, залишивши початковий вміст
//fOut << "Finally. The End!"<<endl;
//fOut << "Hekdsjkldshjskdg!"<<endl;
////
//fOut.close();
//
//////////// Використання вже існуючого об'єкту для роботи з файлом
//fOut.open("new_file.txt", ios_base::trunc);
//fOut << "Truncated file!!!";
//fOut.close();

//system("pause");
#pragma endregion

#pragma region Binary Mode
// Бінарний режим вводу/виводу
// ———————————————————————————
// Особливість бінарного режиму в тому, що ви можете як записувати так і зчитвати
// будь-які дані, починаючи від масивів, закінчуючи структурами

// Бінарний запис
// ——————————————

// Відкриваємо файл для запису в бінарному режимі
//ofstream fileOut("binary.bin", ios_base::out | ios_base::binary);
//
//// Створюємо екземпляр структури
//Product prodOut { "Headphones", 337.5, true };
//
//// Для бінарного запису викликаємо метод write, який приймає два параметри:
////	1 - адресу елемента, який потрібно записати, приведену до типу char*
////	2 - розмір елемента в байтах
//
//
//fileOut.write((char *)&prodOut, sizeof(prodOut));
//
////// sizeof(type|variable) - повертає розмір типа, змінної в байтах
//cout << sizeof(int) << endl;
//
//fileOut.close();
//system("pause");

//// Бінарне читання
//// ———————————————

//// Відкриваємо файл для читання в бінарному режимі
	ifstream fileIn("binary.bin", ios_base::in | ios_base::binary);

	// Створюємо не ініціалізований екземпляр структури, в який запишемо дані з файлу
	Product prodIn;

	/* Для бінарного читання викликаємо метод read, який приймає ті ж аргументи, що і write:
		1 - адресу елемента, в який буде записано результат, приведену до типу char*
		2 - розмір елемента в байтах*/

	fileIn.read((char*)&prodIn, sizeof(prodIn));

	fileIn.close();

	// Перевіряємо результат
	//cout << "prodOut: " << prodOut.name << " " << prodOut.price << " " << prodOut.isInStock << endl;	// записані дані
	cout << "prodIn: " << prodIn.name << " " << prodIn.price << " " << prodIn.isInStock << endl;		// зчитані дані

#pragma endregion

	system("pause");
	//
}