//
//  main.cpp
//  p04_cppScoreManagement
//
//  Created by Jimmy Fan on 2017/4/13.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#include <iostream>
#include "ScoreManagement.h"
#include "Student.h"

int main(int argc, const char * argv[]) {
    ScoreManagement scoreManagement;
    scoreManagement.inputFromFile();

    bool flag = 1;
    while (flag) {
        int k;
        printf("\n请输入需要进行的操作编号:\n");
        printf(" 1:查看学生名单\n 2:添加学生\n 3:删除学生\n 4:录入成绩\n 0:退出程序\n");
        scanf("%d",&k);
        switch (k) {
            case 0: {
                flag = 0;
                scoreManagement.outputToFile();
                break;
            }
            case 1: {
                int t;
                printf("*按成绩查看名单请输入1\n*按学号查看名单请输入2\n");
                scanf("%d",&t);
                if (t == 1) {
                    scoreManagement.sortByScore();
                    scoreManagement.show();
                }
                else {
                    scoreManagement.sortByID();
                    scoreManagement.show();
                }
                break;
            }
            case 2: {
                char *name;
                name = (char *)malloc(sizeof(char));
                long ID; double score;
                printf("请输入学生信息\n");
                printf(" 请输入学生姓名:");
                scanf("%s",name);
                printf(" 请输入学生学号:");
                scanf("%ld",&ID);
                printf(" 请输入学生成绩:");
                scanf("%lf",&score);
                scoreManagement.addStudent(Student(name,ID,score));
                break;
            }
            case 3: {
                int t;
                printf("*按姓名删除学生请输入1\n*按学号删除学生请输入2\n");
                scanf("%d",&t);
                if (t == 1) {
                    printf("请输入学生姓名:");
                    char *name;
                    scanf("%s",name);
                    int num = scoreManagement.delStudent(name);
                    if (num == 0) {
                        printf("Error:未找到姓名为%s的学生!!\n",name);
                    }
                    else {
                        printf("共找到%d名姓名为%s的学生,已删除其信息\n",num,name);
                    }
                }
                else {
                    printf("请输入学生姓名:");
                    long ID;
                    scanf("%ld",&ID);
                    int num = scoreManagement.delStudent(ID);
                    if (num == 0) {
                        printf("Error:未找到学号为%03ld的学生!!\n",ID);
                    }
                    else {
                        printf("共找到%d名学号为%03ld的学生,已删除其信息\n",num,ID);
                    }
                }
                break;
            }
            case 4: {
                printf("请输入起始学号:");
                long startID;
                scanf("%ld",&startID);
                scoreManagement.inputScore(startID);
                break;
            }
        }
    }
    
    return 0;
}
