// gui.cpp
#include <string>
#include "vex.h"
#include "gui.h"
#include <map>

std::string CurrentSlide;
int x;
int y;

//Deprecated? Will use as subpar for now.
enum class ChosenPath
{
    redleft,
    blueleft,
    redright,
    blueright
};

enum GUIState guiState;
ChosenPath chosenpath;
inline void xyReset()
{
    x = 0;
    y = 0;
}

inline void AUTONSELECT(std::String pngFile,enum GUIState guiParam){
    Brain.Screen.drawImageFromFile(pngFile,0,0);
    guiState = guiParam;
    xyReset();
}

void switchGUI()
{
    switch (guiState)
    {
    case autonselect:
        AUTONSELECT("AUTONRED_SELECT.png",GUIState::autonredselect);
    case autonredselect:
        chosenpath = redleft;
        AUTONSELECT("AUTONRED_RUN.png",GUIState::autonredrun);
    case autonblueselect:
        chosenpath = redleft;
        AUTONSELECT("AUTONBLUE_RUN.png",GUIState::autonbluerun);
    }
}

void Handler()
{
    guiState = GUIState::autonselect;
    x = Brain.Screen.xPosition();
    y = Brain.Screen.yPosition();
    switch (guiState)
    {
    case GUIState::autonselect || GUIState::autonredselect || GUIState::autonblueselect:
        if (y >= 72 && y <= 204)
        {
            if (x >= 0 && x < 240)
            {
                switchGUI();
            }
            else if (x <= 480)
            {
                switchGUI();
            }
        }
        else
        {
            AUTONSELECT();
        }
        void switchGUI();
    }
    {
        switch (guiState)
        {
        case GUIState::autonselect:
            AUTONSELECT("AUTONRED_SELECT.png",GUIState::autonredselect);  
            basicAuton(guiState);
        case GUIState::autonredselect:
            chosenpath = ChosenPath::redleft;
            AUTONSELECT("AUTONRED_RUN.png",GUIState::autonredrun);
            basicAuton(guiState);
        case GUIState::autonblueselect:
            chosenpath = ChosenPath::blueleft;
            AUTONSELECT("AUTONBLUE_RUN.png",GUIState::autonbluerun);
            basicAuton(guiState);
            }
    }
    
}