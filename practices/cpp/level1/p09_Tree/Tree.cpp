//
//  Tree.cpp
//  p09_Tree
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Tree.h"
using namespace std;

Tree::Tree() {
    numOfNode = 0;
    nodes = new Node(N);
}

void Tree::append(int data, int k) {
    Node node(data, ++numOfNode, k);
    nodes[k].append(node);
}

int Tree::getNumOfSon(int k) {
    return nodes[k].getNumOfSon();
}

int Tree::getParentID(int k) {
    return nodes[k].getParentID();
}
