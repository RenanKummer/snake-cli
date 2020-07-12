#ifndef INCLUDE_TEST_UNITTEST_H
#define INCLUDE_TEST_UNITTEST_H
/**
 * Functions, structures and common includes to support unit testing.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "type/Boolean.h"

#include <stdlib.h>
#include <stdio.h>

typedef struct TestResult
{
    const char *testName;
    Boolean hasPassed;
} TestResult;

int printTestResults(
    const char *const identifier,
    const TestResult *const results,
    const unsigned resultsSize
);

#endif // INCLUDE_TEST_UNITTEST_H
