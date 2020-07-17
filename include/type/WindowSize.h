#ifndef INCLUDE_TYPE_WINDOWSIZE_H
#define INCLUDE_TYPE_WINDOWSIZE_H
/**
 * Structure defining the size of the Command Line Interface window.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "Boolean.h"

typedef struct WindowSize
{
    const int height;
    const int width;
} WindowSize, WindowCoordinate;

Boolean equalsWindowSize(const WindowSize val1, const WindowSize val2);
Boolean isValidWindowSize(const WindowSize windowSize);
Boolean isValidWindowCoordinate(
    const WindowSize size, 
    const WindowCoordinate coordinate
);

#endif // INCLUDE_TYPE_WINDOWSIZE_H
