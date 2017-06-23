#include "employee.h"
class Sales : public Employee {
    public:
        Sales(char* salesName, int salesLevel);
        virtual ~Sales();
        void setSaleCount(int Count);
        virtual int getSalary();
    protected:
    private:
        int saleCount;
};
