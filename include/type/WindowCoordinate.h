#ifndef INCLUDE_TYPE_WINDOWCOORDINATE_H
#define INCLUDE_TYPE_WINDOWCOORDINATE_H
/**
 * Structure defining the coordinates of the Command Line Interface window.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "Boolean.h"

typedef struct WindowCoordinate
{
    const int height;
    const int width;
} WindowCoordinate, WindowSize;

/**
 * Compare if two instances of WindowCoordinate are equal.
 * 
 * @param instance1 The WindowCoordinate instance to compare.
 * @param instance2 The WindowCoordinate instance to compare.
 * 
 * @return true if equal, false otherwise.
 */
Boolean equalsWindowCoordinate(
    const WindowCoordinate instance1,
    const WindowCoordinate instance2
);

/**
 * Compare if two instances of WindowSize are equal.
 * 
 * @param instance1 The WindowSize instance to compare.
 * @param instance2 The WindowSize instance to compare.
 * 
 * @return true if equal, false otherwise.
 */
Boolean equalsWindowSize(
    const WindowSize instance1, 
    const WindowSize instance2
);

/**
 * Validate WindowCoordinate instance for a given command line window size.
 * 
 * Assuming a valid size as {H, W}:
 *   - Coordinate's height must be >= 0 and < H.
 *   - Coordinate's width must be >= 0 and < W.
 * 
 * @param coordinate The instance to validate.
 * @param size       The command line window size.
 * 
 * @return true if valid, false otherwise.
 */
Boolean isValidWindowCoordinate(
    const WindowCoordinate coordinate,
    const WindowSize size 
);

/**
 * Validate WindowSize instance.
 * 
 * Both dimensions, height and width, must be positive.
 * 
 * @param windowSize The instance to validate.
 * 
 * @return true if valid, false otherwise.
 */
Boolean isValidWindowSize(const WindowSize windowSize);

#endif // INCLUDE_TYPE_WINDOWCOORDINATE_H
