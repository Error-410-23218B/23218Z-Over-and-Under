//gui.cpp
#include <iostream>>
#include "vex.h"
#include "gui.h"
#include <map>

std::string CurrentSlide;
std::string ChosenPath;
 int x;
 int y;

void xyReset(){
   x = 0;
   y = 0;
}

short int AUTONBLUERUN(){
    Brain.Screen.drawImageFromFile("AUTONBLUE_RUN.png", 0, 0);
    CurrentSlide = "AUTONBLUERUN";
    xyReset();
    return 0;
}

 short int AUTONREDRUN(){
    Brain.Screen.drawImageFromFile("AUTONRED_RUN.png", 0, 0);
    CurrentSlide = "AUTONREDRUN";
    xyReset();
    return 0;
}

 short int AUTONBLUESELECT(){
    Brain.Screen.drawImageFromFile("AUTONBLUE_SELECT.png", 0, 0);
    CurrentSlide = "AUTONBLUESELECT";
    xyReset();
    return 0;
}

short int AUTONREDSELECT(){
    Brain.Screen.drawImageFromFile("AUTONRED_SELECT.png", 0, 0);
    CurrentSlide = "AUTONREDSELECT";
    xyReset();
    return 0;
}

short int AUTONSELECT(){
    Brain.Screen.drawImageFromFile("AUTON_SELECT.png", 0, 0);
    CurrentSlide = "AUTONSELECT";
    xyReset();
    return 0;
}

void Handler(){
    x = Brain.Screen.xPosition();
    y = Brain.Screen.yPosition();


if (CurrentSlide == "AUTONSELECT" || CurrentSlide == "AUTONREDSELECT" || CurrentSlide == "AUTONBLUESELECT"){
    if (y >= 72 && y <= 204){
        if (x >= 0 && x < 240){
            if (CurrentSlide == "AUTONSELECT"){
                    AUTONREDSELECT();
            }else if (CurrentSlide == "AUTONREDSELECT"){
                    ChosenPath = "REDLEFT";
                    AUTONREDRUN();
                }else if (CurrentSlide == "AUTONBLUESELECT"){
                    ChosenPath = "BLUELEFT";
                    AUTONBLUERUN();
                    }
        }else if (x <= 480){
            if (CurrentSlide == "AUTONSELECT"){
                    AUTONBLUESELECT();
            }else if (CurrentSlide == "AUTONREDSELECT"){
                    ChosenPath = "REDRIGHT";
                    AUTONREDRUN();
                }else if (CurrentSlide == "AUTONBLUESELECT"){
                    ChosenPath = "BLUERIGHT";
                    AUTONBLUERUN();
                    }
            }
        }
    }else{
        AUTONSELECT();
    }
}