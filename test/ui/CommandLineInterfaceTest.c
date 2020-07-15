#include "type/Boolean.h"
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
    RESIZE_WINDOW = 1,
    CLEAR_WINDOW  = 2
} Option;

void printOptions();
Option readOption();

Boolean isResizeWindowOption(Option option);
Boolean isClearWindowOption(Option option);
void runResizeWindow();
void runClearWindow();

int main()
{
    while (true) {
        printOptions();
        Option option = readOption();

        if (isResizeWindowOption(option)) {
            runResizeWindow();
        } else if (isClearWindowOption(option)) {
            runClearWindow();
        } else {
            clearWindow();
        }
    }    
}

void printOptions()
{
    printf(
        "Test CommandLineInterface\n"
        "%2d: resizeWindow()\n"
        "%2d: clearWindow()\n"
        "\n",
        RESIZE_WINDOW, 
        CLEAR_WINDOW
    );
}

Option readOption()
{
    Option option;
    printf("Your option: ");
    scanf("%d", &option);

    return option;
}

Boolean isResizeWindowOption(Option option)
{
    return option == RESIZE_WINDOW;
}

Boolean isClearWindowOption(Option option)
{
    return option == CLEAR_WINDOW;
}

void runResizeWindow()
{
    int height;
    printf("Height: ");
    scanf("%d", &height);

    int width;
    printf("Width: ");
    scanf("%d", &width);

    resizeWindow(height, width);
}

void runClearWindow()
{
    printf("\nSome text here!\n");
    printf("More over here...\n");
    printf("\nAnd last, but not least, here.");

    Sleep(1000);

    clearWindow();
}
