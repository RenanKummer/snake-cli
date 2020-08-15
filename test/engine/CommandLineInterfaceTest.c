#include "engine/CommandLineInterface.h"
/**
 * This is a manual test.
 * 
 * @author Renan Kummer [ GitHub: @RenanKummer ]
 */
#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("Disclaimer: This test must be run in a resizable command line window!\n");

    WindowSize newSize = {30, 100};
    printf("Resizing window to {%d, %d}\n", newSize.height, newSize.width);
    wait(5000);
    resizeWindow(newSize);

    WindowCoordinate cursorCoordinate = {9, 3};
    printf("Moving cursor to {%d, %d}\n", 
        cursorCoordinate.height, 
        cursorCoordinate.width
    );
    moveCursor(newSize, cursorCoordinate);

    wait(5000);

    cursorCoordinate.height = 30;
    printf("Attempting to move cursor to out of range position {%d, %d}\n", 
        cursorCoordinate.height,
        cursorCoordinate.width
    );
    moveCursor(newSize, cursorCoordinate);

    wait(5000);

    printf("I must be at the default position {%d, %d}\n", 
        getDefaultWindowCoordinate().height,
        getDefaultWindowCoordinate().width
    );

    printf("Waiting 5 seconds before clearing all output...");
    wait(5000);
    clearWindow();

    printf("Waiting for any key to be entered...\n");
    while (!hasKeyboardHit()) {}
    printf("You entered key %d\n", readKeyboardHitNoEcho());
}
