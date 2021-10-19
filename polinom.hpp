#ifndef polinom_hpp
#define polinom_hpp


#include <stdio.h>
#include "list.hpp"
#include "CNum.hpp"

class Polinom{
    SingleLinkList::List<CNumber::CNum> *allCoeff;
    SingleLinkList::List<int> *powers; // power of the number X for all members
    
    int power;
public:
    Polinom();
    
    Polinom(const SingleLinkList::List<CNumber::CNum> &secondOperand);
    
    Polinom(const Polinom &secondOperand);
    
    
    
    ~Polinom();
    
    void input(); 
    
    void add(CNumber::CNum number);
    
    friend void add(Polinom &, CNumber::CNum number, int power);
    
    void output();
    
    Polinom* copy() const;
    
    CNumber::CNum getValueInPoint(CNumber::CNum pointX);
    
    CNumber::CNum getValueInPoint(CNumber::CNum pointX, CNumber::CNum pointB);
    
    friend Polinom operator +(const Polinom &, const Polinom &);
    
    Polinom operator -(const Polinom &) const;
    
    Polinom operator *(const Polinom &) const;
    
    bool operator ==(const Polinom &) const;
    
    Polinom& operator =(const Polinom &);
};



#endif
