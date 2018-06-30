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

    num1.set(99922);
    for(int x=0; x<50; x++)
        cout << (int)num1.get(x);

    cout << endl;

    num2.set(923);
    for(int x=0; x<50; x++)
        cout << (int)num2.get(x);

    cout << endl << "----------------------------------------------------------" << endl;
    int start = clock();
    num1.multiply(num2);
    int stop = clock();
    cout << "-------------------------------------------------------------------" << endl;

    draw(num1.getString(), 0, 56, slBLUE);

    cout << endl;

    draw(stop-start, 80, 15, slRED);

    ////////////////////////////////

    pause();

    cleanScreen();

    return 0;
}
