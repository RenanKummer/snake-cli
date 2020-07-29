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

/**
 * Move cursor in command line window.
 * 
 * The coordinates are limited to the maximum size of each axis. If invalid 
 * arguments are passed, the cursor will be moved to default location.
 * 
 * @param size       The command line window size.
 * @param coordinate The target coordinate.
 * 
 * @return The coordinate where the cursor is located.
 */
WindowCoordinate moveCursor(
    const WindowSize size, 
    const WindowCoordinate coordinate
);

/**
 * @return The default command line window coordinate.
 */
WindowCoordinate getDefaultWindowCoordinate();

/**
 * Resize command line window.
 * 
 * @param windowSize The new window size.
 * 
 * @return true if window has been resized, false if an error occurs.
 */
Boolean resizeWindow(const WindowSize windowSize);

/**
 * Clear all output from command line window.
 */
void clearWindow();

/**
 * Temporarily pause the application execution.
 * 
 * @param miliseconds The time to wait in miliseconds.
 */
void wait(int miliseconds);

#endif // INCLUDE_UI_COMMANDLINEINTERFACE_H
