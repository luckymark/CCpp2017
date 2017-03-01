//#include <cstring>
#include <cstdio>
#include <sys/time.h>
//#include <numeric>
//#include <chrono>
#define maxn 2005
//using namespace std;
int prime[maxn];
int not_prime[maxn];
int cnt_prime;
void get_prime(){
		for(int i = 2; i <= 2000; i++){
				if(!not_prime[i]) prime[++cnt_prime] = i;
				for(int j = 1; j <= cnt_prime; j++){
						if(i * prime[j] > 2000) break;
						not_prime[i * prime[j]] = 1;
						if(i % prime[j] == 0) break;
				}
		}
}
void work(){
		get_prime();
		for(int i = 1; i <= cnt_prime; i++){
				printf("%d ",prime[i]);
		}
		printf("\n");
}
int main(){
		struct timeval start, end;
		gettimeofday( &start, NULL );

		work();

		gettimeofday( &end, NULL );
		float timeuse = 1e6 * (end.tv_sec - start.tv_sec) + end.tv_usec - start.tv_usec;
		timeuse *= 1e-6;
		printf("Total time: %f\n", timeuse);
		return 0;

}
