#include <iostream>
#include <time.h>

#include "lib/slEngine.h"

using namespace std;

int main()
{
    setUpEngine(80, 20);

    setBackgroundColor(slDARK_GRAY);

    translateTo(0,0);
    setCursorPosition(0,0);
    setColor(slGREEN);



    slGigano num1;
    slGigano num2;

    num1.set(1024);
    num2.set(128);

    draw(num1.getString(), 0, 0, slDARK_BLUE);
    draw(num2.getString(), 0, 1, slDARK_BLUE);

    draw("--------------------------------------------------------------", 0, 2, slBLUE);

    int start = clock();
    num1.pow(num2);
    int stop = clock();

    //draw(num1.getString(), 0, 3, slGREEN);

    setCursorPosition(0, 5);
    setColor(slDARK_PURPLE);
    cout << num1.getString() << endl;

    draw(stop-start, 10, 10, slDARK_RED);

    ////////////////////////////////

    pause();

    cleanScreen();

    return 0;
}
