#include "Circuit.h"
using namespace std;

void Circuit::addCell(Cell* cell)
{
	Element.push_back(cell);
}

void Circuit::on()
{
	for(unsigned i=0;i != Element.size();i++)
	{
			Element[i]->turnon();
	}
}

void Circuit::off()
{
	for(unsigned i=0;i != Element.size();i++)
	{
			Element[i]->turnoff();
	}
}


