#pragma once

template <class T>
class Node
{
public:
	Node(T i = 0, Node<T>* n = nullptr)
		: info(i), next(n) {};
	T info;
	Node<T>* next;
};