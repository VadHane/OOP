#include <iostream>
#include "CNum.hpp"
#include "NewPolinom.hpp"
using namespace std;

int main() {
    
    NewPolinom add1;
    NewPolinom add2;
    
    while (true) {
        cout << "\nChoice action: \
                \n1)Power \
                \n2)Multiply by -1 \
                \n3)Increase each item by 1 \
                \n4)Derivative \
                \n5)Indefinite Integral) \
                \n6)Definite Integral \
                \n7)Get coeff by index \
                \n0)Stop \
                \n--> ";
        int choice;
        cin >> choice;
        
        if (choice == 1) {
            cin >> add1;
            int power;
            cout << "Power: ";
            cin >> power;
            
            cout << add1 << "\n        ^ \n" << power << "\n        = \n" << (add1^power);

        } else if (choice == 2){
            cin >> add1;
            
            cout << add1 << "\n        ! \n" << "\n        = \n" << (!add1);
        } else if (choice == 3){
            cin >> add1;
            
            cout << add1 << "\n        ++ \n" << "\n        = \n" << (++add1);
        } else if (choice == 4) {
            cin >> add1;
            
            cout << add1 << "\n        "<< add1.getName() << " = " << add1.getName() <<"`("<< add1.getSymbolOfVar() <<") \n" << "\n        = \n" << add1.derivative();
        } else if (choice == 5){
            cin >> add1;
            
            cout << add1 << "\n        "<< add1.getName() << " = F(" << add1.getName() << ") \n" << "\n        = \n" << add1.indefiniteIntegral();
        } else if (choice == 6){
            cin >> add1;
            double top, bottom;
            cout << "Input top border: ";
            cin >> top;
            cout << "Input bottom border: ";
            cin >> bottom;
            
            cout << add1 << "\n        "<< add1.getName() << " = F(" << add1.getName()  <<") \n" << "\n        = \n" << add1.definiteIntegral(bottom, top);
        } else if (choice == 7){
            int index;
            cin >> add1;
            cout << "Input index: ";
            cin >> index;
            
            cout << add1 << "\n " << add1.getName() << "[" << index << "] = " << add1[index];
        } else {
            break;
        }
        
    }
}
