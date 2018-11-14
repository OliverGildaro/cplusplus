#ifndef LINE_H
#define LINE_H
#include "shape.h"
template<typename RENDERER>
class line:public shape<RENDERER>
{
public:
    line()
    :shape<RENDERER>("line")
    {}
    ~line()
    {}
    
    void  paint(RENDERER& p_paint) const 
    {
        auto height = shape<RENDERER>::get_height();
        auto width = shape<RENDERER>::get_width();
        auto X = shape<RENDERER>::get_x();
        double Y = shape<RENDERER>::get_y();
        double delta= ((double)height)/((double)width);
        
        for (int i = 0; i <  width; ++i)
        {
            p_paint.set_pixel(i + X, (int) Y);
            Y+=delta;
        }        
    }
};

#endif