#include "type/String.h"
#include "ui/CommandLineInterface.h"

#include <windows.h>

Boolean resizeWindow(const int height, const int width)
{
    if ((height > 0) && (width > 0)) {
        const char *const heightString = castIntToString(height);
        const char *const widthString = castIntToString(width);

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
