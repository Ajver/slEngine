#include "slGigano.h"

#include "slGraphics.h"


slGigano::slGigano() {
    root = 10;
    val = new char[len];

    clear();
}
slGigano::slGigano(int nroot) {
    if(root < 2) root = 2;
    else root = nroot;

    val = new char[len];

    clear();
}
void slGigano::clear() {
    _isPositive = true;

    for(int i=0; i<len; i++)
        val[i] = 0;
}
void slGigano::set(int a) {
    clear();
    _isPositive = a >= 0;

    int i = len-1;
    do {
        val[i] = a%10;
        a /= 10;
        i--;
    }while(a != 0);
}
void slGigano::set(slGigano a) {
    _isPositive = a.isPositive();
    for(int i=0; i<len; i++)
        val[i] = a.get(i);
}
bool slGigano::set(int i, int a) {
    if(i >= 0 && i <= len-1 && a >= 0 && a <= 255) {
        val[i] = a;
        return true;
    }else
        return false;
}
bool slGigano::add(slGigano a) {
    int offset = 0;

    for(int i=len-1; i>=0; i--) {
        offset += a.get(i) + val[i];
        val[i] = offset % root;
        offset /= root;
    }

    return offset == 0;
}
bool slGigano::add(int a) {
    slGigano ga(root);
    ga.set(a);

    return add(ga);
}

bool slGigano::substract(slGigano a) {
    int offset = 0;

    for(int i=len-1; i>=0; i--) {
        int cur = val[i] + root;
        int next = cur - a.get(i) - offset;

        val[i] = next % root;

        if(next < root)
            offset = 1;
        else
            offset = 0;
    }

    return true;
}
bool slGigano::substract(int a) {
    slGigano ga;
    ga.set(a);

    return substract(ga);
}

bool slGigano::multiply(slGigano a) {
    int offset = 0;
    slGigano next[len];

    for(int j=len-1; j>=0; j--) {
        for(int i=len-1; i>=0; i--) {
            offset += val[i] * a.get(j);
            next[j].set(j-(len-i)+1, offset%root);
            offset /= root;
        }
        for(int x=0; x<len; x++)
            cout << (int)next[j].get(x);

        cout << endl;

        if(offset != 0) return false;
    }
    clear();

    for(int i=0; i<len; i++) {
        if(!add(next[i]))
            return false;
    }

    return true;
}
bool slGigano::multiply(int a) {
    slGigano ga;
    ga.set(a);

    return multiply(ga);
}

bool slGigano::isPositive() {
    return _isPositive;
}

char slGigano::get(int i) {
    if(i >= 0 && i <= len-1)
        return val[i];

    return 0;
}
string slGigano::getString() {
    string str = "";
    for(int i=0; i<len; i++)
        str += val[i]+48;

    return str;
}
