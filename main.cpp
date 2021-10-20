#include <iostream>
#include "CNum.hpp"
#include "polinom.hpp"
using namespace std;

int main() {
    Polinom add1 = *new Polinom();
    Polinom add2 = *new Polinom();
    
    while (true) {
        cout << "\n1) + \n2) - \n3) * \n4) == \n->";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            add1.input();
            add2.input();
            
            add1.output();
            cout << "\n        + \n";
            add2.output();
            cout << "\n        = \n";
            (add1 + add2).output();
        } else if (choice == 2){
            add1.input();
            add2.input();
            
            add1.output();
            cout << "\n        - \n";
            add2.output();
            cout << "\n        = \n";
            (add1 - add2).output();
        } else if (choice == 3){
            add1.input();
            add2.input();
            
            add1.output();
            cout << "\n        * \n";
            add2.output();
            cout << "\n        = \n";
            (add1 * add2).output();
        } else if (choice == 4) {
            add1.input();
            add2.input();
            
            if (add1 == add2) {
                cout << "\nadd1 = add2\n";
            } else {
                cout << "\nadd1 = add2\n";
            }
        } else {
            break;
        }
        
    }
}
