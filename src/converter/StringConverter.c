#include "converter/StringConverter.h"
#include "util/StringUtils.h"

#include <stdlib.h>

char* convertIntToString(const int number)
{
    int positiveNum = (number >= 0) ? (int) number : (int) number * -1;

    int size = (positiveNum > 0) ? 0 : 1;
    int remainingNum = (int) positiveNum;
    while (remainingNum > 0) {
        remainingNum /= 10;
        size++;
    }

    char *intString = (char*) malloc(sizeof(char) * (size + 1));

    remainingNum = (int) positiveNum;
    for (int i = (size - 1); i >= 0; i--) {
        intString[i] = '0' + (remainingNum % 10);
        remainingNum /= 10;
    }
    intString[size] = '\0';

    if (number >= 0) {
        return intString;
    } else {
        char *negativeIntString = concatenateStrings("-", intString);
        free(intString);

        return negativeIntString;
    }
}
