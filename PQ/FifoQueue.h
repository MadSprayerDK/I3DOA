#include "Node.hpp"
#include "LLToolKit.h"

namespace PriorityQueue
{
	template<class T>
	class FifoQueue
	{
	public: 
		FifoQueue()
		{
			headPtr = nullptr;
		}

		void push(T data)
		{
			this->toolkit.headInsert(this->headPtr, data);
		}

		void pop()
		{
			for (Node<T>* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
			{
				if (cursor->next->next == nullptr)
				{
					toolkit.remove(cursor);
					break;
				}	
			}
		}

		T front()
		{
			for (Node<T>* cursor = headPtr; cursor != nullptr; cursor = cursor->next)
			{
				if (cursor->next == nullptr)
				{
					return cursor->info;
				}
			}

			return nullptr;
		}

		bool isEmpty()
		{
			return this->headPtr == nullptr;
		}

	private:
		Node<T>* headPtr;
		LLTK::LLToolkit<T> toolkit;
	};
}