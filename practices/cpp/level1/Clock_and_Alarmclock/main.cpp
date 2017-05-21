#include <iostream>
#include "AClock.h"
using namespace std;
int main(){
	Alarmclock my_clock;
	my_clock.set_alarm(10,5);
	while(1){
		if(my_clock.check_alarm()){
			cout << "time is up" << endl;
			getchar();
			my_clock.stop_alarm();
		}
	}
	my_clock.clean_alarm();
	return 0;
}
