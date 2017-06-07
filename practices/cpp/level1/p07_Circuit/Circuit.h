#ifndef CIRCUIT_H
#define CIRCUIT_H
#include "Cell.h"
#include <vector>
using namespace std;

class Circuit
{
	public:
		void addCell(Cell* cell);
        void off();
        void on();
	private:
		vector<Cell*> Element;
};

#endif // CIRCUIT_H
