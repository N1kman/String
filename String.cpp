#include "String.h"

//перегрузка оператора присваивания
String& String::operator=(const String& T)
{
	cout << "Вызов оператора присваивания!" << endl;
	if (this != &T)                          //проверка на присваивание самому себе
	{
		delete[] _str;                                 //очистка памяти
		_str = new char[strlen(T._str) + 1];           //выделение памяти
		strcpy_s(_str, strlen(T._str) + 1, T._str);    //копирование строки
	}
	return *this;
}

//перегрузка оператора присваивания
String& String::operator=(const char* str)
{
	cout << "Вызов оператора присваивания!" << endl;
	delete[] _str;                            //очистка памяти
	_str = new char[strlen(str) + 1];         //выделение памяти
	strcpy_s(_str, strlen(str) + 1, str);     //копирование строки
	return *this;
}

//перегрузка оператора сложения
String String::operator+(const char* str)
{
	cout << "Вызов оператора сложения!" << endl;
	String buff;                                              //новый объект
	buff._str = new char[strlen(_str) + strlen(str) + 1];     //выделение памяти
	strcpy_s(buff._str, strlen(_str) + strlen(str) + 1, _str);
	strcat_s(buff._str, strlen(_str) + strlen(str) + 1, str);
	return buff;
}

//перегрузка оператора сложения
String String::operator+(const String& T)
{
	cout << "Вызов оператора сложения!" << endl;
	String buff;                                                 //новый объект
	buff._str = new char[strlen(_str) + strlen(T._str) + 1];     //выделение памяти
	strcpy_s(buff._str, strlen(_str) + strlen(T._str) + 1, _str);
	strcat_s(buff._str, strlen(_str) + strlen(T._str) + 1, T._str);
	return buff;
}

//перегрузка оператора сложения
String String::operator+(const char& c)
{
	cout << "Вызов оператора сложения!" << endl;
	String buff;                                              //новый объект
	buff._str = new char[strlen(_str) + 2];                   //выделение памяти
	strcpy_s(buff._str, strlen(_str) + 2, _str);
	buff[strlen(_str)] = c;
	buff[strlen(_str) + 1] = '\0';
	return buff;
}

//перегрузка оператора сложения
String String::operator-(const char& c)
{
	cout << "Вызов оператора сложения!" << endl;
	String buff;                                              //новый объект
	buff._str = new char[strlen(_str) + 1];                   //выделение памяти
	int j = 0;
	for (int i = 0; i < strlen(_str) + 1; ++i)
		if (_str[i] != c)buff[j++] = _str[i];
	buff[j] = '\0';
	return buff;
}

//перегрузка оператора []
char& String::operator[](int position)
{
	return _str[position];
}

//перегрузка оператора !=
bool String::operator!=(const String& T)
{
	return strcmp(_str, T._str);
}

//перегрузка оператора ==
bool String::operator==(const String& T)
{
	return !(*this != T);
}

//перегрузка оператора !=
bool String::operator!=(const char* str)
{
	return strcmp(_str, str);
}

//перегрузка оператора ==
bool String::operator==(const char* str)
{
	return !(*this != str);
}

//перегрузка оператора +=
void String::operator+=(const char* str)
{
	cout << "Вызов оператора += !" << endl;
	*this = *this + str;
}

//перегрузка оператора +=
void String::operator+=(const String& T)
{
	cout << "Вызов оператора += !" << endl;
	*this = *this + T;
}

//перегрузка оператора()
String String::operator()(int pos1, int pos2)
{
	cout << "Вызов оператора круглые скобки!" << endl;
	String buff;
	buff._str = new char[pos2 - pos1 + 2];

	for (int j = 0, i = pos1; i <= pos2; i++, j++)
		buff._str[j] = _str[i];
	buff._str[pos2 - pos1 + 1] = 0;

	return buff;
}

//перегрузка оператора сложения
String operator+(const char* str, const String& T)
{
	cout << "Вызов оператора сложения!" << endl;
	String buff;                                             //новый объект
	buff._str = new char[strlen(str) + strlen(T._str) + 1];  //выделение памяти
	strcpy_s(buff._str, strlen(str) + strlen(T._str) + 1, str);
	strcat_s(buff._str, strlen(str) + strlen(T._str) + 1, T._str);
	return buff;
}

//перегрузка вывода
std::ostream& operator<<(std::ostream& out, const String& T)
{
	out << T._str;
	return out;
}

//ввод String
std::istream& operator>>(std::istream& is, String& T)
{
	char buff[_length];

	rewind(stdin);
	is.getline(buff, _length);

	T = buff;

	return is;
}

//оператор присваивания перемещения
String& String::operator=(String&& T) noexcept
{
	cout << "Вызов оператора присваивания перемещения!" << endl;
	if (*this != T)
	{
		delete[] _str;
		_str = T._str;
		T._str = nullptr;
	}
	return *this;
}