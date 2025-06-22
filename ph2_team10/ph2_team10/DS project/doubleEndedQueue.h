#pragma once
#include "LinkedQueue.h"


template <class T>
class doubleEndedQueue :public LinkedQueue<T>
{
private:
public:
	doubleEndedQueue() :LinkedQueue<T>()
	{
	}
	bool dequeueFront(T& frntEntry)
	{
		if (!this->frontPtr) return false;
		if (!this->frontPtr->getNext())
		{
			frntEntry = this->frontPtr->getItem();
			delete this->frontPtr;
			this->frontPtr = nullptr;
			this->backPtr = nullptr;
		}
		else
		{
			Node<T>* temp = this->frontPtr;
			frntEntry = temp->getItem();
			this->frontPtr = this->frontPtr->getNext();
			if (this->frontPtr) this->frontPtr->setPrev(nullptr);
			delete temp;
		}
		this->count--;

		return true;
	}
	bool dequeueBack(T& backEntry)
	{
		if (!this->frontPtr) return false;
		if (!this->frontPtr->getNext())
		{
			backEntry = this->frontPtr->getItem();
			delete this->frontPtr;
			this->frontPtr = nullptr;
			this->backPtr = nullptr;
		}
		else
		{
			Node<T>* temp = this->backPtr;
			backEntry = temp->getItem();
			this->backPtr = this->backPtr->getPrev();
			this->backPtr->setNext(nullptr);
			delete temp;
		}
		this->count--;
		return true;
	}

	bool enqueueBack(T val)
	{
		if (!this->frontPtr)
		{
			this->frontPtr = new Node<T>(val);
			this->backPtr = this->frontPtr;
		}
		else
		{
			Node<T>* node = new Node<T>(val);
			this->backPtr->setNext(node); node->setPrev(this->backPtr);
			this->backPtr = this->backPtr->getNext();
		}
		this->count++;
		return true;
	}

	bool enqueueFront(T val)
	{
		if (!this->frontPtr)
		{
			this->frontPtr = new Node<T>(val);
			this->backPtr = this->frontPtr;
		}
		else
		{
			Node<T>* node = new Node<T>(val);
			node->setNext(this->frontPtr);
			this->frontPtr->setPrev(this->frontPtr);
			this->frontPtr = node;
		}
		this->count++;
		return true;
	}
	bool PeekFront(T& val)
	{
		if (!this->frontPtr) return false;
		val = this->frontPtr->getItem();
		return true;
	}
	bool PeekBack(T& val)
	{
		if (!this->frontPtr) return false;
		val = this->backPtr->getItem();
		return true;
	}
	
    ~doubleEndedQueue()
	{
		while (this->frontPtr)
		{
			Node<T> *temp = this->frontPtr;
			this->frontPtr = this->frontPtr->getNext();
			delete temp;
		}
	}
};

