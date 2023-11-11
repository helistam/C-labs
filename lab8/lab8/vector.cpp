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
		cout << "1-�������� ������� � ������" << endl << "2-������ ������ �������" << endl << "3-������� ���������� �������"
			<< endl << "4-������� �������� � ��������� ���������" << endl << "5-������� ������� �� ������� �� ��� ���������" << endl
			<< "6-�������� ������� � ������������ ������� c ������� ��������� advance"<<endl<<"7-�������� ���� ������"<<endl;
		cin >> choose;
		switch (choose)
		{
		case 1:
			cout << "����� ������� ������� ������ �������� � ������" << endl;
			k = 1;
			while (k)
			{
				clock.input();
				vt.push_back(clock);
				cout << "������ ����������(0-���/1-��)" << endl;
				cin >> z;
				if (z == 0)k = 0;
			}
			break;
		case 2:
			if (vt.size() == 0)
			{
				cout << "������ ���� " << endl;
				break;
			}
			cout << "������� ������ �������" << endl
				<< vt.size();
			break;
		case 3:
			cout << "������� ���������� �������" << endl;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				(*iter).output();
			}
			cout << endl;
			break;
		case 4:
			if (vt.size() == 0)
			{
				cout << "������ ����";
				break;
			}
			cout << "����� ������� � �������� ���� �������";
			diapason(min, vt);
			iter = vt.begin();
			iter += min;
			cout << "������� ������� �� ������� ���� �������";
			diapason(max, vt);
			end = vt.begin();
			end += max;
			vt.erase(iter, end);
			cout << "������� ���������� �������" << endl;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				iter->output();
			}
			cout << endl;
			break;
		case 5:
			cout << "������� �������� �� �������� ������� ����";
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
				cout << "��� ������ ��������" << endl;
				break;
			}
			vt.erase(end);
			cout << "������� ���������� �������" << endl;
			for (iter = vt.begin(); iter < vt.end(); iter++)
			{
				iter->output();
			}
			cout << endl;
			break;
		case 6:
			iter = vt.begin();
			cout << "������� ������� ���� �� ������ �������� �������" << endl;
			cin >> z;
			if (z > vt.size())
			{
				cout << "��� ����� �������" << endl;
				break;
			}
			cout << "������� ������� ������� ������ ��������" << endl;
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
		cout <<endl<< "1-������� ���������� �������" << endl << "2-������� ���������� �������" << endl
			<< "3-����������" << endl<<"4-������� ������� (������� ������ � ������� ������� find)"<<endl
			<<"5-����� ���������� ��������� ��������"<<endl<<"6-�������� ��� �������� � �������� ��������� ���������"<<endl
			<<"7-��������� ���������"<<endl;
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
						cout << "������� ����� ������� �������" << endl;
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
				cout << "����������(1-���/0-��)" << endl;
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
			cout << "������� ������� ������� ������ �������"<<endl;
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
			cout << "����� ������� ������� �� ������ �����" << endl;
			cin >> per;
			 n=count(och.begin(), och.end(),per);
			cout << "N=" << n<<endl;
			break;
		case 6:
			cout << "����� ��������" << endl;
			cin >> first;
			cin >> last;
			if (first > och.size() || last > och.size())break;
			cout << "����� �������� ������� ��������� ��������" << endl;
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
