#include <iostream>
#include "CNum.hpp"
#include "polinom.hpp"
using namespace std;

int main() {
    Polinom add1 = *new Polinom();
    Polinom add2 = *new Polinom();
    
    while (true) {
        cout << "\n1) + \n2) - \n3) * \n4) = \n->";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            add1.input();
            add2.input();
            
            add1.output();
            cout << "\n        + \n";
            add2.output();
            cout << endl;
            (add1 + add2).output();
        } else if (choice == 2){
            add1.input();
            add2.input();
            
            add1.output();
            cout << "\n        - \n";
            add2.output();
            cout << endl;
            (add1 - add2).output();
        } else if (choice == 3){
            add1.input();
            add2.input();
            
            add1.output();
            cout << "\n        * \n";
            add2.output();
            cout << endl;
            (add1 * add2).output();
        } else if (choice == 4) {
            add1.input();
            add2.input();
            Polinom add3 = *new Polinom();
            add3.input();
            
            add1 = add2 = add3;
            
            add2 = add1 + add3;
            
            cout << "\nadd1: \n";
            add1.output();
            
            cout << "\nadd1: \n";
            add2.output();
            
            cout << "\nadd1: \n";
            add3.output();
        } else {
            break;
        }
        
    }
}
