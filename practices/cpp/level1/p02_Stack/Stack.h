#ifndef STACK_H
#define STACK_H
using std::cout;
using std::endl;
template <class T>
class Stack
{
	private:
		T *data;
		int top;
		bool flag;
		int len;
	public:
		Stack(int item=100);
		bool isFull();
		bool isNull();
		void disp();
		void push(T item);
		void pop();
	protected:
};
template <class T>
Stack<T>::Stack(int item){
	len=item;
	top=0;
	flag=0;
	T *p=new T[item];
	data=p;
}
template <class T>
void Stack<T>::disp(){
	cout<<"top\n";
	if(flag){
		cout<<data[top]<<endl;
	}
	for(int i=top-1;i>=0;i--){
		cout<<data[i]<<endl;
	}
	cout<<"bottom\n";
}
template <class T>
void Stack<T>::push(T item){
	data[top]=item;
	if(top<len-1){
		++top;
	}
	else{
		flag=1;
	}
}
template <class T>
void Stack<T>::pop(){
	if(len-1==top&&flag){
		flag=0;
		data[top]=0;
		return;
	}
	data[top]=0;
	--top;
}
template <class T>
bool Stack<T>::isFull(){
	if(flag)return true;
	return false;
}
template <class T>
bool Stack<T>::isNull(){
	if(0==top)return true;
	return false;
}
#endif
