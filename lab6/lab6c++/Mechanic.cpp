#include<iostream>
#include"Mechanic.h"
#include"ExpVvod.h"
using namespace std;
char* Mechanic::GetMaterial()
{
	return Material;
}
void Mechanic::SetMaterial(char* mat)
{
	strcpy_s(Material,40,mat);
}
Mechanic::Mechanic()
{
	Material[0] = ' ';
}

void Mechanic::input()
{
	bool a;
	cout << "Введите материал из которого сделаны часы" << endl;
	a = 1;
	while (a)
	{
		try
		{
			if (!(cin >> this->Material))throw Exp_vvod(123, "Вводите только целые числа");
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
void Mechanic::output()
{
	cout << "Материал :" << endl << this->Material << endl;
}