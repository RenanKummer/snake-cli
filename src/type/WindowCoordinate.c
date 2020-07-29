#include "type/WindowCoordinate.h"

Boolean equalsWindowCoordinate(
    const WindowCoordinate instance1,
    const WindowCoordinate instance2
)
{
    return (instance1.height == instance2.height) && 
        (instance1.width == instance2.width);
}

Boolean equalsWindowSize(
    const WindowSize instance1, 
    const WindowSize instance2
)
{
    return equalsWindowCoordinate(instance1, instance2);
}

Boolean isValidWindowCoordinate(
    const WindowCoordinate coordinate,
    const WindowSize size
)
{
    return isValidWindowSize(size) && 
        ((coordinate.height >= 0) && (coordinate.height < size.height)) &&
        ((coordinate.width >= 0) && (coordinate.width < size.width));
}

Boolean isValidWindowSize(const WindowSize windowSize)
{
    return (windowSize.height > 0) && (windowSize.width);
}
