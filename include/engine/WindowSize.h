#ifndef INCLUDE_ENGINE_WINDOWSIZE_H
#define INCLUDE_ENGINE_WINDOWSIZE_H
/**
 * Structure defining the dimensions of the Command Line Interface window.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include "constant/Boolean.h"

typedef struct WindowSize
{
    const int height;
    const int width;
} WindowSize;

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
 * Validate WindowSize instance. Both dimensions, height and width, must be positive.
 * 
 * @param windowSize The instance to validate.
 * 
 * @return true if valid, false otherwise.
 */
Boolean isValidWindowSize(const WindowSize windowSize);

#endif // INCLUDE_ENGINE_WINDOWSIZE_H
