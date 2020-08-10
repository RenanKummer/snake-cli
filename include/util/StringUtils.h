#ifndef INCLUDE_UTIL_STRINGUTILS_H
#define INCLUDE_UTIL_STRINGUTILS_H
/**
 * Extends features from C Standard Library's string.h header file.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "type/Boolean.h"
#include <string.h>

Boolean equalsString(const char *const str1, const char *const str2);

char* concatenateStrings(const char *const str1, const char *const str2);

char* castIntToString(const int number);

#endif // INCLUDE_UTIL_STRINGUTILS_H
