#include "util/StringUtils.h"
#include "util/UnitTest.h"

TestResult testEqualsString_Equal();
TestResult testEqualsString_NotEqual();
TestResult testEqualsString_NullAndValid();
TestResult testEqualsString_BothNull();
TestResult testConcatenateStrings_BothValid();
TestResult testConcatenateStrings_NullAndValid();
TestResult testConcatenateStrings_ValidAndNull();
TestResult testConcatenateStrings_BothNull();
TestResult testConcatenateStrings_Modifiable();
TestResult testCastIntToString_PositiveRightZeros();
TestResult testCastIntToString_PositiveMiddleZeros();
TestResult testCastIntToString_PositiveNoZeros();
TestResult testCastIntToString_Zero();
TestResult testCastIntToString_Negative();

int main()
{
    enum Constant { NUM_TESTS = 14 };

    TestResult results[NUM_TESTS] = {
        testEqualsString_Equal(),
        testEqualsString_NotEqual(),
        testEqualsString_NullAndValid(),
        testEqualsString_BothNull(),
        testConcatenateStrings_BothValid(),
        testConcatenateStrings_NullAndValid(),
        testConcatenateStrings_ValidAndNull(),
        testConcatenateStrings_BothNull(),
        testConcatenateStrings_Modifiable(),
        testCastIntToString_PositiveRightZeros(),
        testCastIntToString_PositiveMiddleZeros(),
        testCastIntToString_PositiveNoZeros(),
        testCastIntToString_Zero(),
        testCastIntToString_Negative()
    };

    const char *const identifier = "type.StringTest";
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

TestResult testEqualsString_NullAndValid()
{
    TestResult testResult = {"testEqualsString_NullAndValid", false};

    if (!equalsString(NULL, "string")) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testEqualsString_BothNull()
{
    TestResult testResult = {"testEqualsString_NullAndValid", false};

    if (equalsString(NULL, NULL)) {
        testResult.hasPassed = true;
    }

    return testResult;  
}

TestResult testConcatenateStrings_BothValid()
{
    TestResult testResult = {"testConcatenateStrings_BothValid", false};

    const char *const string1 = "str1-";
    const char *const string2 = "str2";
    const char *const expectedString = "str1-str2";

    const char *const actualString = concatenateStrings(string1, string2);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConcatenateStrings_NullAndValid()
{
    TestResult testResult = {"testConcatenateStrings_NullAndValid", false};

    const char *const string1 = NULL;
    const char *const string2 = "str2";
    const char *const expectedString = "str2";

    const char *const actualString = concatenateStrings(string1, string2);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConcatenateStrings_ValidAndNull()
{
    TestResult testResult = {"testConcatenateStrings_ValidAndNull", false};

    const char *const string1 = "str1-";
    const char *const string2 = NULL;
    const char *const expectedString = "str1-";

    const char *const actualString = concatenateStrings(string1, string2);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConcatenateStrings_BothNull()
{
    TestResult testResult = {"testConcatenateStrings_BothNull", false};

    const char *const string1 = NULL;
    const char *const string2 = NULL;
    const char *const expectedString = NULL;

    const char *const actualString = concatenateStrings(string1, string2);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testConcatenateStrings_Modifiable()
{
    TestResult testResult = {"testConcatenateStrings_Modifiable", false};

    char *const string = concatenateStrings("str1-", "str2");
    string[0] = 'S';

    const char *const expectedString = "Str1-str2";

    if (equalsString(string, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testCastIntToString_PositiveRightZeros()
{
    TestResult testResult = 
        {"testCastIntToString_PositiveRightZeros", false};

    char *expectedString = "32100";
    char *actualString = castIntToString(32100);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testCastIntToString_PositiveMiddleZeros()
{
    TestResult testResult = 
        {"testCastIntToString_PositiveMiddleZeros", false};

    char *expectedString = "32001";
    char *actualString = castIntToString(32001);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testCastIntToString_PositiveNoZeros()
{
    TestResult testResult = 
        {"testCastIntToString_PositiveNoZeros", false};

    char *expectedString = "54321";
    char *actualString = castIntToString(54321);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testCastIntToString_Zero()
{
    TestResult testResult = {"testCastIntToString_Zero", false};

    char *expectedString = "0";
    char *actualString = castIntToString(0);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}

TestResult testCastIntToString_Negative()
{
    TestResult testResult = {"testCastIntToString_Negative", false};

    char *expectedString = "-54321";
    char *actualString = castIntToString(-54321);

    if (equalsString(actualString, expectedString)) {
        testResult.hasPassed = true;
    }

    return testResult;
}
