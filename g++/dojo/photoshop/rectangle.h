#ifndef RECTANGLE_H
#define RECTANGLE_H
#include "shape.h"
template <typename RENDERER>

class rectangle:public shape<RENDERER>
{
public:
    rectangle()
    :shape<RENDERER>("rectangle")
    {}
    ~rectangle()
    {}

    void  paint(RENDERER& p_paint) const 
    {
        auto height = shape<RENDERER>::get_height();
        auto width = shape<RENDERER>::get_width();
        auto X = shape<RENDERER>::get_x();
        auto Y = shape<RENDERER>::get_y();

        for (int i = X; i < X + width; ++i)
        {
            p_paint.set_pixel(i, Y);
            p_paint.set_pixel(i, Y + height -1);
        }
        
        for (int i = Y + 1; i < Y + height-1 ; ++i)
        {
            p_paint.set_pixel(X, i);
            p_paint.set_pixel(X + width-1, i);
        }

    }
};

#endif