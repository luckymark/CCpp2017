//
//  Rect.h
//  p05_Canvas02
//
//  Created by Jimmy Fan on 2017/4/27.
//  Copyright © 2017年 Jimmy Fan. All rights reserved.
//

#ifndef Rect_h
#define Rect_h

#include "Point.h"

class Rect: public Point{
private:
    int width,height;
public:
    Rect(int = 0, int = 0, int = 0, int = 0);
    double area();
    void show();
};

#endif /* Rect_h */
