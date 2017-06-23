
class SafeArray 
{

	private:
		int *data;
		int capbility;
	public:		
		SafeArray(int cap);
		~SafeArray();
		int& operator[] (int n);
};
