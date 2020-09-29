#include "config/CliWindowConfig.h"
#include "engine/CommandLineInterface.h"

CliWindowConfig initializeCliWindow()
{   
    hideCursor();

    WindowSize snakeCliWindowSize = configureWindowSize();

    CliWindowConfig cliWindowConfig = {false, snakeCliWindowSize};
    return cliWindowConfig;
}

WindowSize configureWindowSize()
{
    WindowSize snakeCliWindowSize = {40, 120};
    resizeWindow(snakeCliWindowSize);

    return snakeCliWindowSize;
}
