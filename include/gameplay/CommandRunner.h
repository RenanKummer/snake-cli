#ifndef INCLUDE_GAMEPLAY_COMMANDRUNNER_H
#define INCLUDE_GAMEPLAY_COMMANDRUNNER_H
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
 * Move the Snake character one row up. Only updates the map.
 * 
 * @param levelMap The level map.
 */
void moveSnakeUp(LevelMap *const levelMap);

/**
 * Move the Snake character one column to the left. Only updates the map.
 * 
 * @param levelMap The level map.
 */
void moveSnakeLeft(LevelMap *const levelMap);

/**
 * Move the Snake character one row down. Only updates the map.
 * 
 * @param levelMap The level map.
 */
void moveSnakeDown(LevelMap *const levelMap);

/**
 * Move the Snake character one column to the right. Only updates the map.
 * 
 * @param levelMap The level map.
 */
void moveSnakeRight(LevelMap *const levelMap);

/**
 * Refresh the level map on the screen. Only refreshes modified characters.
 * 
 * @param oldMap The old LevelMap instance.
 * @param newMap The new LevelMap instance.
 */
void refreshSnakeLevelMap(const LevelMap oldMap, const LevelMap newMap);

#endif // INCLUDE_GAMEPLAY_COMMANDRUNNER_H
