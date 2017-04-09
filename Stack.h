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
