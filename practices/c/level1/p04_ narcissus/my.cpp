#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int pow_3(int x){
		return x * x * x;
}
int main(){
		for(int i = 100; i <= 999; i++){
				int cur = pow_3( i % 10 ) + pow_3( (i/10) % 10 ) + pow_3( i / 100 );
				if(cur == i) 
						cout << i << endl;
		}
		return 0;
}
