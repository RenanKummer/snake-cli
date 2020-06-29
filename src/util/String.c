#include "util/String.h"

Boolean equalsString(const char *const str1, const char *const str2)
{
    if ((str1 != NULL) && (str2 != NULL)) {
        return strcmp(str1, str2) == 0;
    }

    return (str1 == NULL) && (str2 == NULL);
}
