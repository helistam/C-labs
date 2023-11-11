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
		cout << "������� ��� �� ������ �������:" << endl << "1-������� ����(����������� ������)" << endl
			<< "2-����������� ���������� ������" << endl << "3-�������� ������� � ������ ������"
			<< endl << "4-�������� ������� �  �����  ������" << endl << "5-������� ������� � ������ ������"
			<< endl << "6-������� ������� � ����� ������" << endl << "7-������� ������� ������ �� �������"
			<< endl << "8-������ ������� ������ ������" << endl << "9-������� ������" << endl << "A-�������� ������� �� �������"
			<< endl << "0-��������� ���������" << endl;
		cin >> type;
		switch (type)
		{
		case '0':
			choose = 0;
			break;
		case '1':
			if (spis == 0)
			{
				cout << "������� ���������� ��������� ������" << endl;
				cin >> kol;
				for (int i = 0; i < kol; i++)
				{
					cout << "������� ������  � " << i << " ������ ������" << endl;
					cin >> data;
					obj.push_back(data);
				}
				cout << "������ ������� ������" << endl;
				spis = 1;
				break;
			}
			else
			{
				cout << "������ ��� ����������, ������ ��� ������� ����� �������� ������������" << endl;
				break;
			}
		case '2':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
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
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� ������ � ����������� ������ ������";
				cin >> data;
				obj.push_front(data);
				break;
			}
		case '4':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� ������ � ����������� ������ ������";
				cin >> data;
				obj.push_back(data);
				break;
			}
		case '5':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				obj.pop_front();
				cout << "������� ������" << endl;
				break;
			}
		case '6':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{

				obj.popback();
				cout << "������� ������" << endl;
				break;
			}
		case '7':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� ������" << endl;
				cin >> index;
				obj.removeAt(index);
				break;

			}
		case '8':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������ ������:  " << endl << obj.GetSize();
				break;
			}
		case '9':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������ ������� ������" << endl;
				spis = 0;
				obj.clear();
				break;

			}
		case 'A':
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� �����";
				cin >> index;
				cout << "������� ���������� �������� ������";
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

