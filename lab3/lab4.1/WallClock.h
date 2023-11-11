#pragma once
#include"Mechanic.h"
class WallClock :public Mechanic
{
	bool mayatnic;
public:
	WallClock();
	void input() override;
	void output() override;

};
