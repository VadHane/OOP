#include <iostream>
#include <ctime>
using namespace std;

class stack {
    struct elem {
        int value;
        elem* next;
    };
    
private:
    elem* last;
    int len;
    
public:
    stack(){
        last = new elem();
        len = 0;
    }
    
    int pop(){
        if (len <= 0) {
            return 0/0;
        }
        
        elem* tmp = last->next;
        int result = last->value;

        delete last;

        last = tmp;

        len--;
        
        return result;
    }
    
    void add(int value){
        elem* tmp = new elem();
        tmp->next = last;
        
        last = tmp;
        
        last->value = value;
       
        len++;
    }
    
    int getLen(){
        return len;
    }
    
};





class queue {
    struct elem {
        int value;
        elem* next;
    };
    
private:
    elem* last;
    elem* first;
    
public:
    queue(){
        last = nullptr;
        first = nullptr;
    }
    
    bool isEmpty(){
        return last == nullptr;
    }
    
    int pop(){
        if (isEmpty()) {
            return 0;
        }
        elem* tmp = first->next;
        int result = first->value;
        
        delete first;
        first = tmp;
        
        if (first == nullptr) last = nullptr;
        
        return result;
    }
    
    void add(int value){
        if (isEmpty()) {
            first = new elem();
            first->value = value;
            first->next = nullptr;
            last = first;
        } else {
            last->next = new elem();
            last = last->next;
            last->value = value;
            last->next = nullptr;
        }
    }
};

queue getPair(queue q1, queue q2){
    queue result = *new queue();
    
    cout << "First queue: \n<- ";
    while (!q1.isEmpty()){
        int item = q1.pop();
        if (item % 2 == 0) result.add(item);
        cout << item << " ";
    }
    cout << "\nSecond queue: \n<- ";
    while (!q2.isEmpty()){
        int item = q2.pop();
        if (item % 2 == 0) result.add(item);
        cout << item << " ";
    }
    
    return result;
}


int main() {
    srand((int)time(0));
    
    queue q1 = *new queue(), q2 = *new queue(), result = *new queue();
    
    int len;
    cout << "Input len of queue: ";
    cin >> len;
    
    for (int i = 0; i < len; i++) {
        q1.add(rand() % 100);
        q2.add(rand() % 100);
        
    }
    
    result = getPair(q1, q2);
    
    cout << "\nResult \n<- ";
    while (!result.isEmpty()) cout << result.pop() << " ";;
}
