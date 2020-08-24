#include "constant/Boolean.h"
#include "constant/LevelMapElement.h"
#include "constant/SnakeBodyPart.h"
#include "gameplay/LevelMap.h"
#include "util/StringUtils.h"

#include <stdlib.h>
#include <stdio.h>

LevelMap getLevelMap()
{
    const int numRows = 38;
    const int numColumns = 120;

    LevelMap levelMap = {"hardcoded-level", numRows, numColumns};
    levelMap.startCoordinate.height = numRows / 2;
    levelMap.snakeCoordinate.height = numRows / 2;
    levelMap.startCoordinate.width = numColumns / 2;
    levelMap.snakeCoordinate.width = numColumns / 2;
    levelMap.map = (char**) malloc(sizeof(char*) * numRows);

    for (int i = 0; i < numRows; i++) {
        levelMap.map[i] = (char*) malloc(sizeof(char) * numColumns);

        for (int j = 0; j < numColumns; j++) {
            Boolean isWallPosition = 
                (i == 0) || (i == (numRows - 1)) ||
                (j == 0) || (j == (numColumns - 1));
            Boolean isStartPosition = 
                (i == numRows / 2) && (j == numColumns / 2);
            
            if (isWallPosition) {
                levelMap.map[i][j] = WALL;
            } else if (isStartPosition) {
                levelMap.map[i][j] = START_POSITION;
            } else {
                levelMap.map[i][j] = AVAILABLE_SPACE;
            }
        }
    }

    return levelMap;
}

Boolean isValidLevelMap(const LevelMap levelMap)
{
    Boolean hasValidIdentifier = !isEmptyString(levelMap.identifier);
    Boolean hasValidDimensions = (levelMap.height > 0) && (levelMap.width > 0);

    WindowSize levelMapSize = {levelMap.height, levelMap.width};
    Boolean hasValidSnakeCoordinate = 
        isValidWindowCoordinate(levelMap.snakeCoordinate, levelMapSize);
    Boolean hasValidStartCoordinate =
        isValidWindowCoordinate(levelMap.startCoordinate, levelMapSize);

    if (!hasValidIdentifier || !hasValidDimensions ||
        !hasValidSnakeCoordinate || !hasValidStartCoordinate ||
        (levelMap.map == NULL)) {
        return false;
    } else {
        for (int i = 0; i < levelMap.height; i++) {
            for (int j = 0; j < levelMap.width; j++) {
                Boolean isInvalidCharacter = 
                    (levelMap.map[i][j] != AVAILABLE_SPACE) &&
                    (levelMap.map[i][j] != START_POSITION) &&
                    (levelMap.map[i][j] != WALL) && 
                    (levelMap.map[i][j] != ROCK) &&
                    (levelMap.map[i][j] != MOUSE) &&
                    (levelMap.map[i][j] != APPLE) &&
                    (levelMap.map[i][j] != HEAD_UP) &&
                    (levelMap.map[i][j] != HEAD_LEFT) &&
                    (levelMap.map[i][j] != HEAD_DOWN) &&
                    (levelMap.map[i][j] != HEAD_RIGHT) &&
                    (levelMap.map[i][j] != BODY_VERTICAL) &&
                    (levelMap.map[i][j] != BODY_HORIZONTAL);

                if (isInvalidCharacter) {
                    return false;
                }
            }
        }
    }

    return true;
}

LevelMap copyLevelMap(const LevelMap levelMap)
{
    LevelMap levelMapCopy = {
        levelMap.identifier,
        levelMap.height,
        levelMap.width,
        NULL,
        levelMap.startCoordinate,
        levelMap.snakeCoordinate
    };

    const int numRows = levelMap.height;
    const int numColumns = levelMap.width;

    if ((numRows > 0) && (numColumns > 0)) {
        levelMapCopy.map = (char**) malloc(sizeof(char*) * numRows);

        for (int i = 0; i < numRows; i++) {
            levelMapCopy.map[i] = (char*) malloc(sizeof(char) * numColumns);
            
            for (int j = 0; j < numColumns; j++) {
                levelMapCopy.map[i][j] = levelMap.map[i][j];
            }
        }
    }

    return levelMapCopy;
}

void printLevelMap(const LevelMap levelMap)
{
    for (int i = 0; i < levelMap.height; i++) {
        for (int j = 0; j < levelMap.width; j++) {
            printf("%c", levelMap.map[i][j]);
        }
        printf("\n");
    }
}