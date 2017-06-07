#ifndef SAFEARRAY_H
#define SAFEARRAY_H

class SafeArray
{
	public:
		SafeArray(int number):k(number)
		{
			array = new int[k];
		}	
		
		void put(int number,int value);
		int get(int number);
			
	protected:
		int k;
		int *array;
		
};

#endif
