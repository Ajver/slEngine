#include <iostream>

#include "lib/slEngine.h"

using namespace std;

int main()
{
    setWindowSize(120, 40);
    hideCursor();

    setBackgroundColor(slDARK_GRAY);

    draw("Hello whole world!", "center", 3, slCYAN);
    write("This is my program created for testing slEngine.", "center", 5, slWHITE, 20);

    drawCircle('$', 10, 30, 8, slBLUE);

    drawCircle('.', -10, -30, getWindowWidth(), slCYAN);
    drawCircle('.', -6, -30, getWindowWidth(), slCYAN);

    translate(-30, 0);

    draw("Lorem ipsum", "right", 20, slGRAY);

    translate(30, 0);

    pause();

    cleanScreen();

    return 0;
}
