#include "engine/WindowSize.h"
#include "util/UnitTest.h"

TestResult testEqualsWindowSize_Equal();
TestResult testEqualsWindowSize_NotEqual();
TestResult testIsValidWindowSize_Valid();
TestResult testIsValidWindowSize_ZeroDimension();
TestResult testIsValidWindowSize_NegativeDimension();

int main()
{
    enum Constant { NUM_TESTS = 5 };

    TestResult results[NUM_TESTS] = {
        testEqualsWindowSize_Equal(),
        testEqualsWindowSize_NotEqual(),
        testIsValidWindowSize_Valid(),
        testIsValidWindowSize_ZeroDimension(),
        testIsValidWindowSize_NegativeDimension()
    };

    const char *identifier = "engine.WindowSizeTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testEqualsWindowSize_Equal()
{
    TestResult testResult = {"testEqualsWindowSize_Equal", false};

    WindowSize windowSize1 = {30, 100};
    WindowSize windowSize2 = {30, 100};

    if (equalsWindowSize(windowSize1, windowSize2)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testEqualsWindowSize_NotEqual()
{
    TestResult testResult = {"testEqualsWindowSize_NotEqual", false};

    WindowSize windowSize1 = {30, 100};
    WindowSize windowSize2 = {100, 30};

    if (!equalsWindowSize(windowSize1, windowSize2)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidWindowSize_Valid()
{
    TestResult testResult = {"testIsValidWindowSize_Valid", false};

    WindowSize windowSize = {1, 1};

    if (isValidWindowSize(windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidWindowSize_ZeroDimension()
{
    TestResult testResult = {"testIsValidWindowSize_ZeroDimension", false};

    WindowSize windowSize = {1, 0};
    
    if (!isValidWindowSize(windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidWindowSize_NegativeDimension()
{
    TestResult testResult = {"testIsValidWindowSize_NegativeDimension", false};

    WindowSize windowSize = {-1, 1};
    
    if (!isValidWindowSize(windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}
