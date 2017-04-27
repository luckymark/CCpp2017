class Fan: public Switch{
	private:
		bool rotating;
	public:
		Fan();
		virtual void TurnOn();
		virtual void TurnOff();
};
