#ifndef SRC_MAIN_HEADERS_CONFIG_CLIWINDOWCONFIG_H
#define SRC_MAIN_HEADERS_CONFIG_CLIWINDOWCONFIG_H
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
 * Perform configurations required when booting the game window.
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

#endif // SRC_MAIN_HEADERS_CONFIG_CLIWINDOWCONFIG_H
