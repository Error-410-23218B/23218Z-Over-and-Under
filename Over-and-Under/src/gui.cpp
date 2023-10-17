// gui.cpp
#include <string>
#include "vex.h"
#include "gui.h"
#include <map>

int x;
int y;



//TODO:
/*
* Implement a class that is a screen contains all instantiation variables,
* no constructor, within named structures, 
* instantiate class for you,
*named structure can be accesed for you.
*  Avoids problems of inheritance.
*   It also makes code simpler to use and read.
*/

BaseScreen::BaseScreen(std::string filepath, int x, int y,BaseScreen* lastScreen = NULL,
BaseScreen* nextScreen = NULL) : FilePath(filepath), x(x), y(y), LastScreen(lastScreen),NextScreen(nextScreen)
{}

BaseScreen::~BaseScreen(){
    Brain.Screen.clearScreen();
    delete LastScreen;
    delete NextScreen;
}



void BaseScreen::loadScreen()
{
    Brain.Screen.clearScreen();
    Brain.Screen.drawImageFromFile(FilePath.c_str(), x, y);
}

BackgroundScreen::BackgroundScreen(std::string filepath,BaseScreen* lastScreen = NULL,BaseScreen* nextScreen = NULL) : BaseScreen(filepath, 0, 0,lastScreen,nextScreen) {}

Button::Button(int xsize, int ysize, int xpos, int ypos, vex::color color, void (*func)(void)) : xlength(xsize), yheight(ysize), xposition(xpos), yposition(ypos), colour(color)
{
    int xTouch = Brain.Screen.xPosition();
    int yTouch = Brain.Screen.yPosition();

    Brain.Screen.setFillColor(colour);

}

Button::~Button(){
    
}

Button::load(){
    Brain.Screen.drawRectangle(xlength, yheight, xposition, yposition);
    while (1)
    {
        if (xTouch > xposition && xTouch < (xposition + xlength) && yTouch > yposition && yTouch < (yposition + yheight))
        {
            func(); 
        }
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
    Button autonSkills(20,30,50,40,vex::color::blue,buttonTrial);
    BackgroundScreen mainScreen("MAIN.png",NULL,NULL);
    BackgroundScreen autonBlueRun("AUTONBLUERUN.png",mainScreen);
    BackgroundScreen autonRedRun("AUTONREDRUN.png",mainScreen);
    BackgroundScreen autonSkillRun("AUTONSKILLRUN.png",mainScreen);
    return 0;
}
