#include <iostream>
using namespace std;
int main(){
		int n; cin >> n;
		cout << ( ( n % 4 == 0 && n % 100 != 0) || (n % 400 == 0) ? "YES" : "NO") << endl;
		return 0;
}
///算法来自百度
