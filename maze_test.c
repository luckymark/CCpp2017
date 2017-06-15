//maze_test By lizitong
#include<stdio.h>
#include<time.h>
#include<conio.h>
#include<string.h>
#include<stdlib.h>

int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
char a[111][111];
int coin;
int n=5,m;
int px[10011],py[10011],e;
int xs[11][11],ys[11][11],step,steplim;
char pr[111][111];

int Abs(int x);
void lose();//判断失败 
void print(int x,int y);//更新地图 

int main(){
	//输出游戏说明 
	printf("\n\n\n\n\n");
	printf("\t这是一个迷宫游戏！\n");
	printf("\t“#”代表墙壁，“*”代表整个迷宫的边界，这两种地方都不能踩踏！\n");
	printf("\t“o”代表你的位置，用方向键控制你的移动！\n");
	printf("\t当你走到出口(即边界的缺口处)时，你就获胜了！整个迷宫只有一个出口！\n");
	printf("\t你需要在规定的步数以内走出迷宫，你选择的难度等级越大，规定的步数越少！\n");
	printf("\t你可以在迷宫里捡到金币！以“G”表示！\n");
	printf("\t你最终的得分将根据迷宫结构、剩余步数、你选择的难度等级、\n\t捡到的金币数进行计算！\n");
	printf("\n\n");
	printf("\t\t作者：李子通，电子科技大学 计算机科学与工程学院\n\n\t\t2017年2月");
	printf("\n\n\n\t按任意键继续\n");
	printf("\n\n\n\n");
	while(!kbhit());
	getch();
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t请输入迷宫大小(下限为5，上限为30)\n\n\t小于5会默认迷宫大小为5×5，大于30会默认迷宫大小为30×30\n\n\t按下回车确认\n\n\t");
	scanf("%d",&n);
	if(n<5){
		n=5;
	}
	if(n>30){
		n=30;
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t请输入难度等级(下限为1，上限为3)\n\n\t小于1会默认为难度1，大于3会默认为难度3\n\n\t按下回车确认\n\n\t");
	scanf("%d",&m);
	if(m<1){
		m=1;
	}
	if(m>3){
		m=3;
	}
	int xishu[4]={0,1,3,9};
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("\t按任意键开始游戏！迷宫大小：%d×%d 难度等级：%d\n\n\t",n,n,m);
	while(!kbhit());
	getch();
	system("cls");
	
	//随机生成迷宫地图 
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			a[i][j]='#';
		}
	}
	for(int i=0;i<=n+1;++i){
		a[0][i]=a[n+1][i]='*';
	}
	for(int i=1;i<=n;++i){
		a[i][0]=a[i][n+1]='*';
	}
	px[++e]=1;
	py[e]=1;
	px[++e]=n;
	py[e]=n;
	srand(time(0));
	int x=1,y=1;
	while(x<=n&&y<=n){//先构造一条从左上到右下的通路 
		a[x][y]=' ';
		if(x==n){
			++y;
		}
		else if(y==n){
			++x;
		}
		else{
			int dir=rand()%2;
			if(dir){
				++x;
			}
			else{
				++y;
			}
		}
	}
	//随机生成空格总数 
	int space_sum=n*2-1;
	int chushu=rand()%5+1;
	while(chushu<2){
		chushu=rand()%5+1;
	}
	chushu=2;
	int lim=n*n/chushu;
	if(lim<space_sum){
		lim=space_sum;
	}
	//根据难度生成步数限制 
	int xishu2[4];
	if(n<10){
		xishu2[3]=3;
		xishu2[2]=5;
		xishu2[1]=8;
	}
	else if(n<20){
		xishu2[3]=5;
		xishu2[2]=7;
		xishu2[1]=11;
	}
	else{
		xishu2[3]=7;
		xishu2[2]=9;
		xishu2[1]=14;
	}
	if(m==1){
		steplim=(n*2-1)*xishu2[m]/2-(lim-space_sum)/5;
	}
	else if(m==2){
		steplim=(n*2-1)*xishu2[m]/2-(lim-space_sum)/4;
	}
	else{
		steplim=(n*2-1)*xishu2[m]/2-(lim-space_sum)/3;
	}
	while(space_sum<lim){//随机进行挖掘 
		int x=rand()%n+1,y=rand()%n+1;
		while(a[x][y]=='#'){
			x=rand()%n+1;
		 	y=rand()%n+1;
		}
		int op=rand()%4;
		x=x+dx[op];
		y=y+dy[op];
		if(a[x][y]=='#'){
			while(x>=1 && x<=n && y>=1 && y<=n){
				if(a[x][y]==' '){
					break;
				}
				int rnd=rand()%(n/2); 
				if(!rnd){
					break;
				}
				a[x][y]=' ';
				if(x==1 || x==n || y==1 || y==n){
					px[++e]=x;
					py[e]=y;
				}
				++space_sum;
				if(space_sum==lim){
					break;
				}
				x=x+dx[op];
				y=y+dy[op];
			}
		}
	}
	
	//随机生成硬币 
	int coins=rand()%(lim/5)+1,sidescnt=0;
	for(int i=1;i<=coins;++i){
		x=rand()%n+1;
		y=rand()%n+1;
		while(a[x][y]!=' ' || ((x==1 || x==n ||y==1 || y==n) && sidescnt==e-1)){
			x=rand()%n+1;
			y=rand()%n+1;
		}
		a[x][y]='G';
		if(x==1 || x==n || y==1 || y==n){
			++sidescnt;
		}
	}
	
	//随机构造起点终点 
	int id=rand()%e+1;
	int id2=rand()%e+1;
	while(id2==id || Abs(px[id]-px[id2])+Abs(py[id]-py[id2])<=n/2 || a[px[id]][py[id]]!=' '){
		id=rand()%e+1;
		id2=rand()%e+1;
	}
	
	int nowx=px[id],nowy=py[id],aimx,aimy;
	
	if(px[id2]==1){
		a[0][py[id2]]=' ';
		aimx=0,aimy=py[id2];
	}
	else if(px[id2]==n){
		a[n+1][py[id2]]=' ';
		aimx=n+1,aimy=py[id2];
	}
	else if(py[id2]==1){
		a[px[id2]][0]=' ';
		aimx=px[id2],aimy=0;
	}
	else{
		a[px[id2]][n+1]=' ';
		aimx=px[id2];
		aimy=n+1;
	}
	
	for(int i=1;i<=20;++i){
		for(int j=1;j<=20;++j){
			pr[i][j]=' ';
		}
	}
	
	for(int i=1,I=1;i<=5;++i,I+=4){
		for(int j=1,J=1;j<=5;++j,J+=4){
			xs[i][j]=I;
			ys[i][j]=J;
		}
	}
	
	a[nowx][nowy]='o';
	print(nowx,nowy);
	
	while(1){
		//方向键控制，从键盘进行读入 
		int ttx,tty;
		while(!kbhit());
		getch();
		char ch=getch();
		if(ch==72){
			ttx=nowx-1;
			tty=nowy;
		}
		else if(ch==80){
			ttx=nowx+1;
			tty=nowy;
		}
		else if(ch==75){
			ttx=nowx;
			tty=nowy-1;
		}
		else if(ch==77){
			ttx=nowx;
			tty=nowy+1;
		}
		else{
			continue;
		}
		if((a[ttx][tty]!=' ' && a[ttx][tty]!='G') || ttx<0 || ttx>n+1 || tty<0 || tty>n+1){
			continue;
		}
		system("cls");
		a[nowx][nowy]=' ';
		nowx=ttx;
		nowy=tty;
		if(a[nowx][nowy]=='G'){
			++coin;
		}
		a[nowx][nowy]='o';
		print(nowx,nowy);
		if(nowx==aimx && nowy==aimy){//判断到达终点 
			if(step-1>steplim){
				lose();
			}
			//输出最终得分情况 
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t\tYou Win!\n\n");
			printf("\t\t你用了%d步走出迷宫\n\n\t\t你得到了%d个金币\n\n\t\t你的得分是%d！恭喜你！\n",step-1,coin,(steplim-step+1+coin*5+Abs(px[id]-px[id2])+Abs(px[id]+px[id2]))*100*xishu[m]*n/5);
			printf("\n\n\n\n\n\n");
			while(!kbhit());
			getch();
			break;
		}
	}
	return 0;
}

int Abs(int x){
	return x<0 ? (-x) : x;
}

void lose(){
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n");
	printf("\t\tYou Lose!\n");
	printf("\n\n\n\n\n\n\n\n\n\n");
	while(!kbhit());
	getch();
	exit(0);
}

void print(int x,int y){
	if(step>steplim){
		lose();
	}
	for(int i=x-2,I=1;i<=x+2;++i,++I){
		for(int j=y-2,J=1;j<=y+2;++j,++J){
			if(a[i][j]=='#' || a[i][j]=='*' || a[i][j]==' '){
				for(int k=xs[I][J];k<=xs[I][J]+2;++k){
					for(int l=ys[I][J];l<=ys[I][J]+2;++l){
						pr[k][l]=a[i][j];
					}
				}
			}
			else if(a[i][j]=='G'){
				for(int k=xs[I][J];k<=xs[I][J]+2;++k){
					for(int l=ys[I][J];l<=ys[I][J]+2;++l){
						pr[k][l]=' ';
					}
				}
				pr[xs[I][J]+1][ys[I][J]+1]='G';
			}
			else if(a[i][j]=='o'){
				for(int k=xs[I][J];k<=xs[I][J]+2;++k){
					for(int l=ys[I][J];l<=ys[I][J]+2;++l){
						pr[k][l]=' ';
					}
				}
				pr[xs[I][J]+1][ys[I][J]+1]='o';
			}
			else if(i<0 || i>n+1 || j<0 || j>n+1){
				for(int k=xs[I][J];k<=xs[I][J]+2;++k){
					for(int l=ys[I][J];l<=ys[I][J]+2;++l){
						pr[k][l]=' ';
					}
				}
			}
		}
	}
	for(int i=1;i<=20;++i){
		for(int j=1;j<=20;++j){
			putchar(pr[i][j]);
			putchar(' ');
		}
		puts("");
	}
	printf("\n\n");
	printf("\t步数限制：%d\t你的金币数：%d\t你的步数：%d\n",steplim,coin,step++);
}
