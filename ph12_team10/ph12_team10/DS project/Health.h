#pragma once
class Health
{
private:
	int health;
	int initial_health;
public:
	Health(int hlth = 100);
	operator int();
	void operator-=(int val);
	void operator+=(int val);
	void operator/=(int val);
	void operator=(int val);
	bool operator==(int val);
	int get_health();
	int get_initial_health();
};

