#include <iostream>

void pattern(unsigned int n, unsigned int i)
{
	if (n == 0)
		return;

	pattern(n / 2, i);

	for (int k = 0; k < i; k++)
	{
		std::cout << "  ";
	}

	for (int k = 0; k < n; k++)
	{
		std::cout << "* ";
	}
	std::cout << std::endl;

	pattern(n / 2, n / 2 + i);
}

int main()
{
	pattern(8, 0);

	return 0;
}