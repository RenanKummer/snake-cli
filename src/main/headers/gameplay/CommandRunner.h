#ifndef SRC_MAIN_HEADERS_GAMEPLAY_COMMANDRUNNER_H
#define SRC_MAIN_HEADERS_GAMEPLAY_COMMANDRUNNER_H
/**
 * Runner functions for game commands.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/CommandKey.h"
#include "gameplay/LevelMap.h"

/**
 * Move the Snake character based on command key. Ignores keys unrelated
 * to movement commands.
 * 
 * @param levelMap The level map.
 * @param commandKey The command key pressed.
 */
void moveSnake(LevelMap *const levelMap, const CommandKey commandKey);

/**
 * Check if moving to new coordinate hits a wall.
 * 
 * @param levelMap      The level map.
 * @param newCoordinate The new coordinate to check.
 * 
 * @return true if hits, false otherwise.
 */
Boolean hitsWall(
    const LevelMap levelMap, 
    const LevelMapCoordinate newCoordinate
);

/**
 * Refresh the level map on the screen. Only refreshes modified characters.
 * 
 * @param oldMap The old LevelMap instance.
 * @param newMap The new LevelMap instance.
 */
void refreshSnakeLevelMap(const LevelMap oldMap, const LevelMap newMap);

#endif // SRC_MAIN_HEADERS_GAMEPLAY_COMMANDRUNNER_H
