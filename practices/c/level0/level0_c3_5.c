#include <stdio.h>
void main()
{
    //输入两个矩形的左上角和右下角的点的坐标（x1,y1)(x2,y2)(x3,y3)(x4,y4)
    float x1,y1,x2,y2;
    float x3,y3,x4,y4;
    float wide;
    int x=0;
    scanf("%f%f%f%f%f%f%f%f", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (x2 - x1 > x4-x3) {
        wide = (x4 - x3) / 2;
        if (wide > x1&&wide < x2&&y3 < y4) {
            printf("两个矩形重叠");
            x=1;
        }
    }
    else {
        wide = (x2 - x1) / 2;
        if (wide > x3&&wide < x4&&y1 < y4) {
            printf("两个矩形重叠");
            x=1;
        }
    }
    if (x3 > x1&&x3 < x2&&y3 > y2&&y3 < y1) {
        printf("两个矩形重叠");
        x=1;
    }
    if (x1 > x3&&x1 < x4&&y1>y4&&y1<y3) {
        printf("两个矩形重叠");
        x=1;
    }
    if(x=1){
        printf("两个矩形不重叠");
    }
}
