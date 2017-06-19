#include <iostream>
#include "SafeArray.h"
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	SafeArray S;
	S[2] = 2;
	for(int i = 0; i<5; i++){
		cout<<S[i]<<endl;
	}
	return 0;
}
