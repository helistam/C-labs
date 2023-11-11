#pragma once
#include"Electronic.h"
class FitnesTracker :public Electronic
{
	int distans[2];
public:
	int Getdistance();
	void Setdistance(int xdistance[]);
	FitnesTracker();
	void input() override;
	void output()  override;
};
