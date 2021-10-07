#ifndef list_hpp
#define list_hpp
namespace CircleList{
template<typename type> class List {
public:
    struct elem {
        type value;
        elem* next;
        elem* previous;
        
        elem() : value(){}
    };
private:
    
    elem* head; /// be save link to the first elem
    elem* end; /// be save link to the last elem
    int len; /// length of list
    
public:
    
    List(){
        head = nullptr;
        end = nullptr;
        len = 0;
    }
    
    /// func for adding new element in list
    void add(type &);
    
    /// be delete some element by index; int - index of element
    bool del(int);
    
    /// be return element by index; int - index of element
    elem* get(int);
    
    /// func for iteration on all elem of list; elem - iterator
    type next(elem **);
    
    /// func for checking list on availability some elem
    bool isEmpty();
    
    elem* getIterator();
    
};

template <typename type>
bool List<type>::isEmpty(){
    return end == nullptr;
}

template <typename type>
typename List<type>::elem* List<type>::get(int index){
    if (index > len || index < 0) return nullptr;
    
    elem* position = head;
    
    for (int i = 1; i < index; i++) {
        position = position->next;
    }
    
    return position;
}

template <typename type>
bool List<type>::del(int index){
    elem* tmp = get(index);
    
    if(tmp == nullptr) return false;
    
    tmp->previous->next = tmp->next;
    tmp->next->previos = tmp->previous;
    
    delete tmp;
    len--;
    return true;
}

template <typename type>
void List<type>::add(type &value) {
    if (isEmpty()) {
        head = new elem();
        head->value = value;
        head->next = head;
        head->previous = head;
        end = head;
        
    } else {
        end->next = new elem();
        elem* tmp = end;
        end = end->next;
        end->previous = tmp;
        end->value = value;
        end->next = head;
        head->previous = end;
    }
    
    len++;
}

template <typename type>
type List<type>::next(elem **iterator){
    type res = (*iterator)->value;
    
    *iterator = (*iterator)->next;
    
    if (*iterator == head) *iterator = nullptr;
    return res;
}

template <typename type>
typename List<type>::elem* List<type>::getIterator(){
    return head;
}
}

namespace SingleLinkList {

template <typename T>
class List;

template <typename T>
struct element{
    T value;
    element* next;
    element* previous;
    int position;
};

template <typename T>
class Iterator{
private:
    element<T>* iterator;
    element<T>* firstElementOfList;
    int position;
    
public:
    Iterator(element<T> *firstElement);
    
    Iterator(element<T> *firstElement, element<T> *someElementAsIterator);
    
    Iterator(List<T> &list, int iteratorPosition = 0);
    
    
    element<T>* getIterator();
    
    void next();
    
    void moveToStart();
    
    int getPosition();
    
    element<T>* operator ++();
    
    element<T>* operator ++(int);
    
    element<T>* operator --();
    
    element<T>* operator --(int);
    
    operator bool();
};

template <typename T>
class List{
private:
    element<T> *head, *last;
    
public:
    List();
    
    //~List();
    
    bool isEmpty();
    
    void add(T value);
    
    T get(int position);
    
    T get(Iterator<T> iterator);
    
    element<T>* getFirstElement();
};

// Functions for iterator
    
template <typename T> Iterator<T>::Iterator(element<T> *firstElement){
    iterator = firstElement;
    firstElementOfList = firstElement;
    position = 0;
}

template <typename T> Iterator<T>::Iterator(element<T> *firstElement, element<T> *someElementAsIterator){
    iterator = someElementAsIterator;
    firstElementOfList = firstElement;
    position = someElementAsIterator->position;
}

template <typename T> Iterator<T>::Iterator(List<T> &list, int iteratorPosition){
    iterator = list.getFirstElement();
    firstElementOfList = iterator;
    for (int i = 0; i < iteratorPosition; i++) {
        iterator = iterator->next;
    }
    position = iteratorPosition;
}

template <typename T>  element<T>* Iterator<T>::getIterator(){
    return iterator;
}

template <typename T> void Iterator<T>::next(){
    iterator = iterator->next;
    position++;
}

template <typename T> void Iterator<T>::moveToStart(){
    iterator = firstElementOfList;
    position = 0;
}

template <typename T> int Iterator<T>::getPosition(){
    return position;
}


template <typename T> element<T>* Iterator<T>::operator ++(){
    if(iterator == nullptr) return nullptr;
    iterator = iterator->next;
    position++;
    return iterator;
}

template <typename T> element<T>* Iterator<T>::operator ++(int){
    if(iterator == nullptr) return nullptr;
    element<T> *tmp = iterator;
    iterator = iterator->next;
    position++;
    return tmp;
}

template <typename T> element<T>* Iterator<T>::operator --(){
    iterator = iterator->previous;
    position--;
    return iterator;
}

template <typename T> element<T>* Iterator<T>::operator --(int){
    element<T> tmp = iterator;
    iterator = iterator->previous;
    position--;
    return tmp;
}

template <typename T> Iterator<T>::operator bool(){
    return !(iterator == nullptr);
}


// Functions for list

template <typename T> List<T>::List(){
    head = nullptr;
    last = nullptr;
}

/*
template <typename T> List<T>::~List(){
    Iterator<T> iter = *new Iterator<T>(head);
    
    while(iter){
        delete iter++;
    }
    
    //delete iter;
}
 */

template <typename T> bool List<T>::isEmpty(){
    return last == nullptr;
}

template <typename T> void List<T>::add(T value){
    if (isEmpty()) {
        head = new element<T>();
        head->value = value;
        head->previous = nullptr;
        head->next = nullptr;
        last = head;
        head->position = 0;
    } else {
        element<T>* tmp = new element<T>();
        last->next = tmp;
        tmp->previous = last;
        last = last->next;
        last->value = value;
        last->next = nullptr;
        last->position = last->previous->position + 1;
    }
}

template <typename T> T List<T>::get(int position){
    Iterator<T> iter = *new Iterator<T>(head);
    
    while (iter) {
        if (iter.getPosition() == position) {
            element<T>* result = iter.getIterator();
            delete &iter;
            
            return result->value;
        }
    }
    
    return head->value;
}

template <typename T> T List<T>::get(Iterator<T> iterator){
    return iterator.getIterator()->value;
}

template <typename T> element<T>* List<T>::getFirstElement(){
    return head;
}

}

#endif /* list_hpp */
