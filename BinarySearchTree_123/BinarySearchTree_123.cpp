#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	string info;
	node* leftchild;
	node* rightchild;

	// constructor for the node class
	node(string i, node* l, node* r) 
	{
		info = i;
		leftchild = l;
		rightchild = r;
	}
};

class BinaryTree 
{
public:
	node* ROOT;

	BinaryTree()
	{
		ROOT = NULL; //initializing Root to null
	}

	void insert(string element) // insert a node in the binary search tree
	{
		node* NewNode = new node(element, NULL, NULL); //allocate memory for the new node
		NewNode->info = element; //assign value to the data field of the new node
		NewNode->leftchild = NULL; //make the left child of the new node point to null
		NewNode->rightchild = NULL; //make the right child of the new node point to null

		node* parent = NULL;
		node* currentNode = NULL;
		search(element, parent, currentNode); // locate the node which will be the parent of the node to be inserted

		if (parent == NULL) // if the parent is NULL (Tree is empty)
		{
			ROOT = NewNode; //mark the new node as ROOT
			return; //exit
		}

		if (element < parent->info) // if the value in the data field of the new node is less than that of the parent
		{
			parent->leftchild = NewNode; // make the left child of the parent point to the new node
		}
		else if (element > parent->info)  // if the value in the data field of the new node is greater than that of the parent 
		{
			parent->rightchild = NewNode; // make the right child of the parent point to the new node
		}
	}


	void search(string element, node*& parent, node*& currentNode)
	{
		//this function searches the currentNode of the specified node as well as current Node of its parent
		currentNode = ROOT;
		parent = NULL;
		while ((currentNode != NULL) && (currentNode->info != element))
		{
			parent = currentNode;
			if (element < currentNode->info)
				currentNode = currentNode->leftchild;
			else
				currentNode = currentNode->rightchild;
		}
	}

	void inorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			inorder(ptr->leftchild);
			cout << ptr->info << "  ";
			inorder(ptr->rightchild);
		}
	}

	void preorder(node* ptr)
	{
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			cout << ptr->info << "  ";
			preorder(ptr->leftchild);
			preorder(ptr->rightchild);
		}
	}

	void postorder(node* ptr)
	{
		//performs the postorder traversal of the tree
		if (ROOT == NULL)
		{
			cout << "Tree is empty" << endl;
			return;
		}
		if (ptr != NULL)
		{
			postorder(ptr->leftchild);
			postorder(ptr->rightchild);
			cout << ptr->info << "  ";
		}
	}
};
