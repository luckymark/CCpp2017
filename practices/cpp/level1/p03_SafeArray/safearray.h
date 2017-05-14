#ifndef SAFEARRAY_H_
#define SAFEARRAY_H_

using namespace std;

class safearray
{
	public:
		safearray();
		safearray(int size);
		~safearray();
		int& operator[] (int i);
		friend ostream& operator<<(ostream &output, safearray &s);
	private:
		int size;
		int *data;
};

#endif
