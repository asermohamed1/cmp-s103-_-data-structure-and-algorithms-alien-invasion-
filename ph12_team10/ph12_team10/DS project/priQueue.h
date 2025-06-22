#pragma once
#include "priNode.h"
#include <iostream>
using namespace std;

template <typename T>
class priQueue
{
    int count;
    priNode<T>* head;
public:
    priQueue() : head(nullptr) { count = 0; }

    ~priQueue() {
        T tmp;
        int p;
        while (dequeue(tmp, p));
    }

    
    void enqueue(const T& data, int priority) {
        priNode<T>* newNode = new priNode<T>(data, priority);

        if (head == nullptr || priority > head->getPri()) {

            newNode->setNext(head);
            head = newNode;
            count++;
            return;
        }

        priNode<T>* current = head;
        while (current->getNext() && priority <= current->getNext()->getPri()) {
            current = current->getNext();
        }
        newNode->setNext(current->getNext());
        current->setNext(newNode);
        count++;
    }

    bool dequeue(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem(pri);
        priNode<T>* temp = head;
        head = head->getNext();
        delete temp;
        count--;
        return true;
    }

    int size() { return count; }
    void print()
    {
        priNode<T>* temp = head;
        int pri;
        cout << "[";
        while (temp)
        {
            cout << temp->getItem(pri)->GetId();
            temp = temp->getNext();
            if (temp)  cout << ",";
            else  cout << "]";
        }
    }

    bool peek(T& topEntry, int& pri) {
        if (isEmpty())
            return false;

        topEntry = head->getItem();
        pri = head->getPri();
        return true;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};
