#include <iostream>

#include "lib/slEngine.h"

using namespace std;

int main()
{
    setWindowSize(120, 40);

    setBackgroundColor(2);

    draw("Hello whole world!", "center", 3, slPURPLE);
    write("This is my program created for testing slEngine.", "center", 5, slGRAY, 20);

    drawCircle('$', 10, 30, 8, slBLUE);

    //drawLine('-', 22, 20, 50, 29, slDARK_BLUE);

    pause();

    cleanScreen();

    return 0;
}
