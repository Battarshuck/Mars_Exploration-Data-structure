#pragma once
class Event
{
private:
	char type;
	int event_day;
	int id;
	int distance;
	int num_days;
	int sig; //significance

public:
	Event(char, int, int, int, int, int);
	int get_ExecuteDay();
	void Execute();
};

