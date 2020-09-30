#ifndef SRC_MAIN_HEADERS_GAMEPLAY_COMMANDREADER_H
#define SRC_MAIN_HEADERS_GAMEPLAY_COMMANDREADER_H
/**
 * Functions to read and parse commands.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/Boolean.h"
#include "constant/CommandKey.h"

/**
 * Read command key from user input without echo.
 * 
 * @return The command key entered by user if valid, INVALID_COMMAND otherwise.
 */
CommandKey readCommandKeyNoEcho();

/**
 * Parse command key of single code type, i.e. part of ASCII table.
 * 
 * @param inputKey The input key to parse.
 * 
 * @return Parsed command key if valid, or INVALID_COMMAND otherwise.
 */
CommandKey parseSingleCodeCommandKey(const int inputKey);

/**
 * Parse command key of double code type, i.e. key followed by event code,
 * such as arrow keys.
 * 
 * @param inputKey The input key to parse.
 * 
 * @return Parsed command key if valid, or INVALID_COMMAND otherwise.
 */
CommandKey parseDoubleCodeCommandKey(const int inputKey);

/**
 * Check if input key means MOVE_UP_COMMAND command. This function
 * ignores arrow keys.
 * 
 * @param inputKey        The input key to validate.
 * @param isDoubleCodeKey Indicate if input key is from double code.
 * 
 * @return true if input means MOVE_UP_COMMAND command, false otherwise.
 */
Boolean isMoveUpCommandKey(const int inputKey, Boolean isDoubleCodeKey);

/**
 * Check if input key means MOVE_LEFT_COMMAND command.
 * 
 * @param inputKey        The input key to validate.
 * @param isDoubleCodeKey Indicate if input key is from double code.
 * 
 * @return true if input means MOVE_LEFT_COMMAND command, false otherwise.
 */
Boolean isMoveLeftCommandKey(const int inputKey, Boolean isDoubleCodeKey);

/**
 * Check if input key means MOVE_DOWN_COMMAND command.
 * 
 * @param inputKey        The input key to validate.
 * @param isDoubleCodeKey Indicate if input key is from double code.
 * 
 * @return true if input means MOVE_DOWN_COMMAND command, false otherwise.
 */
Boolean isMoveDownCommandKey(const int inputKey, Boolean isDoubleCodeKey);

/**
 * Check if input key means MOVE_RIGHT_COMMAND command.
 * 
 * @param inputKey        The input key to validate.
 * @param isDoubleCodeKey Indicate if input key is from double code.
 * 
 * @return true if input means MOVE_RIGHT_COMMAND command, false otherwise.
 */
Boolean isMoveRightCommandKey(const int inputKey, Boolean isDoubleCodeKey);

/**
 * Check if input key means PAUSE_COMMAND command.
 * 
 * @param inputKey The input key to validate.
 * 
 * @return true if input means PAUSE_COMMAND command, false otherwise.
 */
Boolean isPauseCommandKey(const int inputKey);

/**
 * Check if input key means END_GAME_COMMAND command.
 * 
 * @param inputKey The input key to validate.
 * 
 * @return true if input means END_GAME_COMMAND command, false otherwise.
 */
Boolean isEndGameCommandKey(const int inputKey);

#endif // SRC_MAIN_HEADERS_GAMEPLAY_COMMANDREADER_H
