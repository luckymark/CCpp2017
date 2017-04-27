class Circuit{
	private:
		Switch** switches;
		int capability,End;
	public:
		Circuit(int capability);
		~Circuit();
		void insert(Switch* sw);
		void test();
};
