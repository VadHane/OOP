#include <iostream>
#include "CNum.hpp"
#include "polinom.hpp"
using namespace std;



int main() {
    /*
    {
    CNumber::CNum num1;
    num1.realPart = 1;
    num1.imaginaryPart = 1;
    
    
    CNumber::CNum num2;
    num2.realPart = 2;
    num2.imaginaryPart = 2;
    
    Polinom pol1(num1, num2);
        pol1.output();
    
        pol1.copy()->output();
    }
    
    
    {
        
    Polinom polinom;
    
    polinom.input();
    cout << "Your polinom: " << endl;
    polinom.output();
    
    
    }
    
    {
        
    Polinom add1;
    Polinom add2;
    Polinom add3;
    
    add1.input();
    add2.input();
    add3.input();
    
    add1 = add2 = add3;
    
    cout << "\nadd1: \n";
    add1.output();
    
    cout << "\nadd1: \n";
    add2.output();
    
    cout << "\nadd1: \n";
    add3.output();
        
        add2.input();
        
        cout << "\nadd1: \n";
        add1.output();
        
        cout << "\nadd1: \n";
        add2.output();
        
        cout << "\nadd1: \n";
        add3.output();
        
    }
    */
    
    {
        CNumber::CNum num1;
        num1.realPart = 1;
        num1.imaginaryPart = 1;
        
        
        CNumber::CNum num2;
        num2.realPart = 2;
        num2.imaginaryPart = 2;
        
        Polinom pol1(num1, num2);
        
        
        Polinom pol2(pol1);
        
        pol1.output();
        cout << endl;
        pol2.output();
    }
     
    /*
    {
        
    cout << "Input length of your polinom:";
    int len;
    cin >> len;
    
    SingleLinkList::List<CNumber::CNum> list = *new SingleLinkList::List<CNumber::CNum>();
    
    for (int i = 0; i < len; i++){
        int real, imag;
        cout << "Input your complex number for x^" << i <<":\n";
        cout << "Real part of this number: ";
        cin >> real;
        cout << "Imaginary part of this number: ";
        cin >> imag;
        
        list.add(*new CNumber::CNum(real, imag));
    }
    
    cout << "Your polinom: " << endl;
    Polinom polinom = *new Polinom(list);
    polinom.output();
        
    }
    */
    cout << "\nMain завершила роботу\n";
}
