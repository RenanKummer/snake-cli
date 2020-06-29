#include "util/String.h"
#include "util/UnitTest.h"

TestResult testEqualsString_Equal();
TestResult testEqualsString_NotEqual();

int main()
{
    enum Constant { NUM_TESTS = 2 };

    TestResult results[NUM_TESTS] = {
        testEqualsString_Equal(),
        testEqualsString_NotEqual()
    };

    const char *const identifier = "util.StringTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testEqualsString_Equal()
{
    TestResult testResult = {"testEqualsString_Equal", false};

    if (equalsString("string", "string")) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testEqualsString_NotEqual()
{
    TestResult testResult = {"testEqualsString_NotEqual", false};

    if (!equalsString("String", "string")) {
        testResult.hasPassed = true;
    }

    return testResult;
}
