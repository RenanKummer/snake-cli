#include "constant/LevelMapElement.h"
#include "engine/CommandLineInterface.h"
#include "gameplay/CommandRunner.h"

#include <stdio.h>

void moveSnake(LevelMap *const levelMap, const CommandKey commandKey)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMap originalLevelMap = copyLevelMap(*levelMap);

        LevelMapCoordinate *coordinate = &(levelMap->snakeCoordinate);
        levelMap->map[coordinate->height][coordinate->width] = AVAILABLE_SPACE;

        if (commandKey == MOVE_UP_COMMAND) {
            coordinate->height--;
        } else if (commandKey == MOVE_LEFT_COMMAND) {
            coordinate->width--;
        } else if (commandKey == MOVE_DOWN_COMMAND) {
            coordinate->height++;
        } else if (commandKey == MOVE_RIGHT_COMMAND) {
            coordinate->width++;
        }

        if (hitsWall(*levelMap, *coordinate)) {
            coordinate->height = levelMap->startCoordinate.height;
            coordinate->width = levelMap->startCoordinate.width;
        }

        levelMap->map[coordinate->height][coordinate->width] = START_POSITION;
        refreshSnakeLevelMap(originalLevelMap, *levelMap);
    }
}

Boolean hitsWall(
    const LevelMap levelMap, 
    const LevelMapCoordinate newCoordinate
)
{
    WindowSize mapSize = {levelMap.height, levelMap.width};
    if (isValidLevelMap(levelMap) && isValidWindowCoordinate(newCoordinate, mapSize)) {
        return (levelMap.map[newCoordinate.height][newCoordinate.width] == WALL);
    }

    return false;
}

void refreshSnakeLevelMap(const LevelMap oldMap, const LevelMap newMap)
{
    if (isValidLevelMap(oldMap) && isValidLevelMap(newMap) &&
        (oldMap.height == newMap.height) && (oldMap.width == newMap.width)) {
        const int numRows = oldMap.height;
        const int numColumns = oldMap.width;

        WindowSize windowSize = {numRows, numColumns};
        for (int i = 0; i < numRows; i++) {
            for (int j = 0; j < numColumns; j++) {
                if (newMap.map[i][j] != oldMap.map[i][j]) {
                    WindowCoordinate windowCoordinate = {i, j};
                    moveCursor(windowSize, windowCoordinate);
                    printf("%c", newMap.map[i][j]);
                }
            }
        }

        moveCursor(windowSize, newMap.snakeCoordinate);
    }
}