//gui.cpp
#include <string>
#include "vex.h"
#include "gui.h"
#include <map>

std::string CurrentSlide;
<<<<<<< HEAD
<<<<<<< HEAD
 int x;
 int y;
 enum ChosenPath{redleft};
 enum GUIState{autonselect, autonredselect,autonblueselect,autonredrun,autonbluerun};
enum GUIState guiState; 
enum ChosenPath chosenpath;
=======
std::string ChosenPath;

 enum GUIState{autonselect, autonredselect,autonblueselect}

>>>>>>> b2062c2292b5adfe4e8145f2cae0fb9e88d254da
=======
std::string ChosenPath;
 int x;
 int y;

 enum GUIState{autonselect, autonredselect,autonblueselect}

>>>>>>> parent of 5385ee2 (enumeration fixed, compiled)
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

<<<<<<< HEAD
<<<<<<< HEAD
void switchGUI(){
    switch (guiState)
    {
        case autonselect:AUTONREDSELECT();
        case autonredselect:chosenpath = redleft; AUTONREDRUN();
        case autonblueselect:chosenpath = redleft; AUTONBLUERUN();
    }
}


=======
>>>>>>> parent of 5385ee2 (enumeration fixed, compiled)
void Handler(){
    x = Brain.Screen.xPosition();
    y = Brain.Screen.yPosition();
    
<<<<<<< HEAD
switch(guiState){
    case autonselect || autonredselect || autonblueselect: 
=======
void switchGUI(int x, int y){
    switch ()
    {
        case autonselect:AUTONREDSELECT();
        case autonredselect:ChosenPath = "REDLEFT"; AUTONREDRUN();
        case autonblueselect:ChosenPath = "REDLEFT"; AUTONBLUERUN();
    }
}

if (CurrentSlide == "AUTONSELECT" || CurrentSlide == "AUTONREDSELECT" || CurrentSlide == "AUTONBLUESELECT"){
>>>>>>> b2062c2292b5adfe4e8145f2cae0fb9e88d254da
=======

if (CurrentSlide == "AUTONSELECT" || CurrentSlide == "AUTONREDSELECT" || CurrentSlide == "AUTONBLUESELECT"){
>>>>>>> parent of 5385ee2 (enumeration fixed, compiled)
    if (y >= 72 && y <= 204){
        if (x >= 0 && x < 240){
         switchGUI();
        }else if (x <= 480){
                    switchGUI();
            }
        }
    }else{
        AUTONSELECT();
<<<<<<< HEAD
    }
void switchGUI()}{
    switch ()
    {
        case autonselect:AUTONREDSELECT();
        case autonredselect:ChosenPath = "REDLEFT"; AUTONREDRUN();
        case autonblueselect:ChosenPath = "REDLEFT"; AUTONBLUERUN();
    }
}
<<<<<<< HEAD


    

=======
    }
>>>>>>> b2062c2292b5adfe4e8145f2cae0fb9e88d254da
=======
>>>>>>> parent of 5385ee2 (enumeration fixed, compiled)
