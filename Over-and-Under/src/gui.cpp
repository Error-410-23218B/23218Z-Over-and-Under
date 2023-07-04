#include <iostream>>
#include "vex.h"
#include <map>

//excuse me wtf?, why declare as a 2d array, when it is a hashmap
std::map<std::string,bool> slidesMap;
//This is awful
/*
//This isn't python, what type is it?
Slides[2][2]= {
    {"mainmenu.png", false},
    {"running.png", false}
};
*/



void MainMenu(){
    //How did you screw up method calls?
    Brain.Screen.render();
    //2d array = hashmap? wtf?
    // fixed your code.
    slidesMap.insert({"mainmenu.png",false});
    slidesMap.insert({"running.png",false});
    slidesMap["running.png"] = true;
    // why the empty return? It's a void function
    //return;
}

void GUI_Handler(){
    //empty function why?
}
//WTF is there a definition of main here, main is the calling point for the whole program? wtf?
void GUI(){
    
    //TF are you doing, where are the brackets?
    MainMenu();//<----
    GUI_Handler();//<-----
    //Why did you declare it as an int function, and no return?
}

