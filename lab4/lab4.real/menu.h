#include"List.h"
#include<string>

#pragma once
template<class T>
void menu1(List<T> obj)
{
	T data;
	int kol, index;
	char type;
	bool choose = 1, spis = 0;
	do
	{
		cout << "Введите что вы хотите сделать:" << endl << "1-Создать лист(односвязный список)" << endl
			<< "2-Просмотреть содержимое списка" << endl << "3-Добавить элемент в начало списка"
			<< endl << "4-Добавить элемень в  конец  списка" << endl << "5-Удалить элемент с начала списка"
			<< endl << "6-Удалить элемент с конца списка" << endl << "7-Удалить элемент списка по индексу"
			<< endl << "8-Узнать текущий размер списка" << endl << "9-Удалить список" << endl << "A-Добавить элемент по индексу"
			<< endl << "0-Завершить программу" << endl;
		cin >> type;
		switch (type)
		{
		case '0':
			choose = 0;
			break;
		case '1':
			if (spis == 0)
			{
				cout << "Введите количество элементов списка" << endl;
				cin >> kol;
				for (int i = 0; i < kol; i++)
				{
					cout << "Введите данные  в " << i << " ячейку списка" << endl;
					cin >> data;
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
		case '2':
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				for (int i = 0; i < obj.GetSize(); i++)
				{
					cout << obj[i] << endl;
				}
				break;
			}
		case '3':
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите данные в добавляемую ячейку списка";
				cin >> data;
				obj.push_front(data);
				break;
			}
		case '4':
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите данные в добавляемую ячейку списка";
				cin >> data;
				obj.push_back(data);
				break;
			}
		case '5':
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
		case '6':
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
		case '7':
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите индекс" << endl;
				cin >> index;
				obj.removeAt(index);
				break;

			}
		case '8':
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
		case '9':
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
		case 'A':
			if (spis == 0)
			{
				cout << "Список еще не создан " << endl;
				break;
			}
			else
			{
				cout << "Введите инекс";
				cin >> index;
				cout << "Введите содержимое элемента списка";
				cin >> data;
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

