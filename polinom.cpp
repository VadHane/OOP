#include "polinom.hpp"
#include "list.hpp"
#include "CNum.hpp"
#include <iostream>
#include <typeinfo>

using namespace std;
using namespace CNumber;
using namespace SingleLinkList;

Polinom::Polinom(){
    cout << "Конструктор без параметрів: \n";
    allCoeff = new List<CNum>();
    powers = new List<int>();
    power = 0;
}

Polinom::Polinom(const List<CNum> &secondOperand){
    cout << "Конструктор з параметром: \n";
    
    if(allCoeff == nullptr) allCoeff = new List<CNum>();
    
    *allCoeff = secondOperand;
    
    Iterator<CNum> iter = *new Iterator<CNum>(*allCoeff);
    powers = new List<int>();
    while (iter) {
        powers->add((iter++)->position);
        power++;
    }
}

Polinom::Polinom(CNumber::CNum add1, CNumber::CNum add2){
    cout << "Конструктор з двома комп числами: \n";
    allCoeff = new List<CNum>();
    powers = new List<int>();
    
    allCoeff->add(add1);
    powers->add(0);
    
    allCoeff->add(add2);
    powers->add(1);
}

Polinom::Polinom(const Polinom &secondOperand){
    cout << "\nКонструктор копіювання: \n";
    Polinom* tmp = secondOperand.copy();
    this->allCoeff = tmp->allCoeff;
    this->powers = tmp->powers;
    this->power = tmp->power;
    
}


Polinom::~Polinom(){
    cout << "\nДеструктор полінома\n";
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

std::ostream& operator <<(std::ostream& out, const CNum &num){
    if(num.imaginaryPart >= 0) out << "(" << num.realPart << " + " << num.imaginaryPart << "i)";
    else out << "(" << num.realPart << " - " << num.imaginaryPart * - 1<< "i)";
    return out;
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


void Polinom::output() {
    if (allCoeff == nullptr || powers == nullptr) {
        cout << "NULL" << endl;
        return;
    }
    
    Iterator<int> iterPow = *new Iterator<int>(*powers);
    Iterator<CNum> iter = *new Iterator<CNum>(*allCoeff);
    
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
    Iterator<CNum> iter = *new Iterator<CNum>(*allCoeff);
    
    while (iter) {
        result->add(allCoeff->get(iter++));
    }
    
    
    return result;
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
