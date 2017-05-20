#include <iostream>
#include <thread>
using namespace std;
void print(){
	cerr << "this is the foo thread" << endl;
}
int main(){
	thread t(print);
	t.join();
	cerr << "this is the main thread" << endl;
	return 0;
}
