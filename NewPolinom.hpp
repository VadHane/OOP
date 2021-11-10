#ifndef NewPolinom_hpp
#define NewPolinom_hpp

#include <iostream>
#include "polinom.hpp"
#include "CNum.hpp"

using namespace std;

class NewPolinom : public Polinom {
private:
    char name, symbolOfVar;
    
public:
    NewPolinom();
    
    NewPolinom(const Polinom&);
    
    NewPolinom(const NewPolinom&);
    
    NewPolinom(const SingleLinkList::List<CNumber::CNum> list) : Polinom(list) {name = 'y'; symbolOfVar = 'x';};
    
    NewPolinom(CNumber::CNum num1, CNumber::CNum num2) : Polinom(num1, num2) {name = 'y'; symbolOfVar = 'x';}
    
    ~NewPolinom();
    
    
    
    char getName() const {return name;}
    
    char getSymbolOfVar() const {return symbolOfVar;}
    
    void setSymbolOfVar(char);
    
    NewPolinom* copy() const;
    
    
    NewPolinom& derivative() const;
    
    NewPolinom& indefiniteIntegral() const;
    
    CNumber::CNum definiteIntegral(double, double) const;
    
    
    
    // power
    NewPolinom& operator ^(int power) const;
    
    // mult -1
    NewPolinom& operator !() const;
    
    // get elem by index
    CNumber::CNum operator [](int index);
    
    NewPolinom& operator =(const NewPolinom&); 
    
    NewPolinom& operator ++(int);
    
    NewPolinom& operator ++();
    
    
    
friend ostream& operator<< (ostream& out, const NewPolinom& pol){
    out << pol.name << " =";
    
    if (pol.allCoeff == nullptr || pol.powers == nullptr) {
        out << "NULL" << endl;
        return out;
    }
    
    SingleLinkList::Iterator<int> iterPow(*pol.powers);
    SingleLinkList::Iterator<CNumber::CNum> iter(*pol.allCoeff);
    
    if(pol.powers->get(iterPow) == 0) out << pol.allCoeff->get(iter);
    else out << "(" << pol.allCoeff->get(iter) << " * " << pol.symbolOfVar << "^" << pol.powers->get(iterPow) << ")";
    iter++;
    iterPow++;
        
    while (iter) {
        
        out << " + (" << pol.allCoeff->get(iter) << " * " << pol.symbolOfVar << "^" << pol.powers->get(iterPow) << ")";
        iter++;
        iterPow++;
    }
    
    return out;
}
    
friend istream& operator>> (istream& in, NewPolinom& pol){
    cout << "Input name of your polinome: ";
    in >> pol.name;
    cout << "Input symbol of var of your polinome: ";
    in >> pol.symbolOfVar;
    
    pol.input();
    
    return in;
}
    
};

#endif
