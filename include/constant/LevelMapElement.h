#ifndef INCLUDE_CONSTANT_LEVELMAPELEMENT_H
#define INCLUDE_CONSTANT_LEVELMAPELEMENT_H
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

#endif // INCLUDE_CONSTANT_LEVELMAPELEMENT_H
