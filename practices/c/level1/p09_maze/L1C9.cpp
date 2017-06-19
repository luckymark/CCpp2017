# include<conio.h>
# include<iostream>
# include<cstdio>
using namespace std;
int main(){
	int pos[2]{11, 0};
	int end[2]{2, 40};
	int row = 21, line = 42;
	char map[21][42]={
	"*****************************************",
	"*   *         *             *       *   *",
	"* *** ******* *** *** ***** * *** *** * X",
	"*           *     * * * *   *   *   * * *",
	"*********** ******* * * * ***** * * *** *",
	"*   *     * *       *   *       * *     *",
	"* * * *** * * *** *************** *******",
	"* *     *   * * *     *     *   *       *",
	"* ********* * * ***** * *** * * *** *** *",
	"*       * *   *     * *   * * *   *   * *",
	"******* * *** *** * * *** * * *** *** ***",
	"O   * *   * * * * * * * * *     * *     *",
	"* * * ***** * * * * * * * ******* ***** *",
	"* *   * *     *   *     *       * *   * *",
	"* *** * * * ******************* *** * * *",
	"*   *   * * *       *       *   *   *   *",
	"* * ***** * ******* * ***** * * * ***** *",
	"* *       *         *     *   * * *     *",
	"* * ********* *********** ******* * *****",
	"* *         *           *         *     *",
	"*****************************************"};
	while(1){
		system("cls");
		for(int i=0; i<row; i++){
			for(int k=0; k<line; k++) 
				switch (map[i][k]){
					case '*':
						cout<<"¡ö";
						break;
					case 'O':
						cout<<"¡ð";
						break;
					case ' ':
						cout<<"  ";
						break;
					case 'X':
						cout<<"->";
					default:
						break;
				}
			cout<<endl;
		}
		if(pos[0]==end[0]&&pos[1]==end[1]){
			cout<<"YOU'VE OUT THIS MIGONG"<<endl;
			break;
		}
		switch(getche()){
			case 224:
				switch(getche()){
					case 80:
						if(map[pos[0]+1][pos[1]]!='*'){
							map[pos[0]][pos[1]]=' ';
							map[pos[0]+1][pos[1]]='O';
							pos[0]+=1;
						}
						break;
					case 77:
						if(map[pos[0]][pos[1]+1]!='*'){
							map[pos[0]][pos[1]]=' ';
							map[pos[0]][pos[1]+1]='O';
							pos[1]+=1;
						} 
						break;
					case 72:
						if(map[pos[0]-1][pos[1]]!='*'){
							map[pos[0]][pos[1]]=' ';
							map[pos[0]-1][pos[1]]='O';
							pos[0]-=1;
						} 
						break;
					case 75:
						if(map[pos[0]][pos[1]-1]!='*'){
							map[pos[0]][pos[1]]=' ';
							map[pos[0]][pos[1]-1]='O';
							pos[1]-=1;
						} 
						break;
					default: 
						break;
				} 
				break;
			default:
				break;
		}
	}
	return 0;
}
