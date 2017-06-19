#pragma once
#include <iostream>
#include <vector>
using namespace std;



class Device
{
private:
	bool	judge;
public:
	void	ON();
	void	OFF();
	int		character;
};

class Circuit
{
private:
	vector< Device* >		Items;
public:
	Circuit() ;
	void				Add();
	void				Delete();
	void				Show();
	void				Menu();
};

class Bulb:public Device
{
private:
	int		Intence=100;
public:
	void	Show();
	Bulb() { character = 1; };
			~Bulb();
};

class Fan :public Device
{
private:
	int		Speed=100;
public:
	void	Show();
	Fan() { character = 2; };
			~Fan();
};