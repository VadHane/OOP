#ifndef list_hpp
#define list_hpp

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
    
    Iterator(const List<T> &list, int iteratorPosition = 0);
    
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
    
    ~List();
    
    void freeMemory();
    
    bool isEmpty();
    
    void add(const T value);
    
    T get(int position) const;
    
    T get(Iterator<T> iterator) const;
    
    element<T>* getFirstElement() const;
    
    List& operator =(const List<T> &);
    
    
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

template <typename T> Iterator<T>::Iterator(const List<T> &list, int iteratorPosition){
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

template <typename T> void List<T>::freeMemory(){
    if(head == nullptr || this == nullptr) return;
    
    Iterator<T> iter = *new Iterator<T>(head);
    
    while (iter) {
        delete iter++;
    }
    
    head = nullptr;
    last = nullptr;
}


template <typename T> List<T>::List(){
    head = nullptr;
    last = nullptr;
}

template <typename T> List<T>::~List(){
    
    Iterator<T> iter = *new Iterator<T>(head);
    
    while(iter){
        delete iter++;
    }
    
    head = nullptr;
    last = nullptr;
    
    
}


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

template <typename T> T List<T>::get(int position) const{
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

template <typename T> T List<T>::get(Iterator<T> iterator) const{
    return iterator.getIterator()->value;
}

template <typename T> element<T>* List<T>::getFirstElement() const{
    return head;
}

template <typename T>  List<T>& List<T>::operator =(const List<T> &list){
    if (head != nullptr) {
        freeMemory();
    }
    
    
    Iterator<T> iter = *new Iterator<T>(list.getFirstElement());
    
    while (iter) {
        add((iter++)->value);
    }
    
    return *this;
}

}

#endif /* list_hpp */
