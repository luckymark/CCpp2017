//this program will print the solution of hanoi of n discs 
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
void dfs(int num,int a,int b,int c){
		if(num == 1){
				cout << a << " -> " << c << endl;
				return;
		}
		dfs(num-1,a,c,b);
		dfs(1,a,b,c);
		dfs(num-1,b,a,c);
}
int main(){
		int n; cin >> n;
		dfs(n,1,2,3);
		return 0;
}
