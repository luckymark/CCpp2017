#include <iostream>
#include <cstring>
#include <cstdio>
#include <numeric>
#include <chrono>
#define maxn 2005
using namespace std;
int prime[maxn];
int not_prime[maxn];
int cnt_prime;
void get_prime(){
		for(int i = 2; i <= 2000; i++){
				if(!not_prime[i]) prime[++cnt_prime] = i;
				for(int j = 1; j <= cnt_prime; j++){
						if(i * prime[j] > 2000) break;
						not_prime[i * prime[j]] = 1;
						if(i % prime[j]) break;
				}
		}
}
void work(){
		get_prime();
		for(int i = 1; i <= cnt_prime; i++){
				cout << prime[i] << " ";
		}
		cout << endl;
}
int main(){
		auto start = std::chrono::system_clock::now();

		work();

		auto end = std::chrono::system_clock::now();
		std::chrono::duration<double> diff = end-start;
		std::cout << "Total Time: "<< diff.count() << " s\n";
		return 0;
}
