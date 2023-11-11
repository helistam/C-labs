#pragma once
#include"Clock.h"
class Mechanic : public Clock
{
	char Material[255];
public:
	char* GetMaterial();
	void SetMaterial(char* mat);
	Mechanic();
	void input() override;
	void output() override;
};
