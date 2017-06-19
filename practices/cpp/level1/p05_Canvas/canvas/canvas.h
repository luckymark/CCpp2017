#ifndef CL_CAVAS_H
#define CL_CAVAS_H


class canvas
{
    private:
        shape* draw[10];
        bool p[10];
        int count;
    public:
        void add(circle &c)
        {
            draw[count]=&c;
            count++;
        }
        void add(rect &r)
        {
            draw[count]=&r;
            count++;
        }
        void show()
        {
            for(int i=0;i<count;i++)
            {
                cout<<i+1<<": ";
                draw[i]->show();
            }
        }
};


#endif //CL_CAVAS_H
