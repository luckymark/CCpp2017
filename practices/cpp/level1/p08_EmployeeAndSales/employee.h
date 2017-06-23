class Employee
{
    public:
    	Employee(){	};
        Employee(char *employeeName, int employeeLevel);
        virtual ~Employee();
        virtual int getSalary();
        char* getName();
        int getLevel();
        void setLevel(int employeeLevel);
    protected:
    private:
        char* name = new char[32];
        int level = 0;
};
