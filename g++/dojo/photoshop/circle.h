#ifndef CIRCLE_H
#define CIRCLE_H
#include "shape.h"
#include <cmath>
int dist_squared(int p1, int p2)
{
    int dif = p1 - p2;
    return abs((dif*dif));
}
template <typename RENDERER>

class circle: public shape<RENDERER>
{
public:
    circle()
    :shape<RENDERER>{"circle"}
    {}
    ~circle()
    {}
    void  paint(RENDERER& p_paint) const 
    {
        auto height = shape<RENDERER>::get_height();
        auto width = shape<RENDERER>::get_width();
        auto X = shape<RENDERER>::get_x();
        auto Y = shape<RENDERER>::get_y();
        //calculate the centre of the circle
        int x, y;
        int length = width/2;
        float angle = 0.0;
        float angle_stepsize = 0.00001;

        // go through all angles from 0 to 2 * PI radians
        while (angle < 2 * 3.1415926)
        {
            // calculate x, y from a vector with known length and angle
            x = length * cos (angle)+X;
            y = length * sin (angle)+Y;
            p_paint.set_pixel (
                x + width / 2, y + height / 2);
            angle += angle_stepsize;
        }


    }





    
};


#endif