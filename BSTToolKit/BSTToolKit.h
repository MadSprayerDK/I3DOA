#include "../SumOfTree/BTNode.h"

template <typename T>
class BTToolKit
{
public:
	void insert(BTNode<T>*& root, const T& data)
	{
		if (root == nullptr)
			root = new BTNode<T>(data);

		if (data > root->data)
		{
			if (root->right == nullptr)
				root->right = new BTNode<T>(data);
			else
				insert(root->right, data);
		}
		else
		{
			if (root->left == nullptr)
				root->left = new BTNode<T>(data);
			else
				insert(root->left, data);
		}
	}

	void remove(BTNode<T>*& root, const T& data)
	{
		
	}

	bool search(BTNode<T>* root, const T& data)
	{
		if (root == nullptr)
			return false;

		if (root->data == data)
			return true;

		return search(root->left, data) || search(root->right, data);
	}
};