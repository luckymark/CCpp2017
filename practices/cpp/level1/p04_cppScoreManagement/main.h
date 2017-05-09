#include <string>

using namespace std;

class Class_information
{
    int score;
    bool is_choose;
};

class Class
{
    public:
        Class_information
            chinese,
            math,
            english;
};

class Student
{
    public:
        string num;
        int gender;
        Class classes;
};


void display_menu();
int get_choose();
void clear_screen();
void read_data();
void write_data();