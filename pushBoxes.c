#include<stdio.h>
#include<conio.h>
#include<windows.h>
#define LEVEL 3

typedef struct Node{
	int x[3],y[3];
	char deled[3];
	struct Node *pre;
}Node;
Node *tail;
void push_back(int xs[],int ys[],char dels[]);

char Map[110][110];
int dx[110],dy[110],n,m;
int had,all;
int is_place[110][110];

void print_xy(const char* str,int len,int x,int y);
int check_boxes(int x,int y,char dir);
void calc_had();

int main(){
	char ch;
	//游戏说明 
	printf("This is a Game of Pushing Boxes.\n");
	printf("You are at the Place of 'O'.\n");
	printf("Use the Direction Keys to Move.\n");
	printf("'#' is a box. You can Move Several Boxes at the Same Time.\n");
	printf("'*' is a Wall,You can not Move on it or Put the Boxes on it.\n");
	printf("'@' is a Place You Need to Put a Box on it.\n");
	printf("'Y' is a Box which is on the '@'.\n");
	printf("\n\t\tAuthor : Li Zitong, CCSE, UESTC, 2017/03\n");
	printf("\n\n请按任意键继续．．．\n");
	while(!kbhit());
	ch=getch();
	if(ch==-32){
		getch();
	}
	
	system("cls");
	FILE *fp,*fp2=fopen("RESULTS.txt","w");
	char tmp_print[5]={0};
	char file_name[20];
	dx[72]=-1; dy[72]=0;
	dx[80]=1; dy[80]=0;
	dx[75]=0; dy[75]=-1;
	dx[77]=0; dy[77]=1;
	
	int xs[3],ys[3];
	char dels[3];
	
	for(int i=1;i<=LEVEL;++i){
		had=all=0;
		int steps=0,cancels=0;
		int x,y;
		sprintf(file_name,"LEVEL%d.txt",i);
		fp=fopen(file_name,"r");
		fscanf(fp,"%d%d%d%d",&n,&m,&x,&y);
		fgetc(fp);
		for(int j=0;j<n;++j){
			fgets(Map[j],m+2,fp);
		}
		fclose(fp);
		memset(is_place,0,sizeof(is_place));
		for(int j=0;j<n;++j){
			for(int k=0;k<m;++k){
				if(Map[j][k]=='@'){
					++all;
					is_place[j][k]=1;
				}
			}
		}
		for(int j=0;j<n;++j){
			printf(Map[j]);
		}
		printf("LEVEL: %d\nSteps:0    Cancels:0   \n",i);
		while(1){
			//方向键控制，从键盘进行读入
			while(!kbhit());
			ch=getch();
			if(ch==8){
				if(tail==NULL){
					continue;
				}
				++cancels;
				for(int j=0;j<=2 && (*tail).deled[j];++j){
					Map[(*tail).x[j]][(*tail).y[j]]=tmp_print[0]=(*tail).deled[j];
					print_xy(tmp_print,1,(*tail).x[j],(*tail).y[j]);
				}
				x=(*tail).x[1]; y=(*tail).y[1];
				Node* tmp=tail;
				tail=(*tail).pre;
				free(tmp);
				sprintf(tmp_print,"%d",cancels);
				print_xy(tmp_print,strlen(tmp_print),n+1,19);
//				calc_had();
			}
			else{
				if(ch==-32){
					ch=getch();
				}
				int tx,ty;
				if(ch==72 || ch==80 || ch==75 || ch==77){
					tx=x+dx[ch];
					ty=y+dy[ch];
				}
				else{
					continue;
				}
				if(Map[tx][ty]==' ' || Map[tx][ty]=='@'){
					++steps;
					dels[0]=Map[tx][ty];
					xs[0]=tx; ys[0]=ty;
					Map[tx][ty]=tmp_print[0]='O';
					print_xy(tmp_print,1,tx,ty);
					xs[1]=x; ys[1]=y;
					dels[1]=Map[x][y];
					Map[x][y]=tmp_print[0]=(is_place[x][y] ? '@' : ' ');
					print_xy(tmp_print,1,x,y);
					dels[2]=0;
					x=tx; y=ty;
					push_back(xs,ys,dels);
					sprintf(tmp_print,"%d",steps);
					print_xy(tmp_print,strlen(tmp_print),n+1,6);
				}
				else{
					int sum_boxes=check_boxes(tx,ty,ch);
					if(sum_boxes){
						++steps;
						int ttx=tx+dx[ch]*sum_boxes,tty=ty+dy[ch]*sum_boxes;
						dels[0]=Map[ttx][tty];
						xs[0]=ttx; ys[0]=tty;
						Map[ttx][tty]=tmp_print[0]=(is_place[ttx][tty] ? 'Y' : '#');
						print_xy(tmp_print,1,ttx,tty);
						dels[2]=Map[tx][ty];
						xs[2]=tx; ys[2]=ty;
						Map[tx][ty]=tmp_print[0]='O';
						print_xy(tmp_print,1,tx,ty);
						dels[1]=Map[x][y];
						xs[1]=x; ys[1]=y;
						Map[x][y]=tmp_print[0]=(is_place[x][y] ? '@' : ' ');
						print_xy(tmp_print,1,x,y);
						x=tx; y=ty;
						push_back(xs,ys,dels);
						sprintf(tmp_print,"%d",steps);
						print_xy(tmp_print,strlen(tmp_print),n+1,6);
						calc_had();
						if(had==all){
							printf("You Win!\n请按任意键继续．．．\n");
							break;
						}
					}
				}
			}
		}
		fprintf(fp2,"LEVEL%d : Steps:%d\tCancels:%d\n",i,steps,cancels);
		while(!kbhit());
		ch=getch();
		if(ch==-32){
			getch();
		}
		system("cls");
		while(tail!=NULL){
			Node* tmp=tail;
			tail=(*tail).pre;
			free(tmp);
		}
	}
	fclose(fp2);
	fp=fopen("RESULTS.txt","r");
	char tmp_print_2[110];
	printf("Game is Over.\nYou can Check Your Scores in the RESULTS.txt.\n\n");
	for(int i=1;i<=LEVEL;++i){
		fgets(tmp_print_2,100,fp);
		printf(tmp_print_2);
	}
	return 0;
}

void print_xy(const char* str,int len,int x,int y){
	//向第x行y列输出len长度的字符串(位置从零开始) 
    PDWORD NumberOfCharsWritten;
    HANDLE hnd=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD coord={y,x};
    WriteConsoleOutputCharacter(hnd,str,len,coord,NumberOfCharsWritten);
}

int check_boxes(int x,int y,char dir){
	if(Map[x][y]!='#' && Map[x][y]!='Y'){
		return 0;
	}
	int cnt=0;
	while(Map[x][y]=='#' || Map[x][y]=='Y'){
		++cnt;
		x=x+dx[dir];
		y=y+dy[dir];
	}
	return Map[x][y]!='*' ? cnt : 0;
}

void push_back(int xs[],int ys[],char dels[]){
	if(tail==NULL){
		tail=(Node*)malloc(sizeof(Node));
		(*tail).pre=NULL;
	}
	else{
		Node* tmp=(Node*)malloc(sizeof(Node));
		(*tmp).pre=tail;
		tail=tmp;
	}
	memcpy((*tail).x,xs,sizeof(int)*3);
	memcpy((*tail).y,ys,sizeof(int)*3);
	memcpy((*tail).deled,dels,sizeof(char)*3);
}

void calc_had(){
	had=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(Map[i][j]=='Y'){
				++had;
			}
		}
	}
}
