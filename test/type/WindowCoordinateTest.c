#include "test/UnitTest.h"
#include "type/WindowCoordinate.h"

TestResult testEqualsWindowCoordinate_Equal();
TestResult testEqualsWindowCoordinate_NotEqual();
TestResult testEqualsWindowSize_Equal();
TestResult testEqualsWindowSize_NotEqual();

int main()
{
    enum Constant { NUM_TESTS = 4 };

    TestResult results[NUM_TESTS] = {
        testEqualsWindowSize_Equal(),
        testEqualsWindowSize_NotEqual(),
        testEqualsWindowCoordinate_Equal(),
        testEqualsWindowCoordinate_NotEqual()
    };

    const char *identifier = "type.WindowCoordinateTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testEqualsWindowCoordinate_Equal()
{
    TestResult testResult = {"testEqualsWindowSize_Equal", false};

    WindowCoordinate windowCoordinate1 = {30, 100};
    WindowCoordinate windowCoordinate2 = {30, 100};

    if (equalsWindowCoordinate(windowCoordinate1, windowCoordinate2)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testEqualsWindowCoordinate_NotEqual()
{
    TestResult testResult = {"testEqualsWindowSize_NotEqual", false};

    WindowCoordinate windowCoordinate1 = {30, 100};
    WindowCoordinate windowCoordinate2 = {100, 30};

    if (!equalsWindowCoordinate(windowCoordinate1, windowCoordinate2)) {
        testResult.hasPassed = true;
    }   

    return testResult;
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
