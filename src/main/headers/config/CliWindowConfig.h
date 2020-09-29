#ifndef INCLUDE_CONFIG_CLIWINDOWCONFIG_H
#define INCLUDE_CONFIG_CLIWINDOWCONFIG_H
/**
 * Configurations related with Command Line Interface window.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/Boolean.h"
#include "engine/WindowSize.h"

typedef struct CliWindowConfig
{
    Boolean isCursorVisible;
    WindowSize windowSize;
} CliWindowConfig;

/**
 * Perform configurations required when starting the game.
 * 
 * @return The configurations set.
 */
CliWindowConfig initializeCliWindow();

/**
 * Set command line window size.
 * 
 * @return The window's dimensions.
 */
WindowSize configureWindowSize();

#endif // INCLUDE_CONFIG_CLIWINDOWCONFIG_H
