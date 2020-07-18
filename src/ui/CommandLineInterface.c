#include "type/String.h"
#include "type/WindowSize.h"
#include "ui/CommandLineInterface.h"
#include <windows.h>

WindowCoordinate moveCursor(
    const WindowSize size, 
    const WindowCoordinate coordinate
)
{
    if (isValidWindowSize(size)) {
        WindowCoordinate realCoordinate = {
            coordinate.height % size.height,
            coordinate.width % size.width
        };

        if (isValidWindowCoordinate(size, coordinate)) {
            COORD microsoftWindowsCoordinate = 
                {coordinate.width, coordinate.height};
            
            SetConsoleCursorPosition(
                GetStdHandle(STD_OUTPUT_HANDLE), 
                microsoftWindowsCoordinate
            );
        }

        return realCoordinate;
    }

    WindowCoordinate defaultCoordinate = {0, 0};
    return defaultCoordinate;
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
