#pragma once
#include "MyException.h"
#include<iostream>

class Exp_file : public Exp
{
public:
	Exp_file() {};
	Exp_file(int Code, string message) {
		code = Code;
		msg = message;
	}
	void Show()
	{
		cout << "Error code:" << code << ", " << msg << endl;
	}
};