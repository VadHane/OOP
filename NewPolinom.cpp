#include "NewPolinom.hpp"
#include "polinom.hpp"
#include "list.hpp"

using namespace CNumber;
using namespace SingleLinkList;



/// Конструктор без параметрів
NewPolinom::NewPolinom(){
    // неявний виклик конструктора без параметрів для Polinom
    name = 'y';
    symbolOfVar = 'x';
}

/// Конструктор для довн-каста.
/// @param polinom Поліном, що потрібно перетворити на новий тип.
NewPolinom::NewPolinom(const Polinom& polinom){
    Polinom *tmp = polinom.copy();
    
    allCoeff = tmp->getAllCoeff();
    powers = tmp->getPowers();
    power = tmp->getPower();
    name = 'y';
    symbolOfVar = 'x';
}

/// Конструктор копіювання
/// @param polinom Об'єкт, який потрібно скопіювати
NewPolinom::NewPolinom(const NewPolinom& polinom){
    NewPolinom *tmp = polinom.copy();
    name = polinom.name;
    symbolOfVar = polinom.symbolOfVar;
    allCoeff = tmp->allCoeff;
    powers = tmp->powers;
    power = tmp->power;
    
}

/// Деструктор
NewPolinom::~NewPolinom(){
    delete allCoeff;
    delete powers;
    allCoeff = nullptr;
    powers = nullptr;
}





/// Знаходить похідну полінома
NewPolinom& NewPolinom::derivative() const{
    NewPolinom *res = new NewPolinom();
    res->name = name;
    res->symbolOfVar = symbolOfVar;
    
    Iterator<CNum> iter(*allCoeff);
    Iterator<int> iterPow(*powers);
    
    while (iter) {
        int power = (iterPow++)->value;
        CNum elem = (iter++)->value;
        
        if (power == 0) continue;
        
        res->add(elem * power, power - 1);
    }
    
    return *res;
}

/// Невизначений інтеграл полінома
NewPolinom& NewPolinom::indefiniteIntegral() const{
    NewPolinom *res = new NewPolinom();
    res->name = name;
    res->symbolOfVar = symbolOfVar;
    
    Iterator<CNum> iter(*allCoeff);
    Iterator<int> iterPow(*powers);
    
    while (iter) {
        int power = (iterPow++)->value;
        CNum elem = (iter++)->value;
        
        res->add(elem / (power + 1), power + 1);
    }
    
    return *res;

}

/// Визначений інтеграл полінома.
/// @param bottom  Нижня межа.
/// @param top Верхня межа.
CNum NewPolinom::definiteIntegral(double bottom, double top) const{
    NewPolinom tmp = this->indefiniteIntegral();
    
    return tmp.getValueInPoint(top) - tmp.getValueInPoint(bottom);
}





/// Сеттер для поля змінної в поліномі. Валідує вхідні значення перед присвоїнням.
/// @param value Нове значення поля назви змінної.
void NewPolinom::setSymbolOfVar(char value){
    if ( ('A' < value && 'Z' > value) || ('a' < value && 'z' > value) ){
        symbolOfVar = value;
    }
}

/// Функція копіювання вмісту елемента NewPolinom
NewPolinom* NewPolinom::copy() const{
    NewPolinom* result = new NewPolinom(*Polinom::copy());
    result->name = name;
    result->symbolOfVar = symbolOfVar;
    
    return result;
}

/// Оператор піднесення до степеня.
/// @param power Показник степеня, до якого потрібно піднести.
NewPolinom& NewPolinom::operator ^(int power) const{
    Polinom *res = new Polinom(*this);
    
    for (int i = 1; i < power; i++) {
        *res = *res * *this;
    }
    NewPolinom *tmp = new NewPolinom(*res);
    tmp->name = name;
    tmp->symbolOfVar = symbolOfVar;
    
    return *tmp;
}

/// Множить кожен коефіцієнт полінома на -1
NewPolinom& NewPolinom::operator !() const {
    NewPolinom *res = new NewPolinom(*this);
    res->name = name;
    res->symbolOfVar = symbolOfVar;
    
    Iterator<CNum> iter(*res->allCoeff);
    
    while (iter) {
        CNum tmp = res->allCoeff->get(iter);
        tmp = tmp * -1;
        (iter++)->value = tmp;
    }
    
    return *res;
}

/// Повертає коефіцієнт при змінній з показником степеня index. Або nullptr, якщо такого немає.
/// @param index Показник степеня, при якому знаходиться коефіцієнт.
CNumber::CNum NewPolinom::operator [](int index){
    return allCoeff->get(index);
}

/// Оператор присвоєння.
/// @param secondOperand Поліном, з інформацію якого потрібно присвоїти.
NewPolinom& NewPolinom::operator =(const NewPolinom& secondOperand){
    (Polinom)*this = (Polinom)secondOperand;
    name = secondOperand.name;
    symbolOfVar = secondOperand.symbolOfVar;
    
    return *this;
}

/// Збільшує на одиницю кожен коефіцієнт.
NewPolinom& NewPolinom::operator ++(int){
    NewPolinom *res = new NewPolinom(*this);
    res->name = name;
    res->symbolOfVar = symbolOfVar;
    Iterator<CNum> iter(*allCoeff);
    
    while (iter) {
        CNum tmp = allCoeff->get(iter);
        tmp = tmp + 1;
        (iter++)->value = tmp;
    }
    
    return *res;
}

/// Збільшує на одиницю кожен коефіцієнт.
NewPolinom& NewPolinom::operator ++(){
    Iterator<CNum> iter(*allCoeff);
    
    while (iter) {
        CNum tmp = allCoeff->get(iter);
        tmp = tmp + 1;
        (iter++)->value = tmp;
    }
    
    return *copy();
}

