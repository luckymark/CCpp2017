#include "Circuit.h"

void Circuit::insert_power(int from,int to, string name){
	if(!power_flag){
		power_flag = 1;
		data[tot] = new Power(from, to, head[from], 1, name);
		head[from] = tot++;
		data[tot] = new Power(to, from, head[to], 0, name);
		head[to] = tot++;
		s = to; t = from;
	}
}

void Circuit::insert_light(int from,int to, string name){
	if(!power_flag) return;
	data[tot] = new Light(from, to, head[from], 0, name);
	head[from] = tot++;
	data[tot] = new Light(to, from, head[to], 0, name);
	head[to] = tot++;
}

void Circuit::insert_fan(int from,int to, string name){
	if(!power_flag) return;
	data[tot] = new Fan(from, to, head[from], 0, name);
	head[from] = tot++;
	data[tot] = new Fan(to, from, head[to], 0, name);
	head[to] = tot++;
}

void Circuit::insert_switch(int from,int to, string name){
	if(!power_flag) return;
	data[tot] = new Switch(from, to, head[from], 1, name);
	head[from] = tot++;
	data[tot] = new Switch(to, from, head[to], 1, name);
	head[to] = tot++;
}

int Circuit::dfs(int x,int fa){
	if(vis[x]) return flag[x];
	vis[x] = 1;
	if(x == t) {
		flag[x] = 1;
		return 1;
	}
	for(int k = head[x]; k != -1; k = data[k] -> get_next() ){
		int tmp = 0;
		if(data[k] -> is_switch() && !(data[k] -> get_state())){
			continue;
		}

		if(vis[data[k] -> get_to()]){
			tmp |= flag[data[k] -> get_to()];
		}else if(data[k] -> get_to() != fa){
			tmp |= dfs(data[k] -> get_to(), x);
		}

		if(!(data[k] -> is_switch())){
			if(tmp){
				data[k] -> set_state(1);
				data[k^1] -> set_state(1);
			}else{
				data[k] -> set_state(0);
				data[k^1] -> set_state(0);
			}
		}

		flag[x] |= tmp;
	}
	return flag[x];
}

void Circuit::update_state(){
	if(!power_flag) return;
	memset(vis,0,sizeof(vis));
	memset(flag,0,sizeof(flag));
	dfs(s,-1);
}

void Circuit::change_switch(int x){
	if(data[x*2-1] -> is_switch()){
		data[x*2-2] -> change_state();
		data[x*2-1] -> change_state();
		update_state();
	}
}

void Circuit::show(){
	update_state();
	for(int i = 0; i < tot; i+=2){
		data[i] -> show();
	}
}

void Circuit::show(int x){
	data[x] -> show();
}

Circuit::~Circuit(){
	for(int i = 0; i < tot; i++)
		delete data[i];
}
