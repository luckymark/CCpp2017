#ifndef QUEUE_H
#define QUEUE_H
class Queue {
public:
	Queue() {
		for (int i = 0;i < 100;++i) {
			data[i] = 0;
		}
	}
	void disp(void);
	void append(int num);
	int pop(void);
	bool isEmpty(void);
	bool isFull(void);
private:
	int data[100];
	int head = 0;
	int tail = 0;
protected:
};
#endif
