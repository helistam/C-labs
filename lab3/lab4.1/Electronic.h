
#pragma once
#include"Clock.h"
class Electronic : public Clock
{
	int zar;
public:
	Electronic();
	int GetZar();
	void SetZar(int xzar);
	void input() override;
	void output()override;
};