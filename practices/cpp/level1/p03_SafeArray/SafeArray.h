#ifndef SAFE_ARRAY_H_INCLUDED

#define SAFE_ARRAY_H_INCLUDED
class SafeArray{
	private:
		int *w;
		int size;
	public:
		SafeArray();
		SafeArray(int _size);
		~SafeArray();
		int& operator [] (int idx);
};

#endif
