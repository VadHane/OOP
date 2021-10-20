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
    
    Polinom(CNumber::CNum, CNumber::CNum); 
    
    Polinom(const Polinom &secondOperand);
    
    
    
    ~Polinom();
    
    void add(CNumber::CNum number);
    
    friend void add(Polinom &, CNumber::CNum number, int power);
    
    void input();
    
    void output();
    
    Polinom* copy() const;
    
    Polinom& operator =(const Polinom &secondOperand);
};



#endif
