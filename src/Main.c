/**
 * Application's entry point.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "config/CliWindowConfig.h"
#include "gameplay/LevelMap.h"

#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    CliWindowConfig cliWindowConfig = initializeCliWindow();
    
    LevelMap levelMap = getLevelMap();
    printLevelMap(levelMap);
}
