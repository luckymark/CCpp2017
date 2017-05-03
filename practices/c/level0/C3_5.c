#include <stdio.h>

struct Rect
{
	int left;
	int right;
	int top;
	int bottom;
}A,B;

void judge(Rect A, Rect B)
    {
        if(A.right <= B.left) printf("不重叠");
        if(A.left >= B.right ) printf("不重叠");
        if(A.top <= B.bottom) printf("不重叠");
        if(A.bottom >= B.top) printf("不重叠");
        else printf("重叠");
	
	return;
    }

int main()
{
	A.left=0;
	A.right=1;
	A.top=1;
	A.bottom=0;
	B.left=0;
	B.right=2;
	B.top=2;
	B.bottom=0;
	judge(Rect A, Rect B);
	
	return 0; 
} 
