#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
struct Queue{
		int w[105];
		int l,r;
		int len;
		Queue(){
				l = r = 0;
				len = 0;
				memset(w,0,sizeof(w));
		}
		void append(int x){
				w[r] = x;
				r++; r %= 100;
				len++;
		}
		void pop(){
				l++; l %= 100;
				len--;
		}
		bool empty(){
				return len == 0;
		}
		bool full(){
				return len == 100;
		}
}q;
int main(){
		q.append(1);
		q.append(2);
		q.pop();
		q.empty();
		q.pop();
		q.empty();
		return 0;

}
