#include "vex.h"

Slides[2][2]= {
    {"mainmenu.png", false},
    {"running.png", false}
};

void MainMenu(){
    Brain.Screen.Display(Slides[0])
    Slides[0][1] = true;
    return;
}

void GUI_Handler(){
    
}

int main(){
    MainMenu;
    GUI_Handler;
}

