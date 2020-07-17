#include "type/Boolean.h"
#include "type/WindowSize.h"
#include "ui/CommandLineInterface.h"
#include <windows.h>
#include <stdio.h>
/**
 * This is a manual unit test application.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */

typedef enum Option
{
    MOVE_CURSOR   = 1,
    RESIZE_WINDOW = 2,
    CLEAR_WINDOW  = 3
} Option;

void printOptions();
Option readOption();

Boolean isMoveCursorOption(Option option);
Boolean isResizeWindowOption(Option option);
Boolean isClearWindowOption(Option option);
void runMoveCursor();
void runResizeWindow();
void runClearWindow();

int main()
{
    while (true) {
        printOptions();
        Option option = readOption();

        if (isMoveCursorOption(option)) {
            runMoveCursor();
        } else if (isResizeWindowOption(option)) {
            runResizeWindow();
        } else if (isClearWindowOption(option)) {
            runClearWindow();
        }
    }    
}

void printOptions()
{
    printf(
        "Test CommandLineInterface\n"
        "  %2d: moveCursor()\n"
        "  %2d: resizeWindow()\n"
        "  %2d: clearWindow()\n"
        "\n",
        MOVE_CURSOR,
        RESIZE_WINDOW, 
        CLEAR_WINDOW
    );
}

Option readOption()
{
    Option option;
    printf("Your option: ");
    scanf("%d", &option);
    printf("\n");

    return option;
}

Boolean isMoveCursorOption(Option option)
{
    return option == MOVE_CURSOR;
}

Boolean isResizeWindowOption(Option option)
{
    return option == RESIZE_WINDOW;
}

Boolean isClearWindowOption(Option option)
{
    return option == CLEAR_WINDOW;
}

void runMoveCursor()
{
    int height;
    printf("  Window height: ");
    scanf("%d", &height);

    int width;
    printf("  Window width: ");
    scanf("%d", &width);

    WindowSize windowSize = {height, width};
    resizeWindow(windowSize);

    int moveToHeight;
    printf("  Move to height: ");
    scanf("%d", &moveToHeight);

    int moveToWidth;
    printf("  Move to width: ");
    scanf("%d", &moveToWidth);

    clearWindow();
    WindowCoordinate coordinate = {moveToHeight, moveToWidth};
    moveCursor(windowSize, coordinate);

    printf("X");
    WindowCoordinate firstCoordinate = {0, 0};
    moveCursor(windowSize, firstCoordinate);    
    Sleep(3000);
    
    clearWindow();
}

void runResizeWindow()
{
    int height;
    printf("  Height: ");
    scanf("%d", &height);

    int width;
    printf("  Width: ");
    scanf("%d", &width);

    WindowSize windowSize = {height, width};
    resizeWindow(windowSize);
}

void runClearWindow()
{
    printf(
        "  Some text here!\n"
        "  More over here...\n"
        "\n"
        "  And last, but not least, here.\n"
    );

    Sleep(1000);

    clearWindow();
}
