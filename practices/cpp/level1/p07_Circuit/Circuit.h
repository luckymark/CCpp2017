#ifndef CIRCUIT_H_
#define CIRCUIT_H_
#include <iostream>
#include <string>
#include <cstring>
using namespace std;


class Edge{
	protected:
		string name;
		int state;
	private:
		int from,to,next;
	public:
		Edge(int from = 0, int to = 0, int next = 0, int state = 0, string name = ""):
			from(from),to(to),next(next),state(state),name(name){}
		virtual void show(){}
		int get_state(){return state;}
		int get_next(){return next;}
		int get_to(){ return to; }
		virtual void set_state(int x){ state = x; }
		void change_state(){ state ^= 1; }
		virtual int is_switch(){return 0;}
		virtual int is_power(){return 0;}
		virtual ~Edge(){}
};

class Light:public Edge{
	public:
		Light(int from, int to, int next, int state, string name):
			Edge(from,to,next,state,name){}
		virtual void show();
		virtual ~Light(){}
};


class Fan:public Edge{
	public:
		Fan(int from, int to, int next, int state, string name):
			Edge(from,to,next,state,name){}
		virtual void show();
		virtual ~Fan(){}
};

class Switch:public Edge{
	public:
		Switch(int from, int to, int next, int state, string name):
			Edge(from,to,next,state,name){}
		virtual void show();
		virtual int is_switch();
		virtual ~Switch(){}
};

class Power:public Edge{
	public:
		Power(int from, int to, int next, int state, string name):
			Edge(from,to,next,state,name){}
		virtual void show();
		virtual int is_power();
		virtual void set_state(){};
		virtual ~Power(){}
};

class Circuit{
	private:
		Edge *data[10005];
		int head[1005];
		int tot;
		int power_flag;
		int s,t;
		int vis[1005];
		int flag[1005];
		int dfs(int x,int fa);
		void update_state();
	public:
		Circuit(){
			memset(data,0,sizeof(data));
			memset(head,-1,sizeof(head));
			tot = 0;
			power_flag = 0;
		}
		void change_switch(int x);
		void insert_power(int from, int to, string name);
		void insert_light(int from, int to, string name);
		void insert_fan(int from, int to, string name);
		void insert_switch(int from, int to, string name);
		void show();
		void show(int x);
		~Circuit();
};


#endif
