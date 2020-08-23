#include "constant/LevelMapElement.h"
#include "engine/WindowSize.h"
#include "gameplay/LevelMap.h"
#include "util/UnitTest.h"

TestResult testGetLevelMap_ValidDimensions();
TestResult testGetLevelMap_ValidIdentifier();
TestResult testGetLevelMap_ValidMap();
TestResult testGetLevelMap_ValidStartCoordinate();
TestResult testIsValidLevelMap_Valid();
TestResult testIsValidLevelMap_InvalidIdentifier();
TestResult testIsValidLevelMap_InvalidDimensions();
TestResult testIsValidLevelMap_InvalidSnakeCoordinate();
TestResult testIsValidLevelMap_NullLevelMap();
TestResult testIsValidLevelMap_InvalidLevelMapElement();
TestResult testCopyLevelMap();

int main()
{
    enum Constant { NUM_TESTS = 11 };

    TestResult results[NUM_TESTS] = {
        testGetLevelMap_ValidDimensions(),
        testGetLevelMap_ValidIdentifier(),
        testGetLevelMap_ValidMap(),
        testGetLevelMap_ValidStartCoordinate(),
        testIsValidLevelMap_Valid(),
        testIsValidLevelMap_InvalidIdentifier(),
        testIsValidLevelMap_InvalidDimensions(),
        testIsValidLevelMap_InvalidSnakeCoordinate(),
        testIsValidLevelMap_NullLevelMap(),
        testIsValidLevelMap_InvalidLevelMapElement(),
        testCopyLevelMap()
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

TestResult testGetLevelMap_ValidStartCoordinate()
{
    TestResult testResult = {"testGetLevelMap_ValidStartCoordinate", false};

    LevelMap levelMap = getLevelMap();
    WindowSize levelMapSize = {levelMap.height, levelMap.width};
    
    if (isValidWindowCoordinate(levelMap.snakeCoordinate, levelMapSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidLevelMap_Valid()
{
    TestResult testResult = {"testIsValidLevelMap_Valid", false};

    enum Constant {NUM_ROWS = 10, NUM_COLUMNS = 10};

    char **map = (char**) malloc(sizeof(char*) * NUM_ROWS);
    for (int i = 0; i < NUM_ROWS; i++) {
        map[i] = (char*) malloc(sizeof(char) * NUM_COLUMNS);
        for (int j = 0; j < NUM_COLUMNS; j++) {
            map[i][j] = AVAILABLE_SPACE;
        }
    }

    LevelMap levelMap = {"unit-test", NUM_ROWS, NUM_COLUMNS, map, {1, 1}};
    if (isValidLevelMap(levelMap)) {
        testResult.hasPassed = true;
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        free(map[i]);
    }
    free(map);
    
    return testResult;
}

TestResult testIsValidLevelMap_InvalidIdentifier()
{
    TestResult testResult = {"testIsValidLevelMap_InvalidIdentifier", false};

    enum Constant {NUM_ROWS = 10, NUM_COLUMNS = 10};

    char **map = (char**) malloc(sizeof(char*) * NUM_ROWS);
    for (int i = 0; i < NUM_ROWS; i++) {
        map[i] = (char*) malloc(sizeof(char) * NUM_COLUMNS);
        for (int j = 0; j < NUM_COLUMNS; j++) {
            map[i][j] = AVAILABLE_SPACE;
        }
    }

    LevelMap levelMap = {NULL, NUM_ROWS, NUM_COLUMNS, map, {1, 1}};
    if (isValidLevelMap(levelMap)) {
        testResult.hasPassed = true;
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        free(map[i]);
    }
    free(map);

    return testResult;
}

TestResult testIsValidLevelMap_InvalidDimensions()
{
    TestResult testResult = {"testIsValidLevelMap_InvalidDimensions", false};

    enum Constant {NUM_ROWS = -1, NUM_COLUMNS = 10};

    LevelMap levelMap = {NULL, NUM_ROWS, NUM_COLUMNS, NULL, {1, 1}};
    if (!isValidLevelMap(levelMap)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidLevelMap_InvalidSnakeCoordinate()
{
    TestResult testResult = 
        {"testIsValidLevelMap_InvalidSnakeCoordinate", false};

    enum Constant {NUM_ROWS = 10, NUM_COLUMNS = 10};

    char **map = (char**) malloc(sizeof(char*) * NUM_ROWS);
    for (int i = 0; i < NUM_ROWS; i++) {
        map[i] = (char*) malloc(sizeof(char) * NUM_COLUMNS);
        for (int j = 0; j < NUM_COLUMNS; j++) {
            map[i][j] = AVAILABLE_SPACE;
        }
    }

    LevelMap levelMap = {"unit-test", NUM_ROWS, NUM_COLUMNS, map, {-1, 1}};
    if (!isValidLevelMap(levelMap)) {
        testResult.hasPassed = true;
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        free(map[i]);
    }
    free(map);

    return testResult;
}

TestResult testIsValidLevelMap_NullLevelMap()
{
    TestResult testResult = {"testIsValidLevelMap_NullLevelMap", false};

    enum Constant {NUM_ROWS = 10, NUM_COLUMNS = 10};

    LevelMap levelMap = {"unit-test", NUM_ROWS, NUM_COLUMNS, NULL, {1, 1}};
    if (!isValidLevelMap(levelMap)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidLevelMap_InvalidLevelMapElement()
{
    TestResult testResult = 
        {"testIsValidLevelMap_InvalidLevelMapElement", false};

    enum Constant {NUM_ROWS = 10, NUM_COLUMNS = 10};

    char **map = (char**) malloc(sizeof(char*) * NUM_ROWS);
    for (int i = 0; i < NUM_ROWS; i++) {
        map[i] = (char*) malloc(sizeof(char) * NUM_COLUMNS);
        for (int j = 0; j < NUM_COLUMNS; j++) {
            map[i][j] = AVAILABLE_SPACE;
        }
    }
    map[NUM_ROWS - 1][NUM_COLUMNS - 1] = 'z';

    LevelMap levelMap = {"unit-test", NUM_ROWS, NUM_COLUMNS, map, {1, 1}};
    if (!isValidLevelMap(levelMap)) {
        testResult.hasPassed = true;
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        free(map[i]);
    }
    free(map);

    return testResult;
}

TestResult testCopyLevelMap()
{
    TestResult testResult = {"testCopyLevelMap", true};

    enum Constant {NUM_ROWS = 10, NUM_COLUMNS = 10};

    char **map = (char**) malloc(sizeof(char*) * NUM_ROWS);
    for (int i = 0; i < NUM_ROWS; i++) {
        map[i] = (char*) malloc(sizeof(char) * NUM_COLUMNS);
        for (int j = 0; j < NUM_COLUMNS; j++) {
            map[i][j] = AVAILABLE_SPACE;
        }
    }
    
    LevelMap levelMap = {"unit-test", NUM_ROWS, NUM_COLUMNS, map, {1, 1}};
    LevelMap levelMapCopy = copyLevelMap(levelMap);

    if (!equalsString(levelMap.identifier, levelMapCopy.identifier)) {
        testResult.hasPassed = false;
    } else if ((levelMap.height != levelMapCopy.height) ||
        (levelMap.width != levelMapCopy.width)) {
        testResult.hasPassed = false;
    } else if (!equalsWindowCoordinate(
        levelMap.snakeCoordinate, 
        levelMapCopy.snakeCoordinate
    )) {
        testResult.hasPassed = false;
    } else if ((levelMap.height > 0) && (levelMap.width)) {
        for (int i = 0; i < levelMap.height; i++) {
            for (int j = 0; j < levelMap.width; j++) {
                if (levelMap.map[i][j] != levelMapCopy.map[i][j]) {
                    testResult.hasPassed = false;
                }
            }
        }
    }

    for (int i = 0; i < NUM_ROWS; i++) {
        free(map[i]);
    }
    free(map);

    return testResult;
}
