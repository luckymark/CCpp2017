#ifndef SAFEARRAY_H
#define SAFEARRAY_H


class SafeArray
{
    public:
        SafeArray(int number):k(number){safearray = new int[k];}
        void publish(int n);
        void init(int number,int value);
        void see(int n);

    private:
        int* safearray;
        int k;
};

#endif // SAFEARRAY_H
