// _Tree.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"


#include <iostream>
using namespace std;
typedef struct T
{
	struct T *ltree;
	struct T *rtree;
	int data;
}*tr;
class tree
{
private:
	tr root = NULL;
public:
	void in_tree(int k);     
	void front_out_tree(tr mk);
	void middle_out_tree(tr mk);
	void behind_out_tree(tr mk);
	void creat_tree(tr q, int k);
	tr get_root()
	{
		return root;
	}
};

void tree::in_tree(int k)             
{
	int a;
	cout << "please input:" << endl;
	if (!root && 0 == k)     
	{
		cin >> a;
		root = new T;
		root->data = a;
		root->ltree = NULL;
		root->rtree = NULL;
	}
	creat_tree(root, 1);
	creat_tree(root, 2);
}

void tree::creat_tree(tr q, int k)      
{
	int a;
	cin >> a;
	tr p;
	if (0 != a)
	{
		p = new T;               
		p->data = a;
		p->ltree = NULL;           
		p->rtree = NULL;
		if (1 == k)
		{
			q->ltree = p;
		}
		if (2 == k)
		{
			q->rtree = p;
		}

		creat_tree(p, 1);
		creat_tree(p, 2);
	}
	return;
}


void tree::front_out_tree(tr mk)
{
	if (!mk)
	{
		return;
	}
	cout << mk->data << " ";
	front_out_tree(mk->ltree);
	front_out_tree(mk->rtree);
}

void tree::middle_out_tree(tr mk)
{
	if (!mk)
	{
		return;
	}
	middle_out_tree(mk->ltree);
	cout << mk->data << " ";
	middle_out_tree(mk->rtree);
}


void tree::behind_out_tree(tr mk)
{
	if (!mk)
	{
		return;

		behind_out_tree(mk->ltree);
		behind_out_tree(mk->rtree);
		cout << mk->data << " ";
	}
}



int main()
{
	tree tb;
	tb.in_tree(0);
	tb.front_out_tree(tb.get_root());     
	cout << endl;
	tb.middle_out_tree(tb.get_root());      
	cout << endl;
	tb.behind_out_tree(tb.get_root());      
	cout << endl;
	return 0;
}
