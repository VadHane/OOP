#include "../Headers/TBinary.hpp"
#include <iostream>
using namespace std;

int* TBinaryView(long number);

TBinary::TBinary(){
    number = 0;
    binaryNumber = new int[len];
}

TBinary::TBinary(long num) {
    number = num;
    binaryNumber = TBinaryView(num);
}

TBinary::TBinary(TBinary &num){
    number = num.number;
    binaryNumber = new int[65];
    for(int i = 0; i < 65; i++) binaryNumber[i] = num.binaryNumber[i];
}

TBinary::~TBinary(){
    delete [] binaryNumber;
}


int* TBinaryView(long number){
    int *binaryView = new int[65];
    int index = 0;
    
    for (int i = 0; i < 65; i++) binaryView[i] = 0;
    
    while (number > 0) {
        binaryView[index] = number % 2;
        number /= 2;
        index++;
    }
    
    return binaryView;
}

void TBinary::input(){
    long userNumber;
    
    if (binaryNumber != nullptr) delete [] binaryNumber;
    
    do
    {
        cout << "Input your unsigned long number: ";
        cin >> userNumber;
    } while (userNumber < 0);
    
    binaryNumber = TBinaryView(userNumber);
}

void TBinary::output() const{
    int index = 0;
    
    if (binaryNumber == nullptr) {
        cout << "Null";
        return;
    }
    for (int i = 0; i < 65; i++) if (binaryNumber[i] == 1) index = i;
    
    if(minus) cout << "-";
    
    for (int i = index; i >=0; i--) {
        cout << binaryNumber[i];
    }
    cout << ";" << endl;
}


ITInteger& TBinary::operator +=(const ITInteger& secondNumber){
    int add = 0;
    
    int* secondBinaryNumber = TBinaryView(secondNumber.number);
    
    for (int i = 0 ; i < 65; i++) {
        binaryNumber[i] += add;
        add = 0;
        binaryNumber[i] += secondBinaryNumber[i];
        //cout << binaryNumber[i] << " " << secondBinaryNumber[i];
        if (binaryNumber[i] > 1) {
            add = binaryNumber[i] / 2;
            binaryNumber[i] = binaryNumber[i] % 2;
        }
    }
    return *this;
}

int* subtraction(const int* first, const int* second){
    int* result = new int[65];
    
    for (int i = 0; i < 65; i++) result[i] = first[i];
    
    for (int i = 0; i < 0; i++) {
        if (result[i] < second[i]) {
            for (int k = i + 1; i < 65; i++) {
                if (result[k] == 0) {
                    result[k] = 1;
                } else {
                    result[k] -= 1;
                    result[i] += 2;
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

ITInteger& TBinary::operator -=(const ITInteger& secondNumber){
    int* tmp;
    int* secondBinaryNumber = TBinaryView(secondNumber.number);
    
    for (int i = 64; i >= 0; i--) {
        if (binaryNumber[i] > secondBinaryNumber[i]) {
            minus = false;
            break;
        } else if (binaryNumber[i] < secondBinaryNumber[i]) {
            minus = true;
            break;
        }
    }
    
    if (minus) {
        tmp = subtraction(secondBinaryNumber, binaryNumber);
    } else {
        tmp = subtraction(binaryNumber, secondBinaryNumber);
    }
    delete [] binaryNumber;
    binaryNumber = tmp;
    
    return *this;
}


ITInteger& TBinary::operator*=(const ITInteger& secondNumber){
    int *result = new int[65];
    int *tmp = new int[65];
    
    int* secondBinaryNumber = TBinaryView(secondNumber.number);
    
    for (int i = 0; i < 65; i++) { result[i] = 0; tmp[i] = 0; }
    
    for (int i = 0; i < 65; i++) {
        for (int k = 0; k < 65; k++) {
            tmp[k] = binaryNumber[i] * secondBinaryNumber[k];
        }
        
        int add = 0;
        for (int k = i ; k < 65; k++) {
            result[k] += add;
            add = 0;
            result[k] += tmp[k - i];
            
            if (result[k] > 1) {
                add = result[k] / 2;
                result[k] = result[k] % 2;
            }
        }
    }
    
    for (int i = 0; i < 65; i++) binaryNumber[i] = result[i];
    
    return *this;
}
