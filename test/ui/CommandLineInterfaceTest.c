#include "type/Boolean.h"
#include "type/WindowCoordinate.h"
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
    WAIT          = 2,
    RESIZE_WINDOW = 3,
    CLEAR_WINDOW  = 4,
    KEYBOARD_HIT  = 5
} Option;

void printOptions();
Option readOption();

Boolean isMoveCursorOption(Option option);
Boolean isWaitOption(Option option);
Boolean isResizeWindowOption(Option option);
Boolean isClearWindowOption(Option option);
Boolean isKeyboardHitOption(Option option);
void runMoveCursor();
void runWait();
void runResizeWindow();
void runClearWindow();
void runKeyboardHit();

int main()
{
    while (true) {
        printOptions();
        Option option = readOption();

        if (isMoveCursorOption(option)) {
            runMoveCursor();
        } else if (isWaitOption(option)) {
            runWait();
        } else if (isResizeWindowOption(option)) {
            runResizeWindow();
        } else if (isClearWindowOption(option)) {
            runClearWindow();
        } else if (isKeyboardHitOption(option)) {
            runKeyboardHit();
        }
    }    
}

void printOptions()
{
    printf(
        "Test CommandLineInterface\n"
        "  %2d: moveCursor()\n"
        "  %2d: wait()\n"
        "  %2d: resizeWindow()\n"
        "  %2d: clearWindow()\n"
        "  %2d: keyboardHit()\n"
        "\n",
        MOVE_CURSOR,
        WAIT,
        RESIZE_WINDOW, 
        CLEAR_WINDOW,
        KEYBOARD_HIT
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

Boolean isWaitOption(Option option)
{
    return option == WAIT;
}

Boolean isResizeWindowOption(Option option)
{
    return option == RESIZE_WINDOW;
}

Boolean isClearWindowOption(Option option)
{
    return option == CLEAR_WINDOW;
}

Boolean isKeyboardHitOption(Option option)
{
    return option == KEYBOARD_HIT;
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
    wait(3000);
    
    clearWindow();
}

void runWait()
{
    printf("Waiting 3 seconds...\n");
    wait(3000);
    printf("Waiting 2 seconds...\n");
    wait(2000);
    printf("Waiting 1 seconds...\n");
    wait(1000);
    printf("And we're done!\n\n");
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

    wait(1000);

    clearWindow();
}

void runKeyboardHit()
{
    printf("Waiting for keyboard hit...\n");

    while (!hasKeyboardHit()) {
        // Do nothing.
    }

    int key = readKeyboardHitNoEcho();
    printf("You entered key %d.\n", key);

    wait(3000);
    clearWindow();
}
