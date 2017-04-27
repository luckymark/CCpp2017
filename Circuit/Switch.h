class Switch{
	protected:
		bool on;
	public:
		Switch();
		virtual void TurnOn();
		virtual void TurnOff();
		bool is_on();
};
