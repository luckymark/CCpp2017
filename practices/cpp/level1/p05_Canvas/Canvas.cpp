#include <iostream>
#include <cstdio>
#include <vector>
#define ll long long
using namespace std;
struct Shape {
    string name;
    Shape(string A) {
        name = A;
    }
    Shape() {
        name = "None";
    }
    virtual void print() {
    }
};

struct Circle: public Shape {
    double x, y, r;
    Circle(string SS, double x_input, double y_input , double r_input): Shape(SS)
    {
        name = SS;
        x = x_input;
        y = y_input;
        r = r_input;
    }

    void print() {
        printf("Circle: ");
        cout << name;
        printf("  (x-%lf)^2+(y-%lf)^2=%lf^2", x, y, r);
    }
};

struct Rect: public Shape {
    double x1, y1, x2, y2;
    Rect(string SS, double x1_input, double y1_input , double x2_input, double y2_input): Shape(SS)
    {
        name = SS;
        x1 = x1_input;
        y1 = y1_input;
        x2 = x2_input;
        y2 = y2_input;
    }

    void print() {
        printf("Rect  ");
        cout << name;
        printf("   from (%lf,%lf) to (%lf,%lf)", x1, y1, x2, y2);
    }
};

Shape* All_Shape[100000];
int total = 0;

int main() {
    for (;;) {
        char s[100];
        gets(s);
        if ('J' == s[0])
        {
            gets(s);
            switch (s[0]) {
            case 'C':
            {
                string name_input;
                double x_input, y_input, r_input;
                cin >> name_input;
                scanf("%lf%lf%lf", &x_input, &y_input, &r_input);
                total++;
                All_Shape[total] = new Circle(name_input, x_input, y_input, r_input);
                break;
            }
            case 'R':
            {

                string name_input;
                double x1_input, y1_input, x2_input, y2_input;
                cin >> name_input;
                scanf("%lf%lf%lf%lf", &x1_input, &y1_input, &x2_input, &y2_input);
                total++;
                All_Shape[total] = new Rect(name_input, x1_input, y1_input, x2_input, y2_input);
                break;
            }
            }
        }
        else if ('S' == s[0])
        {
            for (int i = 1; i <= total; i++)
            {
                All_Shape[i]->print();
                puts("");
            }
        }
    }
    return 0;
}