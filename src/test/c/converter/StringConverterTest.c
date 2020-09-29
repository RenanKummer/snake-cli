#include "converter/StringConverter.h"
#include "util/UnitTest.h"

TestResult testConvertIntToString_PositiveRightZeros();
TestResult testConvertIntToString_PositiveMiddleZeros();
TestResult testConvertIntToString_PositiveNoZeros();
TestResult testConvertIntToString_Zero();
TestResult testConvertIntToString_Negative();

int main()
{
    enum Constant { NUM_TESTS = 5 };

    TestResult results[NUM_TESTS] = {
        testConvertIntToString_PositiveRightZeros(),
        testConvertIntToString_PositiveMiddleZeros(),
        testConvertIntToString_PositiveNoZeros(),
        testConvertIntToString_Zero(),
        testConvertIntToString_Negative()
    };

    const char *const identifier = "converter.StringConverterTest";
    return printTestResults(identifier, results, NUM_TESTS);
}

TestResult testConvertIntToString_PositiveRightZeros()
{
    TestResult testResult = 
        {"testConvertIntToString_PositiveRightZeros", false};

    char *expectedString = "32100";
    char *actualString = convertIntToString(32100);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConvertIntToString_PositiveMiddleZeros()
{
    TestResult testResult = 
        {"testConvertIntToString_PositiveMiddleZeros", false};

    char *expectedString = "32001";
    char *actualString = convertIntToString(32001);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConvertIntToString_PositiveNoZeros()
{
    TestResult testResult = 
        {"testConvertIntToString_PositiveNoZeros", false};

    char *expectedString = "54321";
    char *actualString = convertIntToString(54321);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConvertIntToString_Zero()
{
    TestResult testResult = {"testConvertIntToString_Zero", false};

    char *expectedString = "0";
    char *actualString = convertIntToString(0);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConvertIntToString_Negative()
{
    TestResult testResult = {"testConvertIntToString_Negative", false};

    char *expectedString = "-54321";
    char *actualString = convertIntToString(-54321);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}
