#include <iostream>
#include <cstdio>
#include <conio.h>
#include <time.h>
using namespace std;

void init(int *n, int map_index, int pos[2],int chest_pos[ ][2], int end[][2]){
	switch(map_index){//init box and end position 
		case 1:
			{
				*n = 4;//-----------------------------------------------------
				FILE * fp = fopen("map1_info.txt", "r");
				fscanf(fp, "%d %d\n", &pos[0], &pos[1]);
				for(int i=0; i<5; i++){
					fscanf(fp, "%d %d\n", &chest_pos[i][0], &chest_pos[i][1]);
					if(chest_pos[i][0]==0&&chest_pos[i][1]==0){
						break;
					}
				}
				for(int i=0; i<5; i++){
					fscanf(fp, "%d %d\n", &end[i][0], &end[i][1]);
					if(end[i][0]==0&&end[i][1]==0){
						break;
					}
				}
				fclose(fp);
			break;
			}
		case 2:
			{
				*n = 3;//-----------------------------------------------------
				FILE * fp = fopen("map2_info.txt", "r");
				fscanf(fp, "%d %d\n", &pos[0], &pos[1]);
				for(int i=0; i<5; i++){
					fscanf(fp, "%d %d\n", &chest_pos[i][0], &chest_pos[i][1]);
					if(chest_pos[i][0]==0&&chest_pos[i][1]==0){
						break;
					}
				}
				for(int i=0; i<5; i++){
					fscanf(fp, "%d %d\n", &end[i][0], &end[i][1]);
					if(end[i][0]==0&&end[i][1]==0){
						break;
					}
				}
				fclose(fp);
			break;
			}
		case 3:
			{
				*n = 4;//-----------------------------------------------------
				FILE * fp = fopen("map3_info.txt", "r");
				fscanf(fp, "%d %d\n", &pos[0], &pos[1]);
				for(int i=0; i<5; i++){
					fscanf(fp, "%d %d\n", &chest_pos[i][0], &chest_pos[i][1]);
					if(chest_pos[i][0]==0&&chest_pos[i][1]==0){
						break;
					}
				}
				for(int i=0; i<5; i++){
					fscanf(fp, "%d %d\n", &end[i][0], &end[i][1]);
					if(end[i][0]==0&&end[i][1]==0){
						break;
					}
				}
				fclose(fp);
			break;
			}
		default://----------------------------------------------------------------
			break;
	}
}

void GetMap(int map_index,char MAP[][11])
{
	char temp;
 	int index_x = 0, index_y = 0;
    FILE *fp;
	switch (map_index){
		case 1:
			fp=fopen("map1.txt","r");
			break;
		case 2:
			fp=fopen("map2.txt","r");
			break;
		case 3:
			fp=fopen("map3.txt","r");
			break;
		default:
			return;
	}
    char ch=fgetc(fp); 
    while(ch!=EOF) 
    {
		if(ch == 10){
			index_x += 1;
			index_y = 0;
		}
		else{
			MAP[index_x][index_y] = ch;
        	index_y += 1;
		}
        ch = fgetc(fp); 
	} 
	fclose(fp); 
	return;
}

int main()
{
	int step = 0; 
	int map_index = 1;
	int n = 0;
	int flag = 0;
	int pos[2] ={0};
	int chest_pos[5][2] = {0};
	int end[5][2]={0};
	char map[11][11] = {'\0'};
//	switch(getche()){
//		case '1':
//			{
//				map_index = 1;
//				init(&n, map_index, pos, chest_pos, end);
//				break;
//			}	
//		case '2':
//			{
//				map_index = 2;
//				init(&n, map_index, pos, chest_pos, end);
//				break;
//			}	
//		case '3':
//			{
//				map_index = 3;
//				init(&n, map_index, pos, chest_pos, end);
//				break;
//		    }
//		default:
//			cout<<"Please input 1-3"<<endl;
//			return 0;
//			break;
//	}
	while(map_index < 4){
		if(map_index == 1||map_index == 3){
			n = 4;
		}
		else {
			n = 3;
		}
		init(&n, map_index, pos, chest_pos, end); 
		GetMap(map_index, map);	
		while(1){
		
			system("cls");	//clear
			for(int i=0; i<n; i++){
				if(map[end[i][0]][end[i][1]]==' '){
				map[end[i][0]][end[i][1]]='X';
				}
			}
			
			for(int i=0; i<10; i++){//Draw Map
				for(int k=0; k<10; k++){
					switch (map[i][k]){
						case '#':
							cout<<"■";
							break;
						case 'X':
							cout<<"○";
							break;
						case '@':
							cout<<"★";
							break;
						case '*':
							cout<<"●";
							break;
						case ' ':
							cout<<"  ";
							break;
						default :
							break;
					}
				}
				cout<<endl;
			}
			printf("你当前所用步数为:%d\n", step);
			for(int k=0; k<n; k++){
				for(int i=0; i<n; i++){
					if(end[i][0]==chest_pos[k][0]){
						if(end[i][1]==chest_pos[k][1]){
							flag+=1;						
						}
					}
				}
			}	
			if(flag==n){//congradulation!
				system("cls");
				if(map_index < 4) cout<<"READY FOR NEXT MAP"<<endl;
				system("pause");
				flag = 0;
				map_index += 1;
				break;
			}
			else{
				flag=0;
			}
			switch(getche()){
				case 224:
					switch(getche()){//gaming ------------------------------------- 
						case 80:
							if(map[pos[0]+1][pos[1]]=='#'){
							}
							else if(map[pos[0]+1][pos[1]]=='*'&&map[pos[0]+2][pos[1]]=='#'){
							}
							else if(map[pos[0]+1][pos[1]]=='*'&&map[pos[0]+2][pos[1]]=='*'){
							}
							else if(map[pos[0]+1][pos[1]]=='*'){
								map[pos[0]][pos[1]]=' ';
								map[pos[0]+1][pos[1]]='@';
								map[pos[0]+2][pos[1]]='*';
								for(int i=0; i<n; i++){
									if((pos[0]+1)==chest_pos[i][0]){
										if((pos[1]==chest_pos[i][1])){
											chest_pos[i][0]=pos[0]+2;
											chest_pos[i][1]=pos[1];
											break;
										}
									}
								}
								pos[0]+=1;
								step+=1;
							}
							else{
								map[pos[0]][pos[1]]=' ';
								map[pos[0]+1][pos[1]]='@';
								pos[0]+=1;
								step+=1;
							}
							break;
						case 77:
							if(map[pos[0]][pos[1]+1]=='#'){
							}
							else if(map[pos[0]][pos[1]+1]=='*'&&map[pos[0]][pos[1]+2]=='#'){
							}
							else if(map[pos[0]][pos[1]+1]=='*'&&map[pos[0]][pos[1]+2]=='*'){
							}
							else if(map[pos[0]][pos[1]+1]=='*'){
								map[pos[0]][pos[1]]=' ';
								map[pos[0]][pos[1]+1]='@';
								map[pos[0]][pos[1]+2]='*';
								for(int i=0; i<n; i++){
									if((pos[0])==chest_pos[i][0]){
										if((pos[1]+1==chest_pos[i][1])){
											chest_pos[i][0]=pos[0];
											chest_pos[i][1]=pos[1]+2;
											break;
										}
										
									}
								}
								pos[1]+=1;
								step+=1;
							}
							else{
								map[pos[0]][pos[1]]=' ';
								map[pos[0]][pos[1]+1]='@';
								pos[1]+=1;
								step+=1;
							}
							break;
						case 72:if(map[pos[0]-1][pos[1]]=='#'){
							}
							else if(map[pos[0]-1][pos[1]]=='*'&&map[pos[0]-2][pos[1]]=='#'){
							}
							else if(map[pos[0]-1][pos[1]]=='*'&&map[pos[0]-2][pos[1]]=='*'){
							}
							else if(map[pos[0]-1][pos[1]]=='*'){
								map[pos[0]][pos[1]]=' ';
								map[pos[0]-1][pos[1]]='@';
								map[pos[0]-2][pos[1]]='*';
								for(int i=0; i<n; i++){
									if((pos[0]-1)==chest_pos[i][0]){
										if((pos[1]==chest_pos[i][1])){
											chest_pos[i][0]=pos[0]-2;
											chest_pos[i][1]=pos[1];
											cout<<chest_pos[i][0]<<' '<<chest_pos[i][1]<<endl;
											break;
										}
									}
								}
								pos[0]-=1;
								step+=1;
							}
							else{
								map[pos[0]][pos[1]]=' ';
								map[pos[0]-1][pos[1]]='@';
								pos[0]-=1;
								step+=1;
							}
							break;
						case 75:
							if(map[pos[0]][pos[1]-1]=='#'){
							}
							else if(map[pos[0]][pos[1]-1]=='*'&&map[pos[0]][pos[1]-2]=='#'){
							}
							else if(map[pos[0]][pos[1]-1]=='*'&&map[pos[0]][pos[1]-2]=='*'){
							}
							else if(map[pos[0]][pos[1]-1]=='*'){
								map[pos[0]][pos[1]]=' ';
								map[pos[0]][pos[1]-1]='@';
								map[pos[0]][pos[1]-2]='*';
								for(int i=0; i<n; i++){
									if((pos[0])==chest_pos[i][0]){
										if((pos[1]-1==chest_pos[i][1])){
											chest_pos[i][0]=pos[0];
											chest_pos[i][1]=pos[1]-2;
											cout<<chest_pos[i][0]<<' '<<chest_pos[i][1]<<endl;
											break;
										}
										
									}
								}
								pos[1]-=1;
								step+=1;
							}
							else{
								map[pos[0]][pos[1]]=' ';
								map[pos[0]][pos[1]-1]='@';
								pos[1]-=1;
								step+=1;
							}
							break;//--------------------------------------------------
						default: 
							break;
					}
					break;
				case ' ':
					system("cls");
					cout<<"GAME OVER!"<<endl;
					return 0;
				default:
			    	break;
			}
		}
	}
	cout<<"恭喜你完成了全部关卡！"<<endl; 
	cout<<"你最终所用步数为"<<step<<endl;
	time_t t;
	t=time(NULL);
	char *time;
	time = ctime(&t);
	FILE * fp;
	fp = fopen("Step_rec.txt", "a");
	fprintf(fp, "\n%s	所用步数：%d", time,step);
	fclose(fp);
	return 0;
}
