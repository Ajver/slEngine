#include <iostream>
#include <time.h>

#include "lib/slEngine.h"

using namespace std;

int main()
{
    setUpEngine(120, 40);

    int start = clock();

    setBackgroundColor(slDARK_GRAY);

    draw("Hello whole world!", "center", 3, slCYAN);
    write("This is my program created for testing slEngine.", "center", 5, slWHITE, 20);

    drawCircle('$', 10, 30, 8, slBLUE);

    drawCircle('.', -10, -30, getWindowWidth(), slCYAN);
    drawCircle('.', -6, -30, getWindowWidth(), slCYAN);

    translate(-30, 0);

    draw("Lorem ipsum", "right", 20, slGRAY);

    translate(30, 0);

    int stop = clock();

    draw(stop-start, 10, 10, slRED);

    pause();

    cleanScreen();

    return 0;
}
