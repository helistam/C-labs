#include<iostream>
#include"menu.h"
#include"WallClock.h"
#include"List.h"
#include<locale>
int main()
{
	setlocale(LC_ALL, "Russian");
	WallClock clock;
	List<WallClock>Clock1;
	menu(Clock1);
}