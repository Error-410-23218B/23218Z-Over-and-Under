//gui.h
#include <string>
#pragma once
#ifndef gui_h

#define gui_h


class Button : public BaseScreen
{
protected:
    int xlength;
    int yheight;
    int xposition;
    int yposition;
    vex::color colour;

public:
    Button(int xsize, int ysize, int xpos, int ypos, vex::color color, void (*func)(void));
    friend void nextButton();
};

class BaseScreen
{
protected:
    int x;
    int y;
    std::string FilePath;
    BaseScreen *LastScreen;
    BaseScreen *NextScreen;
public:
    BaseScreen(std::string filepath, int x, int y,BaseScreen* lastScreen,BaseScreen* nextScreen);
    ~BaseScreen();
    void loadScreen();
    void nextButton();
    
};

class BackgroundScreen : public BaseScreen
{
    public:
            BackgroundScreen(std::string filepath);
};

class Text
{
    public:
        std::string textInput;
        vex::color Colour;
        vex::fontType fontFormat;
        Text(std::string txtInput, vex::color color, vex::fontType fontParam);

};

int GUIHandler();
#endif 