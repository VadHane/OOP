#include <iostream>
#include "CNum.hpp"
#include "polinom.hpp"
using namespace std;



int main() {
    Polinom polinom = *new Polinom();
    int len;
    
    cout << "Input length of your polinom: ";
    cin >> len;
    polinom.input(len);
    cout << "Your polinom: " << endl;
    polinom.output();
    
    
    while (true) {
        int userChoice;
        Polinom secondNumber = *new Polinom();
        CNumber::CNum CNumber;
        CNumber::CNum CNumberB;
        
        cout << "\nChoice action: \
        \n1)Adding \
        \n2)Subtraction \
        \n3)Multiplication \
        \n4)Value in point x \
        \n5)Value in point (x + b) \
        \n0)Stop \
        \n--> ";
        
        cin >> userChoice;
        
        switch (userChoice) {
            case 1:
                cout << "Input length of your second polinom: ";
                cin >> len;
                secondNumber.input(len);
                
                polinom.output();
                cout << endl << "    +      " << endl;
                secondNumber.output();
                cout << endl << "    =      " << endl;
                (polinom + secondNumber).output();
                
                break;
            case 2:
                cout << "Input length of your second polinom: ";
                cin >> len;
                secondNumber.input(len);
                
                polinom.output();
                cout << endl << "    -      " << endl;
                secondNumber.output();
                cout << endl << "    =      " << endl;
                (polinom - secondNumber).output();
                
                break;
            case 3:
                cout << "Input length of your second polinom: ";
                cin >> len;
                secondNumber.input(len);
                
                polinom.output();
                cout << endl << "    *      " << endl;
                secondNumber.output();
                cout << endl << "    =      " << endl;
                (polinom * secondNumber).output();
                
                break;
            case 4:
                cout << "Input point x: " << endl;
                CNumber.input();
                CNumber = polinom.getValueInPoint(CNumber);
                
                cout << "Result: (" << CNumber.realPart << " + " << CNumber.imaginaryPart << "i);";
                
                break;
            case 5:
                cout << "Input point x: " << endl;
                CNumber.input();
                cout << endl << "Input point B: " << endl;
                CNumberB.input();
                CNumber = polinom.getValueInPoint(CNumber, CNumberB);
                
                cout << "Result: (" << CNumber.realPart << " + " << CNumber.imaginaryPart << "i);";
                
                break;
            case 0:
                return 0;
            default:
                cout << "Unkomon command";
                break;
        }
    }
    
}
