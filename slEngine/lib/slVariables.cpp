#include "slVariables.h"

string cutString(string root, int from, int to)
{
    string s = "";

    if(from < 0) from = 0;

    for(int i=from; i<=to; i++)
    {
        if(i >= root.length())
            return s;

        s += root[i];
    }

    return s;
}

string toString(int a)
{
    string str;
    bool isNegative = false;

    if(a < 0)
    {
        isNegative = true;
        a *= -1;
    }

    do
    {
        int single = a%10;
        char singleChar = (char)(single + 48);

        a /= 10;

        str = singleChar + str;
    }while(a != 0);

    if(isNegative)
        str = '-' + str;


    return str;
}

string toString(const char c[]) 
{
	return (string)c;
}

string toString(float a)
{
    a *= 10000000;

    string str = toString((int)a);

    string beginS = cutString(str, 0, str.length()-8);
    string finishS = cutString(str, str.length()-7, str.length()-1);

    str = beginS + '.' + finishS;

    for(int i=str.length()-1; i>=0; i--)
    {
        if(str[i] == '0')
            str = cutString(str, 0, i-1);
        else
            return str;
    }

    return str;
}

const char* toCharArr(int a)
{
    return toString(a).c_str();
}

const char* toCharArr(string s)
{
    return s.c_str();
}

string mergeStrings(string a, string b)
{
    return a+b;
}

const char* mergeCharArrs(char* a, char *b)
{
    return "a+b";
}

float map(float a, float minA, float maxA, float minB, float maxB)
{
	float Arange = maxA - minA;
	float Brange = maxB - minB;

	float proportion = (a - minA) / Arange;

	return Brange * proportion + minB;
}