#ifndef INCLUDE_UI_COMMANDLINEINTERFACE_H
#define INCLUDE_UI_COMMANDLINEINTERFACE_H
/**
 * Manipulate Command Line Interface (CLI) on Windows. Functions from conio.h
 * header file are also available.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "type/Boolean.h"
#include <conio.h>

WindowCoordinate moveCursor(
    const WindowSize size, 
    const WindowCoordinate coordinate
);

void wait(int miliseconds);

Boolean resizeWindow(const WindowSize windowSize);
void clearWindow();

#endif // INCLUDE_UI_COMMANDLINEINTERFACE_H
