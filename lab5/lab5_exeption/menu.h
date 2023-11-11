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
		if(i> obj.GetSize())throw Exp_cout(12, "����� �� �������");
		if (!(cout << obj[i] << endl))
		{
			throw Exp_cout(1, "������");
		}
	}
}
void insert(int& kol);
template<class T>
void inp(T& b)
{
	if(!(cin>>b))throw Exp_vvod(22,"�������� ���� ������ �� ������������� ���� ������ ���������� � ������.��������� ����");
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
		cout << "������� ��� �� ������ �������:" << endl << "1-������� ����(����������� ������)" << endl
			<< "2-����������� ���������� ������" << endl << "3-�������� ������� � ������ ������"
			<< endl << "4-�������� ������� �  �����  ������" << endl << "5-������� ������� � ������ ������"
			<< endl << "6-������� ������� � ����� ������" << endl << "7-������� ������� ������ �� �������"
			<< endl << "8-������ ������� ������ ������" << endl << "9-������� ������" << endl << "11-�������� ������� �� �������"
			<< endl << "0-��������� ���������" << endl;
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
				cout << "������� ���������� ��������� ������" << endl;
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
					cout << "������� ������  � " << i << " ������ ������" << endl;
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
				cout << "������ ������� ������" << endl;
				spis = 1;
				break;
			}
			else
			{
				cout << "������ ��� ����������, ������ ��� ������� ����� �������� ������������" << endl;
				break;
			}
		case 2:
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
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
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� ������ � ����������� ������ ������";
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
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� ������ � ����������� ������ ������";
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
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				obj.pop_front();
				cout << "������� ������" << endl;
				break;
			}
		case 6:
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
		case 7:
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� ������" << endl;
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
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������ ������:  " << endl << obj.GetSize();
				break;
			}
		case 9:
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
		case 11:
			if (spis == 0)
			{
				cout << "������ ��� �� ������ " << endl;
				break;
			}
			else
			{
				cout << "������� �����";
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
				cout << "������� ���������� �������� ������";
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

