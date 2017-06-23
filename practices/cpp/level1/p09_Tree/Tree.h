//
//  Tree.h
//  p09_Tree
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Tree_h
#define Tree_h

#include "Node.h"
#define N 100

class Tree {
private:
    int numOfNode;
    Node *nodes;
public:
    Tree();
    void append(int data, int k);
    int getNumOfSon(int k);
    int getParentID(int k);
};


#endif /* Tree_h */
