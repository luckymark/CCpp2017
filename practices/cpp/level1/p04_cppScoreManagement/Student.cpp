//
//  Student.cpp
//  p04_cppScoreManagement
//
//  Created by Jimmy Fan on 2017/4/13.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include "Student.h"

Student::Student(char *name, long ID, double score) {
    this -> name = name;
    this -> ID = ID;
    this -> score = score;
}

long Student::showID() {
    return ID;
}

char* Student::showName() {
    return name;
}

double Student::showScore() {
    return score;
}

void Student::setScore(double score) {
    this -> score = score;
}

void Student::setID(long ID) {
    this -> ID = ID;
}
