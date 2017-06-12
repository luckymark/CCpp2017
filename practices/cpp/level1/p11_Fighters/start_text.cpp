#include "start_text.h"

StartText::StartText()
{
	a[0].setmark(4, "  state");
	a[1].setmark(5, "  newer");
	a[2].setmark(6, "");
}

sf::Text StartText::draw(int i)
{
	return (a[i].draw());
}

void StartText::change(int i, int j)
{
	using namespace std;
	if (j == 0) {
		if (i == 0) {
			a[0].setmark(4, "state");
			a[1].setmark(5, "new");
			a[2].setmark(6, "");
		}
		else if(i==1){
			a[0].setmark(4, "state");
			a[1].setmark(5, "narmal");
			a[2].setmark(6, "");
		}
		else {
			a[0].setmark(4, "state");
			a[1].setmark(5, "hard");
			a[2].setmark(6, "");
		}
	}
	if (j == 1) {
		if (i == 0) {
			a[0].setmark(4, "time");
			a[1].setmark(5, "new");
			a[2].setmark(6, " ");
		}
		if (i == 1) {
			a[0].setmark(4, "time");
			a[1].setmark(5, "normal");
			a[2].setmark(6, " ");
		}
		if (i == 2) {
			a[0].setmark(4, "time ");
			a[1].setmark(5, "hard");
			a[2].setmark(6, " ");
		}
	}
}