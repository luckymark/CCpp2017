#include<iostream>
#include<vector>
using namespace std;

class Device{
	public:
		virtual void setOn()=0;
		virtual void setOff()=0;
};

class Bulb:public Device{
	public:
		void setOn();
		void setOff();
};

class Fan:public Device{
	public:
		void setOn();
		void setOff();
};

class Switch{
	private:
		bool key;
	public:
		void setOn();
		void setOff();
		bool isConnected();
};

class Circult{
	private:
		vector<Device*> devicevector;
		vector<Switch*> switchvector;
		vector<Circult*> circuitvector;
	public:
		void addDevice(Device*);
		void addSwitch(Switch*);
		void addCircuit(Circult*);
		bool isConnected();
};
void Bulb::setOn(){
	cout<<"Bulb is on!."<<endl;
}

void Bulb::setOff(){
	cout<<"Bulb is off!."<<endl;
}

void Fan::setOn(){
	cout<<"Fan is on!."<<endl;
}

void Fan::setOff(){
	cout<<"Bulb is off!."<<endl;
}

void Switch::setOn(){
	this->key=true;
}

void Switch::setOff(){
	this->key=false;
}

bool Switch::isConnected(){
    return this->key;
}

void Circult::addDevice(Device* d){
	this->devicevector.push_back(d);
}
void Circult::addSwitch(Switch* s){
	this->switchvector.push_back(s);
}

void Circult::addCircuit(Circult* c){
	this->circuitvector.push_back(c);
}

bool Circult::isConnected(){
	for(auto it=switchvector.begin();it!=switchvector.end();it++){
		if((*it)->isConnected()==false){
			return false;
		}
	}
	for(auto it=circuitvector.begin();it!=circuitvector.end();it++){
		if((*it)->isConnected()==false){
			return false;
		}
	}
	return true;
}

int main(){
    Switch s1,s2;
    s1.setOn();
    s2.setOn();
    Bulb b;
    Fan f;
    Circult c1,c2,c3;
    //circuit setting
    c3.addDevice(&f);

    c2.addSwitch(&s2);
    c2.addDevice(&b);

    c1.addSwitch(&s1);
    c1.addCircuit(&c2);
    c1.addCircuit(&c3);

    std::cout<<c1.isConnected()<<std::endl;
	return 0;
}

