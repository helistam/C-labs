#include<iostream>
#include<vector>
#include"vector.h"
#include<locale>
using namespace std;
int main()
{
	setlocale(LC_ALL, "Russian");
	int choose;
	bool loop = 1;
	cout << "1-Работа с вектором" << endl << "2-Примеры использования библиотеки algorithm"<<endl;
	while (loop)
	{
		try
		{
			if (!(cin >> choose) || choose < 1 || choose>2)throw exception();
			loop = 0;
		}
		catch (const std::exception& w)
		{
			cout << w.what()<<endl;
			cin.clear();
			cin.ignore(10, '\n');
		}
	}
	switch (choose)
	{
	case 1:
		menu();
		break;
	case 2:
		menu2();
		break;
	default:
		break;
	}
}