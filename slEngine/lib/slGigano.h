#include <iostream>


using namespace std;




class slGigano {

public:
    slGigano();
    slGigano(int);

    char get(int);
    slGigano get();

    void set(slGigano);
    void set(int);

    void clear();

    bool add(slGigano);
    bool add(int);

    bool isPositive();

private:
    int len = 10;
    char root = 10;
    char *val;

    // Zero is positive too in this class
    bool bPositive;

};
