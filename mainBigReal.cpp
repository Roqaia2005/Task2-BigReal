// File: BigReal.cpp  main file
// Purpose: Task2 BigReal class
// Author1: Roqaia Hassan  , ID:20220129
// Author2: Rawan Ahmed ,    ID:20220132
// Author3:Basmala Mohammed   ID:20210621
// Section: s15,s16
// TA: Mohamed Talaat
// Date: 27 oct 2023
#include<iostream>
#include<string>
#include <cctype>
#include <sstream>
#include <cmath>
#include "BigReal.h"
#include "BigReal.cpp"

using namespace std;


int main() {
    BigReal b1("2.45677777777");
    BigReal b2(6.566666666);
    BigReal b3(-5.5444444444);
    cout << "b1: " << b1 << endl;
    cout << "b1 Sign: " << b1.getSign() << endl;
    cout << "b1 Integer Part: " << b1.getIntegerPart() << endl;
    cout << "b1 Fraction Part: " << b1.getFractionPart() << endl;

    cout << "b2: " << b2 << endl;
    cout << "b2 Sign: " << b2.getSign() << endl;
    cout << "b2 Integer Part: " << b2.getIntegerPart() << endl;
    cout << "b2 Fraction Part: " << b2.getFractionPart() << endl;

    BigReal sum = b1 + b2;
    BigReal diff = b1 - b2;

    cout << "Sum: " << sum << endl;
    cout << "Difference: " << diff << endl;

    if (b1 < b2) {
        cout << "b1 is less than b2." << endl;
    } else {
        cout << "b1 is not less than b2." << endl;
    }
    if(b1>b2){
        cout<<"yes\n";
    }
    else{
        cout<<"no";
    }

    if (b1 == b1) {
        cout << "b1 is equal to itself." << endl;
    }

    return 0;
}






