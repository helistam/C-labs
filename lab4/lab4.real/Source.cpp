#include <iostream>
#include<locale>
#include<string>
#include"List.h"
#include"menu.h"

using namespace std;
int main()
{
	char type;
	bool choose_type = 0;
	setlocale(LC_ALL, "Russian");
	List<int> lst_int;
	List<bool> lst_bool;
	List<char> lst_char;
	List<string> lst_str;
	List<float> lst_float;
	do
	{
		cout << "Введите тип данных которые должен содержать список"<<endl<<"1-int"<<endl<<"2-bool" <<endl<< "3-char" << endl <<"4-string" << endl <<"5-float" << endl ;
		cin >> type;
		switch (type)
		{
		case'1':
			menu1(lst_int);
			choose_type = 1;
			break;
		case'2':
			menu1(lst_bool);
			choose_type = 1;
			break;
		case'3':
			menu1(lst_char);
			choose_type = 1;
			break;
		case'4':
			menu1(lst_str);
			choose_type = 1;
			break;
		case'5':
			menu1(lst_float);
			choose_type = 1;
			break;
		default:
			break;
		}

	} while (choose_type == 0);
}
