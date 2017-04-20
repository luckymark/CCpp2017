#ifndef CANVAS_H
#define CANVAS_H
#include <vector>
#include "Graphics.h"
#include <cstddef>
using namespace std;

class Canvas
{
	private:
		vector<Graphics* > container;
		
		static Canvas *instance;
		
		Canvas(){};
			
	public:
		static Canvas *getInstance()
		{
			if(instance == NULL)
			{
				instance = new Canvas();
			}
			return instance;
		}
		
		void draw(Graphics *element);
		
		void output();
};
#endif
