#include "converter/StringConverter.h"
#include "engine/CommandLineInterface.h"
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
        const char *const heightString = convertIntToString(windowSize.height);
        const char *const widthString = convertIntToString(windowSize.width);

        char *modeWithWidth = concatenateStrings("mode ", widthString);
        free((void*) widthString);

        char *modeWithComma = concatenateStrings(modeWithWidth, ",");
        free((void*) modeWithWidth);

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

void hideCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    cursorInfo.bVisible = false;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

void showCursor()
{
    CONSOLE_CURSOR_INFO cursorInfo;
    
    GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);

    cursorInfo.bVisible = true;
    SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursorInfo);
}

Boolean hasKeyboardHit()
{
    return kbhit();
}

int readKeyboardHitNoEcho()
{
    return getch();
}
