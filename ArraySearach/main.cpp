#include <iostream>

bool searchArray(int ar[], int length, int x)
{
	if (length == 1)
		return ar[0] == x;

	return ar[0] == x ? true : searchArray(&ar[1], length - 1, x);
}

int main()
{
	int x[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };

	if (searchArray(x, 150, 39))
		std::cout << "Exists" << std::endl;
	else
		std::cout << "Doesn't exist" << std::endl;

	return 0;
}