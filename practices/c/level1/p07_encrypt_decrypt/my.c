/* useage */
/* whe you use encrypt, the program will return you a seed, and you should use the seed to decrypt the code */
/* example:
   	$./my.cpp.out encrypt abcde
	WXYZ[ 10
	$./my.cpp.out decrypt WXYZ[ 10
	abcde
*/
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
void en(char s[]){
		int len = strlen(s);
		int now = rand() % 30;
		for(int i = 0; i < len; i++){
				//cout << (char)(s[i] - now);
				printf("%c", (char) (s[i] - now));
		}
		//cout << " " << now << endl;
		printf(" %d%d\n", now/10,now%10);
		//cout << endl;
}
void de(char s[],char ti[]){
		int len = strlen(s);
		int now = 10 * (ti[0] - '0') + ti[1] - '0';
		for(int i = 0; i < len; i++){
				//cout << (char)(s[i] + now);
				printf("%c", (char) (s[i] + now) );
		}
		//cout << endl;
		printf("\n");
}
int main(int argc,char *argv[]){
		srand(time(NULL));
		if(argv[1][0] == 'e') 
				en(argv[2]);
		else 
				de(argv[2],argv[3]);
		return 0;
}
