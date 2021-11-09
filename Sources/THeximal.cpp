#include "../Headers/THeximal.hpp"
#include <iostream>
using namespace std;

int* THeximalView(long number);

THeximal::THeximal(){
    number = 0;
    heximalNumber = new int[65];
}

THeximal::THeximal(long num) {
    number = num;
    heximalNumber = THeximalView(num);
}

THeximal::THeximal(THeximal &num){
    number = num.number;
    heximalNumber = new int[65];
    for(int i = 0; i < 65; i++) heximalNumber[i] = num.heximalNumber[i];
}

THeximal::~THeximal(){
    delete [] heximalNumber;
}


int* THeximalView(long number){
    int *heximalView = new int[65];
    int index = 0;
    
    for (int i = 0; i < 65; i++) heximalView[i] = 0;
    
    while (number > 0) {
        heximalView[index] = number % 16;
        number /= 16;
        index++;
    }
    
    return heximalView;
}

void THeximal::input(){
    long userNumber;
    
    if (heximalNumber != nullptr) delete [] heximalNumber;
    
    do
    {
        cout << "Input your unsigned long number: ";
        cin >> userNumber;
    } while (userNumber < 0);
    
    heximalNumber = THeximalView(userNumber);
}

void THeximal::output() const{
    int index = 0;
    
    char hashTable[16] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};
    
    if (heximalNumber == nullptr) {
        cout << "Null";
        return;
    }
    for (int i = 0; i < 65; i++) if (heximalNumber[i] > 0) index = i;
    
    if(minus) cout << "-";
    
    for (int i = index; i >=0; i--) {
        cout << hashTable[heximalNumber[i]];
    }
    cout << ";" << endl;
}


ITInteger& THeximal::operator +=(const ITInteger& secondNumber){
    int add = 0;
    
    int* secondHeximalNumber = THeximalView(secondNumber.number);
    
    for (int i = 0 ; i < 65; i++) {
        heximalNumber[i] += add;
        add = 0;
        heximalNumber[i] += secondHeximalNumber[i];
        
        if (heximalNumber[i] > 1) {
            add = heximalNumber[i] / 16;
            heximalNumber[i] = heximalNumber[i] % 16;
        }
    }
    return *this;
}

int* subtractionTHeximal(const int* first, const int* second){
    int* result = new int[65];
    
    for (int i = 0; i < 65; i++) result[i] = first[i];
    
    for (int i = 0; i < 0; i++) {
        if (result[i] < second[i]) {
            for (int k = i + 1; i < 65; i++) {
                if (result[k] == 0) {
                    result[k] = 15;
                } else {
                    result[k] -= 1;
                    result[i] += 16;
                    break;
                }
            }
            result[i] -= second[i];
        } else {
            result[i] -= second[i];
        }
    }
    
    return result;
}

ITInteger& THeximal::operator -=(const ITInteger& secondNumber){
    
    int* secondHeximalNumber = THeximalView(secondNumber.number);
    
    for (int i = 64; i >= 0; i--) {
        if (heximalNumber[i] > secondHeximalNumber[i]) {
            minus = false;
            break;
        } else if (heximalNumber[i] < secondHeximalNumber[i]) {
            minus = true;
            break;
        }
    }
    
    if (minus) {
        int* tmp = subtractionTHeximal(secondHeximalNumber, heximalNumber);
        delete [] heximalNumber;
        heximalNumber = tmp;
    } else {
        int* tmp = subtractionTHeximal(heximalNumber, secondHeximalNumber);
        delete [] heximalNumber;
        heximalNumber = tmp;
    }
    
    
    return *this;
}


ITInteger& THeximal::operator*=(const ITInteger& secondNumber){
    int *result = new int[65];
    int *tmp = new int[65];
    
    int* secondHeximalNumber = THeximalView(secondNumber.number);
    
    for (int i = 0; i < 65; i++) {
        for (int k = 0; k < 65; k++) {
            tmp[k] = heximalNumber[i] * secondHeximalNumber[i];
        }
        
        int add = 0;
        for (int k = i ; k < 65; k++) {
            result[k] += add;
            result[k] += tmp[k - i];
            
            if (result[k] > 1) {
                add = result[k] / 16;
                result[k] = result[k] % 16;
            }
        }
    }
    
    return *this;
}
