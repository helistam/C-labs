#include"List.h"
#include<string>
#include"MyException.h"
#include"ExpVvod.h"
#include"Exp_cout.h"
#pragma once
void input(int& a);
template<class T>
void count(T& obj)
{
	for (int i = 0; i < obj.GetSize(); i++)
	{
		if(i> obj.GetSize())throw Exp_cout(12, "Выход за пределы");
		if (!(cout << obj[i] << endl))
		{
			throw Exp_cout(1, "Ошибка");
		}
	}
}
void insert(int& kol);
template<class T>
void inp(T& b)
{
	if(!(cin>>b))throw Exp_vvod(22,"Вводимые вами данные не соответствуют типу данных хранящихся в списке.Повторите ввод");
}
template<class T>
void menu1(List<T> obj)
{
	T data;
    int kol, index;
	int in;
	bool choose = 1, spis = 0,vvod;
	do
	{
		cout << "Введите что вы хотите сделать:" << endl << "1-Создать лист(односвязный список)" << endl
			<< "2-Просмотреть содержимое списка" << endl << "3-Добавить элемент в начало списка"
			<< endl << "4-Добавить элемень в  конец  списка" << endl << "5-Удалить элемент с начала списка"
			<< endl << "6-Удалить элемент с конца списка" << endl << "7-Удалить элемент списка по индексу"
			<< endl << "8-Узнать текущий размер списка" << endl << "9-Удалить список" << endl << "11-Добавить элемент по индексу"
			<< endl << "0-Завершить программу" << endl;
		try
		{
			input(in);
		}
		catch (Exp_vvod& er)
		{
		  er.Show();
		  cin.clear();
		  cin.ignore(10, '\n');
		  in = 15;
		}
		
		switch (in)
		{
		case 0:
			choose = 0;
			break;
		case 1:
			if (spis == 0)
			{
				cout << "Введите количество элементов списка" << endl;
				try
				{
					insert(kol);
				}
				catch (Exp_vvod& error)
				{
					error.Show();
					cin.clear();
					cin.ignore(10, '\n');
					break;
				}
				for (int i = 0; i < kol; i++)
				{
					vvod = 1;
					cout << "Введите данные  в " << i << " ячейку списка" << endl;
					while (vvod)
					{
						try
						{
							inp(data);
							vvod = 0;
						}
						catch (Exp_vvod& error)
						{
							error.Show();
							cin.clear();
							cin.ignore(10, '\n');
							
						}
					}
					
					obj.push_back(data);
				}
				cout << "Список успешно создан" << endl;
				spis = 1;
				break;
			}
			else
			{
				cout << "Список уже существует, прежде чем создать новый очистите существующий" << endl;
				break;
			}
		case 2:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
					try
					{
						count(obj);
					}
					catch (Exp_cout& ex)
					{
						 ex.show1();
					}
				
				break;
			}
		case 3:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите данные в добавляемую ячейку списка";
				vvod = 1;
				while (vvod)
				{
					try
					{
						inp(data);
						vvod = 0;
					}
					catch (Exp_vvod& error)
					{
						error.Show();
						cin.clear();
						cin.ignore(10, '\n');

					}
				}
				obj.push_front(data);
				break;
			}
		case 4:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите данные в добавляемую ячейку списка";
				vvod = 1;
				while (vvod)
				{
					try
					{
						inp(data);
						vvod = 0;
					}
					catch (Exp_vvod& error)
					{
						error.Show();
						cin.clear();
						cin.ignore(10, '\n');

					}
				}
				obj.push_back(data);
				break;
			}
		case 5:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				obj.pop_front();
				cout << "Элемент удален" << endl;
				break;
			}
		case 6:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{

				obj.popback();
				cout << "Элемент удален" << endl;
				break;
			}
		case 7:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите индекс" << endl;
				try
				{
					insert(index);
				}
				catch (Exp_vvod& error)
				{
					error.Show();
					cin.clear();
					cin.ignore(10, '\n');

				}
				obj.removeAt(index);
				break;

			}
		case 8:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Размер списка:  " << endl << obj.GetSize();
				break;
			}
		case 9:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Список успешно удален" << endl;
				spis = 0;
				obj.clear();
				break;

			}
		case 11:
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите инекс";
				vvod = 1;
				while (vvod)
				{
					try
					{
						insert(index);
						vvod = 0;
					}
					catch (Exp_vvod& error)
					{
						error.Show();
						cin.clear();
						cin.ignore(10, '\n');

					}
				}
				cout << "Введите содержимое элемента списка";
				vvod = 1;
				while (vvod)
				{
					try
					{
						inp(data);
						vvod = 0;
					}
					catch (Exp_vvod& error)
					{
						error.Show();
						cin.clear();
						cin.ignore(10, '\n');

					}
				}
				obj.insert(data, index);
				break;
			}
		default:
			break;
		}
		system("pause");
		system("cls");
	} while (choose);
}

