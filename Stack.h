#include<cstdio>
using namespace std;
class Stack
{
	private:
		int* s;
		int p,capability;
		
	public:
		Stack(int capability){
			p=0;
			this->capability=capability;
			if(capability){
				s=new int[capability];
			}
		}
		~Stack(){
			if(capability){
				delete[] s;
			}
		}
		int pop();
		bool push(int x);
		bool isEmpty();
		bool isFull();
		void clear();
};

int Stack::pop(){
	return s[--p];
}

bool Stack::push(int x){
	if(p<capability){
		s[p++]=x;
		return 1;
	}
	else{
		return 0;
	}
}

bool Stack::isEmpty(){
	return p==0;
}

bool Stack::isFull(){
	return p==capability;
}

void Stack::clear(){
	while(p){
		pop();
	}
}

