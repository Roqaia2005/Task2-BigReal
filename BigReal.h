#ifndef BIGREAL_H
#define BIGREAL_H

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;

class BigReal {
private:
    string number;
    string integerPart;
    string fractionPart;
    char sign;

public:
    // Constructors
    BigReal();
    BigReal(const string& str);
    BigReal(double value);

    BigReal(const BigReal& other);
    BigReal& operator=(const BigReal& other);

    size_t size() const;
    char getSign() const;
    string getIntegerPart() const;
    string getFractionPart() const;

    bool isValidReal(const string& str) const;
 
    void setNum(const string& str) ;

// .... (existing code)

    void extractParts();

    friend ostream& operator<<(ostream& os, const BigReal& bd);
    friend BigReal operator+(const BigReal& left, const BigReal& right);
    friend BigReal operator-(const BigReal& left, const BigReal& right);
    friend bool operator<(const BigReal& left, const BigReal& right);
    friend bool operator>(const BigReal& left, const BigReal& right);
    friend bool operator==(const BigReal& left, const BigReal& right);
};

#endif








