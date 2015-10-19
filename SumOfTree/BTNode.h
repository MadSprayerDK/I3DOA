template <typename T>
class BTNode
{
public:
	BTNode(T inputData)
	{
		data = inputData;
	}

	T data;
	BTNode* left = nullptr;
	BTNode* right = nullptr;
};