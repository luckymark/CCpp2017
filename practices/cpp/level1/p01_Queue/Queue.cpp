# include<iostream>
using namespace std;

class Queue {
private:
	int data[100];
	int poptrail;
	int apptrail;
	int *p;
public:
	Queue();
	void append(int num);
	void pop();
	bool IsFull();
	bool IsEmpty();
	void showall();
	~Queue();
};

Queue::Queue()
{
	memset(data, 0, 100);
	poptrail = 0;
	apptrail = 0;
	p = data;
}
void Queue::append(int num)
{
	data[apptrail] = num;
	apptrail++;
}
void Queue::pop()
{
	p++;
	poptrail++;
}
bool Queue::IsFull()
{
	if (apptrail == 100) {
		return true;
	}
	return false;
}
bool Queue:: IsEmpty()
{
	if(poptrail==100||apptrail==0){
		return true;
	}
return false;
}

void Queue::showall()
{
	int poptra = poptrail;
	for (int i = poptra; i < 100;i++ ) {
		cout << data[poptra] << endl;
		poptra++;
	}
}
Queue::~Queue()
{

}


int main()
{
	int i = 1;
	Queue queue;
	if (queue.IsEmpty()) {
		for (i = 1; i <= 100; i++) {
			queue.append(i);
		}
	}
	if (queue.IsFull()) {
		queue.showall();
		cout << endl;
	}
	for (i = 1; i <= 100; i++) {
		queue.pop();
		if (queue.IsEmpty()) {
			cout << "the queue pop successfully" << endl;
		}
	}
	system("pause");
	return 0;
}
