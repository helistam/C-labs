#include"WallClock.h"
#include<iostream>
#include"ExpVvod.h"
using namespace std;
void WallClock::input()
{
	int a;
	bool loop,b;
	cout << "Есть ли у часов маятник " << endl << "1-Да" << endl << "2-Нет" << endl;
	do
	{
		loop = 1;
		b = 1;
		while (b)
		{
			try
			{
				if (!(cin >> a)||a<0||a>2)throw Exp_vvod(123, "Неправильный ввод");
				b = 0;
			}
			catch (Exp_vvod& ex)
			{
				ex.Show();
				cin.clear();
				cin.ignore(10, '\n');
			}
		}
		switch (a)
		{
		case 1:
			this->mayatnic = 1;
			break;
		case 2:
			this->mayatnic = 0;
			break;
		default:
			cout << "Введено не верное значение " << endl;
			rewind(stdin);
			loop = 0;
			break;
		}
	} while (loop == 0);
	Mechanic::input();
	Clock::input();
}
void  WallClock::output()
{
	cout << "Характериски часов :" << endl;
	Mechanic::output();
	Clock::output();
	if (this->mayatnic == 1)
	{
		cout << "Наличие маятника: Да " << endl;
	}
	else 	cout << "Наличие маятника: Нет " << endl;

}
WallClock::WallClock()
{
	mayatnic = 1;
}

bool WallClock::Getmayatnic()
{
	return mayatnic;
}

void WallClock::SetMayatnic(bool xm)
{
	mayatnic = xm;
}
