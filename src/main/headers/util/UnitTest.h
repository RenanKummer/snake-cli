#ifndef SRC_MAIN_HEADERS_UTIL_UNITTEST_H
#define SRC_MAIN_HEADERS_UTIL_UNITTEST_H
/**
 * Functions, structures and common includes to support unit testing.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/Boolean.h"
#include "util/StringUtils.h"

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

#endif // SRC_MAIN_HEADERS_UTIL_UNITTEST_H
