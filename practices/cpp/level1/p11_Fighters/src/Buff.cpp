#include "Buff.h"

Buff::Buff(){
	memset(w,0,sizeof(w));
	clock.restart();
	duration_time = 0;
}
Buff::Buff(int key, int val, float duration_time_){
	w[key] = val;
	duration_time = duration_time_;
}
