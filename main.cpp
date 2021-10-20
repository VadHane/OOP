#include <iostream>
#include "CNum.hpp"
#include "polinom.hpp"
using namespace std;

int main() {
    Polinom add1 = *new Polinom();
    Polinom add2 = *new Polinom();
    
    while (true) {
        cout << "\nChoice action: \
                \n1)Adding \
                \n2)Subtraction \
                \n3)Multiplication \
                \n4)Value in point x \
                \n5)Polinom in point (x + b) \
                \n0)Stop \
                \n--> ";
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
            CNumber::CNum CNumber;
            
            cout << "Input point x: " << endl;
            CNumber.input();
            CNumber = add1.getValueInPoint(CNumber);
                            
            cout << "Result: (" << CNumber.realPart << " + " << CNumber.imaginaryPart << "i);\n";
        } else if (choice == 5){
            add1.input();
            
            CNumber::CNum CNumber;
            cout << "Input point В: " << endl;
            CNumber.input();
            
            add1.output();
            cout << "\n   ---   х = х + b  ---  \n";
            add1.newViewWithPointB(CNumber).output();
        } else {
            break;
        }
        
    }
}
