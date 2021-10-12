#include "polinom.hpp"
#include "list.hpp"
#include "CNum.hpp"
#include <iostream>
#include <typeinfo>

using namespace std;
using namespace CNumber;
using namespace SingleLinkList;

Polinom::Polinom(){
    allCoeff = *new List<CNum>();
    powers = *new List<int>();
    power = 0;
}

Polinom::Polinom(const List<CNum> &secondOperand){
    allCoeff = secondOperand;
    
    Iterator<CNum> iter = *new Iterator<CNum>(allCoeff);
    
    while (iter) {
        powers.add((iter++)->position);
        power++;
    }
}

Polinom::Polinom(const Polinom &secondOperand){
    allCoeff = secondOperand.allCoeff;
    powers = secondOperand.powers;
    
    power = secondOperand.power;
}

/*
Polinom::~Polinom(){
    //delete &allCoeff;
}
*/
 
void Polinom::input(){
    int lenOfList;
    cout << "Input length of your second polinom: ";
    cin >> lenOfList;
    
    cout << "Input your polinom: " << endl;
    for (int i = 0; i <lenOfList; i++) {
        CNum item;
        cout << "Input your complex number for x^" << i << ": " << endl;
        item.input();
        allCoeff.add(item);
        powers.add(power);
        power++;
    }
}

std::ostream& operator <<(std::ostream& out, const CNum &num){
    if(num.imaginaryPart >= 0) out << "(" << num.realPart << " + " << num.imaginaryPart << "i)";
    else out << "(" << num.realPart << " - " << num.imaginaryPart * - 1<< "i)";
    return out;
}

void Polinom::add(CNum number){
    allCoeff.add(number);
    powers.add(power);
    power++;
}

void add(Polinom &polinom, CNumber::CNum number, int power){
    polinom.allCoeff.add(number);
    polinom.powers.add(power);
}

Polinom operator +(const Polinom &firstAddition, const Polinom &secondAddition){
    Polinom result = *new Polinom();
    SingleLinkList::Iterator<CNumber::CNum> firstIter = *new SingleLinkList::Iterator<CNumber::CNum>(firstAddition.allCoeff);
    SingleLinkList::Iterator<CNumber::CNum> secondIter = *new SingleLinkList::Iterator<CNumber::CNum>(secondAddition.allCoeff);
    
    while (firstIter) {
        if (secondIter) {
            result.add((firstIter++)->value + (secondIter++)->value);
        } else {
            result.add((firstIter++)->value);
        }
    }
    
    while (secondIter) {
        result.add((secondIter++)->value);
    }
        
    return result;
}

void Polinom::output() {
    Iterator<int> iterPow = *new Iterator<int>(powers);
    Iterator<CNum> iter = *new Iterator<CNum>(allCoeff);
    
    cout << allCoeff.get(iter);
    iter++;
    iterPow++;
    
    while (iter) {
        cout << " + (" << allCoeff.get(iter) << " * x^" << powers.get(iterPow) << ")";
        iter++;
        iterPow++;
    }
    
    //delete &iter;
}

Polinom* Polinom::copy(){
    Polinom* result = new Polinom();
    Iterator<CNum> iter = *new Iterator<CNum>(allCoeff);
    
    while (iter) {
        result->add(allCoeff.get(iter++));
    }
    
    
    return result;
}

CNum Polinom::getValueInPoint(CNum point){
    CNum result;
    int power = 1;
    Iterator<CNum> iter = *new Iterator<CNum>(allCoeff);
    
    result = (iter++)->value;
    
    while (iter) {
        result = result + ((iter++)->value * point.pow(power));
    }
    
    
    return result;
}

CNum Polinom::getValueInPoint(CNum pointX, CNum pointB){
    CNum result;
    int power = 1;
    Iterator<CNum> iter = *new Iterator<CNum>(allCoeff);
    
    result = (iter++)->value;
    
    while (iter) {
        result = result + ((iter++)->value * pointX.pow(pointB, power));
    }
    
    
    return result;
}


Polinom Polinom::operator -(const Polinom &secondAddition){
    Polinom result = *new Polinom();
    Iterator<CNum> firstIter = *new Iterator<CNum>(allCoeff);
    Iterator<CNum> secondIter = *new Iterator<CNum>(secondAddition.allCoeff);
    
    while (firstIter) {
        if (secondIter) {
            result.add((firstIter++)->value - (secondIter++)->value);
        } else {
            result.add((firstIter++)->value);
        }
    }
    
    while (secondIter) {
        result.add((secondIter++)->value * -1);
    }
    
    
    
    
    return result;
}

Polinom Polinom::operator *(const Polinom &secondAddition){ // !!!
    Polinom tmp = *new Polinom();
    
    Iterator<CNum> firstIter = *new Iterator<CNum>(allCoeff);
    Iterator<int> firstIterPower = *new Iterator<int>(powers);
    Iterator<CNum> secondIter = *new Iterator<CNum>(secondAddition.allCoeff);
    Iterator<int> secondIterPower = *new Iterator<int>(secondAddition.powers);
    
    while (firstIter) {
        CNum firstElement = allCoeff.get(firstIter++);
        int power = powers.get(firstIterPower++);
        
        while(secondIter){
            ::add(tmp, firstElement * secondAddition.allCoeff.get(secondIter++), power + secondAddition.powers.get(secondIterPower++));
        }
        
        secondIter.moveToStart();
        secondIterPower.moveToStart();
    }
    

    
    Iterator<CNum> tmpIter = *new Iterator<CNum>(tmp.allCoeff);
    Iterator<int> tmpIterPower = *new Iterator<int>(tmp.powers);
    
    int maxPower = 0;
    
    while(tmpIter){
        tmpIter++;
        int power = tmp.powers.get(tmpIterPower++);
        maxPower = maxPower < power ? power : maxPower;
    }
    
    tmpIter.moveToStart();
    tmpIterPower.moveToStart();
    
    Polinom result = *new Polinom();
    
    
    for(int i = 0; i <= maxPower; i++){
        CNum number = *new CNum(0, 0);
        bool wasEdit = false;
        
        while(tmpIter){
            int power = tmp.powers.get(tmpIterPower++);
            
            if(power == i){
                number = number + tmp.allCoeff.get(tmpIter++);
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

bool Polinom::operator ==(const Polinom &secondAddition){
    Iterator<CNum> firstIter = *new Iterator<CNum>(allCoeff);
    Iterator<CNum> secondIter = *new Iterator<CNum>(secondAddition.allCoeff);
    
    
    while (firstIter) {
        if (secondIter) {
            if ((firstIter++)->value != (secondIter++)->value) return false;
        } else {
            return false; // if first addition have some memberst but second addition have not it
        }
    }
    
    // if second addition have some members
    if (secondIter) return false;
    
    delete &firstIter;
    delete &secondIter;
    
    return true;
}

Polinom& Polinom::operator =(const Polinom &secondOperand){
    if(typeid(allCoeff.getFirstElement()->value) == typeid(secondOperand.allCoeff.getFirstElement()->value)) {
    
    allCoeff = secondOperand.allCoeff;
    powers = secondOperand.powers;
    
    power = secondOperand.power;
    }
    
    return *this;
}


