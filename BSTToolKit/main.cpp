#include "BSTToolKit.h"
#include <iostream>

template<typename T>
void print(BTNode<T>* root, int depth = 0)
{
	if (root)
	{
		print(root->left, depth + 1);
		std::cout << std::string(4 * depth, ' ').c_str() << root->data << std::endl;
		print(root->right, depth + 1);
	}
}

int main()
{
	BTNode<double>* root = new BTNode<double>(12);

	root->left = new BTNode<double>(4); 
	root->left->left = new BTNode<double>(4);
	root->left->right = new BTNode<double>(7);
	root->left->right->left = new BTNode<double>(5);
	root->left->right->right = new BTNode<double>(11);

	root->right = new BTNode<double>(24);
	root->right->left = new BTNode<double>(15);
	root->right->right = new BTNode<double>(25);
	root->right->left->right = new BTNode<double>(21);
	root->right->left->right->left = new BTNode<double>(17);
	root->right->left->right->left->left = new BTNode<double>(16);
	root->right->left->right->left->right = new BTNode<double>(18);

	BTToolKit<double> toolkit;

	print(root);

	// Search
	std::cout << "-- SEARCH --" << std::endl;
	std::cout << "Does 7 exists?: " << toolkit.search(root, 7) << std::endl;
	std::cout << "Does 21 exists?: " << toolkit.search(root, 21) << std::endl;
	std::cout << "Does 99 exists?: " << toolkit.search(root, 99) << std::endl;


	// Insert
	std::cout << std::endl << "-- INSERT --" << std::endl;
	std::cout << "Does 1 exists?: " << toolkit.search(root, 1) << std::endl;
	toolkit.insert(root, 1);
	std::cout << "Does 1 exists?: " << toolkit.search(root, 1) << std::endl;

	/*// Remove
	std::cout << std::endl << "-- REMOVE --" << std::endl;
	std::cout << "Does 1 exists?: " << toolkit.search(root, 1) << std::endl;
	toolkit.remove(root, 1);
	std::cout << "Does 1 exists?: " << toolkit.search(root, 1) << std::endl;

	std::cout << "Does 24 exists?: " << toolkit.search(root, 24) << std::endl;
	toolkit.remove(root, 24);
	std::cout << "Does 24 exists?: " << toolkit.search(root, 24) << std::endl;*/

	return 0;
}