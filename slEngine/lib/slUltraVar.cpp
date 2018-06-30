#include "slUltraVar.h"
#include "slVariables.h"




slUltraVar::slUltraVar() {
    setValue("0");
}

void slUltraVar::setValue(string s) {
    if(s.length() > 0)
        value = "";

    for(int i=0; i<s.length(); i++) {
        if(isDigit(s[i])) {
            value += s[i];
        }
    }

    while(value[0] == '0')
        value = value.substr(1, value.length()-1);
}

void slUltraVar::setValue(double d) {
    setValue(toString(d));
}

string slUltraVar::getStr() const {
    return value;
}


bool slUltraVar::isDigit(char c) const {
    return (int)c >= 48 && (int)c <= 57;
}
