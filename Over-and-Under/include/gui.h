//gui.h
#include <string>
#pragma once
#ifndef gui_h

#define gui_h


void Handler();
void AUTONSELECT();

    extern std::string ChosenPath;
    /*
    REDLEFT
    BLUELEFT
    REDRIGHT
    BLUERIGHT
    */
extern enum class GUIState
{
    autonselect,
    autonredselect,
    autonblueselect,
    autonredrun,
    autonbluerun
};


#endif 