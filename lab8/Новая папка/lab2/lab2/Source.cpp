#include<iostream>
#include<iomanip>
#include<locale.h>
using namespace std;
class Massiv
{

	int* mas;
	int n;
public:
	Massiv(int n1 = 0);
	Massiv(Massiv& ob);
	void peresech(Massiv,Massiv);
	void vvod();
	void display();
	void soed(Massiv, Massiv,int);
	~Massiv();
};
Massiv::Massiv(Massiv& ob)
{
	
	n = ob.n;
	mas = new int[ob.n];
	for (int i = 0; i < ob.n; i++)
	{
		mas[i] = ob.mas[i];
	}

}
Massiv::Massiv(int n1)
{
	n = n1;
	mas = new int[n];
}
Massiv::~Massiv()
{
	delete[] mas;
}

void Massiv::vvod()
{
	for (int i = 0; i < n; i++)
	{
		cin >> mas[i];
	}
}
void Massiv::display()
{
	for (int i = 0; i < n; i++)
	{
		cout << setw(4) << mas[i];
	}
	cout << endl;
}
void Massiv::peresech(Massiv ob, Massiv ob1)
{
	cout << "�������������� ��������: " << endl;
	int n = 0,k=0;
	for (int i = 0; i < ob.n; i++)
	{
		n = 0;
		for (int j = 0; j < ob1.n; j++)
		{
			if(ob.mas[i]==ob1.mas[j]&&n<1)
			{
				k = 1;
				n++;
				cout << ob.mas[i];
			}
			
		}
	}
	if (k == 0)
	{ 
		cout << "�����������" << endl; 
	}
}
void Massiv::soed(Massiv ob, Massiv ob1,int k)
{
	int i,j=0;
	for ( i = 0; i < ob.n; i++)
	{
		mas[i] = ob.mas[i];
	}
	for (int i = ob.n; i < k; i++)
	{
		mas[i] = ob1.mas[i - ob.n];
	}
}
int main()
	{
	setlocale(LC_ALL, "Russian");
	int n,m,k;
	cout << "������� ������ ������� �������  " << endl;
	do
	{
		cin >> n;
		if (n <= 0)
		{
			cout << "������ ������� �� ����� ���� ������������� , ������� ��� ���" << endl;
		}
	} while (n <= 0);
	Massiv obj(n);
	cout << "������� ������ ������" << endl;
	obj.vvod();
	cout << "������� ������ ������� �������  " << endl;
	do
	{
		cin >> m;
		if (m <= 0)
		{
			cout << "������ ������� �� ����� ���� ������������� , ������� ��� ���" << endl;
		}
	} while (m<= 0);
	Massiv obj1(m);
	cout << "������� ������ ������" << endl;
	obj1.vvod();
	cout << "������ ������:" << endl;
	obj.display();
	cout << "������ ������:" << endl;
	obj1.display();
	cout << endl;
	//Massiv obj2(obj);
	//cout << "������������ ������ ������������ �����������" << endl;
	//obj2.display();
	k = n + m;
	Massiv per(k);
	per.peresech(obj, obj1);
	per.soed(obj, obj1,k);
	cout << endl<<"����������� ��������� �������"<<endl;
	per.display();
	}
