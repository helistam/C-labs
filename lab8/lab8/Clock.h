#pragma once
class Clock
{
	char Brend[255];
	int Time;
public:
	Clock();
	char* GetBrend();
	int GetTime();
	void SetTime(int valuex);
	void SetBrend(char* Brendvalue );
	virtual void input();
	virtual void output();
};