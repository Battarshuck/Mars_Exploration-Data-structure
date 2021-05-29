#pragma once
class Mission
{
private:
	const int id;
	int distance;
	int num_days;

public:
	Mission(int, int, int);
	virtual int get_id() const;
	virtual int get_distance() const;
	virtual int get_numDay() const;
	virtual int get_sig() const;
};

