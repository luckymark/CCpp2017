#ifndef ARRAY_H
#define ARRAY_H
using std::cout;
template<class T>
class Array
{
	private:
		int max;
		T * data;
		T def;
	public:
		Array(int item=100);
		T & operator[](int n);
		void disp();
	protected:
};
template<class T>
Array<T>::Array(int item){
	T *p=new T[item];
	
	max=item;
	def=0;
	data=p;
	for(int i=0;i<max;i++){
		data[i]=0;
	}
}
template<class T>
T & Array<T>::operator[](int n){
	if(n>=max||n<=0){
		cout<<"Error\n";
		def=0;
		return def;
	}
	
	return data[n];
}
template<class T>
void Array<T>::disp(){
	for(int i=0;i<max;i++){
		cout<<data[i]<<'\t';
	} 
	cout<<'\n';
} 
#endif
