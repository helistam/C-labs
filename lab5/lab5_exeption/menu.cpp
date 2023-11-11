#include"List.h"
#include"ExpVvod.h"
#include "menu.h"

void input(int& in)
{
	
	if (!(cin >> in))
	{
		throw Exp_vvod(123, "Вводите только целые числа");
	};
	if (in < 0 || in>11)
	{
		throw Exp_vvod(122, "Неправильный ввод( нет подходящих вариантов)");
	}
}
void insert(int& kol)
{
	if (!(cin >> kol))
	{
		throw Exp_vvod(123, "Вводите только целые числа");
	};
	if (kol < 0)
	{
		throw Exp_vvod(121, "Не вводите отрицательные числа");

	}
}


