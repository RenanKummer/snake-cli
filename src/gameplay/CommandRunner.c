#include "constant/LevelMapElement.h"
#include "engine/CommandLineInterface.h"
#include "gameplay/CommandRunner.h"

#include <stdio.h>

void moveSnake(LevelMap *const levelMap, const CommandKey commandKey)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMap originalLevelMap = copyLevelMap(*levelMap);

        if (commandKey == MOVE_UP_COMMAND) {
            moveSnakeUp(levelMap);
        } else if (commandKey == MOVE_LEFT_COMMAND) {
            moveSnakeLeft(levelMap);
        } else if (commandKey == MOVE_DOWN_COMMAND) {
            moveSnakeDown(levelMap);
        } else if (commandKey == MOVE_RIGHT_COMMAND) {
            moveSnakeRight(levelMap);
        }

        refreshSnakeLevelMap(originalLevelMap, *levelMap);
    }
}

void moveSnakeUp(LevelMap *const levelMap)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMapCoordinate *coordinate = &(levelMap->snakeCoordinate);
        
        levelMap->map[coordinate->height][coordinate->width] = AVAILABLE_SPACE;
        coordinate->height--;

        if (!hitsWall(*levelMap, *coordinate)) {
            levelMap->map[coordinate->height][coordinate->width] = START_POSITION;
        } else {
            moveSnakeBackToStartCoordinate(levelMap);
        }
    }
}

void moveSnakeLeft(LevelMap *const levelMap)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMapCoordinate *coordinate = &(levelMap->snakeCoordinate);

        levelMap->map[coordinate->height][coordinate->width] = AVAILABLE_SPACE;
        coordinate->width--;

        if (!hitsWall(*levelMap, *coordinate)) {
            levelMap->map[coordinate->height][coordinate->width] = START_POSITION;
        } else {
            moveSnakeBackToStartCoordinate(levelMap);
        }
    }
}

void moveSnakeDown(LevelMap *const levelMap)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMapCoordinate *coordinate = &(levelMap->snakeCoordinate);

        levelMap->map[coordinate->height][coordinate->width] = AVAILABLE_SPACE;
        coordinate->height++;

        if (!hitsWall(*levelMap, *coordinate)) {
            levelMap->map[coordinate->height][coordinate->width] = START_POSITION;
        } else {
            moveSnakeBackToStartCoordinate(levelMap);
        }
    }
}

void moveSnakeRight(LevelMap *const levelMap)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMapCoordinate *coordinate = &(levelMap->snakeCoordinate);

        levelMap->map[coordinate->height][coordinate->width] = AVAILABLE_SPACE;
        coordinate->width++;
        
        if (!hitsWall(*levelMap, *coordinate)) {
            levelMap->map[coordinate->height][coordinate->width] = START_POSITION;
        } else {
            moveSnakeBackToStartCoordinate(levelMap);
        }
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

void moveSnakeBackToStartCoordinate(LevelMap *const levelMap)
{
    if ((levelMap != NULL) && isValidLevelMap(*levelMap)) {
        LevelMapCoordinate *snake = &(levelMap->snakeCoordinate);      
        snake->height = levelMap->startCoordinate.height;
        snake->width = levelMap->startCoordinate.width;

        levelMap->map[snake->height][snake->width] = START_POSITION;
    }
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