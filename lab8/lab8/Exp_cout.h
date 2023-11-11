#pragma once
#include"MyException.h"
class Exp_cout : public Exp
{
public:
	Exp_cout() {}
	Exp_cout(int Code, string message)
	{
		code = Code;
		msg = message;
	}
	void show1()
	{
		cout << "Error in output, error code:" << code << ", " << msg << endl;
	}
};