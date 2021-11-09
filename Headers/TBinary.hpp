#ifndef TBinary_hpp
#define TBinary_hpp

#include <stdio.h>
#include "ITInteger.hpp"

class TBinary : public ITInteger {
    int* binaryNumber;
    
public:
    TBinary();
    
    TBinary(long);
    
    TBinary(TBinary&);
    
    ~TBinary();
    
    
    ITInteger& operator +=(const ITInteger&);
    
    ITInteger& operator -=(const ITInteger&);
    
    ITInteger& operator *=(const ITInteger&);
    
    void input();
    
    void output() const;
};

#endif 
