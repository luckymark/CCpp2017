class SafeArray{
	private:
		int totalLength;
		int *data;	
	
	public:
		SafeArray();
		~SafeArray();
		bool sizeable(int length);
		bool write(int index,int number);
		int read(int index);
		int& operator [](int index);
};
