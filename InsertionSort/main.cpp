#include "insertionSort.h"

int main()
{
	int content[] = {11, 10, 30, 15, 3, 5, 2, 1, 11, 17, 31, 23};

	int length = sizeof(content) / sizeof(int);

	insertionSort(content, length);

	return 0;
}