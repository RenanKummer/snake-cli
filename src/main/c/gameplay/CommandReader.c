#include "constant/DoubleCodeKey.h"
#include "engine/CommandLineInterface.h"
#include "gameplay/CommandReader.h"

CommandKey readCommandKeyNoEcho()
{
    int inputKey = readKeyboardHitNoEcho();
    
    if (inputKey == DOUBLE_CODE_KEY) {
        inputKey = readKeyboardHitNoEcho();
        return parseDoubleCodeCommandKey(inputKey);
    }

    return parseSingleCodeCommandKey(inputKey);
}

CommandKey parseSingleCodeCommandKey(const int inputKey)
{
    if (isMoveUpCommandKey(inputKey, false))
        return MOVE_UP_COMMAND;
    if (isMoveLeftCommandKey(inputKey, false))
        return MOVE_LEFT_COMMAND;
    if (isMoveDownCommandKey(inputKey, false))
        return MOVE_DOWN_COMMAND;
    if (isMoveRightCommandKey(inputKey, false))
        return MOVE_RIGHT_COMMAND;
    if (isPauseCommandKey(inputKey))
        return PAUSE_COMMAND;
    if (isEndGameCommandKey(inputKey))
        return END_GAME_COMMAND;
    
    return INVALID_COMMAND;  
}

CommandKey parseDoubleCodeCommandKey(const int inputKey)
{
    if (isMoveUpCommandKey(inputKey, true))
        return MOVE_UP_COMMAND;
    if (isMoveLeftCommandKey(inputKey, true))
        return MOVE_LEFT_COMMAND;
    if (isMoveDownCommandKey(inputKey, true))
        return MOVE_DOWN_COMMAND;
    if (isMoveRightCommandKey(inputKey, true))
        return MOVE_RIGHT_COMMAND;

    return INVALID_COMMAND;
}

Boolean isMoveUpCommandKey(const int inputKey, Boolean isDoubleCodeKey)
{
    if (isDoubleCodeKey) {
        return (inputKey == ARROW_UP_KEY);
    }

    return (inputKey == 'w') || (inputKey == 'W');
}

Boolean isMoveLeftCommandKey(const int inputKey, Boolean isDoubleCodeKey)
{
    if (isDoubleCodeKey) {
        return (inputKey == ARROW_LEFT_KEY);
    }

    return (inputKey == 'a') || (inputKey == 'A');
}

Boolean isMoveDownCommandKey(const int inputKey, Boolean isDoubleCodeKey)
{
    if (isDoubleCodeKey) {
        return (inputKey == ARROW_DOWN_KEY);
    }

    return (inputKey == 's') || (inputKey == 'S');
}

Boolean isMoveRightCommandKey(const int inputKey, Boolean isDoubleCodeKey)
{
    if (isDoubleCodeKey) {
        return (inputKey == ARROW_RIGHT_KEY);
    }

    return (inputKey == 'd') || (inputKey == 'D');
}

Boolean isPauseCommandKey(const int inputKey)
{
    return (inputKey == 'p') || (inputKey == 'P');
}

Boolean isEndGameCommandKey(const int inputKey)
{
    return (inputKey == 'q') || (inputKey == 'Q');
}
