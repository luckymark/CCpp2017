/* to do list
create class student
add, delete
enter score one by one
end program
*/

#include<iostream>
#include<cstring>
#include<fstream>
//#include<cstdlib>
#include"student.h"
using namespace std;
int main()
{
    student cs("cs.txt");
    cs.menu();
    return 0;
}
