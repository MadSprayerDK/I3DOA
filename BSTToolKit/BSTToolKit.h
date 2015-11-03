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
		if (!search(root, data))
			return;

		BTNode<T>* toDelete = nodeLocater(root, data);

		if (toDelete->left == nullptr && toDelete->right == nullptr)
		{
			BTNode<T>* parentNode = parentOfNode(root, toDelete);

			if (parentNode->left == toDelete)
				parentNode->left = nullptr;
			else
				parentNode->right = nullptr;

			delete toDelete;
			return;
		}

		BTNode<T>* replacementParent = toDelete->left;

		while (true)
		{
			if (replacementParent->right->right != nullptr)
				replacementParent = replacementParent->right;
			else
				break;
		}

		BTNode<T>* replacementNode = replacementParent->right;

		toDelete->data = replacementNode->data;
		replacementParent->right = replacementNode->left;

		delete replacementNode;
	}

	bool search(BTNode<T>* root, const T& data)
	{
		if (root == nullptr)
			return false;

		if (root->data == data)
			return true;

		return search(root->left, data) || search(root->right, data);
	}

private:
	BTNode<T>* nodeLocater(BTNode<T>* rootNode, const T& data)
	{
		BTNode<T>* returnNode;

		if (rootNode == nullptr)
			return nullptr;

		if (rootNode->data == data)
			returnNode = rootNode;
		else
		{
			returnNode = nodeLocater(rootNode->left, data);

			if (returnNode == nullptr)
				returnNode = nodeLocater(rootNode->right, data);
		}

		return returnNode;
	}

	BTNode<T>* parentOfNode(BTNode<T>* rootNode, BTNode<T>* nodeToFind)
	{
		BTNode<T>* returnNode = nullptr;

		if (rootNode->left == nodeToFind || rootNode->right == nodeToFind)
			returnNode = rootNode;
		else
		{
			returnNode = parentOfNode(rootNode->left, nodeToFind);

			if (returnNode == nullptr)
				returnNode = parentOfNode(rootNode->right, nodeToFind);
		}
		
		return returnNode;
	}
};