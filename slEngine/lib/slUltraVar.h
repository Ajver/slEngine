#ifndef SLULTRAVAR_H
#define SLULTRAVAR_H

#endif // SLULTRAVAR_H

#include <iostream>



using namespace std;

/*
This variable is holding in string var. You can use it by methods.
Think about this variable like double, or something like this, but that var has much bigger precision.

The range of slUltraVar is undefined yet.
*/


class slUltraVar {

public:

    slUltraVar();

    void setValue(string);
    void setValue(double);

    void addTo(slUltraVar);
    void addTo(int);
    void addTo(string);
    void addTo(double);

    string getStr() const;
    int getInt();
    float getFloat();
    double getDouble();

private:
    string value;
    bool isPositive;

    bool isDigit(char) const;

};
