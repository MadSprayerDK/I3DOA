#include <iostream>

// Precondition: endpage should be divisible by 4.
void bookletPrint(int startPage, int endPage)
{
	if ((startPage - endPage) + 1 >= 0)
	{
		return;
	}

	std::cout << "Sheet " << ((startPage) / 2) + 1 << " contains pages "
		<< startPage << ", " << startPage + 1 << ", " << endPage - 1 << ", " << endPage << "." << std::endl;

	bookletPrint(startPage + 2, endPage - 2);
}

int main()
{
	bookletPrint(1, 13);

	return 0;
}