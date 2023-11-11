#include<iostream>
#include<iomanip>
#include<locale.h>
#include <windows.h>
#include<string>

using namespace std;

class String
{
	char* str;
	int num;
public:
	String(int n = 0);
	String(String& obj);
	String& operator = (const String& other);
	String operator + (const String& other);
	bool operator ==(const String& other);
	bool operator !=(const String& other);
	char& operator [] (int index);
	char* operator ()(int index1,int index2);
	String& operator += (const String& other);
	friend ostream& operator<< (ostream& os, const String point);
	friend istream& operator>>(istream& is,  String& point);
	~String();
};
String::String(int n1)
{
	num = n1;
	str = new char[num];
}
String::String(String& ob)
{
	num = ob.num;
	str = new char[ob.num];
	for (int i = 0; i < ob.num; i++)
	{
		str[i] = ob.str[i];
	}

}
String::~String()
{
	delete[] str;
}
String& String:: operator = (const String &other)
{
	this->num = other.num;
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
	this->str = new char[other.num];
	for (int i = 0; i < other.num; i++)
	{
		this->str[i] = other.str[i];
	}
	return *this;

}
bool String:: operator == (const String& other)
{
	bool res,res1;
	int kol=0;
	if (this->num == other.num)
	{
		res = true;
	}
	else
		return false;
	for (int i = 0; i < other.num; i++)
	{
		if (this->str[i] == other.str[i])
		{
			kol++;
		}
	}
	if (kol == other.num && res)
	{
		return true;
	}
	else return false;
	
}
bool String:: operator != (const String& other)
{
	bool res, res1;
	int kol = 0;
	if (this->num != other.num)
	{
		return true;
	}
	else
		res=false;
	for (int i = 0; i < other.num; i++)
	{
		if (this->str[i] == other.str[i])
		{
			kol++;
		}
	}
	if (kol != other.num)
	{
		return true;
	}
	else return false;
}
String String:: operator + (const String & other)
{
	String temp;
	temp.num = this->num + other.num;
	temp.str = new char[temp.num];
	for (int i = 0; i < this->num; i++)
	{
		temp.str[i] = this->str[i];
	} 
	for (int j = this->num; j < temp.num; j++)
	{
		temp.str[j] = other.str[j-this->num];
	}
	return temp;
}
char& String:: operator[] (int index)//we use & because it allows change infor,ation in string
{
	return str[index];
}
char* String:: operator() (int index1, int index2)
{
	char* temp1;
	int raz,j=0;
	raz = index2 - index1;
	temp1 = new char[raz];
	for (int i = index1; i <= index2; i++)
	{
		temp1[j] = this->str[i];
		j++;
	}
	return temp1;
}
String& String:: operator += (const String& other)
{
	char* st;
	int num1;
	num1 = this->num;
	st = new char[num1];
	for (int i = 0; i < num1; i++)
	{
		st[i] = this->str[i];
	}
	this->num += other.num;
	if (this->str != nullptr)
	{
		delete[] this->str;
	}
	this->str = new char[this->num];
	for (int i = 0; i < num1; i++)
	{
		this->str[i] = st[i];
	}
	int k = num1;
	for (int j = 0; j < other.num; j++)
	{
		this->str[k] = other.str[j];
		k++;
	}
	return *this;
	
}
ostream &  operator << (ostream & os, const String point)
{
	os <<"������ ������:"<<endl <<point.num << endl<<"���������� ������ :"<<endl;
	for (int i = 0; i < point.num; i++)
	{
		os << point.str[i];
	}
	return os;
}
istream& operator >> (istream& is,  String& point)
{
	
	cout << endl << "������� ������" << endl;
	for (int i = 0; i < point.num; i++)
	{

		is >> point.str[i];
	}

	return is;
}
int main()
{
	setlocale(LC_ALL, "Russian");
		int size, size1, a, loop = 0, first, second;
		char option;
		do
		{
			cout << "������� ������ ������ ������";
			cin >> size;
		} while (size <= 0);
		do
		{

			cout << "������� ������ ������ ������";
			cin >> size1;
		} while (size1 <= 0);
		String str1(size), str2(size1), str3;
		cin >> str1;
		rewind(stdin);
		cout << "���������� ������� �������" << endl;
		cout << str1;
		cin >> str2;
		rewind(stdin);
		cout << "���������� ������� �������" << endl;
		cout << str2;
		bool result, result1;
		char* st;
		do
		{
			cout << "�������� ������������� �������:" << endl << "1-'=='" << endl << "2-'!='" << endl << "3-'+'" << endl << "4-'[]'" << endl << "5-'(int,int)'" << endl << "6-'+='" << endl << "7-'='" << endl << "8-��������� ���������" << endl;
			cin >> option;
			if (option > '8' || option < '1' )
			{
				cout << "������������ ����";
				continue;
			}
			switch (option)
			{
			case '1':
				result = str1 == str2;
				if (result == true)
				{
					cout << endl << "ravno";
				}
				else cout << endl << "ne ravno"; break;
			case '2':
				result1 = str1 != str2;
				if (result1 == true)
				{
					cout << endl << "�������� �� ����� �������� �������";
				}
				else cout << endl << "�������� �� ����� �� �������� �������"; break;
			case '3':
				str3 = str1 + str2;
				cout << "�������� �������� ��������" << endl;
				cout << str3; break;
			case '4':cout << endl << "����� ������ �� �������� ������ �������� �������� � ������ 1";
				cin >> a;
				cout << endl << "�������� �������� [] ��� ������ ������" << endl << str1[a] << endl; break;
			case '5':
				cout << "������� ��� ������� ��� ��������� ()(int,int)";
				cin >> first;
				cin >> second;
				st = str1(first, second);
				cout << "�������� �������� ()(int,int)" << endl;
				for (int i = 0; i <= (second - first); i++)
				{
					cout << st[i];
				}break;
			case '6':
				str1 += str2;
				cout << "�������� ������������� �������� +=" << endl;
				cout << str1; break;
			case '7':cout << endl << "�������� ������������� �������� �����������" << endl;
				str1 = str2;
				cout << str1;; break;
			case '8':loop = 1; break;
			}
			cout << endl;
			rewind(stdin);
			system("Pause");
			system("cls");

		} while (loop == 0);

	
}
