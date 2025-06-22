#pragma once
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

template <typename T>
class LinkedQueue
{
protected:
	Node<T>* backPtr;
	Node<T>* frontPtr;
	int count;
public:
	LinkedQueue()
	{
		count = 0;
		backPtr = nullptr;
		frontPtr = nullptr;
	}
	bool isEmpty() const
	{
		return (frontPtr == nullptr);
	}
	bool enqueue(const T& newEntry)
	{
		Node<T>* newNodePtr = new Node<T>(newEntry);
		if (isEmpty())	
			frontPtr = newNodePtr; 
		else
			backPtr->setNext(newNodePtr);
		
		
		backPtr = newNodePtr; 
		count++;
		return true;
	}
	bool dequeue(T& frntEntry)
	{
		if (isEmpty())
			return false;

		Node<T>* nodeToDeletePtr = frontPtr;
		frntEntry = frontPtr->getItem();
		frontPtr = frontPtr->getNext();
		if (nodeToDeletePtr == backPtr)	 
			backPtr = nullptr;

		
		delete nodeToDeletePtr;
		count--;
		return true;
	}
	int size() { return count; }
	void print()
	{
		Node<T>* temp = this->frontPtr;
		cout << "[";
		while (temp)
		{
			cout << temp->getItem()->GetId();
			temp = temp->getNext();
			if (temp)  cout << ",";
			else  cout << "]"; 
		}
	}
	bool peek(T& frntEntry)  const
	{
		if (isEmpty())
			return false;

		frntEntry = frontPtr->getItem();
		return true;
	}
	~LinkedQueue()
	{
		T temp;
		while (dequeue(temp));
	}
};

