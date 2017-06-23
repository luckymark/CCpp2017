//
//  ScoreManagement.cpp
//  p04_cppScoreManagement
//
//  Created by Jimmy Fan on 2017/4/13.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <stdio.h>
#include <cstdlib>
#include "ScoreManagement.h"
#include <string>
#include <algorithm>
using namespace std;

ScoreManagement::ScoreManagement(int studentNum) {
    this -> studentNum = studentNum;
    this -> stus = new Student[studentNum];
}

bool ScoreManagement::addStudent(Student stu) {
    bool flag = 0;
    for (int i = 0; i < studentNum; i++) {
        if (stus[i].showID() == -1) {
            stus[i] = stu;
            flag = 1;
            break;
        }
        if (stus[i].showID() == stu.showID()) {
            break;
        }
    }
    return flag;
}

int ScoreManagement::delStudent(char* name) {
    int num = 0;
    for (int i = 0; i < studentNum; i++) {
        if (stus[i].showID() == -1) continue;
        if (strcmp(name, stus[i].showName()) == 0) {
            num ++;
            stus[i].setID(-1);
        }
    }
    return num;
}

int ScoreManagement::delStudent(long ID) {
    int num = 0;
    for (int i = 0; i < studentNum; i++) {
        if (stus[i].showID() == ID) {
            num ++;
            stus[i].setID(-1);
        }
    }
    return num;
}

void ScoreManagement::show() {
    bool flag = 0;
    for (int i = 0; i < studentNum; i++) {
        if (stus[i].showID() != -1) {
            printf(" %s %03ld %.2lf\n",stus[i].showName(),stus[i].showID(),stus[i].showScore());
            flag = 1;
        }
    }
    if (!flag) {
        printf("当前没有学生信息！\n");
    }
}

bool cmpScore(Student stu1, Student stu2) {
    if (stu1.showScore() == stu2.showScore()) {
        return stu1.showID() < stu2.showID();
    }
    return stu1.showScore() > stu2.showScore();
}

void ScoreManagement::sortByScore() {
    sort(stus,stus + studentNum, cmpScore);
}

bool cmpID(Student stu1, Student stu2) {
    return stu1.showID() < stu2.showID();
}

void ScoreManagement::sortByID() {
    sort(stus,stus + studentNum, cmpID);
}

void ScoreManagement::inputScore(long ID) {
    sortByID();
    bool find = 0;
    int stuIndex = 0;
    for (int i = 0; i < studentNum; i++) {
        if (stus[i].showID() == -1) continue;
        if (stus[i].showID() == ID) {
            find = 1;
            stuIndex = i;
            break;
        }
    }
    if (!find) {
        printf("Error:未找到学号为%03ld的学生!\n",ID);
        return;
    }
    while (1) {
        printf("请输入学生 %s(学号:%03ld)的成绩:",stus[stuIndex].showName(),ID);
        double score;
        scanf("%lf",&score);
        stus[stuIndex ++].setScore(score);
        if (stuIndex == studentNum) break;
        ID = stus[stuIndex].showID();
        printf("下一名学生姓名为:%s(学号:%03ld)\n *继续录入请输入1\n *结束录入请输入0\n",stus[stuIndex].showName(),ID);
        int k;
        scanf("%d",&k);
        if (k == 0) break;
    }
}

void ScoreManagement::outputToFile() {
    freopen("cppScoreManagement", "w", stdout);
    printf("%d\n",studentNum);
    for (int i = 0; i < studentNum; i++) {
        if (stus[i].showID() == -1) {
            printf("-1\n");
        }
        else {
            printf("%ld\n%s\n%lf\n",stus[i].showID(),stus[i].showName(),stus[i].showScore());
        }
    }
    fclose(stdout);
}

void ScoreManagement::inputFromFile() {
    FILE *file;
    file = fopen("cppScoreManagement", "r");
    int studentNum;
    bool fileExist = 1;
    if (fscanf(file,"%d",&studentNum) == EOF || studentNum == 0) {
        printf("请输入学生总人数:");
        scanf("%d",&studentNum);
        fileExist = 0;
    }
    this -> studentNum = studentNum;
    this -> stus = new Student[studentNum];
    if (fileExist) {
        for (int i = 0; i < studentNum; i++) {
            long ID;
            fscanf(file,"%ld",&ID);
            if (ID == -1) continue;
            char *name;
            name = (char *)malloc(sizeof(char));
            double score;
            fscanf(file,"%s",name);
            fscanf(file,"%lf",&score);
            stus[i] = Student(name,ID,score);
        }
    }
    fclose(file);
}
