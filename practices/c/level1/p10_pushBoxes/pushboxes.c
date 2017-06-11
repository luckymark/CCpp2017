#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

char map[9][9];
void mapprint();
void move();
struct Point 
{
	int x;
	int y;
};

struct Point box[3];
struct Point person;
struct Point target[3];
int m=1,n=0;
int main() 
{
	printf(" There is two maps that you can chose \ninput map1.txt to chose the first\ninput map2.txt to chose the scecond:\n") ;
	int f,k;
	int a=0,b=0;
	FILE*fp;
	char ch,filename[10];
	printf("name");
	scanf("%s",filename);
	if((fp=fopen(filename,"r"))==NULL){
		printf("cannot open");
		exit(0);
	}
	for(f=0;f<9;f++){
		for(k=0;k<10;k++){
			char n=fgetc(fp);
			if(n!='\n'){
				map[f][k]=n;
				if(n=='R'){
					person.x=f;
					person.y=k;
				}//确定人的坐标 
				if(n=='B'){
					box[a].x=f;
					box[a].y=k;
					a++;
				}//确定三个箱子的坐标 
				if(n=='T'){
					target[b].x=f;
					target[b].y=k;
					b++;
				}//确定三个目标的坐标 
			} 
		}
	}
	printf("\n");
	fclose(fp);
	
	mapprint();
	while(m){
		move();
	}
	return 0;
}

void mapprint()
{
	int i,j;
	for(i=0;i<9;i++){
		for(j=0;j<9;j++){
			printf("%c",map[i][j]);
		}
		printf("\n");
	}
}


void move()
{
	if(GetKeyState(VK_UP)<0){
		int o=0;
		if(target[0].x==person.x&&target[0].y==person.y) o=1;
		if(target[1].x==person.x&&target[1].y==person.y) o=1;
		if(target[2].x==person.x&&target[2].y==person.y) o=1;//判断人是否与T的位置重合 
		if(map[person.x-1][person. y]==' '&&o==0){
			person.x--; 
			map[person.x][person.y]='R';
			map[person.x+1][person.y]=' ';//上面是不重合时 
		}else if(map[person.x-1][person. y]==' '&&o==1){
			person.x--; 
			map[person.x][person.y]='R';
			map[person.x+1][person.y]='T';//上面是重合时
		}else if(map[person.x-1][person. y]=='T'&&o==0){
			person.x--; 
			map[person.x][person.y]='R';
			map[person.x+1][person.y]=' ';//上面是不重合时 
		}else if(map[person.x-1][person. y]=='T'&&o==1){
			person.x--; 
			map[person.x][person.y]='R';
			map[person.x+1][person.y]='T';//上面是重合时
		}else if(map[person.x-1][person.y]=='B'&&map[person.x-2][person.y]!='0'&&map[person.x-2][person.y]!='B'&&o==0){
			person.x--;
			map[person.x][person.y]='R'; 
			map[person.x+1][person.y]=' ';
			map[person.x-1][person.y]='B'; 
		}else if(map[person.x-1][person.y]=='B'&&map[person.x-2][person.y]!='0'&&map[person.x-2][person.y]!='B'&&o==1){
			person.x--;
			map[person.x][person.y]='R'; 
			map[person.x+1][person.y]='T';
			map[person.x-1][person.y]='B'; 
		}
		if(map[target[0].x][target[0].y]!='B'&&map[target[0].x][target[0].y]!='R'){
			map[target[0].x][target[0].y]='T';
		}
		if(map[target[1].x][target[1].y]!='B'&&map[target[1].x][target[1].y]!='R'){
			map[target[1].x][target[1].y]='T';
		}
		if(map[target[2].x][target[2].y]!='B'&&map[target[2].x][target[2].y]!='R'){
			map[target[2].x][target[2].y]='T';
		}
		system("cls");
		mapprint();
		Sleep(100);
		n++;
	}

	if(GetKeyState(VK_DOWN)<0){
		int o=0;
		if(target[0].x==person.x&&target[0].y==person.y) o=1;
		if(target[1].x==person.x&&target[1].y==person.y) o=1;
		if(target[2].x==person.x&&target[2].y==person.y) o=1;//判断人是否与T的位置重合 
		if(map[person.x+1][person. y]==' '&&o==0){
			person.x++; 
			map[person.x][person.y]='R';
			map[person.x-1][person.y]=' ';//上面是不重合时 
		}else if(map[person.x+1][person. y]==' '&&o==1){
			person.x++; 
			map[person.x][person.y]='R';
			map[person.x-1][person.y]='T';//上面是重合时
		}else if(map[person.x+1][person. y]=='T'&&o==0){
			person.x++; 
			map[person.x][person.y]='R';
			map[person.x-1][person.y]=' ';//上面是不重合时 
		}else if(map[person.x+1][person. y]=='T'&&o==1){
			person.x++; 
			map[person.x][person.y]='R';
			map[person.x-1][person.y]='T';//上面是重合时
		}else if(map[person.x+1][person.y]=='B'&&map[person.x+2][person.y]!='0'&&map[person.x+2][person.y]!='B'&&o==0){
			person.x++;
			map[person.x][person.y]='R'; 
			map[person.x-1][person.y]=' ';
			map[person.x+1][person.y]='B'; 
		}else if(map[person.x+1][person.y]=='B'&&map[person.x+2][person.y]!='0'&&map[person.x+2][person.y]!='B'&&o==1){
			person.x++;
			map[person.x][person.y]='R'; 
			map[person.x-1][person.y]='T';
			map[person.x+1][person.y]='B'; 
		}
		if(map[target[0].x][target[0].y]!='B'&&map[target[0].x][target[0].y]!='R'){
			map[target[0].x][target[0].y]='T';
		}
		if(map[target[1].x][target[1].y]!='B'&&map[target[1].x][target[1].y]!='R'){
			map[target[1].x][target[1].y]='T';
		}
		if(map[target[2].x][target[2].y]!='B'&&map[target[2].x][target[2].y]!='R'){
			map[target[2].x][target[2].y]='T';
		}
		system("cls");
		mapprint();
		Sleep(100);
		n++;
	}
	
	if(GetKeyState(VK_LEFT)<0){
		int o=0;
		if(target[0].x==person.x&&target[0].y==person.y) o=1;
		if(target[1].x==person.x&&target[1].y==person.y) o=1;
		if(target[2].x==person.x&&target[2].y==person.y) o=1;//判断人是否与T的位置重合	
		if(map[person.x][person. y-1]==' '&&o==0){
			person.y--; 
			map[person.x][person.y]='R';
			map[person.x][person.y+1]=' ';//上面是不重合时 
		}else if(map[person.x][person. y-1]==' '&&o==1){
			person.y--; 
			map[person.x][person.y]='R';
			map[person.x][person.y+1]='T';//上面是重合时
		}else if(map[person.x][person. y-1]=='T'&&o==0){
			person.y--; 
			map[person.x][person.y]='R';
			map[person.x][person.y+1]=' ';//上面是不重合时 
		}else if(map[person.x][person. y-1]=='T'&&o==1){
			person.y--; 
			map[person.x][person.y]='R';
			map[person.x-1][person.y+1]='T';//上面是重合时
		}else if(map[person.x][person.y-1]=='B'&&map[person.x][person.y-2]!='0'&&map[person.x][person.y-2]!='B'&&o==0){
			person.y--;
			map[person.x][person.y]='R'; 
			map[person.x][person.y+1]=' ';
			map[person.x][person.y-1]='B'; 
		}else if(map[person.x][person.y-1]=='B'&&map[person.x][person.y-2]!='0'&&map[person.x][person.y-2]!='B'&&o==1){
			person.y--;
			map[person.x][person.y]='R'; 
			map[person.x][person.y+1]='T';
			map[person.x][person.y-1]='B'; 
		}
		if(map[target[0].x][target[0].y]!='B'&&map[target[0].x][target[0].y]!='R'){
			map[target[0].x][target[0].y]='T';
		}
		if(map[target[1].x][target[1].y]!='B'&&map[target[1].x][target[1].y]!='R'){
			map[target[1].x][target[1].y]='T';
		}
		if(map[target[2].x][target[2].y]!='B'&&map[target[2].x][target[2].y]!='R'){
			map[target[2].x][target[2].y]='T';
		}
		system("cls");
		mapprint();
		Sleep(100);
		n++;
	}	
	
	if(GetKeyState(VK_RIGHT)<0){
		int o=0;
		if(target[0].x==person.x&&target[0].y==person.y) o=1;
		if(target[1].x==person.x&&target[1].y==person.y) o=1;
		if(target[2].x==person.x&&target[2].y==person.y) o=1;//判断人是否与T的位置重合	
		if(map[person.x][person. y+1]==' '&&o==0){
			person.y++; 
			map[person.x][person.y]='R';
			map[person.x][person.y-1]=' ';//上面是不重合时 
		}else if(map[person.x][person. y+1]==' '&&o==1){
			person.y++; 
			map[person.x][person.y]='R';
			map[person.x][person.y-1]='T';//上面是重合时
		}else if(map[person.x][person. y+1]=='T'&&o==0){
			person.y++; 
			map[person.x][person.y]='R';
			map[person.x][person.y-1]=' ';//上面是不重合时 
		}else if(map[person.x][person. y+1]=='T'&&o==1){
			person.y++; 
			map[person.x][person.y]='R';
			map[person.x+1][person.y-1]='T';//上面是重合时
		}else if(map[person.x][person.y+1]=='B'&&map[person.x][person.y+2]!='0'&&map[person.x][person.y+2]!='B'&&o==0){
			person.y++;
			map[person.x][person.y]='R'; 
			map[person.x][person.y-1]=' ';
			map[person.x][person.y+1]='B'; 
		}else if(map[person.x][person.y+1]=='B'&&map[person.x][person.y+2]!='0'&&map[person.x][person.y+2]!='B'&&o==1){
			person.y++;
			map[person.x][person.y]='R'; 
			map[person.x][person.y-1]='T';
			map[person.x][person.y+1]='B'; 
		}
		if(map[target[0].x][target[0].y]!='B'&&map[target[0].x][target[0].y]!='R'){
			map[target[0].x][target[0].y]='T';
		}
		if(map[target[1].x][target[1].y]!='B'&&map[target[1].x][target[1].y]!='R'){
			map[target[1].x][target[1].y]='T';
		}
		if(map[target[2].x][target[2].y]!='B'&&map[target[2].x][target[2].y]!='R'){
			map[target[2].x][target[2].y]='T';
		}
		system("cls");
		mapprint();
		Sleep(100);
		n++;
	}	
	
	if(map[target[0].x][target[0].y]=='B'&&map[target[1].x][target[1].y]=='B'&&map[target[2].x][target[2].y]=='B'){
		printf("you win!");
		printf("you use %d paces",n);
		char ch;
		FILE*score;
		if((score=fopen("score","w"))==NULL){
		printf("cannot open");
		exit(0);
	}
	ch=n;
	fputc(ch,score);
	fclose(score);
		m=0;
		
	}//判断是否结束 
}



