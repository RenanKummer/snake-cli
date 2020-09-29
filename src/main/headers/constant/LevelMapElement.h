#ifndef SRC_MAIN_HEADERS_CONSTANT_LEVELMAPELEMENT_H
#define SRC_MAIN_HEADERS_CONSTANT_LEVELMAPELEMENT_H
/**
 * Enumeration type for level map's individual elements.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */

typedef enum LevelMapElement
{
    AVAILABLE_SPACE = ' ',
    START_POSITION  = 'O',
    
    WALL = '#',
    ROCK = '*',

    MOUSE = '&',
    APPLE = '@'
} LevelMapElement;

#endif // SRC_MAIN_HEADERS_CONSTANT_LEVELMAPELEMENT_H
