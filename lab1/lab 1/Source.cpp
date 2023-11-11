#include<iostream>
#include<iomanip>
#include<locale.h>
using namespace std;
class Massiv
{
public:
	int* mas;
	int n;
	Massiv(int n1 = 0);//����������� � ����������� �� ���������
	void vvod();
	void display();
	Massiv(const Massiv&);//���������� ����������� 
	void poiskper(int*,int);
	void soed(int*, int);
	~Massiv();
};
Massiv::Massiv(int n1)
{
	n = n1;
	mas = new int[n];
}
Massiv::Massiv(const Massiv& ob)
{
	n = ob.n;
	mas = new int[n];
	for (int i = 0; i < n; i++)
		mas[i] = ob.mas[i];
}
Massiv::~Massiv()
{
	delete[] mas;
}
void Massiv::vvod()
{
	int fl = 0;
	for (int i = 0; i < n; i++)
	{
		
			cin >> mas[i];
			
	}
}
void Massiv::display()
{
	for (int i = 0; i < n; i++)
	{
		cout << mas[i];
	}
	cout << endl;
}
void Massiv::poiskper(int* mas2,int k)
{
	int ll;
	if (k > n)
	{
		ll = k;
	}
	else ll = n;
	int m=0;
	for (int j = 0; j < ll; j++)
	{
		for (int i = 0; i < ll; i++)
		{
			if (mas[i] == mas2[j])
			{
				m++;
				cout << "�������������� ��������:" << mas[i];
			}
		}
	}
	if (m == 0)cout <<endl<< "� ������ �������� ��� �������������� ���������";
}
void Massiv::soed(int* mas2, int k)
{
	int ll;
	ll = k + n;
	int *ms;
	ms = new int[ll];
	for (int i = 0; i < k; i++)
	{
		ms[i] = mas2[i];
	}
	int p = 0;
	for (int j= k; j < ll; j++)
	{
		
		ms[j] = mas[p];
		p++;
	}
	cout << endl<<"�����������:"<<endl;
	for (int p = 0; p < ll; p++)
	{
		cout << ms[p];
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m,flag=0;
		cout << "������� ������ ������� �������" << endl;
		do
		{
			cin >> n;
			if (n < 0)
			{
				cout << "������ �� ����� ���� �������������, ������� ��� ���"<<endl;
			}else
			flag = 1;
		} while (!flag);
		cout << "������� ������ ������� �������" << endl;
		flag = 0;
		do
		{
			cin >> m;
			if (m < 0)
			{
				cout << "������ �� ����� ���� �������������, ������� ��� ���" << endl;
			}
			else
				flag = 1;
		} while (!flag);
	Massiv pl(n),ln(m);
	cout << "������� �������� ������� �������";
	pl.vvod();
	cout << "������� �������� ������� �������";
	ln.vvod(); 
	cout << "������ ������" << endl;
	pl.display();
	cout << "������ ������" << endl;
	ln.display();
	ln.poiskper(pl.mas,n);
	ln.soed(pl.mas, n);
	
}