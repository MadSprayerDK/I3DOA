#include "LLToolKit.h"

using namespace LLTK;

int main()
{
	LLToolkit<int> toolkit;

	Node<int>* n3 = new Node<int>(1);
	Node<int>* n2 = new Node<int>(2, n3);
	Node<int>* headPtr = new Node<int>(3, n2);

	std::cout << "headPtr: ";
	toolkit.print(headPtr);

	Node<int>* newPtr = toolkit.copy(headPtr);
	std::cout << "newPtr:  ";
	toolkit.print(newPtr);

	std::cout << "---" << std::endl;

	std::cout << "headInsert: ";
	toolkit.headInsert(headPtr, 4);
	toolkit.print(headPtr);

	std::cout << "newPtr:  ";
	toolkit.print(newPtr);

	std::cout << "headRemove: ";
	toolkit.headRemove(headPtr);
	toolkit.print(headPtr);

	std::cout << "---" << std::endl;

	std::cout << "insert: ";
	toolkit.insert(headPtr->next, 9);
	toolkit.print(headPtr);

	std::cout << "remove: ";
	toolkit.remove(headPtr->next);
	toolkit.print(headPtr);

	return 0;
}