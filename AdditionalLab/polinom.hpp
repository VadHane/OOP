#ifndef polinom_hpp
#define polinom_hpp


#include <stdio.h>
#include "list.hpp"
#include "CNum.hpp"

class Polinom{
protected:
    SingleLinkList::List<CNumber::CNum> *allCoeff;
    SingleLinkList::List<int> *powers; // power of the number X for all members
    
    int power;
    
public:
    Polinom();
    
    Polinom(const SingleLinkList::List<CNumber::CNum> &secondOperand);
    
    Polinom(const Polinom &secondOperand);
    
    Polinom(CNumber::CNum add1, CNumber::CNum add2);
    
    
    SingleLinkList::List<CNumber::CNum> *getAllCoeff() {return allCoeff;}
    
    SingleLinkList::List<int> *getPowers() {return powers;}
    
    int getPower() {return power;}
    
    ~Polinom();
    
    void add(CNumber::CNum number);
    
    void add(Polinom polinom);
    
    friend void add(Polinom &, CNumber::CNum number, int power);
    
    void add(CNumber::CNum number, int power);
    
    void input();
    
    void output();
    
    Polinom* copy() const;
    
    CNumber::CNum getValueInPoint(CNumber::CNum pointX);
    
    Polinom newViewWithPointB(CNumber::CNum pointB);
    
    friend Polinom operator +(const Polinom &, const Polinom &);
    
    Polinom operator -(const Polinom &) const;
    
    Polinom operator *(const Polinom &) const;
    
    Polinom operator *(const CNumber::CNum &) const;
    
    bool operator ==(const Polinom &) const;
    
    Polinom& operator =(const Polinom &);
    
    
    static Polinom erectSimilar(Polinom polinom){
        
        SingleLinkList::Iterator<CNumber::CNum> tmpIter = *new SingleLinkList::Iterator<CNumber::CNum>(polinom.allCoeff->getFirstElement());
        SingleLinkList::Iterator<int> tmpIterPower = *new SingleLinkList::Iterator<int>(polinom.powers->getFirstElement());
        
        int maxPower = 0;
        
        while(tmpIter){
            tmpIter++;
            int power = polinom.powers->get(tmpIterPower++);
            maxPower = maxPower < power ? power : maxPower;
        }
        
        tmpIter.moveToStart();
        tmpIterPower.moveToStart();
        
        Polinom result = *new Polinom();
        
        
        for(int i = 0; i <= maxPower; i++){
            CNumber::CNum number = *new CNumber::CNum(0, 0);
            bool wasEdit = false;
            
            while(tmpIter){
                int power = polinom.powers->get(tmpIterPower++);
                
                if(power == i){
                    number = number + polinom.allCoeff->get(tmpIter++);
                    wasEdit = true;
                    continue;
                }
                
                tmpIter++;
            }
            
            if (wasEdit) result.add(number);
            
            tmpIter.moveToStart();
            tmpIterPower.moveToStart();
        }
        
        return result;
    }
};



#endif
