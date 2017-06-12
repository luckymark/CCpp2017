#ifndef SAFEARRAY_H
#define SAFEARRAY_H

class SafeArray
{
	public:
		SafeArray(int);
		~SafeArray();
		void write(int,int);
		int read(int);
	protected:
		int *data;
		int Max;
};

#endif
