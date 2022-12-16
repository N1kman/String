#pragma once
#include "standart.h"

class String
{
private:

	char* _str;  //указатель на строку

public:

	//конструктор по умолчанию
	String() : _str(nullptr) 
	{
		std::cout << "Вызов конструктора по умолчанию!" << std::endl;
	}

	//конструктор c параметром
	explicit String(const char* str) :_str(new char[strlen(str) + 1])
	{
		std::cout << "Вызов конструктора с параметром!" << std::endl;
		strcpy_s(_str, strlen(str) + 1, str);
	}

	//конструктор копирования
	String(const String& T) :_str(new char[strlen(T._str) + 1])
	{
		std::cout << "Вызов конструктора копирования!" << std::endl;
		strcpy_s(_str, strlen(T._str) + 1, T._str);
	}

	//конструктор перемещения
	String(String&& T) noexcept : _str(T._str)
	{
		std::cout << "Вызов конструктора перемещения!" << std::endl;
		T._str = nullptr;
	}

	//деструктор
	~String()
	{
		std::cout << "Вызов деструктора!" << std::endl;
		if (_str)
			delete[]_str;
	}

	//перегрузка оператора присваивания
	String& operator=(const String& T);

	//перегрузка оператора присваивания 
	String& operator=(const char* str);

	//перегрузка оператора сложения
	String operator+(const char* str);

	//перегрузка оператора сложения
	String operator+(const String& T);

	//перегрузка оператора сложения
	String operator+(const char& c);

	//перегрузка оператора сложения
	String operator-(const char& c);

	//перегрузка оператора сложения
	friend String operator+(const char* str, const String& T);

	//перегрузка оператора []
	char& operator[](int position);

	//перегрузка оператора !=
	bool operator!=(const String& T);

	//перегрузка оператора ==
	bool operator==(const String& T);

	//перегрузка оператора !=
	bool operator!=(const char* str);

	//перегрузка оператора ==
	bool operator==(const char* str);

	//перегрузка оператора +=
	void operator+=(const char* str);

	//перегрузка оператора +=
	void operator+=(const String& T);

	//перегрузка оператора()
	String operator()(int pos1, int pos2);

	//перегрузка вывода
	friend std::ostream& operator<<(std::ostream& out, const String& T);

	//быстрый и черновой ввод String
	friend std::istream& operator>>(std::istream& is, String& st);

	//оператор присваивания перемещения
	String& operator=(String&& obj) noexcept;
};

