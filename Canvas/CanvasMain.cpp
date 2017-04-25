#include "Canvas.h"
#include <cstdio>
using namespace std;

int main(){
	int x,y,r,lenx,leny;
	Canvas canvas(100);
	
	scanf("%d%d",&x,&y);
	Point point(x,y);
	canvas.insert(&point,0);
	scanf("%d%d%d",&r,&x,&y);
	Circle circle(r,x,y);
	canvas.insert(&circle,1);
	scanf("%d%d%d%d",&lenx,&leny,&x,&y);
	Rect rect(lenx,leny,x,y);
	canvas.insert(&rect,2);
	canvas.draw();
	return 0;
}
