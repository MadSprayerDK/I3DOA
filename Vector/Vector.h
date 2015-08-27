#pragma once

class Vector
{
public:
	static const int SIZE = 10;
	Vector();
	void set(int index, int number);
	int get(int index);
	bool contains(int number);
	int howMany(int number);
	bool allUnique();
private:
	int data[SIZE];
};