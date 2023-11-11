#pragma once
#include"Mechanic.h"
class Watch :public Mechanic
{
	bool automatic;
public:
	Watch();
	void input()override;
	void output() override;
};
