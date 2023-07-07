#pragma once
#ifndef gui_h

#define gui_h
namespace eftl
{
class gui
{

public:
    static void Handler(int x, int y);
    gui();
private:
    static int AUTONSELECT();
    static int AUTONREDSELECT();
    static int AUTONBLUESELECT();
    static int AUTONREDRUN();
    static int AUTONBLUERUN();
    static const char *CurrentSlide;
    static const char *ChosenPath;
    /*
    ChosenPath can equal:
        REDLEFT
        REDRIGHT
        BLUELEFT
        BLUERIGHT
    */
};

}


#endif 