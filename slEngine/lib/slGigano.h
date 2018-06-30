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

    // Divide as integer variables ("1.23" is equal just "1")
    bool divideInt(slGigano);
    bool divideInt(int);

    bool isPositive();
    void setPositive(bool);

    // Grates than, Less than...
    bool gt(slGigano);
    bool gt(int);
    bool lt(slGigano);
    bool lt(int);
    bool equalTo(slGigano);
    bool equalTo(int);

private:
    int len = 50;
    char root = 10;
    unsigned char *val;

    // Zero is positive too in this class
    bool _isPositive = true;

};
