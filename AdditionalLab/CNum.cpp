#include "CNum.hpp"
#include <iostream>

using namespace std;
using namespace CNumber;


/// Constructor for complex number, which consists with two part: real and imaginary;
/// @param real Real part of this complex number;
/// @param imaginary Imaginary part of this complex number;
CNum::CNum(double real, double imaginary){
    this->realPart = real;
    this->imaginaryPart = imaginary;
    this->i = 1;
}

/// Constructor for complex number, which consists only with real part;
/// @param real Real part of this complex number;
CNum::CNum(double real){
    this->realPart = real;
    this->imaginaryPart = 0;
    this->i = 1;
}

/// Default constructor without params
CNum::CNum(){
    this->realPart = 0;
    this->imaginaryPart = 0;
    this->i = 1;
}


/// Read all values of complex number from console.
void CNum::input(){
    cout << " Real part of this number: ";
    cin >> realPart;
    cout << " Imaginary part of this number: ";
    cin >> imaginaryPart;
    this->i = 0;
}

/// Convert type CNum to type string(Char*) and return dynamic array with char
char* CNum::toString(){
    char* resultString = new char[20];
    sprintf(resultString, "%.2lf + %.2lfi", realPart, imaginaryPart);
    return resultString;
}


CNum CNum::pow(int power){
    if(power == 0) return 1;
    
    CNum resultNumber = *new CNum(realPart, imaginaryPart);
    
    for (int i = 1; i < power; i++) {
        resultNumber = resultNumber * *this;
    }
    
    return resultNumber;
}

CNum CNum::operator +(const CNum secondAddition) const {
    return *new CNum(realPart + secondAddition.realPart, imaginaryPart + secondAddition.imaginaryPart);
}

CNum CNum::operator +(double secondAddition) const {
    return *new CNum(realPart + secondAddition, imaginaryPart);
}

CNum CNum::operator -(const CNum secondAddition) const {
    return *new CNum(realPart - secondAddition.realPart, imaginaryPart - secondAddition.imaginaryPart);
}

CNum CNum::operator -(double secondAddition) const {
    return *new CNum(realPart - secondAddition, imaginaryPart);
}

CNum CNum::operator *(const CNum secondAddition) const{
    return *new CNum((realPart * secondAddition.realPart - imaginaryPart * secondAddition.imaginaryPart),
                     (imaginaryPart * secondAddition.realPart + realPart * secondAddition.imaginaryPart));
}

CNum CNum::operator *(double secondAddition) const{
    return *new CNum(realPart * secondAddition, imaginaryPart * secondAddition);
}

CNum CNum::operator /(const CNum num) const{
    if (num.realPart == 0 && num.imaginaryPart == 0) return 0;
    double div = num.realPart * num.realPart + num.imaginaryPart * num.imaginaryPart;
    return *new CNum((realPart * num.realPart + imaginaryPart * num.imaginaryPart) / div, (realPart * num.imaginaryPart - imaginaryPart * num.realPart) / div * -1);
}

CNum CNum::operator /(double num) const{
    return *this / CNum(num, 0);
}

bool CNum::operator ==(const CNum secondAddition) const{
    return realPart == secondAddition.realPart && imaginaryPart == secondAddition.imaginaryPart;
}

bool CNum::operator !=(const CNum secondAddition) const {
    return !(*this == secondAddition);
}
