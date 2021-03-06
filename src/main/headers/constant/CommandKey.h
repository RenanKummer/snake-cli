#ifndef SRC_MAIN_HEADERS_CONSTANT_COMMANDKEY_H
#define SRC_MAIN_HEADERS_CONSTANT_COMMANDKEY_H
/**
 * Enumeration type for command keys.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */

typedef enum CommandKey
{
    INVALID_COMMAND = -1,

    MOVE_UP_COMMAND,
    MOVE_LEFT_COMMAND,
    MOVE_DOWN_COMMAND,
    MOVE_RIGHT_COMMAND,

    PAUSE_COMMAND,
    END_GAME_COMMAND
} CommandKey;

#endif // SRC_MAIN_HEADERS_CONSTANT_COMMANDKEY_H
