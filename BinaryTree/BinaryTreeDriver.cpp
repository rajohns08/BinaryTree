#include <iostream>
#include "BinaryTree.h"
#include "BinaryTree.cpp"

using namespace std;

int main()
{
	BinaryTree<int> binTreeObj;																		// github test

	binTreeObj.insertNode(5);
	binTreeObj.insertNode(3);
	binTreeObj.insertNode(8);
	binTreeObj.insertNode(12);
	binTreeObj.insertNode(9);
	binTreeObj.insertNode(2);

	cout << "Inorder:" << endl;
	binTreeObj.displayInOrder();
	cout << endl;

	cout << "Preorder:" << endl;
	binTreeObj.displayPreOrder();
	cout << endl;

	cout << "Postorder:" << endl;
	binTreeObj.displayPostOrder();
	cout << endl;

	cout << "BFS:" << endl;
	binTreeObj.displayBFS();
	cout << endl;

	cin.get();
	return 0;
}