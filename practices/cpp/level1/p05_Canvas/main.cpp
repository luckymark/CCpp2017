#include "Canvas.h"
#include <stdlib.h>


int main()
{
	Canvas canvas;
	Shape  s[quantity];
	struct Shape* pshape = new struct Shape[quantity];
	while (true)
	{
		canvas.Add(s);
		cout << "Input 'D' to draw all the shapes.Input any other thing to continue." << endl;
		char input;
		cin >> input;
		if (input == 'D')
		{	
			canvas.Draw(s);
		}
	}
}