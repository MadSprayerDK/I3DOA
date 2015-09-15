#include "FifoQueue.h"

namespace PriorityQueue
{
	enum Priorities
	{
		VERY_LOW,
		LOW,
		MEDIUM,
		HIGH,
		VERY_HIGH
	};

	template <class T>
	class PrioQueue
	{
	public:
		PrioQueue()
		{}

		void push(T data, Priorities prio)
		{
			switch (prio)
			{
			case VERY_LOW:
				veryLowQueue.push(data);
				break;

			case LOW:
				lowQueue.push(data);
				break;

			case MEDIUM:
				medQueue.push(data);
				break;

			case HIGH:
				highQueue.push(data);
				break;

			case VERY_HIGH:
				veryHighQueue.push(data);
			}
		}

		void pop()
		{
			if (!veryHighQueue.isEmpty())
				veryHighQueue.pop();
			else if (!highQueue.isEmpty())
				highQueue.pop();
			else if (!medQueue.isEmpty())
				medQueue.pop();
			else if (!lowQueue.isEmpty())
				lowQueue.pop();
			else if (!veryLowQueue.isEmpty())
				veryLowQueue.pop();
		}

		T front()
		{
			T returnElement;

			if (!veryHighQueue.isEmpty())
				returnElement = veryHighQueue.front();
			else if (!highQueue.isEmpty())
				returnElement = highQueue.front();
			else if (!medQueue.isEmpty())
				returnElement = medQueue.front();
			else if (!lowQueue.isEmpty())
				returnElement = lowQueue.front();
			else if (!veryLowQueue.isEmpty())
				returnElement = veryLowQueue.front();

			return returnElement;
		}

		bool isEmpty()
		{
			return lowQueue.isEmpty() || lowQueue.isEmpty() || medQueue.isEmpty() || highQueue.isEmpty() || veryHighQueue.isEmpty();
		}		

	private:
		FifoQueue<T> veryLowQueue;
		FifoQueue<T> lowQueue;
		FifoQueue<T> medQueue;
		FifoQueue<T> highQueue;
		FifoQueue<T> veryHighQueue;
	};	
}