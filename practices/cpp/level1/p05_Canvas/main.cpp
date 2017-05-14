#include <iostream>
#include "canvas.h"

using namespace std;

int main(void)
{
    canvas c;
    c.add_circle(10, 20 , 100);
    c.add_rect(60, 60, 20, 30);
    c.draw();
    return 0;
}
