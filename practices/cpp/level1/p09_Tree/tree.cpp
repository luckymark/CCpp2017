/*
题目：Tree

功能要求：

可以在树的某个节点上append任意数量的子节点
每个节点都可以保存一个int型的值
可获取节点的parent（父节点）
可计算节点的子孙节点总数
*/

#include<iostream>
#include<vector>
using std::cin;
using std::cout;
using std::endl;
using std::vector;

class Tree{
	private:
		vector<Tree*> children;
		Tree* parent;
		int value;
	public:
		Tree(int);
		void app(Tree*);
		Tree* getParent();
		int countChildren();
};

Tree::Tree(int n){
	parent=NULL;
	value=n;
}

void Tree::app(Tree* t){
	t->parent=this;
	children.push_back(t);
}

Tree* Tree::getParent(){
	return this->parent;
}

int Tree::countChildren(){
	vector<Tree*>::iterator it;
	for(it=this->children.begin();it!=this->children.end();it++){}
	return it-children.begin();
}

int main(){
    Tree t1(1),t2(3),t3(3),t4(5),t5(5);
    t2.app(&t4);
    t2.app(&t5);
    t1.app(&t2);
    t1.app(&t3);
	return 0;
}
