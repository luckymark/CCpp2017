#ifndef CIRCUIT_H
#define CIRCUIT_H

class Circuit
{
	public:
		Circuit();
		void add(Device *device);
		void on();
		void off();
	protected:
		Device *device[100];
		int num;
		bool status;
};

#endif
