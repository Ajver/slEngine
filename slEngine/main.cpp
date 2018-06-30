#include <iostream>
#include <time.h>

#include "lib/slEngine.h"

using namespace std;

int main()
{
    setUpEngine(120, 40);

    int start = clock();

    setBackgroundColor(slDARK_GRAY);


    ////////////////////////////////

    pause();

    cleanScreen();

    return 0;
}
