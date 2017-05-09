#include <cstdio>
#include "Stack.h"
using namespace std;

int main()
{
	Stack<int> st(100);
	
	int op;/*
	op==0 pop;
	op==1 push;
	op==2 isEmpty;
	op==3 isFull;
	op==4 clear;
	*/
	
	int n;/*
	sum of operations
	*/
	
	int x;
	
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&op);
		if(op==0){
			if(st.isEmpty()){
				puts("The Stack is Empty.");
			}
			else{
				printf("%d\n",st.pop());
			}
		}
		else if(op==1){
			scanf("%d",&x);
			bool flag=st.push(x);
			if(!flag){
				puts("The Stack is Full.");
			}
		}
		else if(op==2){
			if(st.isEmpty()){
				puts("The Stack is Empty.");
			}
			else{
				puts("The Stack is not Empty.");
			}
		}
		else if(op==3){
			if(st.isFull()){
				puts("The Stack is Full.");
			}
			else{
				puts("The Stack is not Full.");
			}
		}
		else{
			st.clear();
		}
	}
	return 0;
}
