// File: BigReal.cpp  Implementation file
// Purpose: Task2 BigReal class
// Author1: Roqaia Hassan  , ID:20220129
// Author2: Rawan Ahmed ,    ID:20220132
// Author3:Basmala Mohammed   ID:20210621
// Section: s15,s16
// TA: Mohamed Talaat
// Date: 27 oct 2023

#include<iostream>
#include "BigReal.h"
using namespace std;

BigReal::BigReal() : number("0"), sign('+'), integerPart("0"), fractionPart("0") {}

BigReal::BigReal(const string& str) : number(str) {
       if (isValidReal(str)) {
        number = str;
        extractParts();
        if (!str.empty())
        {
        sign = (str[0] == '-') ? '-' : '+';
        }    
        else
        {
        sign = '+';
        }
    }  
       else
       {
        cout << "Invalid Number" << endl;
    }
}

BigReal::BigReal(double value) : sign((value >= 0) ? '+' : '-'), number(std::to_string(std::abs(value))) {
    extractParts();
}

BigReal::BigReal(const BigReal& other) : number(other.number), sign(other.sign), integerPart(other.integerPart), fractionPart(other.fractionPart) {}

BigReal& BigReal::operator=(const BigReal& other) {
    if (this != &other) {
        number = other.number;
        sign = other.sign;
        integerPart = other.integerPart;
        fractionPart = other.fractionPart;
    }
    return *this;
}

size_t BigReal::size() const
{
    return number.size();
}

char BigReal::getSign() const 
{
    return sign;
}

string BigReal::getIntegerPart() const {
    return integerPart;
}

string BigReal::getFractionPart() const {
    return  fractionPart;
}

// ........... (existing code)

// Set the value of a BigReal from a string
// Set the value of a BigReal from a string
void BigReal::setNum(const string& str) {
    if (isValidReal(str)) {
        number = str;
        extractParts();
        if (!str.empty()) {
            sign = (str[0] == '-') ? '-' : '+';
        } else {
            sign = '+';
        }
    } else {
        cout << "Invalid Number" << endl;
    }
}



// ..... (existing code)


bool BigReal::isValidReal(const string& str) const {
    if (str.empty()) {
        return false;
    }

    bool decimalPointFound = false;
    for (char c : str) {
        if (!isdigit(c) && (c != '.')) {
              return false;
        }
        if (c == '.' && decimalPointFound) {
               return false;
        }
        if (c == '.') {
            decimalPointFound = true;
        }
    }

    // Ensure that there's at least one digit before the decimal point
    if (!decimalPointFound || (str.find('.') == 0)) {
        return false;
    }

    return true;
}

void BigReal::extractParts() {
    if (number.find('.') != std::string::npos) {
        size_t decimalPosition = number.find('.');
        integerPart = number.substr(0, decimalPosition);
        fractionPart = number.substr(decimalPosition + 1);
    } else {
        integerPart = number;
        fractionPart = "0";
    }

}

ostream& operator<<(ostream& os, const BigReal& bd) {
    os << bd.sign << bd.integerPart << "." << bd.fractionPart;
    return os;
}

BigReal operator+(const BigReal& left, const BigReal& right) {
    double sum = (left.sign == '+' ? 1 : -1) * std::stod(left.number) + (right.sign == '+' ? 1 : -1) * std::stod(right.number);
    return BigReal(sum);
}

BigReal operator-(const BigReal& left, const BigReal& right) {
    double diff = (left.sign == '+' ? 1 : -1) * std::stod(left.number) - (right.sign == '+' ? 1 : -1) * std::stod(right.number);
    return BigReal(diff);
}

bool operator<(const BigReal& left, const BigReal& right) {
    double leftValue = (left.sign == '+' ? 1 : -1) * stod(left.number);
    double rightValue = (right.sign == '+' ? 1 : -1) * stod(right.number);
    return leftValue < rightValue;
}

bool operator>(const BigReal& left, const BigReal& right) {
    double leftValue = (left.sign == '+' ? 1 : -1) * stod(left.number);
    double rightValue = (right.sign == '+' ? 1 : -1) * stod(right.number);
    return leftValue > rightValue;
}


bool operator==(const BigReal& left, const BigReal& right) {
    return left.number == right.number;
}



