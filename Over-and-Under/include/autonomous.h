//autonomous.h
#pragma once
#ifndef autonomous_h
#define autonomous_h
#include <string>
#include "gui.h"

void autonomous();

extern enum AutonState{
    REDBOTSTART,
    BLUEBOTSTART,
    REDTOPSTART,
    BLUETOPSTART
}

#endif