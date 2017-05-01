class SafeArray{
	private:
		int totalLength;
		int *data;	
	
	public:
		SafeArray();
		~SafeArray();
		void create(int length);
		bool write(int index,int number);
		int read(int index);
};
