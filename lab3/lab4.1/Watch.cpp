#include"Watch.h"
#include<iostream>
using namespace std;
Watch::Watch()
{
	automatic = 1;
}
void Watch::input()
{
	rewind(stdin);
	char autom;
	bool loop;
	cout << "Часы автоматические ?" << endl << "1-Да" << endl << "2-Нет" << endl;
	do
	{
		loop = 1;
		cin >> autom;
		switch (autom)
		{
		case '1':
			this->automatic = 1;
			break;
		case '2':
			this->automatic = 0;
			break;
		default:
			cout << "Введено не верное значение, повторите ввод";
			rewind(stdin);
			loop = 0;
			break;

		}
	} while (loop == 0);
	Mechanic::input();
	Clock::input();


}
void Watch::output()
{
	cout << "Характериски часов :" << endl;
	if (automatic == true)
	{
		cout << "Автоматические" << endl;
	}
	else cout << "Не автоматические" << endl;
	Mechanic::output();
	Clock::output();
}