#include "main.h"

template<typename T>
List<T>::List() {
    Head = Tail = nullptr;
    size_ = 0;
}

template<typename T>
List<T>::List(const List& list) {
    Head = Tail == nullptr;
    size_ = 0;

    Node<T> *temp = list.Head;
    while (temp != nullptr) {
        push_back(temp->data);
        temp = temp->next;
    }
}

template<typename T>
List<T>::~List() {
    while(size_) {
        pop_back();
    }
}

template<typename T>
int List<T>::size() {
    return size_;
}

template<typename T>
void List<T>::push_back(T data) {
    auto *temp = new Node<T>;
    temp->prev = nullptr;
    temp->next = Head;
    temp->data = data;

    if (Head != nullptr)
        Head->prev = temp;

    if (size_ == 0)
        Head = Tail = temp;
    else
        Head = temp;

    size_++;
}

template<typename T>
void List<T>::push_front(T data) {
    auto *temp = new Node<T>;
    temp->next = nullptr;
    temp->prev = Tail;
    temp->data = data;

    if (Tail != nullptr)
        Tail->next = temp;

    if (size_ == 0)
        Head = Tail = temp;
    else
        Tail = temp;

    size_++;
}

template<typename T>
void List<T>::pop_back() {
    auto *temp = Tail;
    Tail = Tail->prev;
    Tail->next = nullptr;
    delete temp;
    size_--;
}

template<typename T>
void List<T>::pop_front() {
    auto *temp = Head;
    Head = Head->next;
    Head->prev = nullptr;
    delete temp;
    size_--;
}

template<typename T>
T& List<T>::get_back() {
    return Tail->data;
}

template<typename T>
T& List<T>::get_front() {
    return Head->data;
}
