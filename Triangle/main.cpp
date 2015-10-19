#include <iostream>

void triangle(unsigned int m, unsigned int n)
{
	if (m > n)
		throw std::exception("m is bigger than n");

	for (int i = 0; i < m; i ++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;

	if (m < n)
		triangle(m + 1, n);

	for (int i = 0; i < m; i++)
	{
		std::cout << "*";
	}
	std::cout << std::endl;
}

int main()
{
	try
	{
		triangle(1000, 100);
	}
	catch (std::exception e)
	{
		std::cout << "Error: " << e.what() << std::endl;
	}
	
	return 0;
}