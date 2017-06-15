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
void lose();//�ж�ʧ�� 
void print(int x,int y);//���µ�ͼ 

int main(){
	//�����Ϸ˵�� 
	printf("\n\n\n\n\n");
	printf("\t����һ���Թ���Ϸ��\n");
	printf("\t��#������ǽ�ڣ���*�����������Թ��ı߽磬�����ֵط������ܲ�̤��\n");
	printf("\t��o���������λ�ã��÷������������ƶ���\n");
	printf("\t�����ߵ�����(���߽��ȱ�ڴ�)ʱ����ͻ�ʤ�ˣ������Թ�ֻ��һ�����ڣ�\n");
	printf("\t����Ҫ�ڹ涨�Ĳ��������߳��Թ�����ѡ����Ѷȵȼ�Խ�󣬹涨�Ĳ���Խ�٣�\n");
	printf("\t��������Թ���񵽽�ң��ԡ�G����ʾ��\n");
	printf("\t�����յĵ÷ֽ������Թ��ṹ��ʣ�ಽ������ѡ����Ѷȵȼ���\n\t�񵽵Ľ�������м��㣡\n");
	printf("\n\n");
	printf("\t\t���ߣ�����ͨ�����ӿƼ���ѧ �������ѧ�빤��ѧԺ\n\n\t\t2017��2��");
	printf("\n\n\n\t�����������\n");
	printf("\n\n\n\n");
	while(!kbhit());
	getch();
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t�������Թ���С(����Ϊ5������Ϊ30)\n\n\tС��5��Ĭ���Թ���СΪ5��5������30��Ĭ���Թ���СΪ30��30\n\n\t���»س�ȷ��\n\n\t");
	scanf("%d",&n);
	if(n<5){
		n=5;
	}
	if(n>30){
		n=30;
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n");
	printf("\t�������Ѷȵȼ�(����Ϊ1������Ϊ3)\n\n\tС��1��Ĭ��Ϊ�Ѷ�1������3��Ĭ��Ϊ�Ѷ�3\n\n\t���»س�ȷ��\n\n\t");
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
	printf("\t���������ʼ��Ϸ���Թ���С��%d��%d �Ѷȵȼ���%d\n\n\t",n,n,m);
	while(!kbhit());
	getch();
	system("cls");
	
	//��������Թ���ͼ 
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
	while(x<=n&&y<=n){//�ȹ���һ�������ϵ����µ�ͨ· 
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
	//������ɿո����� 
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
	//�����Ѷ����ɲ������� 
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
	while(space_sum<lim){//��������ھ� 
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
	
	//�������Ӳ�� 
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
	
	//�����������յ� 
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
		//��������ƣ��Ӽ��̽��ж��� 
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
		if(nowx==aimx && nowy==aimy){//�жϵ����յ� 
			if(step-1>steplim){
				lose();
			}
			//������յ÷���� 
			system("cls");
			printf("\n\n\n\n\n\n\n\n");
			printf("\t\tYou Win!\n\n");
			printf("\t\t������%d���߳��Թ�\n\n\t\t��õ���%d�����\n\n\t\t��ĵ÷���%d����ϲ�㣡\n",step-1,coin,(steplim-step+1+coin*5+Abs(px[id]-px[id2])+Abs(px[id]+px[id2]))*100*xishu[m]*n/5);
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
	printf("\t�������ƣ�%d\t��Ľ������%d\t��Ĳ�����%d\n",steplim,coin,step++);
}
