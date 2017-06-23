//
//  Node.h
//  p09_Tree
//
//  Created by Jimmy Fan on 2017/6/23.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Node_h
#define Node_h

#include <vector>
using namespace std;

class Node {
private:
    int data;
    int ID;
    int parentID;
    vector <Node> son;
public:
    Node(int = 0, int = 0, int = 0);
    void append(Node node);
    int getNumOfSon();
    int getParentID();
};

#endif /* Node_h */
