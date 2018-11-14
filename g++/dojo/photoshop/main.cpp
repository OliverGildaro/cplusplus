#include <iostream>
#include "line.h"
#include "rectangle.h"
#include "circle.h"
#include "photoshop.h"
#include "text_renderer.h"
#include <memory>
#include <string>

using namespace std;

using mtr = text_renderer<80, 25>;

void draw_menu()
{
    cout << "MENU:\n";
    cout << "  1. Add shape\n";
    cout << "  2. Move shape\n";
    cout << "  3. Resize shape\n";
    cout << "  4. Delete shape\n";
    cout << "  5. Quit\n";
}
int menu_option_add()
{
    int op;
    cout << "Shape:\n";
    cout << "  1. Circle\n";
    cout << "  2. Line\n";
    cout << "  3. Rectangle\n";
    cout << "  4. Quit\n";
    cin >>op;
    return op;
}

template <typename T>
shape_type<mtr> &list_shapes(photoshop<T> &ps)
{
    return ps[select_shape_index(ps)];
}
template <typename T>
size_t select_shape_index(photoshop<T> &ps)
{
    cout << "Choose a shape to use :\n";
    size_t index = 0;
    string shape_name;
    for (auto &it:ps)
    {
        visit([&shape_name](auto & v){shape_name=v.get_name(); },it);
        cout <<++index<<": "<< shape_name<<"\n";
    }
    cout << "shape index: ";
    cin >> index;
    return index-1;
}

template <typename T>
void process_move(photoshop<T> &ps)
{
    int x;
    int y;
    auto& sp = list_shapes(ps);
    cout << "enter new axis: ";
    cout << "enter x: ";
    cin>>x;
    cout << "enter y: ";
    cin>>y;
    visit([&x, &y](auto & v){v.move(x,y); },sp);
}

template <typename T>
void process_resize(photoshop<T> &ps)
{
    int width;
    int height;
    auto& sp = list_shapes(ps);
    cout << "enter new size: ";
    cout << "enter width: ";
    cin>>width;
    cout << "enter height: ";
    cin>>height;
    visit([&width, &height](auto & v){v.resize(width,height); },sp);
}

template <typename T>
void process_delete(photoshop<T> &ps)
{
    ps.delete_shape(select_shape_index(ps));
}
void process_add(photoshop<mtr> &ps)
{
    int Option = menu_option_add();
    switch(Option)
    {
        case 1: ps.add_shape<circle>();
                break;
        case 2: ps.add_shape<line>();
                break;
        case 3: ps.add_shape<rectangle>();
                break;
        case 4: break;
        default: throw -1;
    }

}
template <typename T>
void process_option(int op, photoshop<T> &ps)
{
    switch(op)
    {
        case 1: process_add(ps);
                break;
        case 2: process_move(ps);
                break;
        case 3: process_resize(ps);
                break;
        case 4: process_delete(ps);
                break;
        case 5: break;
        default: throw -1;
    }

}

int main()
{
    photoshop<text_renderer<80,25>> ps;
    int op = -1;
    while (op != 5)
    {
        ps.show_image();
        draw_menu();
        cin >> op;
        process_option(op, ps);
    }
}
