#include <iostream>
#include<locale>
#include<string>
#include<fstream>
#include"List.h"
#include"menu.h"
#include"Exp_file.h"
	using namespace std;
	int main()
	{
		setlocale(LC_ALL, "Russian");
		/*ofstream f;
		try
		{
			f.open("file.txt");
			if (f.is_open())throw Exp_file(3, "Ошибка открытия файла");
		}
		catch (Exp_file& error)
		{
			error.Show();
			f.close();
		}
		f.close();*/
		int type;
		bool choose_type = 0;
		List<int> lst_int;
		List<bool> lst_bool;
		List<char> lst_char;
		List<string> lst_str;
		List<float> lst_float;
		do
		{
			cout << "Введите тип данных которые должен содержать список" << endl << "1-int" << endl << "2-bool" << endl << "3-char" << endl << "4-string" << endl << "5-float" << endl;
			try
			{
				if(!(cin>>type))throw Exp_vvod(123, "Вводите только целые числа");
				if(type<0||type>5)throw Exp_vvod(123, "Вы вышли за границы указанного диапазона");
			}
			catch (Exp_vvod& error)
			{
				error.Show();
				cin.clear();
				cin.ignore(10, '\n');
			}
			switch (type)
			{
			case 1:
				menu1(lst_int);
				choose_type = 1;
				break;
			case 2:
				menu1(lst_bool);
				choose_type = 1;
				break;
			case 3:
				menu1(lst_char);
				choose_type = 1;
				break;
			case 4:
				menu1(lst_str);
				choose_type = 1;
				break;
			case 5:
				menu1(lst_float);
				choose_type = 1;
				break;
			default:
				break;
			}

		} while (choose_type == 0);
		
	}