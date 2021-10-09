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
    cout << "Input your complex number: " << endl << " Real part of this number: ";
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

long factorial(int number){
    long result = 1;
    for (int i = 1; i <= number; i++) result *= i;
    return result;
}

int binomCoeff(int topBorder, int lowBorder){
    return (int)(factorial(topBorder) / (factorial(lowBorder) * factorial(topBorder - lowBorder)));
}

CNum CNum::pow(CNum secondNumber, int power){
    CNum result = *new CNum(0);
    
    for (int i = 0; i <= power; i++) {
        result = result + pow(power - i) * secondNumber.pow(i) * binomCoeff(power, power - 1);
    }
    
    return result;
}

CNum CNum::operator +(CNum secondAddition){
    return *new CNum(realPart + secondAddition.realPart, imaginaryPart + secondAddition.imaginaryPart);
}

CNum CNum::operator +(double secondAddition){
    return *new CNum(realPart + secondAddition, imaginaryPart);
}

CNum CNum::operator -(CNum secondAddition){
    return *new CNum(realPart - secondAddition.realPart, imaginaryPart - secondAddition.imaginaryPart);
}

CNum CNum::operator -(double secondAddition){
    return *new CNum(realPart - secondAddition, imaginaryPart);
}

CNum CNum::operator *(CNum secondAddition){
    return *new CNum((realPart * secondAddition.realPart - imaginaryPart * secondAddition.imaginaryPart),
                     (imaginaryPart * secondAddition.realPart + realPart * secondAddition.imaginaryPart));
}

CNum CNum::operator *(double secondAddition){
    return *new CNum(realPart * secondAddition, imaginaryPart * secondAddition);
}

bool CNum::operator ==(CNum secondAddition) {
    return realPart == secondAddition.realPart && imaginaryPart == secondAddition.imaginaryPart;
}

bool CNum::operator !=(CNum secondAddition) {
    return !(*this == secondAddition);
}
