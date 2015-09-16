#include <iostream>

void moveTower(int numberOfBlocks, int sourucePen, int destinationPen, int viaPen)
{
	if (numberOfBlocks == 1)
		std::cout << "Moving block from " << sourucePen << " to " << destinationPen << std::endl;
	else
	{
		moveTower(numberOfBlocks - 1, sourucePen, viaPen, destinationPen);
		std::cout << "Moving block from " << sourucePen << " to " << destinationPen << std::endl;
		moveTower(numberOfBlocks - 1, viaPen, destinationPen, sourucePen);
	}
}

int main()
{
	std::cout << "Tower of Hanoi" << std::endl;
	int n = 20;

	moveTower(n, 1, 3, 2);
}