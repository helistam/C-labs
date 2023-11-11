#include<iostream>
#include<iomanip>
#include<locale.h>
using namespace std;
class Massiv
{
public:
	int* mas;
	int n;
	Massiv(int n1 = 0);//конструктор с параметрами по умолчанию
	void vvod();
	void display();
	Massiv(const Massiv&);//копирующий конструктор 
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
				cout << "Пересекающиеся элементы:" << mas[i];
			}
		}
	}
	if (m == 0)cout <<endl<< "В данных массивах нет пересекающихся элементов";
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
	cout << endl<<"Обьединение:"<<endl;
	for (int p = 0; p < ll; p++)
	{
		cout << ms[p];
	}
}
int main()
{
	setlocale(LC_ALL, "Russian");
	int n, m,flag=0;
		cout << "Введите размер первого массива" << endl;
		do
		{
			cin >> n;
			if (n < 0)
			{
				cout << "Размер не может быть отрицательным, введите еще раз"<<endl;
			}else
			flag = 1;
		} while (!flag);
		cout << "Введите размер второго массива" << endl;
		flag = 0;
		do
		{
			cin >> m;
			if (m < 0)
			{
				cout << "Размер не может быть отрицательным, введите еще раз" << endl;
			}
			else
				flag = 1;
		} while (!flag);
	Massiv pl(n),ln(m);
	cout << "Введите элементы первого массива";
	pl.vvod();
	cout << "Введите элементы второго массива";
	ln.vvod(); 
	cout << "Первый массив" << endl;
	pl.display();
	cout << "Второй массив" << endl;
	ln.display();
	ln.poiskper(pl.mas,n);
	ln.soed(pl.mas, n);
	
}