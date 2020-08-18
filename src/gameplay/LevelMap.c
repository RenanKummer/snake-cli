#include "constant/Boolean.h"
#include "constant/LevelMapElement.h"
#include "gameplay/LevelMap.h"

#include <stdlib.h>
#include <stdio.h>

LevelMap getLevelMap()
{
    const int numRows = 38;
    const int numColumns = 120;

    LevelMap levelMap = {"hardcoded-level", numRows, numColumns};
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

void printLevelMap(const LevelMap levelMap)
{
    printf("Level: %s\n", levelMap.identifier);

    for (int i = 0; i < levelMap.height; i++) {
        for (int j = 0; j < levelMap.width; j++) {
            printf("%c", levelMap.map[i][j]);
        }
        printf("\n");
    }
}