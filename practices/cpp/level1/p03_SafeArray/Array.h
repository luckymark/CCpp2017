#ifndef ARRAY_H
#define ARRAY_H
class Array
{
	private:
		int max;
		int * data;
	public:
		Array(int item=100);
		int & operator[](int n);
		void disp();
	protected:
};

#endif
