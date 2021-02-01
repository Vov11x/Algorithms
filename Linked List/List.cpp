#include "List.h"



template<typename T>
List<T>::List() {
    size_ = 0;
    head = nullptr;
}

template<typename T>
List<T>::~List() {
    clear();
}

template<typename T>
void List<T>::push_back(T data) {
    if (head == nullptr) {
        head = new Node<T>(data);
    } else {
        Node<T> *current = this->head;
        while (current->pNext != nullptr) {
            current = current->pNext;
        }

        current->pNext = new Node<T>(data);
    }
    size_++;
}

template<typename T>
T &List<T>::operator[](int index) {
    Node<T> *current = this->head;
    int counter = 0;
    while (current != nullptr) {
        if (counter == index)
            return current->data;
        current = current->pNext;
        counter++;
    }
}

template<typename T>
void List<T>::pop_front() {
    Node<T> *temp = head;
    head = head->pNext;
    delete temp;

    size_--;
}

template<typename T>
void List<T>::clear() {
    while(size_) {
        pop_front();
    }
}

template<typename T>
void List<T>::push_front(T data) {
    head = new Node<T>(data, head);
    size_++;
}

template<typename T>
void List<T>::insert(T data, int index) {
    if(index == 0) {
        push_front(data);
    } else {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }
        previous->pNext = new Node<T>(data, previous->pNext);;
        size_++;
    }
}

template<typename T>
void List<T>::remove(int index) {
    if(index == 0) {
        pop_front();
    } else {
        Node<T> *previous = this->head;
        for (int i = 0; i < index - 1; ++i) {
            previous = previous->pNext;
        }

        Node<T> *toDelete = previous->pNext;
        previous->pNext = toDelete->pNext;
        size_--;

    }
}

template<typename T>
void List<T>::pop_back() {
    remove(size_-1);
}

