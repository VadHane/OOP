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
    
    CNum operator +(const CNum) const;
    CNum operator +(double) const;
    
    CNum operator -(const CNum) const;
    CNum operator -(double) const;
    
    CNum operator *(const CNum) const;
    CNum operator *(double) const;
    
    bool operator ==(const CNum) const;
    bool operator !=(const CNum) const;
};



}
#endif /* CNum_hpp */
