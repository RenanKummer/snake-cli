#include "engine/WindowCoordinate.h"
#include "util/UnitTest.h"

TestResult testEqualsWindowCoordinate_Equal();
TestResult testEqualsWindowCoordinate_NotEqual();
TestResult testIsValidWindowCoordinate_Valid();
TestResult testIsValidWindowCoordinate_InvalidSize();
TestResult testIsValidWindowCoordinate_NegativeCoordinate();
TestResult testIsValidWindowCoordinate_OutOfRange();

int main()
{
    enum Constant { NUM_TESTS = 6 };

    TestResult results[NUM_TESTS] = {
        testEqualsWindowCoordinate_Equal(),
        testEqualsWindowCoordinate_NotEqual(),
        testIsValidWindowCoordinate_Valid(),
        testIsValidWindowCoordinate_InvalidSize(),
        testIsValidWindowCoordinate_NegativeCoordinate(),
        testIsValidWindowCoordinate_OutOfRange()
    };

    const char *identifier = "engine.WindowCoordinateTest";
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

TestResult testIsValidWindowCoordinate_Valid()
{
    TestResult testResult = {"testIsValidWindowCoordinate_Valid", false};

    WindowCoordinate windowCoordinate = {0, 0};
    WindowSize windowSize = {1, 1};

    if (isValidWindowCoordinate(windowCoordinate, windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidWindowCoordinate_InvalidSize()
{
    TestResult testResult = {"testIsValidWindowCoordinate_InvalidSize", false};

    WindowCoordinate windowCoordinate = {0, 0};
    WindowSize windowSize = {0, 0};

    if (!isValidWindowCoordinate(windowCoordinate, windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidWindowCoordinate_NegativeCoordinate()
{
    TestResult testResult = 
        {"testIsValidWindowCoordinate_NegativeCoordinate", false};

    WindowCoordinate windowCoordinate = {0, -1};
    WindowSize windowSize = {1, 1};

    if (!isValidWindowCoordinate(windowCoordinate, windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testIsValidWindowCoordinate_OutOfRange()
{
    TestResult testResult = {"testIsValidWindowCoordinate_OutOfRange", false};

    WindowCoordinate windowCoordinate = {1, 1};
    WindowSize windowSize = {1, 1};

    if (!isValidWindowCoordinate(windowCoordinate, windowSize)) {
        testResult.hasPassed = true;
    }

    return testResult;
}
