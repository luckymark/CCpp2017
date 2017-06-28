#ifndef CIRCUIT_H_
#define CIRCUIT_H_

class Unit;

class Circuit
{
public:
	Unit* pt[20];
	void show();
	void AddUnit(int unit,int slot);
	Circuit() { count = 0; }
private:
	int count;
	
};

class Unit
{
private:
	bool Switch;
	int slot;
public:
	virtual void show() = 0;
	virtual void ChangeType(int type) = 0;
	void TurnSwitch(bool isOn);
	int isON();
	Unit(int slot) { this->slot = slot; this->Switch = 0; }
};

class Light:public Unit
{
public:
	Light(int type,int slot):Unit(slot)
	{
		this->type = type;
	}
	void show();
	void ChangeType(int n);
private:
	int type;
};

class Motor:public Unit
{
public:
	void show();
	void ChangeType(int n);
	Motor(int type,int slot):Unit(slot) { this->type = type; }
private:
	int type;
};

#endif
