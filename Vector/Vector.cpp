#include "Vector.h"

Vector::Vector()
{
	for (int i = 0; i < SIZE; i++)
	{
		data[i] = 0;
	}
}

void Vector::set(int index, int number)
{
	data[index] = number;
}

int Vector::get(int index)
{
	return data[index];
}

bool Vector::contains(int number)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (data[i] == number)
			return true;
	}

	return false;
}

int Vector::howMany(int number)
{
	int retVal = 0;
	for (int i = 0; i < SIZE; i++)
	{
		if (data[i] == number)
			retVal++;
	}

	return retVal;
}

bool Vector::allUnique()
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = i + 1; j < SIZE; j++)
		{
			if (data[i] == data[j])
				return false;
		}
	}

	return true;
}