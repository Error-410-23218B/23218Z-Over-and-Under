/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Administrator                                             */
/*    Created:      12/05/2023, 16:17:06                                      */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/
#include "vex.h"

using namespace vex;

// A global instance of vex::brain used for printing to the V5 brain screen


// define your global instances of motors and other devices here


void drivercontrol(){

}

int main() {

    Brain.Screen.printAt( 10, 50, "Hello V5" );
   
   
    while(1) {
            
        // Allow other tasks to run
        this_thread::sleep_for(10);
    }
}