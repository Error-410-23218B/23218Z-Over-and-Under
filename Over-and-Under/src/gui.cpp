//gui.cpp
#include <string>
#include "vex.h"
#include "gui.h"
#include <map>

std::string CurrentSlide;
std::string ChosenPath;

 enum GUIState{autonselect, autonredselect,autonblueselect}

void xyReset(){
   x = 0;
   y = 0;
}

void AUTONBLUERUN(){
    Brain.Screen.drawImageFromFile("AUTONBLUE_RUN.png", 0, 0);
    CurrentSlide = "AUTONBLUERUN";
    xyReset();
    
}

 void AUTONREDRUN(){
    Brain.Screen.drawImageFromFile("AUTONRED_RUN.png", 0, 0);
    CurrentSlide = "AUTONREDRUN";
    xyReset();
}

 void  AUTONBLUESELECT(){
    Brain.Screen.drawImageFromFile("AUTONBLUE_SELECT.png", 0, 0);
    CurrentSlide = "AUTONBLUESELECT";
    xyReset();
}

void AUTONREDSELECT(){
    Brain.Screen.drawImageFromFile("AUTONRED_SELECT.png", 0, 0);
    CurrentSlide = "AUTONREDSELECT";
    xyReset();
    
}

void AUTONSELECT(){
    Brain.Screen.drawImageFromFile("AUTON_SELECT.png", 0, 0);
    CurrentSlide = "AUTONSELECT";
    xyReset();
    
}

void switchGUI(int x, int y){
    switch ()
    {
        case autonselect:AUTONREDSELECT();
        case autonredselect:ChosenPath = "REDLEFT"; AUTONREDRUN();
        case autonblueselect:ChosenPath = "REDLEFT"; AUTONBLUERUN();
    }
}

if (CurrentSlide == "AUTONSELECT" || CurrentSlide == "AUTONREDSELECT" || CurrentSlide == "AUTONBLUESELECT"){
    if (y >= 72 && y <= 204){
        if (x >= 0 && x < 240){
         switchGUI();
        }else if (x <= 480){
                    switchGUI();
            }
        }
    }else{
        AUTONSELECT();
    }