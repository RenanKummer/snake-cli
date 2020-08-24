#include "gameplay/CommandRunner.h"
#include "util/UnitTest.h"

TestResult testHitsWall_Hit();
TestResult testHitsWall_DoesNotHit();
TestResult testHitsWall_InvalidLevelMap();
TestResult testHitsWall_InvalidCoordinate();

int main()
{
    enum Constant {NUM_TESTS = 4};

    TestResult results[NUM_TESTS] = {
        testHitsWall_Hit(),
        testHitsWall_DoesNotHit(),
        testHitsWall_InvalidLevelMap(),
        testHitsWall_InvalidCoordinate()
    };

    const char identifier[] = "gameplay.CommandRunnerTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testHitsWall_Hit()
{
    TestResult testResult = {"testHitsWall_Hit", false};

    LevelMap levelMap = getLevelMap();
    LevelMapCoordinate newCoordinate = {0, 0};

    if (hitsWall(levelMap, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testHitsWall_DoesNotHit()
{
    TestResult testResult = {"testHitsWall_DoesNotHit", false};

    LevelMap levelMap = getLevelMap();
    LevelMapCoordinate newCoordinate = {1, 1};

    if (!hitsWall(levelMap, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testHitsWall_InvalidLevelMap()
{
    TestResult testResult = {"testHitsWall_InvalidLevelMap", false};

    LevelMap levelMap = getLevelMap();
    levelMap.map[0][0] = 'z';
    LevelMapCoordinate newCoordinate = {0, 0};

    if (!hitsWall(levelMap, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testHitsWall_InvalidCoordinate()
{
    TestResult testResult = {"testHitsWall_InvalidCoordinate", false};

    LevelMap levelMap = getLevelMap();
    LevelMapCoordinate newCoordinate = {levelMap.height, levelMap.width};

    if (!hitsWall(levelMap, newCoordinate)) {
        testResult.hasPassed = true;
    }

    return testResult;
}
