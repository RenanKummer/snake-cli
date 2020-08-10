#include "type/WindowCoordinate.h"
#include "ui/CommandLineInterface.h"
#include "util/StringUtils.h"

#include <windows.h>
#include <conio.h>

WindowCoordinate moveCursor(
    const WindowSize size, 
    const WindowCoordinate coordinate
)
{
    COORD microsoftWindowsCoordinate;
    if (isValidWindowCoordinate(coordinate, size)) {
        microsoftWindowsCoordinate.X = coordinate.width;
        microsoftWindowsCoordinate.Y = coordinate.height;
    } else {
        microsoftWindowsCoordinate.X = getDefaultWindowCoordinate().width;
        microsoftWindowsCoordinate.Y = getDefaultWindowCoordinate().height;
    }

    SetConsoleCursorPosition(
        GetStdHandle(STD_OUTPUT_HANDLE), 
        microsoftWindowsCoordinate
    );

    WindowCoordinate finalCoordinate = 
        {microsoftWindowsCoordinate.Y, microsoftWindowsCoordinate.X};
    return finalCoordinate;
}

WindowCoordinate getDefaultWindowCoordinate()
{
    WindowCoordinate defaultWindowCoordinate = {0, 0};
    return defaultWindowCoordinate;
}

void wait(int miliseconds)
{
    if (miliseconds > 0) {
        Sleep(miliseconds);
    }
}

Boolean resizeWindow(const WindowSize windowSize)
{
    if (isValidWindowSize(windowSize)) {
        const char *const heightString = castIntToString(windowSize.height);
        const char *const widthString = castIntToString(windowSize.width);

        char *modeWithHeight = concatenateStrings("mode ", widthString);
        free((void*) widthString);

        char *modeWithComma = concatenateStrings(modeWithHeight, ",");
        free((void*) modeWithHeight);

        const char *const resizeMeasures = 
            concatenateStrings(modeWithComma, heightString);
        free((void*) heightString);
        free((void*) modeWithComma);

        system(resizeMeasures);
        free((void*) resizeMeasures);

        return true;
    }

    return false;
}

void clearWindow()
{
    system("cls");
}

Boolean hasKeyboardHit()
{
    return kbhit();
}

int readKeyboardHitNoEcho()
{
    return getch();
}
