#include <iostream>
#include "CNum.hpp"
#include "polinom.hpp"
using namespace std;

int main() {
    {
        
    Polinom polinom = *new Polinom();
    
    polinom.input();
    cout << "Your polinom: " << endl;
    polinom.output();
    
    
    }
    
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
    
    cout << "\nMain завершила роботу\n";
}
