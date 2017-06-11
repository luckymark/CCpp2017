#include "graph.h"

#include <cstdio>
#include <vector>

    int Edge::get_pre(){
        return pre;
    }
    int Edge::get_start(){
        return start;
    }
    int Edge::get_ed(){
        return ed;
    }

    void Edge::set_pre(int In_pre){
        pre=In_pre;
    }

    void Edge::set_start(int In_start){
        start=In_start;
    }

    void Edge::set_ed(int In_ed){
        ed=In_ed;
    }



    Point::Point(int In_value,int In_fa){
        now=0;
        value=In_value;
        printf("v=====%d\n",value);
        fa=In_fa;
        son_total=0;
    }

    int Point::get_now(){
        return now;
    }
    int Point::get_value(){
        return value;
    }
    int Point::get_fa(){
        return fa;
    }

    int Point::get_son_total(){
        return son_total;
    }

    void Point::set_now(int In_now){
        now=In_now;
    }

    void Point::set_value(int In_value){
        value=In_value;
    }

    void Point::set_fa(int In_fa){
        fa=In_fa;
    }

    void Point::inc_son_total(){
        son_total++;
    }

    void Graph::build(int In_start,int In_ed){
        Edge Tmp;
        Tmp.set_pre(point[In_start].get_now());
        point[In_start].set_now(edge.size());
        Tmp.set_start(In_start);
        Tmp.set_ed(In_ed);
        edge.push_back(Tmp);
    }

    void Graph::creat(int In_value,int In_fa){
        Point Tmp=Point(In_value,In_fa);
        if(In_fa==-1)
        {
            point.push_back(Tmp);
            return;
        }
        puts("=========");
        build(In_fa,point.size()-1);
        int tmp_num=In_fa;
        for (;;)
            {
                point[tmp_num].inc_son_total();
                if (point[tmp_num].get_fa()==-1)
                    break;
                tmp_num=point[tmp_num].get_fa();
            }
        point.push_back(Tmp);
    }


    int Graph::get_fa(int In_num){
        return point[In_num].get_fa();
    }

    int Graph::get_son_total(int In_num){
        return point[In_num].get_son_total();
    }

    int Graph::get_value(int In_num){
        return point[In_num].get_value();
    }

    int Graph::get_point_size(){
        return point.size();
    }
