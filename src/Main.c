/**
 * Application's entry point.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "config/CliWindowConfig.h"
#include "engine/CommandLineInterface.h"
#include "gameplay/CommandRunner.h"
#include "gameplay/LevelMap.h"
#include "gameplay/CommandReader.h"

int main(int argc, char **argv)
{
    CliWindowConfig cliWindowConfig = initializeCliWindow();
    
    LevelMap levelMap = getLevelMap();
    printLevelMap(levelMap);

    while (true) {
        while (!hasKeyboardHit()) {}
        CommandKey commandKey = readCommandKeyNoEcho();
        moveSnake(&levelMap, commandKey);
    }
}
