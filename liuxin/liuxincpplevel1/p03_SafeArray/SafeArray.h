class SafeArray{
private:
	int *element,tot;
public:
	SafeArray(int x=100);
	~SafeArray();	
	int& operator [](int x);
};
