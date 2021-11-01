#include "polinom.hpp"
#include "list.hpp"
#include "CNum.hpp"
#include <iostream>
#include <typeinfo>

using namespace std;
using namespace CNumber;
using namespace SingleLinkList;

Polinom::Polinom(){
    allCoeff = new List<CNum>();
    powers = new List<int>();
    power = 0;
}

Polinom::Polinom(const List<CNum> &secondOperand){
    
    //if(allCoeff != nullptr) allCoeff->freeMemory();


    allCoeff = new List<CNum>();
    
    *allCoeff = secondOperand;
    
    Iterator<CNum> iter(*allCoeff);
    powers = new List<int>();
    while (iter) {
        powers->add((iter++)->position);
        power++;
    }
}

Polinom::Polinom(const Polinom &secondOperand){
    Polinom* tmp = secondOperand.copy();
    this->allCoeff = tmp->allCoeff;
    this->powers = tmp->powers;
    this->power = tmp->power;
    
}

Polinom::Polinom(CNumber::CNum add1, CNumber::CNum add2){
    allCoeff = new List<CNum>();
    powers = new List<int>();
    
    allCoeff->add(add1);
    powers->add(0);
    
    allCoeff->add(add2);
    powers->add(1);
}

Polinom::~Polinom(){
    delete allCoeff;
    delete powers;
    allCoeff = nullptr;
    powers = nullptr;
    
}

 
void Polinom::input(){
    int lenOfList;
    cout << "Input length of your polinom: ";
    cin >> lenOfList;
    
    allCoeff->freeMemory();
    powers->freeMemory();
    power = 0;
    
    cout << "Input your polinom: " << endl;
    for (int i = 0; i <lenOfList; i++) {
        CNum item;
        cout << "Input your complex number for x^" << i << ": " << endl;
        item.input();
        allCoeff->add(item);
        powers->add(power);
        power++;
    }
}

void Polinom::add(CNum number){
    allCoeff->add(number);
    powers->add(power);
    power++;
}

void add(Polinom &polinom, CNumber::CNum number, int power){
    polinom.allCoeff->add(number);
    polinom.powers->add(power);
}

void Polinom::add(CNumber::CNum number, int power){
    allCoeff->add(number);
    powers->add(power);
}

void Polinom::add(Polinom polinom){
    Iterator<CNum> iter(polinom.allCoeff->getFirstElement());
    Iterator<int> iterPow(polinom.powers->getFirstElement());
    
    while (iter) {
        ::add(*this, (iter++)->value, (iterPow++)->value);
    }
    
}

void add(CNumber::CNum number, int power);

void Polinom::output() {
    if (allCoeff == nullptr || powers == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    
    Iterator<int> iterPow(*powers);
    Iterator<CNum> iter(*allCoeff);
    
    cout << allCoeff->get(iter);
    iter++;
    iterPow++;
    
    while (iter) {
        cout << " + (" << allCoeff->get(iter) << " * x^" << powers->get(iterPow) << ")";
        iter++;
        iterPow++;
    }
    
    //delete &iter;
}

Polinom* Polinom::copy() const{
    Polinom* result = new Polinom();
    Iterator<CNum> iter(*allCoeff);
    Iterator<int> iterPow(*powers);
    
    while (iter) {
        ::add(*result, allCoeff->get(iter++), powers->get(iterPow++));
    }
    
    
    return result;
}

CNum Polinom::getValueInPoint(CNum point){
    CNum result;
    int power = 1;
    Iterator<CNum> iter(*allCoeff);
    
    result = (iter++)->value;
    
    while (iter) {
        result = result + ((iter++)->value * point.pow(power));
    }
    
    
    return result;
}


long factorial(int number){
    long result = 1;
    for (int i = 1; i <= number; i++) result *= i;
    return result;
}

double binomCoeff(int topBorder, int lowBorder){
    return (factorial(topBorder) / (factorial(lowBorder) * factorial(topBorder - lowBorder)));
}

Polinom pow(CNum numberB, int power){
    Polinom polinom;

    for (int i = 0; i <= power; i++) {
        ::add(polinom, numberB.pow(power - i) * binomCoeff(power, i), i);
    }
    
    return polinom;
}

Polinom Polinom::newViewWithPointB(CNum pointB){
    Polinom result = *new Polinom();
    
    Iterator<CNum> iter(allCoeff->getFirstElement());
    Iterator<int> iterPow(powers->getFirstElement());
    
    while (iter) {
        result.add(pow(pointB, (iterPow++)->value) * (iter++)->value);
    }
    
    return erectSimilar(result);
}

Polinom operator +(const Polinom &firstAddition, const Polinom &secondAddition){
    Polinom result = *new Polinom();
    SingleLinkList::Iterator<CNumber::CNum> firstIter(*firstAddition.allCoeff);
    SingleLinkList::Iterator<CNumber::CNum> secondIter(*secondAddition.allCoeff);
    
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

Polinom Polinom::operator -(const Polinom &secondAddition) const{
    Polinom result = *new Polinom();
    Iterator<CNum> firstIter(*allCoeff);
    Iterator<CNum> secondIter(*secondAddition.allCoeff);
    
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

Polinom Polinom::operator *(const Polinom &secondAddition) const{ // !!!
    Polinom tmp;
    
    Iterator<CNum> firstIter(*allCoeff);
    Iterator<int> firstIterPower(*powers);
    Iterator<CNum> secondIter(*secondAddition.allCoeff);
    Iterator<int> secondIterPower(*secondAddition.powers);
    
    while (firstIter) {
        CNum firstElement = allCoeff->get(firstIter++);
        int power = powers->get(firstIterPower++);
        
        while(secondIter){
            ::add(tmp, firstElement * secondAddition.allCoeff->get(secondIter++), power + secondAddition.powers->get(secondIterPower++));
        }
        
        secondIter.moveToStart();
        secondIterPower.moveToStart();
    }
    
    return erectSimilar(tmp);
}

Polinom Polinom::operator *(const CNum &secondAddition) const {
    Polinom *polinom = new Polinom();
    Iterator<CNum> iter(allCoeff->getFirstElement());
    Iterator<int> iterPow(powers->getFirstElement());
    
    while(iter){
        ::add(*polinom, secondAddition * (iter++)->value, (iterPow++)->value);
    }
    
    return *polinom;
}

bool Polinom::operator ==(const Polinom &secondAddition) const{
    Iterator<CNum> firstIter(*allCoeff);
    Iterator<CNum> secondIter(*secondAddition.allCoeff);
    
    
    while (firstIter) {
        if (secondIter) {
            if ((firstIter++)->value != (secondIter++)->value) return false;
        } else {
            return false; // if first addition have some memberst but second addition have not it
        }
    }
    
    // if second addition have some members
    if (secondIter) return false;
    
    return true;
}

Polinom& Polinom::operator =(const Polinom &secondOperand){
    if(typeid(allCoeff->getFirstElement()->value) == typeid(secondOperand.allCoeff->getFirstElement()->value)) {
        if( this == &secondOperand ) return *this;
        allCoeff->freeMemory();
        powers->freeMemory();
        Polinom* tmp = secondOperand.copy();
        this->allCoeff = tmp->allCoeff;
        this->powers = tmp->powers;
        this->power = tmp->power;
    }
    
    return *this;
}
