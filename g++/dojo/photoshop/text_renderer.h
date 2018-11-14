#ifndef TEXT_RENDERER_H
#define TEXT_RENDERER_H
#include "shape.h"
template <size_t WIDTH, size_t HEIGHT >
class text_renderer
{
private:
     char m_canvas [HEIGHT][WIDTH+1];
public:
    text_renderer()
    {
        clear();
    }
    void show()const
    {
        for (size_t i = 0; i < HEIGHT; ++i)
        {
            puts(m_canvas[i]);
        }
    }
    
    void set_pixel(size_t x,size_t y)
    {
        m_canvas[y][x]='*';
    }

    void clear()
    {
        for (size_t b = 0U; b < HEIGHT; ++b)
        {
            for (size_t a = 0U; a < WIDTH; ++a)
            {
                m_canvas[b][a]=' ';
            }
            m_canvas[b][WIDTH]='\0';
        }
    }

};



#endif