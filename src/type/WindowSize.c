#include "type/WindowSize.h"

Boolean equalsWindowSize(const WindowSize val1, const WindowSize val2)
{
    return (val1.height == val2.height) && (val1.width == val2.width);
}

Boolean isValidWindowSize(const WindowSize windowSize)
{
    return (windowSize.height > 0) && (windowSize.width);
}

Boolean isValidWindowCoordinate(
    const WindowSize size, 
    const WindowCoordinate coordinate
)
{
    return isValidWindowSize(size) && 
        ((coordinate.height >= 0) && (coordinate.height < size.height)) &&
        ((coordinate.width >= 0) && (coordinate.width < size.width));
}
