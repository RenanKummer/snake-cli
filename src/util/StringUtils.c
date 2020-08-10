#include "util/StringUtils.h"

#include <stdlib.h>

Boolean equalsString(const char *const str1, const char *const str2)
{
    if ((str1 != NULL) && (str2 != NULL)) {
        return strcmp(str1, str2) == 0;
    }

    return (str1 == NULL) && (str2 == NULL);
}

char* concatenateStrings(const char *const str1, const char *const str2)
{
    char *concatenatedString = NULL;

    if ((str1 != NULL) && (str2 != NULL)) {
        int totalSize = strlen(str1) + strlen(str2) + 1;

        concatenatedString = (char*) malloc(sizeof(char) * totalSize);
        concatenatedString[0] = '\0';

        if (concatenatedString != NULL) {
            strcat(concatenatedString, str1);
            concatenatedString[strlen(str1)] = '\0';
            strcat(concatenatedString, str2);
            concatenatedString[totalSize - 1] = '\0';
        }
    } else if (str1 != NULL) {
        int totalSize = strlen(str1) + 1;
        
        concatenatedString = (char*) malloc(sizeof(char) * totalSize);
        strcpy(concatenatedString, str1);
        concatenatedString[totalSize - 1] = '\0';
    } else if (str2 != NULL) {
        int totalSize = strlen(str2) + 1;

        concatenatedString = (char*) malloc(sizeof(char) * totalSize);
        strcpy(concatenatedString, str2);
        concatenatedString[totalSize - 1] = '\0';
    }

    return concatenatedString;
}

char* castIntToString(const int number)
{
    int positiveNum = (number > 0) ? (int) number : (int) number * -1;

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
