#pragma once
#ifndef gui_h

#define gui_h
namespace eftl
{
class gui
{

public:

    gui(int x, int y);
    static int Handler();

private:
    static int MainMenu();
    static int Running();

};

}


#endif 