#ifndef CELL_H
#define CELL_H


class Cell
{
	public:
		Cell()
		{
			isPassable = 0;
		}
		virtual void turnon()=0;
		virtual void turnoff()=0;
		bool isSwitch;
    protected:
        bool isPassable;
};

class Switch : public Cell
{
    public:
        Switch();
        void turnon();
        void turnoff();
};


class Fan : public Cell
{
    public:
        Fan();
        void turnon();
        void turnoff();
        int getRotateSpeed();
	private:
        int rotateSpeed;
};

class Bulb : public Cell
{
	public:
		Bulb();
		void turnon();
		void turnoff();
		int getLight();
	private:
		int light;
};

#endif // CELL_H
