#include "slGigano.h"



slGigano::slGigano() {
    root = 10;

    len = 256;
    val = new char[len];

    clear();
}
slGigano::slGigano(int nroot) {
    if(root < 2) root = 2;
    else root = nroot;

    len = 256;
    val = new char[len];

    clear();
}
void slGigano::clear() {
    for(int i=0; i<len; i++) {
        val[i] = 0;
    }
}

bool slGigano::add(slGigano a) {
    int offset = 0;

    for(int i=len-1; i>=0; i--) {
        offset += a.get(i) + val[i];
        val[i] = offset % root;
        offset /= root;

        for(int i=0; i<len; i++) {
            cout << val[i];
        }
    }

    return true;
}
bool slGigano::add(int a) {
    slGigano ga(root);
    ga.set(a);

    return add(ga);
}
void slGigano::set(int a) {

}

char slGigano::get(int i) {
    if(i >= 0 && i <= 255)
        return val[i];

    return 0;
}
