#ifndef polinom_hpp
#define polinom_hpp


#include <stdio.h>
#include "list.hpp"
#include "CNum.hpp"

class Polinom{
    SingleLinkList::List<CNumber::CNum> allCoeff;
    SingleLinkList::List<int> powers; // power of the number X for all members
    
    int power;
public:
    Polinom();
    
    //~Polinom();
    
    void input(int lenOfList);
    
    void add(CNumber::CNum number);
    
    void add(CNumber::CNum number, int power);
    
    void output();
    
    Polinom* copy();
    
    CNumber::CNum getValueInPoint(CNumber::CNum pointX);
    
    CNumber::CNum getValueInPoint(CNumber::CNum pointX, CNumber::CNum pointB);
    
    Polinom operator +(Polinom);
    
    Polinom operator -(Polinom);
    
    Polinom operator *(Polinom);
    
    bool operator ==(Polinom);
};

#endif
