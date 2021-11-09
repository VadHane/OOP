#ifndef ITInteger_hpp
#define ITInteger_hpp

#include <stdio.h>

class ITInteger {
public:
    
    
    long number;
    
    const int len = 65;
    
    bool minus = false;
    
    virtual ITInteger& operator +=(const ITInteger&) = 0;
    //virtual ITInteger& operator +=(long) = 0; there is constructor [long -> ITInteger]
    
    virtual ITInteger& operator -=(const ITInteger&) = 0;
    
    virtual ITInteger& operator *=(const ITInteger&) = 0;
    
    virtual void input() = 0;
    
    virtual void output() const = 0;
};

#endif 
