#include "vex.h"

//excuse me wtf?, why declare as a 2d array, when it is a hashmap

Slides[2][2]= {
    {"mainmenu.png", false},
    {"running.png", false}
};

void MainMenu(){
    //How did you screw up method calls?
    Brain.Screen.Display(Slides[0])
    //2d array = hashmap? wtf?
    Slides[0][1] = true;
    return;
}

void GUI_Handler(){
    
}

int main(){
    //TF are you doing, where are the brackets?
    MainMenu;
    GUI_Handler;
}

