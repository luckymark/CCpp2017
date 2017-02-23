#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
int main(){
		int n; cin >> n;
		int flag = 1;
		for(int i = 2; i*i <= n; i++)
				if(n % i == 0){
						flag = 0;
						break;
				}
		cout << (flag == 1 ? "YES" : "NO") << endl;
		return 0;
}
