// gui.cpp
#include <string>
#include "vex.h"
#include "gui.h"
#include <map>

int x;
int y;

class BaseScreen{
    protected:
        int x;
        int y;
        std::string FilePath;
        BaseScreen* LastScreen;
    public:
            BaseScreen(std::string filepath,int x,int y):
            FilePath(filepath),x(x),y(y)
            {}
            void loadScreen(){
                Brain.Screen.clearScreen();
                Brain.Screen.drawImageFromFile(FilePath,x,y);
            }

}

class BackgroundScreen : public BaseScreen {
    public:
            BackgroundScreen(std::string filepath):BaseScreen(filepath,0,0){}
}

class Button{
    protected:
            int xlength;
            int yheight;
            int xposition;
            int yposition;
            vex::color colour;
    public:

            Button(int xsize,int ysize, int xpos, int ypos,vex::color color,void(*func)(void)):
            xlength(xsize),yheight(ysize),xposition(xpos),yposition(ypos),colour(color)
            {
                int TouchPos = Brain.Screen.isTouched();
                Brain.Screen.setFillColor(colour);  
                Brain.Screen.drawRectangle(xlength,yheight,xposition,yposition);
                
                if (TouchPos>xposition && TouchPos<(xposition+xlength) && TouchPos>yposition && TouchPos<(yposition+yheight)){
                       func(void); 
                }
            }
            
}

class Text{
    public:
    std::string textInput;
    vex::color Colour;
    int fontSize;
        Text(std::string txtInput,vex::color color, int fontS):textInput(txtInput),Colour(color),fontSize(fontS){
           Brain.Screen.setFillColour(Colour); 
            Brain.Screen.print(textInput);
        }   
}






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