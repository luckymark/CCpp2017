//
//  Node.cpp
//  p09_Tree
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <cstdio>
#include "Node.h"
using namespace std;

Node::Node(int data, int ID, int parentID) {
    this -> data = data;
    this -> ID = ID;
    this -> parentID = parentID;
}

void Node::append(Node node) {
    son.push_back(node);
}

int Node::getNumOfSon() {
    return son.size();
}

int Node::getParentID() {
    return parentID;
}
