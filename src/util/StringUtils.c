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
