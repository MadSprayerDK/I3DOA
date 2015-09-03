#pragma once
#include <iostream>
#include "Node.hpp"

template<class T>
class LLToolkit
{
public:
	LLToolkit()
	{}

	// Precondition: headPtr points to the head of a list
	// Postcondition: Info has been inserted at the head of the list, and headPtr is updated
	// Time complexity: O(1), Constant
	void headInsert(Node<T>*& headPtr, T info)
	{
		Node<T>* newHeadPtr = new Node<T>(info);
		newHeadPtr->next = headPtr;
		headPtr = newHeadPtr;
	}

	// Precondition: headPtr points to the head of a list with at least 1 element
	// Postcondition: The head element has been removed and headPtr is updated to point to the new
	// head element
	// Time complexity: O(1), Constant
	void headRemove(Node<T>*& headPtr)
	{
		Node<T>* deletePtr = headPtr;
		headPtr = headPtr->next;
		delete deletePtr;
	}

	// Precondition: prevPtr points to Node just before insertion point
	// Postcondition: A new Node with data=info has been inserted into the list after prevPtr
	// Time complexity: O(1), Constant
	void insert(Node<T>* prevPtr, T info)
	{
		Node<T>* newNode = new Node<T>(info);
		newNode->next = prevPtr->next;
		prevPtr->next = newNode;
	}

	// Precondition: prevPtr points to Node just before Node to remove
	// Postcondition: The Node after prevPtr has been removed from the list
	// Time complexity: O(1), Constant
	void remove(Node<T>* prevPtr)
	{
		Node<T>* deletePtr = prevPtr->next;
		prevPtr->next = deletePtr->next;
		delete deletePtr;
	}

	// Precondition: sourcePtr is the head pointer of a linked list.
	// Postcondition: A pointer to a copy of the linked list is returned. The original list is
	// unaltered.
	// Time complexity: O(N), Linear
	Node<T>* copy(Node<T>* headPtr)
	{
		Node<T>* cursor = headPtr;
		Node<T>* newHead = new Node<T>(headPtr->info);
		Node<T>* lastInserted = newHead;

		for (cursor = cursor->next; cursor != nullptr; cursor = cursor->next)
		{
			Node<T>* newNode = new Node<T>(cursor->info);
			lastInserted->next = newNode;
			lastInserted = newNode;
		}

		return newHead;
	}

	// Precondition: headPtr is the head pointer of a linked list.
	// Postcondition: The data item of each Node in the list has been printed to the screen in an
	// easily readable way, e.g. “3 - 4 - 7 - /”
	// Time complexity: O(N), Linear
	void print(Node<T>* headPtr)
	{
		Node<T>* cursor;

		for (cursor = headPtr; cursor != nullptr; cursor = cursor->next)
		{
			std::cout << cursor->info << " - ";
		}

		std::cout << "/" << std::endl;
	}
};