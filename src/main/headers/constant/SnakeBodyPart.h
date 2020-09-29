#ifndef SRC_MAIN_HEADERS_CONSTANT_SNAKEBODYPART_H
#define SRC_MAIN_HEADERS_CONSTANT_SNAKEBODYPART_H
/**
 * Enumeration type for snake body parts.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */

typedef enum SnakeBodyPart
{
    HEAD_UP    = '^',
    HEAD_LEFT  = '<',
    HEAD_RIGHT = '>',
    HEAD_DOWN  = 'v',

    BODY_VERTICAL   = '|',
    BODY_HORIZONTAL = '-'
} SnakeBodyPart;

#endif // SRC_MAIN_HEADERS_CONSTANT_SNAKEBODYPART_H
