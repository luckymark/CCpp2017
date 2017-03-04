#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
using namespace std;
string ans1[3] = {"正数","负数","0"};
string ans2[2] = {"奇数","偶数"};
string ans[2];
int sgn(int n){
		if(n == 0) return 2;
		return n > 0 ? 0 : 1;
}
int main(){
		int n; cin >> n;
		ans[0] = ans1[sgn(n)];
		ans[1] = n % 2 ? ans2[0] : ans2[1];
		cout << ans[0] << " " << ans[1] << endl;
		return 0;
}
