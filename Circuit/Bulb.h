class Bulb: public Switch{
	private:
		bool lighting;
	public:
		Bulb();
		virtual void TurnOn();
		virtual void TurnOff();
};
