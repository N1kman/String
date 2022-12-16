#pragma once
#include "standart.h"

class String
{
private:

	char* _str;  //��������� �� ������

public:

	//����������� �� ���������
	String() : _str(nullptr) 
	{
		std::cout << "����� ������������ �� ���������!" << std::endl;
	}

	//����������� c ����������
	explicit String(const char* str) :_str(new char[strlen(str) + 1])
	{
		std::cout << "����� ������������ � ����������!" << std::endl;
		strcpy_s(_str, strlen(str) + 1, str);
	}

	//����������� �����������
	String(const String& T) :_str(new char[strlen(T._str) + 1])
	{
		std::cout << "����� ������������ �����������!" << std::endl;
		strcpy_s(_str, strlen(T._str) + 1, T._str);
	}

	//����������� �����������
	String(String&& T) noexcept : _str(T._str)
	{
		std::cout << "����� ������������ �����������!" << std::endl;
		T._str = nullptr;
	}

	//����������
	~String()
	{
		std::cout << "����� �����������!" << std::endl;
		if (_str)
			delete[]_str;
	}

	//���������� ��������� ������������
	String& operator=(const String& T);

	//���������� ��������� ������������ 
	String& operator=(const char* str);

	//���������� ��������� ��������
	String operator+(const char* str);

	//���������� ��������� ��������
	String operator+(const String& T);

	//���������� ��������� ��������
	String operator+(const char& c);

	//���������� ��������� ��������
	String operator-(const char& c);

	//���������� ��������� ��������
	friend String operator+(const char* str, const String& T);

	//���������� ��������� []
	char& operator[](int position);

	//���������� ��������� !=
	bool operator!=(const String& T);

	//���������� ��������� ==
	bool operator==(const String& T);

	//���������� ��������� !=
	bool operator!=(const char* str);

	//���������� ��������� ==
	bool operator==(const char* str);

	//���������� ��������� +=
	void operator+=(const char* str);

	//���������� ��������� +=
	void operator+=(const String& T);

	//���������� ���������()
	String operator()(int pos1, int pos2);

	//���������� ������
	friend std::ostream& operator<<(std::ostream& out, const String& T);

	//������� � �������� ���� String
	friend std::istream& operator>>(std::istream& is, String& st);

	//�������� ������������ �����������
	String& operator=(String&& obj) noexcept;
};

