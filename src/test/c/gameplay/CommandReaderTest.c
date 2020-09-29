#include "constant/DoubleCodeKey.h"
#include "gameplay/CommandReader.h"
#include "util/UnitTest.h"

TestResult testParseSingleCodeCommandKey_MovementKeys();
TestResult testParseSingleCodeCommandKey_PauseKeys();
TestResult testParseSingleCodeCommandKey_EndGameKeys();
TestResult testParseSingleCodeCommandKey_InvalidKeys();
TestResult testParseDoubleCodeCommandKey_MovementKeys();
TestResult testParseDoubleCodeCommandKey_InvalidKeys();

int main()
{
    enum Constant { NUM_TESTS = 6 };

    TestResult results[NUM_TESTS] = {
        testParseSingleCodeCommandKey_MovementKeys(),
        testParseSingleCodeCommandKey_PauseKeys(),
        testParseSingleCodeCommandKey_EndGameKeys(),
        testParseSingleCodeCommandKey_InvalidKeys(),
        testParseDoubleCodeCommandKey_MovementKeys(),
        testParseDoubleCodeCommandKey_InvalidKeys()
    };

    const char identifier[] = "gameplay.CommandReaderTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testParseSingleCodeCommandKey_MovementKeys()
{
    TestResult testResult = 
        {"testParseSingleCodeCommandKey_MovementKeys", false};

    Boolean parsesMoveUp = 
        (MOVE_UP_COMMAND == parseSingleCodeCommandKey('w')) &&
        (MOVE_UP_COMMAND == parseSingleCodeCommandKey('W'));
    Boolean parsesMoveLeft = 
        (MOVE_LEFT_COMMAND == parseSingleCodeCommandKey('a')) &&
        (MOVE_LEFT_COMMAND == parseSingleCodeCommandKey('A'));
    Boolean parsesMoveDown =
        (MOVE_DOWN_COMMAND == parseSingleCodeCommandKey('s')) &&
        (MOVE_DOWN_COMMAND == parseSingleCodeCommandKey('S'));
    Boolean parsesMoveRight =
        (MOVE_RIGHT_COMMAND == parseSingleCodeCommandKey('d')) &&
        (MOVE_RIGHT_COMMAND == parseSingleCodeCommandKey('D'));

    if (parsesMoveUp && parsesMoveLeft && parsesMoveDown && parsesMoveRight) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testParseSingleCodeCommandKey_PauseKeys()
{
    TestResult testResult = {"testParseSingleCodeCommandKey_PauseKeys", false};

    Boolean parsesPause = 
        (PAUSE_COMMAND == parseSingleCodeCommandKey('p')) &&
        (PAUSE_COMMAND == parseSingleCodeCommandKey('P'));

    if (parsesPause) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testParseSingleCodeCommandKey_EndGameKeys()
{
    TestResult testResult = 
        {"testParseSingleCodeCommandKey_EndGameKeys", false};

    Boolean parsesEndGame =
        (END_GAME_COMMAND == parseSingleCodeCommandKey('q')) &&
        (END_GAME_COMMAND == parseSingleCodeCommandKey('Q'));

    if (parsesEndGame) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testParseSingleCodeCommandKey_InvalidKeys()
{
    TestResult testResult = 
        {"testParseSingleCodeCommandKey_InvalidKeys", false};

    Boolean ignoresInvalidKeys =
        (INVALID_COMMAND == parseSingleCodeCommandKey('/')) &&
        (INVALID_COMMAND == parseSingleCodeCommandKey(0)) &&
        (INVALID_COMMAND == parseSingleCodeCommandKey(-1));

    if (ignoresInvalidKeys) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testParseDoubleCodeCommandKey_MovementKeys()
{
    TestResult testResult = 
        {"testParseDoubleCodeCommandKey_MovementKeys", false};

    Boolean parsesMoveUp = 
        (MOVE_UP_COMMAND == parseDoubleCodeCommandKey(ARROW_UP_KEY));
    Boolean parsesMoveLeft =
        (MOVE_LEFT_COMMAND == parseDoubleCodeCommandKey(ARROW_LEFT_KEY));
    Boolean parsesMoveDown =
        (MOVE_DOWN_COMMAND == parseDoubleCodeCommandKey(ARROW_DOWN_KEY));
    Boolean parsesMoveRight =
        (MOVE_RIGHT_COMMAND == parseDoubleCodeCommandKey(ARROW_RIGHT_KEY));

    if (parsesMoveUp && parsesMoveLeft && parsesMoveDown && parsesMoveRight) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testParseDoubleCodeCommandKey_InvalidKeys()
{
    TestResult testResult = 
        {"testParseDoubleCodeCommandKey_InvalidKeys", false};

    Boolean ignoresInvalidKeys =
        (INVALID_COMMAND == parseDoubleCodeCommandKey(0)) &&
        (INVALID_COMMAND == parseDoubleCodeCommandKey(-1));

    if (ignoresInvalidKeys) {
        testResult.hasPassed = true;
    }

    return testResult;
}
