#include<iostream>
#include"Clock.h"
#include"ExpVvod.h"
using namespace std;
Clock::Clock()
{
	Brend[0] = { ' ' };
	Time = 0;
}
char Clock::GetBrend()
{
	return Brend[12];
}
int Clock::GetTime()
{
	return Time;
}
void Clock::SetTime(int valuex)
{
	Time = valuex;
}
void Clock::SetBrend(char Brendvalue[])
{
	Brend[1] = Brendvalue[1];
}
void Clock::input()
{
	bool a;
	cout << "¬ведите бренд часов" << endl;
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->Brend))throw Exp_vvod(123, "¬водите только целые числа");
			a = 0;
		}
		catch (Exp_vvod& ex)
		{
			ex.Show();
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
	cout << "ќтработанное врем€" << endl;
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->Time))throw Exp_vvod(123, "¬водите только целые числа");
			a = 0;
		}
		catch (Exp_vvod& ex)
		{
			ex.Show();
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
}
void Clock::output()
{
	cout << "Ѕренд:" << endl << this->Brend << endl;
	cout << "¬рем€" << endl << this->Time << endl;
}