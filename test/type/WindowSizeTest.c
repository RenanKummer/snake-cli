#include "test/UnitTest.h"
#include "type/WindowSize.h"

TestResult testEqualsWindowSize_Equal();
TestResult testEqualsWindowSize_NotEqual();

int main()
{
    enum Constant { NUM_TESTS = 2 };

    TestResult results[NUM_TESTS] = {
        testEqualsWindowSize_Equal(),
        testEqualsWindowSize_NotEqual()
    };

    const char *identifier = "type.WindowSizeTest";
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
