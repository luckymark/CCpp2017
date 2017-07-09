#include"Tree.h"

using namespace std;

Tree::Tree()
{
	count = 0;
	root = NULL;

}

void Tree::append(int value)
{
	Node* temp=root;
	if (root == NULL)
	{
		root = new Node(root,value);
		count++;
	}
	else
	{
		while (1)
		{
			if (value > temp->value)
			{
				if (temp->right == NULL)
				{
					temp->right = new Node(temp, value);
					count++;
					break;
				}
				temp = temp->right;
			}
			else if (value < temp->value)
			{
				if (temp->left == NULL)
				{
					temp->left = new Node(temp, value);
					count++;
					break;
				}
				temp = temp->left;
			}
			else break;	//value已经存在
		}
	}
}

Node* Tree::locate(int value)
{
	

	Node* temp = root;

	while (1)
	{
		if (value > temp->value)
		{
			if (temp->right == NULL)
			{
				cout << "not found" << endl;
				return NULL;
			}
			temp = temp->right;
		}
		else if (value < temp->value)
		{
			if (temp->left == NULL)
			{
				cout << "not found" << endl;
				return NULL;
			}
			temp = temp->left;
		}
		else		//value已经找到
		{
			cout << "found" << endl;
			return temp;
		}
	}
		
}

void Tree::countNode()
{
	cout << count << endl;
}

Node* Tree::getParent(int value)
{
	Node* temp = locate(value);
	if (temp != NULL)
	{
		if (temp->parent == NULL)
		{
			cout << "target is root" << endl;
		}
		else
		{
			cout << temp->parent->value << endl;
		}
		return temp->parent;
	}
}