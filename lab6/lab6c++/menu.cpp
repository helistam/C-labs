#include"List.h"
#include"ExpVvod.h"
#include "menu.h"

void input(int& in)
{
	
	if (!(cin >> in))
	{
		throw Exp_vvod(123, "Вводите только целые числа");
	};
	if (in < 0 || in>16)
	{
		throw Exp_vvod(122, "Неправильный ввод( нет подходящих вариантов)");
	}
}
void insert(int& kol)
{
	if (!(cin >> kol))
	{
		throw Exp_vvod(123, "Вводите только целые числа");
	};
	if (kol < 0)
	{
		throw Exp_vvod(121, "Не вводите отрицательные числа");

	}
}
void inputloop(int& loop, List<WallClock> obj)
{
	try
	{
		if(!(cin>>loop)||loop>obj.GetSize()) throw Exp_vvod(123, "Данного элемента нет в списке");
	}
	catch (Exp_vvod& p)
	{
		p.Show();
	}
}
void menu(List<WallClock> obj)
{
	char c[20],t[20];
	strcpy_s(c, 20, "Binary.dat");
	strcpy_s(t, 20, "Text.txt");
		File f(c);
		f.Open();
		File ft(t);
		WallClock data;
		int kol, index;
		int in;
		bool choose = 1, spis = 0, vvod;
		do
		{
			cout << "Введите что вы хотите сделать:" << endl << "1-Создать лист(односвязный список)" << endl
				<< "2-Просмотреть содержимое списка" << endl << "3-Добавить элемент в начало списка"
				<< endl << "4-Добавить элемень в  конец  списка" << endl << "5-Удалить элемент с начала списка"
				<< endl << "6-Удалить элемент с конца списка" << endl << "7-Удалить элемент списка по индексу"
				<< endl << "8-Узнать текущий размер списка" << endl << "9-Удалить список" << endl << "11-Добавить элемент по индексу"
				<< endl <<"12-Поместить список в бинарный файл"<<endl<<"13-прочитать из бинарного файла "<<endl <<"14-Прочитать данные из текстового файла"
				<<endl<<"15-Добавить лист в текстовый файл"<<endl<<"0-Завершить программу" << endl;
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
								data.input();
								//inp(data);
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
						for (int i = 0; i < obj.GetSize(); i++)
						{
							if (i > obj.GetSize())throw Exp_cout(12, "Выход за пределы");
							obj[i].output();
						}
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
							data.input();
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
							data.input();
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
							data.input();
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
			case 12:
				if (obj.GetSize() == 0)
				{
					cout << "файл пустой" << endl;
					break;
				}
				f.Add(obj);
				break;
			case 13:
				obj.clear();
				f.Read(obj);
				if (obj.GetSize() == 0)
				{
					cout << "файл пустой" << endl;
					break;
				}
				 for(int k=0;k<obj.GetSize();k++)
					obj[k].output();
				 break;
			case 14:
				ft.OpenText();
				obj.clear();
				ft.Readtext(obj);
				if (obj.GetSize() == 0)
				{
					cout << "файл пустой"<<endl;
					break;
				}
				for (int k = 0; k < obj.GetSize(); k++)
					obj[k].output();
				ft.CloseText();
				break;
			case 15:
				if (obj.GetSize() == 0)
				{
					cout << "файл пустой"<<endl;
					break;
				};
				ft.OpenText();
				ft.Addtext(obj);
				ft.CloseText();
				break;
			default:
				break;
			}
			system("pause");
			system("cls");
		} while (choose);
	
}


