#include <string.h>
#include <stdio.h>
#define maxn 105
int prime[maxn];
int not_prime[maxn];
int cnt_prime;
void get_prime(){
		for(int i = 2; i <= 100; i++){
				if(!not_prime[i]) prime[++cnt_prime] = i;
				for(int j = 1; j <= cnt_prime; j++){
						if(i * prime[j] > 100) break;
						not_prime[i * prime[j]] = 1;
						if(i % prime[j] == 0) break;
				}
		}
}
int main(){
		get_prime();
		int flag = 1;
		for(int i = 4; i <= 100; i += 2){
				int cur = 0;
				for(int j = 2; j <= i-2; j++) if(!not_prime[j] && !not_prime[i-j]){
						//cout << j << " " << i-j << endl;
						//printf("%d %d",i,i-j);
						cur = 1; break;
				}
				if(cur == 0){
						flag = 0; break;
				}
		}
		printf("%s\n", (flag == 1 ? "right" : "wrong") );
		return 0;
}
