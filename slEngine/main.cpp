#include <iostream>
#include <time.h>

#include "lib/slEngine.h"
#include "lib/slGigano.h"

using namespace std;

int main()
{
    setUpEngine(120, 40);

    int start = clock();

    setBackgroundColor(slDARK_GRAY);

    translateTo(0,0);
    setCursorPosition(0,0);
    setColor(slGREEN);

    slGigano num1;
    slGigano num2;

    num1.set(999);
    cout << endl;
    num2.set(9);

    cout << endl << "-------------------------------------------" << endl;
    num1.add(num2);

    ////////////////////////////////

    //pause();

    //cleanScreen();

    return 0;
}
