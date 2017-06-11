#ifndef GRAPH_H
#define GRAPH_H
#include <vector>

class Edge{
private:
    int pre,start,ed;
public:
    int get_pre();

    int get_start();

    int get_ed();

    void set_pre(int In_pre);

    void set_start(int In_start);

    void set_ed(int In_ed);
};

class Point{
private:
    int now,value,fa;
    int son_total;
public:
    Point(int In_value,int In_fa);

    int get_now();

    int get_value();

    int get_fa();

    int get_son_total();

    void set_now(int In_now);

    void set_value(int In_vlaue);

    void set_fa(int In_fa);

    void inc_son_total();
};

class Graph{
private:
    std::vector<Edge> edge;
    std::vector<Point> point;
public:
    void build(int In_start,int In_ed);

    void creat(int In_value,int In_fa);

    int get_fa(int In_num);

    int get_son_total(int In_num);

    int get_value(int In_num);

    int get_point_size();
};




#endif // GRAPH_H
