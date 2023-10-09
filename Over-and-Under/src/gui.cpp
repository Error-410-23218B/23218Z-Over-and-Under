// gui.cpp
#include <string>
#include "vex.h"
#include "gui.h"
#include <map>

int x;
int y;

BaseScreen::BaseScreen(std::string filepath, int x, int y,BaseScreen* lastScreen = NULL,BaseScreen* nextScreen = NULL) : FilePath(filepath), x(x), y(y), LastScreen(lastScreen),NextScreen(nextScreen)
{
}

void BaseScreen::loadScreen()
{
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromFile(FilePath.c_str(), x, y);
}

BackgroundScreen::BackgroundScreen(std::string filepath) : BaseScreen(filepath, 0, 0) {}

Button::Button(int xsize, int ysize, int xpos, int ypos, vex::color color, void (*func)(void)) : xlength(xsize), yheight(ysize), xposition(xpos), yposition(ypos), colour(color)
{
    int xTouch = Brain.Screen.xPosition();
    int yTouch = Brain.Screen.yPosition();

    Brain.Screen.setFillColor(colour);
    Brain.Screen.drawRectangle(xlength, yheight, xposition, yposition);

    if (xTouch > xposition && xTouch < (xposition + xlength) && yTouch > yposition && yTouch < (yposition + yheight))
    {
        func();
    }
}

Text::Text(std::string txtInput, vex::color color, vex::fontType fontParam) : textInput(txtInput), Colour(color),fontFormat(fontParam)
{
    Brain.Screen.setFont(fontFormat);
    Brain.Screen.setFillColor(Colour);
    Brain.Screen.print(textInput);

}

void buttonTrial(){
    Drivetrain.setDriveVelocity(100,percent);
}

int GUIHandler()
{
    //Object creation happens here, runs on seperate task?
    Text title = Text("This is a test",vex::color::black,vex::fontType::mono30);
    Button autonSkills = Button(20,30,50,40,vex::color::blue,buttonTrial);
    BackgroundScreen Screen1 = BackgroundScreen("test/test/png");
    return 0;
}



/*
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

            }
        }
        else{
        {
            AUTONSELECT();
        }
        void switchGUI();
            }
    }




}