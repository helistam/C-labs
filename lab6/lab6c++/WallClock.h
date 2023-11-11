#pragma once
#include"Mechanic.h"
class WallClock :public Mechanic
{
	bool mayatnic;
public:
	WallClock();
	bool Getmayatnic();
	void SetMayatnic(bool xm);
	void input() override;
	void output() override;

};
