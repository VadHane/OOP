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
    
    CNum operator /(const CNum) const;
    CNum operator /(double) const;
    
    bool operator ==(const CNum) const;
    bool operator !=(const CNum) const;
    
    friend std::ostream& operator <<(std::ostream& out, const CNum &num){
        if(num.imaginaryPart >= 0) out << "(" << num.realPart << " + " << num.imaginaryPart << "i)";
        else out << "(" << num.realPart << " - " << num.imaginaryPart * - 1<< "i)";
        return out;
    }
};



}
#endif /* CNum_hpp */
