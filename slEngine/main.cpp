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

    slGigano num;

    draw((int)num.get(0), 0, 0, slGREEN);

    ////////////////////////////////

    pause();

    cleanScreen();

    return 0;
}
