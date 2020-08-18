#include "constant/LevelMapElement.h"
#include "engine/WindowSize.h"
#include "gameplay/LevelMap.h"
#include "util/UnitTest.h"

TestResult testGetLevelMap_ValidDimensions();
TestResult testGetLevelMap_ValidIdentifier();
TestResult testGetLevelMap_ValidMap();

int main()
{
    enum Constant { NUM_TESTS = 3 };

    TestResult results[NUM_TESTS] = {
        testGetLevelMap_ValidDimensions(),
        testGetLevelMap_ValidIdentifier(),
        testGetLevelMap_ValidMap()
    };

    const char identifier[] = "gameplay.LevelMapTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testGetLevelMap_ValidDimensions()
{
    TestResult testResult = {"testGetLevelMap_ValidDimensions", false};

    LevelMap levelMap = getLevelMap();
    if ((levelMap.height > 0) && (levelMap.width > 0)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testGetLevelMap_ValidIdentifier()
{
    TestResult testResult = {"testGetLevelMap_ValidIdentifier", false};

    LevelMap levelMap = getLevelMap();
    if (!isEmptyString(levelMap.identifier)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testGetLevelMap_ValidMap()
{
    TestResult testResult = {"testGetLevelMap_ValidMap", true};

    LevelMap levelMap = getLevelMap();

    for (int i = 0; i < levelMap.height; i++) {
        for (int j = 0; j < levelMap.width; j++) {
            Boolean isInvalidCharacter = 
                (levelMap.map[i][j] != AVAILABLE_SPACE) &&
                (levelMap.map[i][j] != START_POSITION) &&
                (levelMap.map[i][j] != WALL) &&
                (levelMap.map[i][j] != ROCK);

            if (isInvalidCharacter) {
                testResult.hasPassed = false;
            }
        }
    }

    return testResult;
}