class Clock
{
    private:
        int h, m, s;
    public:
        void set_time(int h, int m, int s=0);
        void disp_time();
};

class Alarm_clock:public Clock
{
    private:
        int alarm_h, alarm_m, alarm_s;
    public:
        void set_alarm(int h, int m, int s=0);
        void check_alarm();
        void stop_alarm();
        void clear_alarm();
};