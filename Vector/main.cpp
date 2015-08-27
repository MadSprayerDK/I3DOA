#include <iostream>
#include "Vector.h"
using namespace std;

void printVector(Vector vector)
{
	for (int i = 0; i < 10; i++)
	{
		cout << vector.get(i) << " ";
	}
	cout << endl;
}

int main()
{
	Vector vector;
	printVector(vector);

	vector.set(0, 13);
	vector.set(1, 5);
	vector.set(2, 5);
	vector.set(3, 7);
	vector.set(4, 19);
	vector.set(5, 3);
	vector.set(6, 10);
	vector.set(7, 23);
	vector.set(8, 30);
	vector.set(9, 1);

	printVector(vector);

	cout << "Indeholder 10: " << (vector.contains(10) ? "true" : "false") << endl;
	cout << "Indeholder 11: " << (vector.contains(11) ? "true" : "false") << endl;

	cout << "Antal forkomster af 5: " << vector.howMany(5) << endl;
	cout << "Antal forkomster af 10: " << vector.howMany(10) << endl;
	cout << "Antal forkomster af 50: " << vector.howMany(50) << endl;

	cout << "Alle unikke: " << (vector.allUnique() ? "true" : "false") << endl;
	vector.set(1, 14);
	printVector(vector);
	cout << "Alle unikke: " << (vector.allUnique() ? "true" : "false") << endl;

	return 0;
}