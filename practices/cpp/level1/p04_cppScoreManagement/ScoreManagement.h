//
//  ScoreManagement.h
//  p04_cppScoreManagement
//
//  Created by Jimmy Fan on 2017/4/13.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef ScoreManagement_h
#define ScoreManagement_h

#include "Student.h"

class ScoreManagement {
private:
    int studentNum;
    Student *stus;
public:
    ScoreManagement(int = 0);
    bool addStudent(Student stu);
    int delStudent(char* name);
    int delStudent(long ID);
    void show();
    void sortByScore();
    void sortByID();
    void inputScore(long startID);
    void outputToFile();
    void inputFromFile();
};


#endif /* ScoreManagement_h */
