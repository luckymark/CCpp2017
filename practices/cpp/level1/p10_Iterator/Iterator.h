#pragma once
class Iterator
{
	
	private:
		int *origin;
		int *current;
	public:
		Iterator();
		Iterator(int*,int*);
		Iterator& operator=(Iterator);
		bool operator==(Iterator);
		bool operator!=(Iterator);
		Iterator& operator++();
		int operator*();
};