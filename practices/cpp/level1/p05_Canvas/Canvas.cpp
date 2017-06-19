#include "Canvas.h"
#include <iostream>

void Canvas::Add(struct Shape s[quantity])
{
	cout << "Please enter the name of the shape you want to add:" << endl;
	cin >> s[Count].name;
	cout << "Please enter the size of it:" << endl;
	cin >> s[Count].characters;
	Count += 1;

}

void Canvas::Draw(struct Shape s[quantity])
{
	for (int i = 0; i < Count; ++i)
	{
		cout << s[i].name << endl;
		cout << s[i].characters << endl;
	}
}
