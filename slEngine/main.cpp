#include <iostream>
#include <time.h>

#include "lib/slEngine.h"

using namespace std;

int main()
{
    setUpEngine(120, 70);



    setBackgroundColor(slDARK_GRAY);

    translateTo(0,0);
    setCursorPosition(0,0);
    setColor(slGREEN);

    slGigano num1;
    slGigano num2;

    num1.set(123123123);
    num2.set(7483852);

    draw(num1.getString(), 0, 0, slBLUE);
    draw(num2.getString(), 0, 1, slBLUE);

    draw("--------------------------------------------------------------", 0, 2, slBLUE);

    num1.substract(7483852);
    draw(num1.getString(), 0, 3, slGREEN);

    ////////////////////////////////

    pause();

    cleanScreen();

    return 0;
}
