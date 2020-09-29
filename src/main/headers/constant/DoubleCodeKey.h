#ifndef SRC_MAIN_HEADERS_CONSTANT_DOUBLECODEKEY_H
#define SRC_MAIN_HEADERS_CONSTANT_DOUBLECODEKEY_H
/**
 * Enumeration type for double code keys. These values identify keys that
 * are not part of the ASCII table.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */

typedef enum DoubleCodeKey
{
    DOUBLE_CODE_KEY = 224,

    ARROW_UP_KEY    = 72,
    ARROW_LEFT_KEY  = 75,
    ARROW_DOWN_KEY  = 80,
    ARROW_RIGHT_KEY = 77
} DoubleCodeKey;

#endif // SRC_MAIN_HEADERS_CONSTANT_DOUBLECODEKEY_H
