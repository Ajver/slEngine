#include <iostream>
#include <time.h>
#include <string>

#include "lib/slGraphics.h"

using namespace std;

void drawChessboard() {
    cleanScreen();
    for (int j=0;j<getWindowHeight();j+=2) {
        for(int i=0;i<getWindowWidth();i+=2) {
            draw((char)219, i, j, slBLACK);
            draw((char)219, i+1, j+1, slBLACK);
        }
    }
}

int main()
{
    //setUpEngine(80, 20);

    setWindowSize(40, 20);

    setBackgroundColor(slDARK_GRAY);

    for(int i;;i)
    drawChessboard();


    // Sleep(100);
    // cleanScreen();
    //translate(-1,0);

    ////////////////////////////////

    pause();

    cleanScreen();

    return 0;
}
