#include "BTNode.h"
#include <iostream>

double sum(BTNode<double>* root)
{
	double total = 0;

	total += root->data;

	if (root->left != nullptr)
		total += sum(root->left);

	if (root->right != nullptr)
		total += sum(root->right);

	return total;
}

int main()
{
	BTNode<double>* root = new BTNode<double>(5);
	BTNode<double>* rootL = new BTNode<double>(3);
	BTNode<double>* rootR = new BTNode<double>(13);

	root->left = rootL;
	root->right = rootR;

	root->left->right = new BTNode<double>(7);
	root->left->left = new BTNode<double>(9);

	std::cout << "Total sum of tree is: " << sum(root) << std::endl;

	return 0;
}