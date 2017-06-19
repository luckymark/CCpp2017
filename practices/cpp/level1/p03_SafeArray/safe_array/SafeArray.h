#ifndef CL_SAFEARRAY_H
#define CL_SAFEARRAY_H

class SafeArray
{
    private:
        int len;
    public:
        SafeArray(int l)
        {
            len=l;
        }
        ~SafeArray()
        {
            delete p;
        }
        int* p=new int[len];
        void value(int index,int value)
        {
            if(index>=len)
            {
                std::cout<<"index out of range"<<std::endl;
                return;
            }
            p[index]=value;
        }
        int get(int index)
        {
            if(index>=len)
            {
                std::cout<<"index out of range"<<std::endl;
                return 0;
            }
            return p[index];
        }
};


#endif //CL_SAFEARRAY_H
