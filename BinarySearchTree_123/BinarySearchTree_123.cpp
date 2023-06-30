#include<iostream>
#include<string>
using namespace std;

class node
{
public:
	string info;
	node* leftchild;
	node* rightchild;

	// constuctor for the node class
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
		node* NewNode = new node(element, NULL, NULL); // allocate memory for the new node
		NewNode->info = element; //Assign value to the data field of the new node
	}
};
