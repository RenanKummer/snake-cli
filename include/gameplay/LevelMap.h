#ifndef INCLUDE_GAMEPLAY_LEVELMAP_H
#define INCLUDE_GAMEPLAY_LEVELMAP_H
/**
 * Structures and functions to handle level maps.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "engine/WindowCoordinate.h"

typedef WindowCoordinate LevelMapCoordinate;
typedef struct LevelMap
{
    const char *const identifier;
    const int height;
    const int width;

    char **map;
    
    LevelMapCoordinate startCoordinate;
} LevelMap;

/**
 * @return The level map.
 */
LevelMap getLevelMap();

/**
 * Print the level map into the Command Line Interface.
 * 
 * @param levelMap The level map to print.
 */
void printLevelMap(const LevelMap levelMap);

#endif // INCLUDE_CONSTANT_SNAKEBODYPART_H
