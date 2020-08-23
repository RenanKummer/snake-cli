#include "gameplay/CommandRunner.h"
#include "util/UnitTest.h"

TestResult testMoveSnakeUp_Move();
TestResult testMoveSnakeUp_NullMap();
TestResult testMoveSnakeLeft_Move();
TestResult testMoveSnakeLeft_NullMap();
TestResult testMoveSnakeDown_Move();
TestResult testMoveSnakeDown_NullMap();
TestResult testMoveSnakeRight_Move();
TestResult testMoveSnakeRight_NullMap();

int main()
{
    enum Constant {NUM_TESTS = 8};

    TestResult results[NUM_TESTS] = {
        testMoveSnakeUp_Move(),
        testMoveSnakeUp_NullMap(),
        testMoveSnakeLeft_Move(),
        testMoveSnakeLeft_NullMap(),
        testMoveSnakeDown_Move(),
        testMoveSnakeDown_NullMap(),
        testMoveSnakeRight_Move(),
        testMoveSnakeRight_NullMap()
    };

    const char identifier[] = "gameplay.CommandRunnerTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testMoveSnakeUp_Move()
{
    TestResult testResult = {"testMoveSnakeUp_Move", false};

    LevelMap levelMap = getLevelMap();
    WindowCoordinate newCoordinate = levelMap.snakeCoordinate;
    newCoordinate.height--;

    moveSnakeUp(&levelMap);

    if (equalsWindowCoordinate(levelMap.snakeCoordinate, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testMoveSnakeUp_NullMap()
{
    TestResult testResult = {"testMoveSnakeUp_NullMap", false};

    moveSnakeUp(NULL);
    testResult.hasPassed = true;

    return testResult;
}

TestResult testMoveSnakeLeft_Move()
{
    TestResult testResult = {"testMoveSnakeLeft_Move", false};

    LevelMap levelMap = getLevelMap();
    WindowCoordinate newCoordinate = levelMap.snakeCoordinate;
    newCoordinate.width--;

    moveSnakeLeft(&levelMap);

    if (equalsWindowCoordinate(levelMap.snakeCoordinate, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testMoveSnakeLeft_NullMap()
{
    TestResult testResult = {"testMoveSnakeLeft_NullMap", false};

    moveSnakeLeft(NULL);
    testResult.hasPassed = true;

    return testResult;
}

TestResult testMoveSnakeDown_Move()
{
    TestResult testResult = {"testMoveSnakeDown_Move", false};

    LevelMap levelMap = getLevelMap();
    WindowCoordinate newCoordinate = levelMap.snakeCoordinate;
    newCoordinate.height++;

    moveSnakeDown(&levelMap);

    if (equalsWindowCoordinate(levelMap.snakeCoordinate, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testMoveSnakeDown_NullMap()
{
    TestResult testResult = {"testMoveSnakeDown_NullMap", false};

    moveSnakeDown(NULL);
    testResult.hasPassed = true;

    return testResult;
}

TestResult testMoveSnakeRight_Move()
{
    TestResult testResult = {"testMoveSnakeRight_Move", false};

    LevelMap levelMap = getLevelMap();
    WindowCoordinate newCoordinate = levelMap.snakeCoordinate;
    newCoordinate.width++;

    moveSnakeRight(&levelMap);

    if (equalsWindowCoordinate(levelMap.snakeCoordinate, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testMoveSnakeRight_NullMap()
{
    TestResult testResult = {"testMoveSnakeRight_NullMap", false};

    moveSnakeRight(NULL);
    testResult.hasPassed = true;

    return testResult;
}
