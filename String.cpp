#include "String.h"

//���������� ��������� ������������
String& String::operator=(const String& T)
{
	cout << "����� ��������� ������������!" << endl;
	if (this != &T)                          //�������� �� ������������ ������ ����
	{
		delete[] _str;                                 //������� ������
		_str = new char[strlen(T._str) + 1];           //��������� ������
		strcpy_s(_str, strlen(T._str) + 1, T._str);    //����������� ������
	}
	return *this;
}

//���������� ��������� ������������
String& String::operator=(const char* str)
{
	cout << "����� ��������� ������������!" << endl;
	delete[] _str;                            //������� ������
	_str = new char[strlen(str) + 1];         //��������� ������
	strcpy_s(_str, strlen(str) + 1, str);     //����������� ������
	return *this;
}

//���������� ��������� ��������
String String::operator+(const char* str)
{
	cout << "����� ��������� ��������!" << endl;
	String buff;                                              //����� ������
	buff._str = new char[strlen(_str) + strlen(str) + 1];     //��������� ������
	strcpy_s(buff._str, strlen(_str) + strlen(str) + 1, _str);
	strcat_s(buff._str, strlen(_str) + strlen(str) + 1, str);
	return buff;
}

//���������� ��������� ��������
String String::operator+(const String& T)
{
	cout << "����� ��������� ��������!" << endl;
	String buff;                                                 //����� ������
	buff._str = new char[strlen(_str) + strlen(T._str) + 1];     //��������� ������
	strcpy_s(buff._str, strlen(_str) + strlen(T._str) + 1, _str);
	strcat_s(buff._str, strlen(_str) + strlen(T._str) + 1, T._str);
	return buff;
}

//���������� ��������� ��������
String String::operator+(const char& c)
{
	cout << "����� ��������� ��������!" << endl;
	String buff;                                              //����� ������
	buff._str = new char[strlen(_str) + 2];                   //��������� ������
	strcpy_s(buff._str, strlen(_str) + 2, _str);
	buff[strlen(_str)] = c;
	buff[strlen(_str) + 1] = '\0';
	return buff;
}

//���������� ��������� ��������
String String::operator-(const char& c)
{
	cout << "����� ��������� ��������!" << endl;
	String buff;                                              //����� ������
	buff._str = new char[strlen(_str) + 1];                   //��������� ������
	int j = 0;
	for (int i = 0; i < strlen(_str) + 1; ++i)
		if (_str[i] != c)buff[j++] = _str[i];
	buff[j] = '\0';
	return buff;
}

//���������� ��������� []
char& String::operator[](int position)
{
	return _str[position];
}

//���������� ��������� !=
bool String::operator!=(const String& T)
{
	return strcmp(_str, T._str);
}

//���������� ��������� ==
bool String::operator==(const String& T)
{
	return !(*this != T);
}

//���������� ��������� !=
bool String::operator!=(const char* str)
{
	return strcmp(_str, str);
}

//���������� ��������� ==
bool String::operator==(const char* str)
{
	return !(*this != str);
}

//���������� ��������� +=
void String::operator+=(const char* str)
{
	cout << "����� ��������� += !" << endl;
	*this = *this + str;
}

//���������� ��������� +=
void String::operator+=(const String& T)
{
	cout << "����� ��������� += !" << endl;
	*this = *this + T;
}

//���������� ���������()
String String::operator()(int pos1, int pos2)
{
	cout << "����� ��������� ������� ������!" << endl;
	String buff;
	buff._str = new char[pos2 - pos1 + 2];

	for (int j = 0, i = pos1; i <= pos2; i++, j++)
		buff._str[j] = _str[i];
	buff._str[pos2 - pos1 + 1] = 0;

	return buff;
}

//���������� ��������� ��������
String operator+(const char* str, const String& T)
{
	cout << "����� ��������� ��������!" << endl;
	String buff;                                             //����� ������
	buff._str = new char[strlen(str) + strlen(T._str) + 1];  //��������� ������
	strcpy_s(buff._str, strlen(str) + strlen(T._str) + 1, str);
	strcat_s(buff._str, strlen(str) + strlen(T._str) + 1, T._str);
	return buff;
}

//���������� ������
std::ostream& operator<<(std::ostream& out, const String& T)
{
	out << T._str;
	return out;
}

//���� String
std::istream& operator>>(std::istream& is, String& T)
{
	char buff[_length];

	rewind(stdin);
	is.getline(buff, _length);

	T = buff;

	return is;
}

//�������� ������������ �����������
String& String::operator=(String&& T) noexcept
{
	cout << "����� ��������� ������������ �����������!" << endl;
	if (*this != T)
	{
		delete[] _str;
		_str = T._str;
		T._str = nullptr;
	}
	return *this;
}