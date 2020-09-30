#ifndef SRC_MAIN_HEADERS_ENGINE_WINDOWCOORDINATE_H
#define SRC_MAIN_HEADERS_ENGINE_WINDOWCOORDINATE_H
/**
 * Structure defining the coordinates of the Command Line Interface window.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/Boolean.h"
#include "engine/WindowSize.h"

typedef struct WindowCoordinate
{
    int height;
    int width;
} WindowCoordinate;

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


#endif // SRC_MAIN_HEADERS_ENGINE_WINDOWCOORDINATE_H
