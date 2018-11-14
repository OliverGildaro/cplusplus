#ifndef PHOTOSHOP_H
#define PHOTOSHOP_H
#include <memory>
#include <vector>
#include <string>
#include "shape.h"
#include <variant>

using namespace std;
template <typename R>//si esta dentro de la clase seria R = RENDERER
using shape_type = variant<circle<R>,line<R>,rectangle<R>>;
template <class RENDERER>
class photoshop
{
private:
    RENDERER m_renderer;
    vector< shape_type<RENDERER>> shapes;
public:
    using iterator =typename vector<shape_type<RENDERER>>::iterator;
    template <template <typename ...> class TYPESHAPE>//esto es un template de template que soporta n argumentos
    void add_shape()
    {
        shapes.push_back(TYPESHAPE<RENDERER>{});
    }
    // Move_shape
    // void Resize_shape
    void delete_shape(int p_index)
    {
        shapes.erase(begin()+p_index);
    }

    iterator begin()
    {
        return shapes.begin();
    }

    iterator end()
    {
        return shapes.end();
    }

    shape_type<RENDERER>& operator[](int index)
    {
        return shapes[index];
    }
    void show_image() 
    {
        m_renderer.clear();
        //visit recive un  lambda

        for (auto& s: shapes)
        {
            visit([this](auto & v){v.paint(this->m_renderer); },s);
        }
        m_renderer.show();
    }
    // quit
};
#endif