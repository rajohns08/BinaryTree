#include "BinaryTree.h"
#include <iostream>
#include <queue>

using namespace std;

template <class T>
void BinaryTree<T>::insertNode(T val)																// The public function for inserting a node of value val into the tree
{
	TreeNode *newNode;																				// Create the new node

	newNode = new TreeNode;																			// Allocate space for the new node
	newNode->value = val;																			// Initialize the new node's vlaue and left and right pointers
	newNode->left = newNode->right = NULL;

	insert(root, newNode);																			// Call with root, but the insert function will keep digging until it finds the right spot to insert
}

template <class T>
void BinaryTree<T>::insert(TreeNode *&nodePtr, TreeNode *&newNode)									// Must accept a reference pointer for root, becuase we want to change this value non-locally, and it might not end up being root if the function has to dig deeper down the tree
{
	if (nodePtr == NULL)																			// If we are at the end of the tree then we can insert here
	{
		nodePtr = newNode;
	}
	else if (newNode->value < nodePtr->value)														// Keep digging down deeper into the tree until we find the end
	{
		insert(nodePtr->left, newNode);
	}
	else
	{
		insert(nodePtr->right, newNode);
	}
}

template <class T>
void BinaryTree<T>::displayInOrder(TreeNode *nodePtr) const											// Displays the tree "Inorder" (Left Value Right LVR)
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);																// Go left until you can't anymore, then start displaying values
		cout << nodePtr->value << endl;
		displayInOrder(nodePtr->right);
	}
}

template <class T>
void BinaryTree<T>::displayPreOrder(TreeNode *nodePtr) const										// (VLR)
{
	if (nodePtr)
	{
		cout << nodePtr->value << endl;																// Display the value of a node as soon as you get to it
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}

template <class T>
void BinaryTree<T>::displayPostOrder(TreeNode *nodePtr) const										// (LRV)
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);															// Only display value when you can't go left or right, or if coming back to a node that has already exhausted its left and right options
		displayPostOrder(nodePtr->right);
		cout << nodePtr->value << endl;
	}
}

template <class T>
bool BinaryTree<T>::searchNode(T val)																// Search the tree for a given value
{
	TreeNode *nodePtr = root;

	while (nodePtr)																					// While we are not at the end of the tree, keep digging down in the correct order to look for value
	{
		if (nodePtr->value == val)
		{
			return true;
		}
		else if (val < nodePtr->value)
		{
			nodePtr = nodePtr->left;
		}
		else
		{
			nodePtr = nodePtr->right;
		}
	}

	return false;																					// If the while loop exits because we are at the end of the tree, return false
	
}

template <class T>
void BinaryTree<T>::remove(T val)																	// Remove a node of a given value
{
	deleteNode(val, root);
}

template <class T>
void BinaryTree<T>::deleteNode(T val, TreeNode *&nodePtr)											// Search for the correct node to delete and call "makeDeletion" on that node
{
	if (val < nodePtr->value)
	{
		deleteNode(val, nodePtr->left);
	}
	else if (val > nodePtr->value)
	{
		deleteNode(val, nodePtr->right);
	}
	else
	{
		makeDeletion(nodePtr);
	}
}

template <class T>
void BinaryTree<T>::makeDeletion(TreeNode *&nodePtr)												// Actually delete the node we found to have the value specified for deletion
{
	TreeNode *tempNodePtr;

	if (nodePtr == NULL)																			// If the node was never found in "deleteNode", notify that the node can't be deleted
	{
		cout << "Cannot delete an empty node" << endl;
	}
	else if (nodePtr->right == NULL)																// If the right side is NULL, then assign the left side to parent
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;
		delete tempNodePtr;
	}
	else if (nodePtr->left == NULL)																	// If the left side is NULL, then assign the right side to parent
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;
		delete tempNodePtr;
	}
	else																							// If the node to be deleted has 2 children
	{
		tempNodePtr = nodePtr->right;																// Set tempNodePtr to the right child
		
		while (tempNodePtr->left)																	// Need to dig to the end of the left side of the right child, because this is where the node's left pointer will point from
		{
			tempNodePtr = tempNodePtr->left;
		}

		tempNodePtr->left = nodePtr->left;															// Assign the least valued one on the right side to have its left pointer point to the deleted node's left pointer
		tempNodePtr = nodePtr;																		// Reassign tempNodePtr to the node we want to be deleted
		nodePtr = nodePtr->right;																	// Reassign the parent node's pointer to deleted node's right side
		delete tempNodePtr;																			// Delete the node
	}
}

template <class T>
void BinaryTree<T>::destroySubTree(TreeNode *nodePtr)												// Called by public destructor
{
	if (nodePtr)																					// As long as we have something to delete
	{
		if (nodePtr->left)																			// If the node has a left pointer that isn't null, call this function recursively with that node
		{
			destroySubTree(nodePtr->left);
		}
		else if (nodePtr->right)																	// If the node has a right pointer that isn't null, call this function recursively with that node
		{
			destroySubTree(nodePtr->right);
		}
		else
		{
			delete nodePtr;																			// Once we have reached the end, delete the node and return back from function calls until we can find a new node to delete
		}
	}
}

template <class T>
void BinaryTree<T>::displayBFS(TreeNode *nodePtr) const												// Display the tree in breadth first search order
{
	static queue<TreeNode*> myQueue;																// Make this static because we want it to stay the same through the recursive function calls

	if (!myQueue.empty())																			// Only pop if the queue is not empty. Pop off the value that was just called
	{
		myQueue.pop();
	}

	if (nodePtr)																					// Only add things and print value if there is actually a value
	{
		if (nodePtr->left)																			// If the current node has a left child, add it to the queue
		{
			myQueue.push(nodePtr->left);
		}
		if (nodePtr->right)																			// If the current node has a right child, add it to the queue
		{
			myQueue.push(nodePtr->right);
		}

		cout << nodePtr->value << endl;																// Print the current value

		if (!myQueue.empty())																		// If the still has elements, call the function recursively with the front of the queue
		{
			displayBFS(myQueue.front());
		}
	}
}