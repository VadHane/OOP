#ifndef CNum_hpp
#define CNum_hpp

#include <stdio.h>
#include <iostream>
namespace CNumber {

class CNum{
public:
    double realPart;
    double imaginaryPart;
    int i;
    

    CNum(double, double);
    CNum(double);
    CNum();
    
    void input();
    char* toString();
    CNum pow(int);
    CNum pow(CNum, int);
    
    CNum operator +(CNum);
    CNum operator +(double);
    
    CNum operator -(CNum);
    CNum operator -(double);
    
    CNum operator *(CNum);
    CNum operator *(double);
    
    bool operator ==(CNum);
    bool operator !=(CNum);
};



}
#endif /* CNum_hpp */
