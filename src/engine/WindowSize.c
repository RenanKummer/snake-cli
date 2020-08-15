#include "engine/WindowSize.h"

Boolean equalsWindowSize(
    const WindowSize instance1, 
    const WindowSize instance2
)
{
    return (instance1.height == instance2.height) &&
        (instance1.width == instance2.width);
}

Boolean isValidWindowSize(const WindowSize windowSize)
{
    return (windowSize.height > 0) && (windowSize.width > 0);
}
