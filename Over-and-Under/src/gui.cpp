#include <iostream>>
#include "vex.h"
#include "gui.h"
#include <map>
std::map<std::string,bool> slidesMap;
const char *ChosenPath;
const char *CurrentSlide;

const char *CurrentSlide = "Startup";

int AUTONBLUERUN(){
    Brain.Screen.drawImageFromFile("AUTONBLUE_RUN.png", 0, 0);
    CurrentSlide = "AUTONBLUERUN";
    return 0;
}

int AUTONREDRUN(){
    Brain.Screen.drawImageFromFile("AUTONRED_RUN.png", 0, 0);
    CurrentSlide = "AUTONREDRUN";
    return 0;
}

int AUTONBLUESELECT(){
    Brain.Screen.drawImageFromFile("AUTONBLUE_SELECT.png", 0, 0);
    CurrentSlide = "AUTONBLUESELECT";
    return 0;
}

int AUTONREDSELECT(){
    Brain.Screen.drawImageFromFile("AUTONRED_SELECT.png", 0, 0);
    CurrentSlide = "AUTONREDSELECT";
    return 0;
}

 int AUTONSELECT(){
    Brain.Screen.drawImageFromFile("AUTON_SELECT.png", 0, 0);
    CurrentSlide = "AUTONSELECT";
    return 0;
}

void Handler(int x, int y){

    if (CurrentSlide == "Startup"){
        AUTONSELECT();
    } else if (CurrentSlide == "AUTONSELECT" || CurrentSlide == "AUTONREDSELECT" || CurrentSlide == "AUTONBLUESELECT"){
        if (y >= 72 && y <= 204){
            if (x >= 0 && x < 240){
                if (CurrentSlide == "AUTONSELECT"){
                    AUTONREDSELECT();
                }
                if (CurrentSlide == "AUTONREDSELECT"){
                    ChosenPath = "REDLEFT";
                    AUTONREDRUN();
                }
                if (CurrentSlide == "AUTONBLUESELECT"){
                    ChosenPath = "BLUELEFT";
                    AUTONBLUERUN();
                }
            }else if (x <= 480){
                if (CurrentSlide == "AUTONSELECT"){
                    AUTONBLUESELECT();
                }
                if (CurrentSlide == "AUTONREDSELECT"){
                    ChosenPath = "REDRIGHT";
                    AUTONREDRUN();
                }
                if (CurrentSlide == "AUTONBLUESELECT"){
                    ChosenPath = "BLUERIGHT";
                    AUTONBLUERUN();
                }
            }
        }
    }
}

