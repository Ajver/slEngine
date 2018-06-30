#include "slGigano.h"

#include "slGraphics.h"


slGigano::slGigano() {
    root = 10;
    val = new unsigned char[len];

    clear();
}
slGigano::slGigano(int nroot) {
    if(root < 2) root = 2;
    else root = nroot;

    val = new unsigned char[len];

    clear();
}
void slGigano::clear() {
    _isPositive = true;

    for(int i=0; i<len; i++)
        val[i] = 0;
}
void slGigano::set(int a) {
    clear();

    if(a < 0) {
        _isPositive = false;
        a *= -1;
    }else {
        _isPositive = true;
    }

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
    if(a.isPositive()) {
        int offset = 0;

        for(int i=len-1; i>=0; i--) {
            offset += a.get(i) + val[i];
            val[i] = offset % root;
            offset /= root;
        }

        return offset == 0;
    }else {
        a.setPositive(true);
        return substract(a);
    }
}
bool slGigano::add(int a) {
    slGigano ga(root);
    ga.set(a);

    return add(ga);
}

bool slGigano::substract(slGigano a) {
    if(a.isPositive()) {
        bool nextPositive = !lt(a);

        if(nextPositive) {
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
        }else {
            slGigano gthis;
            gthis.set(get());

            a.substract(gthis);
            set(a);
        }

        _isPositive = nextPositive;

        return true;
    }else {
        a.setPositive(true);
        return add(a);
    }
}
bool slGigano::substract(int a) {
    slGigano ga;
    ga.set(a);

    return substract(ga);
}

bool slGigano::multiply(slGigano a) {
    bool nextPositive = _isPositive == a.isPositive();
    int offset = 0;
    slGigano next[len];

    for(int j=len-1; j>=0; j--) {
        for(int i=len-1; i>=0; i--) {
            offset += val[i] * a.get(j);
            next[j].set(j-(len-i)+1, offset%root);
            offset /= root;
        }

        if(offset != 0) return false;
    }
    clear();

    for(int i=0; i<len; i++) {
        if(!add(next[i]))
            return false;
    }

    _isPositive = nextPositive;

    return true;
}
bool slGigano::multiply(int a) {
    slGigano ga;
    ga.set(a);
    return multiply(ga);
}

bool slGigano::divide(slGigano a) {

    return true;
}
bool slGigano::divide(int a) {
    slGigano ga;
    ga.set(a);
    return divide(ga);
}

bool slGigano::gt(slGigano a) {
    for(int i=0; i<len; i++) {
        if(val[i] != a.get(i))
            return val[i] > a.get(i);
    }

    return false;
}
bool slGigano::gt(int a) {
    slGigano ga;
    ga.set(a);
    return gt(ga);
}
bool slGigano::lt(slGigano a) {
    for(int i=0; i<len; i++) {
        if(val[i] != a.get(i))
            return val[i] < a.get(i);
    }

    return true;
}
bool slGigano::lt(int a) {
    slGigano ga;
    ga.set(a);
    return lt(ga);
}
bool slGigano::equalTo(slGigano a) {
    for(int i=0; i<len; i++) {
        if(val[i] != a.get(i))
            return false;
    }

    return true;
}
bool slGigano::equalTo(int a) {
    slGigano ga;
    ga.set(a);
    return equalTo(ga);
}

bool slGigano::isPositive() {
    return _isPositive;
}
void slGigano::setPositive(bool isP) {
    _isPositive = isP;
}

char slGigano::get(int i) {
    if(i >= 0 && i <= len-1)
        return val[i];

    return 0;
}
slGigano slGigano::get() {
    slGigano ga(root);

    for(int i=0; i<len; i++)
        ga.set(i, val[i]);

    ga.setPositive(_isPositive);

    return ga;
}

string slGigano::getString() {
    string str = _isPositive ? "+" : "-";
    for(int i=0; i<len; i++)
        str += val[i]+48;

    return str;
}
