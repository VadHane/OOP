#ifndef THeximal_hpp
#define THeximal_hpp

#include "ITInteger.hpp"
#include <stdio.h>

class THeximal : public ITInteger {
    int* heximalNumber;
    
public:
    THeximal();
    
    THeximal(long);
    
    THeximal(THeximal&);
    
    ~THeximal();
    
    
    ITInteger& operator +=(const ITInteger&);
    
    ITInteger& operator -=(const ITInteger&);
    
    ITInteger& operator *=(const ITInteger&);
    
    void input();
    
    void output() const;
};

#endif
