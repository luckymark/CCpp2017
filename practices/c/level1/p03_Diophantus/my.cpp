#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
		for(int i = 0; i <= 200; i+=7*12){
				if(2 * ( (i - 4) - (i / 7 + i / 6 + i / 12 + 5)) == i){
						cout << i - 4 << endl;
				}
		}
		return 0;
}
