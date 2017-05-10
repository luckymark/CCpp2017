//
//  Student.h
//  p04_cppScoreManagement
//
//  Created by Jimmy Fan on 2017/4/13.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Student_h
#define Student_h

#include <stdio.h>

class Student {
private:
    char *name;
    long ID;
    double score;
public:
    Student(char* = NULL, long = -1, double = 0);
    long showID();
    char* showName();
    double showScore();
    void setScore(double score);
    void setID(long ID);
};


#endif /* Student_h */
