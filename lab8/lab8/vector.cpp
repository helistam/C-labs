#include "vector.h"
#include <iostream>
void diapason(int& b,vector<WallClock>& obj)
{
	bool metka=1;
	while (metka)
	{
		try
		{
			if (!(cin >> b) || b > obj.size())throw exception();
			metka = 0;
		}
		catch (const std::exception& b)
		{
			cout << b.what();
		}
	}
}
void menu()
{
	int choose, per, min,max,z,m=0;
	char material[255];
	bool lop=1,k=1;
	vector<WallClock> vt;
	WallClock clock;
	vector<WallClock>::iterator iter, end;
	while (lop == 1)
	{
		cout << "1-Добавить элемент в вектор" << endl << "2-Узнать размер вектора" << endl << "3-Вывести содержимое вектора"
			<< endl << "4-Удалить элементы в указанном диапазоне" << endl << "5-Удалить элемент из вектора по его материалу" << endl
			<< "6-Добавить элемент в определенную позицию c помощью алгоритма advance"<<endl<<"7-Очистить весь вектор"<<endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "Введи элемент который хотите добавить в вектор" << endl;
			k = 1;
			while (k)
			{
				clock.input();
				vt.push_back(clock);
				cout << "Хотите продолжить(0-нет/1-да)" << endl;
				cin >> z;
				if (z == 0)k = 0;
			}
			break;
		case 2:
			if (vt.size() == 0)
			{
				cout << "Вектор пуст " << endl;
				break;
			}
			cout << "Текущий размер вектора" << endl
				<< vt.size();
			break;
		case 3:
			cout << "Текущее содержимое вектора" << endl;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				(*iter).output();
			}
			cout << endl;
			break;
		case 4:
			if (vt.size() == 0)
			{
				cout << "Вектор пуст";
				break;
			}
			cout << "Введи элемент с которого надо удалять";
			diapason(min, vt);
			iter = vt.begin();
			iter += min;
			cout << "Введите элемент по который надо удалять";
			diapason(max, vt);
			end = vt.begin();
			end += max;
			vt.erase(iter, end);
			cout << "Текущее содержимое вектора" << endl;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				iter->output();
			}
			cout << endl;
			break;
		case 5:
			cout << "Введите материал из которого сделаны часы";
			cin >> material;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				if (!(strcmp(iter->GetMaterial(),material)))
				{
					end = iter;
					m = 1;
				}
			}
			if (m == 0)
			{
				cout << "Нет такого элемента" << endl;
				break;
			}
			vt.erase(end);
			cout << "Текущее содержимое вектора" << endl;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				iter->output();
			}
			cout << endl;
			break;
		case 6:
			iter = vt.begin();
			cout << "Введите позицию куда вы хотите вставить элемент" << endl;
			cin >> z;
			if (z > vt.size())
			{
				cout << "Нет такой позиции" << endl;
				break;
			}
			cout << "Введите элемент который хотите вставить" << endl;
			clock.input();
			advance(iter,z);
			vt.emplace(iter, clock);
			break;
		case 7:
			vt.clear();
			break;
		default:
			break;
			rewind(stdin);
		}

		system("pause");
		system("cls");
	}
}

void menu2()
{
	int n,first,last;
	deque<int> och;
	int choose,per,del;
	bool loop = 1, l=1,d,ww=1;
	deque<int>::iterator it,beg;
	while (ww)
	{
		cout <<endl<< "1-Введите содержимое очереди" << endl << "2-Вывести содержимое очереди" << endl
			<< "3-Сортировка" << endl<<"4-Удалить элемент (элемент ищется с помощью функции find)"<<endl
			<<"5-Найти количество включений элемента"<<endl<<"6-Заменить все элементы в заданном диапазоне выбранным"<<endl
			<<"7-Завершить программу"<<endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			while (loop)
			{
				while (l)
				{
					try
					{
						cout << "Введите новый элемент очереди" << endl;
						if (!(cin >> per))throw exception();
						l = 0;
					}
					catch (const std::exception& w)
					{
						cout << w.what();
						cin.clear();
						cin.ignore(10, '\n');
					}
				}
				och.push_back(per);
				cout << "Продолжить(1-нет/0-да)" << endl;
				try
				{
					if (!(cin >> d))throw exception();
				}
				catch (const std::exception& w)
				{
					cout << w.what();
				}
				if (d == 1)break;
				l = 1;
			}
			break;
		case 2:
			for (int i = 0; i < och.size(); i++)
			{
				cout << och[i];
			}
			break;
		case 3:
			sort(och.begin(), och.end());
			for (int i = 0; i < och.size(); i++)
			{
				cout << och[i];
			}
		case 4:
			cout << "Введите элемент который хотите удалить"<<endl;
			try
			{
				if (!(cin >> del))throw exception();
			}
			catch (const std::exception&w)
			{
				cout << w.what();
				break;
			}
			
			it = find(och.begin(), och.end(), del);
			och.erase(it);
			for (int i = 0; i < och.size(); i++)
			{
				cout << och[i];
			}
			break;
		case 5:
			cout << "Введи элемент который вы хотите найти" << endl;
			cin >> per;
			 n=count(och.begin(), och.end(),per);
			cout << "N=" << n<<endl;
			break;
		case 6:
			cout << "Введи диапазон" << endl;
			cin >> first;
			cin >> last;
			if (first > och.size() || last > och.size())break;
			cout << "Введи значение которым заполнить диапазон" << endl;
			cin >> per;
			fill(och.begin() + first, och.begin()+last, per);
			for (int i = 0; i < och.size(); i++)
			{
				cout << och[i];
			}
			break;
		case 7:
			ww = 0;
			break;
		default:
			break;
		}
	}
}
