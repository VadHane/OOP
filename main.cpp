#include <iostream>
#include "Headers/ITInteger.hpp"
#include "Headers/THeximal.hpp"
#include "Headers/TBinary.hpp"


void printAll(){
    int len;
    
    std::cout << "Enter len of array of elements: ";
    std::cin >> len;
    
    ITInteger* elements[len];
    
    for (int i = 0; i < len; i++) {
        int choice;
        long number;
        
        std::cout << "1 - Binary; \n 2 - Heximal \n->";
        std::cin >> choice;
        
        std::cout << "Enter number: \n";
        std::cin >> number;
        
        if (choice == 1) {
            elements[i] = new TBinary(number);
        } else {
            elements[i] = new THeximal(number);
        }
    }
    
    std::cout << "result in order: ";
    for (int i = 0; i < len; i++) {
        elements[i]->output();
    }
}


int main(){
    {
        THeximal test(1000);
        THeximal test2(500);
    
        test -= test2;
        test.output();
    }
    
    {
        TBinary test(500);
        THeximal test2(500);
        
        test += test2;
        test.output();
    }
    
    {
        THeximal test(20);
        TBinary test2(500);
        
        test *= test2;
        test.output();
    }
    
    {
        ITInteger& test = *new TBinary(10);
        ITInteger& test2 = *new THeximal(100);
        
        test *= test2;
        test.output();
    }
    
    printAll();
}
