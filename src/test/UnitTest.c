#include "test/UnitTest.h"

#include <string.h>

int printTestResults(
    const char *const identifier,
    const TestResult *const results,
    const unsigned resultsSize
)
{
    const Boolean hasIdentifier = 
        (identifier != NULL) && (strcmp(identifier, "") != 0);

    const char *const suiteName = hasIdentifier ? identifier : "Test Results";
    printf(":%s\n", suiteName);
    
    Boolean hasPassed = true;
    if ((results != NULL) && (resultsSize > 0)) {
        int numPassed = 0;
        for (int i = 0; i < resultsSize; i++) {
            numPassed += (results[i].hasPassed) ? 1 : 0;
        }

        printf("%d/%d tests have passed.\n", numPassed, resultsSize);
        if (numPassed != resultsSize) {
            printf("\n");
        }

        for (int i = 0; i < resultsSize; i++) {
            if (!results[i].hasPassed) {
                printf("    [Fail] %s\n", results[i].testName);
                hasPassed = false;
            }
        }
        printf("\n");
    } else {
        printf("No tests.\n\n");
    }

    if (hasPassed) {
        return EXIT_SUCCESS;
    } else {
        return EXIT_FAILURE;
    }
}
