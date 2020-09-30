#ifndef SRC_MAIN_HEADERS_GAMEPLAY_LEVELMAP_H
#define SRC_MAIN_HEADERS_GAMEPLAY_LEVELMAP_H
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
    LevelMapCoordinate snakeCoordinate;
} LevelMap;

/**
 * @return The level map.
 */
LevelMap getLevelMap();

/**
 * Validate fields of a LevelMap instance.
 * 
 * @param levelMap The level map to validate.
 * 
 * @return true if valid, false otherwise.
 */
Boolean isValidLevelMap(const LevelMap levelMap);

/**
 * Copy LevelMap instance. This functions uses dynamic memory allocation 
 * for pointer fields.
 * 
 * @param levelMap The instance to copy.
 * 
 * @return Copied instance.
 */
LevelMap copyLevelMap(const LevelMap levelMap);

/**
 * Print the level map into the Command Line Interface.
 * 
 * @param levelMap The level map to print.
 */
void printLevelMap(const LevelMap levelMap);

#endif // INCLUDE_CONSTANT_SNAKEBODYPART_H
