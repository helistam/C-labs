#pragma once
#include<iostream>
#include<fstream>

using namespace std;

class Exp:public exception
{
protected:
	int code;
	string msg;

public:
	Exp() {}
	Exp(int Code, string message)
	{
		this->code = code;
		this->msg = msg;
	}
	void Show()
	{
		 cout << "unnamed error" << code << ", " << msg << endl;
	}

};