#ifndef BINARYTREE_H
#define BINARYTREE_H

template <class T>																				// Template class for binary tree. This is dangerous because the data must be able to be compared with > operators
class BinaryTree
{
private:
	struct TreeNode																				// The structure for each tree node. A value, and a left and right pointer to its children.
	{
		T value;
		TreeNode *left;
		TreeNode *right;
	};

	TreeNode *root;																				// The root of the tree initialzed to NULL in the constructor

	void insert(TreeNode *&nodePtr, TreeNode *&newNode);										// Must accept the arguments as pointer references so that they can be changed non-locally. The asterisk is because they are pointers obviously. The asterisk is to make them reference variables.
	void destroySubTree(TreeNode *nodePtr);														// Used by the destructor to destroy the tree
	void deleteNode(T val, TreeNode *&nodePtr);													// Used by the public "remove" function to find the correct node to delete
	void makeDeletion(TreeNode *&nodePtr);														// Used by "deleteNode" to actually remove the node
	void displayInOrder(TreeNode *nodePtr) const;												// Don't need these to be references, because we aren't updating any values, just displaying
	void displayPreOrder(TreeNode *nodePtr) const;
	void displayPostOrder(TreeNode *nodePtr) const;
	void displayBFS(TreeNode *nodePtr) const;

public:
	BinaryTree()
		{ root = NULL; }

	~BinaryTree()
		{ destroySubTree(root); }

	void insertNode(T val);																		// Insert a node with value val into the tree
	bool searchNode(T val);																		// Search for a node with value val in the tree
	void remove(T val);																			// Remove a node with value val in the tree

	void displayInOrder() const
		{ displayInOrder(root); }

	void displayPreOrder() const
		{ displayPreOrder(root); }

	void displayPostOrder() const
		{ displayPostOrder(root); }

	void displayBFS() const
		{ displayBFS(root); }
};


#endif 
