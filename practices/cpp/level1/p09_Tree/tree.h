#pragma once
#include<bits/stdc++.h>
using namespace std;
struct Node{
	int val;
	int parent;
};
class tree {
private:
	vector<Node>list;
	vector<int>set;
public:
	tree();
	~tree(){}
	void insert(int i);
	int totSon(int i);
	void setval(int i,int val);
	int getparent(int i);
};