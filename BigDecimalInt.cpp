#include "BigDecimalInt.h"

BigDecimalInt::BigDecimalInt(){}
BigDecimalInt::BigDecimalInt(int n) {num = to_string(n);}
BigDecimalInt::BigDecimalInt(string n) {
    if (n[0] == '0'){
        cout << "invalid number!" << endl;
    } else if ((n[0] == '+' || n[0] == '-') && (n[1] == '+' || n[1] == '-')){
        cout << "invalid number!" << endl;
    } else if ((n[0] == '+' || n[0] == '-') && n[1] == '0'){
        cout << "invalid number!" << endl;
    } else{
        if (n[0] == '+'){
            n.erase(n.begin());
        }
        num = n;
    }
}
BigDecimalInt::BigDecimalInt(const BigDecimalInt &anotherDec){
    this->num = anotherDec.num;
}
BigDecimalInt BigDecimalInt::operator+(BigDecimalInt anotherDec){

    BigDecimalInt temp;
    int tempSum = 0;

    reverse(num.begin(), num.end());
    reverse(anotherDec.num.begin(), anotherDec.num.end());

    while (num.length() > anotherDec.num.length()){
        anotherDec.num += '0';
    }
    while (num.length() < anotherDec.num.length()){
        num += '0';
    }
    if (num[0] == '-' || anotherDec.num[0] == '-'){
        for (int i = 0; i < num.length(); i++) {

            tempSum += (num[i] - '0') - (anotherDec.num[i] - '0');
            temp.num += char((tempSum % 10) + '0');
            tempSum /= 10;
        }
    } else {
        for (int i = 0; i < num.length(); i++) {

            tempSum += (num[i] - '0') + (anotherDec.num[i] - '0');
            temp.num += char((tempSum % 10) + '0');
            tempSum /= 10;
        }
    }
    reverse(temp.num.begin(),temp.num.end());
    while (temp.num[0] == '0'){
        temp.num.erase(temp.num.begin());
    }
    return temp;
}
BigDecimalInt BigDecimalInt::operator-(BigDecimalInt anotherDec){
    BigDecimalInt temp;
    int tempSub = 0;

    while (num.length() > anotherDec.num.length()){
        anotherDec.num.insert(0,"0");
    }
    while (num.length() < anotherDec.num.length()){
        num.insert(0,"0");
    }
    if (num >= anotherDec.num) {
        for (int i = 0; i < num.length(); i++) {

            if (num[i] - '0' >= anotherDec.num[i] - '0') {
                tempSub += (num[i] - '0') - (anotherDec.num[i] - '0');
                temp.num += char((tempSub % 10) + '0');
                tempSub /= 10;
            } else {
                int x = num[i] - '0';
                x += 10;
                temp.num[i - 1]--;

                tempSub += x - (anotherDec.num[i] - '0');
                temp.num += char((tempSub % 10) + '0');
                tempSub /= 10;
            }
        }
        while (temp.num[0] == '0'){
            temp.num.erase(temp.num.begin());
        }
    } else{
        for (int i = 0; i < num.length(); i++) {

            if (anotherDec.num[i] - '0' >= num[i] - '0') {
                tempSub += (anotherDec.num[i] - '0') - (num[i] - '0');
                temp.num += char((tempSub % 10) + '0');
                tempSub /= 10;
            } else {
                int x = anotherDec.num[i] - '0';
                x += 10;
                if (temp.num[i-1] != '0') {
                    temp.num[i - 1]--;
                } else{
                    int count = i;
                    while (temp.num[count-1] != '0'){
                        temp.num[count - 1]--;
                        count--;
                    }
                }
                tempSub += x - (num[i] - '0');
                temp.num += char((tempSub % 10) + '0');
                tempSub /= 10;
            }
        }
        while (temp.num[0] == '0'){
            temp.num.erase(temp.num.begin());
        }
        temp.num.insert(0,"-");

    }
    return temp;
}
ostream &operator<<(ostream &out, BigDecimalInt b){
    cout << b.num << endl;
    return out;
}
bool BigDecimalInt::operator <(BigDecimalInt anotherDec) {
    int lengthnum = num.length(), lengthAntherNum = anotherDec.num.length();
    if (num[0] == '-') {
        lengthnum--;
    }
    if (anotherDec.num[0] == '-') {
        lengthAntherNum--;
    }
    if (lengthnum == lengthAntherNum && num[0] == '-' && anotherDec.num[0] == '-'){
        while (lengthnum--) {
            if (num[lengthnum] != anotherDec.num[lengthnum]) {
                return num[lengthnum] > anotherDec.num[lengthnum];
            }
        }
        return false;
    }
    if (lengthnum != lengthAntherNum) {
        return lengthnum < lengthAntherNum;
    }
    while (lengthnum--) {
        if (num[lengthnum] != anotherDec.num[lengthnum]) {
            return num[lengthnum] < anotherDec.num[lengthnum];
        }
    }
    return false;
}
bool BigDecimalInt::operator >(BigDecimalInt anotherDec){
    int lengthnum = num.length() , lengthAntherNum = anotherDec.num.length();
    if (num[0] == '-'){
        lengthnum--;
    }
    if (anotherDec.num[0] == '-'){
        lengthAntherNum--;
    }
    if (lengthnum == lengthAntherNum && num[0] == '-' && anotherDec.num[0] == '-'){
        while (lengthnum--) {
            if (num[lengthnum] != anotherDec.num[lengthnum]) {
                return num[lengthnum] < anotherDec.num[lengthnum];
            }
        }
        return false;
    }
    if (lengthnum != lengthAntherNum){
        return lengthnum > lengthAntherNum;
    }
    while (lengthnum--){
        if (num[lengthnum] != anotherDec.num[lengthnum]){
            return num[lengthnum] > anotherDec.num[lengthnum];
        }
    }
    return false;
}
bool BigDecimalInt::operator==(BigDecimalInt anotherDec){
    for (int i = 0; i < max(num.length(),anotherDec.num.length()); ++i) {
        if (num[i] != anotherDec.num[i]){
            return false;
        }
    }
    return true;
}
BigDecimalInt BigDecimalInt::operator=(BigDecimalInt anotherDec){
    num = anotherDec.num;
    return *this;
}
int BigDecimalInt::size() {
    return num.length();
}
int BigDecimalInt::sign() {
    if (num[0] == '+' || isdigit(num[0])){
        return 1;
    } else{
        return 0;
    }
}

