#ifndef INCLUDE_UTIL_STRINGUTILS_H
#define INCLUDE_UTIL_STRINGUTILS_H
/**
 * Extends features from C Standard Library's string.h header file.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/Boolean.h"

#include <string.h>

/**
 * Compare if two strings are equal.
 * 
 * @param str1 The string to compare.
 * @param str2 The string to compare.
 * 
 * @return true if equal, false otherwise.
 */
Boolean equalsString(const char *const str1, const char *const str2);

/**
 * Check if string is empty or null.
 * 
 * @param str The string to check if empty.
 * 
 * @return true if empty or null, false otherwise.
 */
Boolean isEmptyString(const char *const str);

/**
 * Concatenate two strings as a new string instance.
 * 
 * @param startString The string that comes first.
 * @param endString   The string to append at the end.
 * 
 * @return Concatenated string.
 */
char* concatenateStrings(
    const char *const startString, 
    const char *const endString
);

#endif // INCLUDE_UTIL_STRINGUTILS_H
