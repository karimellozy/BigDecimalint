//
// Created by user on 10/25/2022.
//

#ifndef MAIN_CPP_BIGDECIMALINT_H
#define MAIN_CPP_BIGDECIMALINT_H
#include<bits/stdc++.h>
using namespace std;

class BigDecimalInt {
private:
    string num;
public:
    BigDecimalInt();
    BigDecimalInt(string n);
    BigDecimalInt(int n);
    BigDecimalInt(const BigDecimalInt &anotherDec);
    BigDecimalInt operator+(BigDecimalInt anotherDec); // member fn
    BigDecimalInt operator-(BigDecimalInt anotherDec); // member fn
    bool operator<(BigDecimalInt anotherDec); // member fn
    bool operator>(BigDecimalInt anotherDec); // member fn
    bool operator==(BigDecimalInt anotherDec); // member fn
    BigDecimalInt operator=(BigDecimalInt anotherDec);
    int size(); // member fn
    int sign(); // member fn
    friend ostream &operator<<(ostream &out, BigDecimalInt b);
};
ostream &operator<<(ostream &out, BigDecimalInt b);



#endif //MAIN_CPP_BIGDECIMALINT_H
