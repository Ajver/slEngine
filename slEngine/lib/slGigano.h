#include <iostream>


using namespace std;




class slGigano {

public:
    slGigano();
    slGigano(int);

    char get(int);
    string getString();
    slGigano get();

    void set(slGigano);
    void set(int);
    bool set(int, int);

    void clear();

    bool add(slGigano);
    bool add(int);

    bool substract(slGigano);
    bool substract(int);

    bool multiply(slGigano);
    bool multiply(int);

    bool isPositive();

private:
    int len = 50;
    char root = 10;
    char *val;

    // Zero is positive too in this class
    bool _isPositive = true;

};
