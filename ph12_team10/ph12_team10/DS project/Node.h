#pragma once
template <class T>
class Node
{
private:
	T item;
	Node<T>* next;
	Node<T>* prev;
public:
	Node()
	{
		next = nullptr;
		prev = nullptr;
	}
	Node(const T& r_Item)
	{
		item = r_Item;
		next = nullptr;
		prev = nullptr;
	}
	Node(const T& r_Item, Node<T>* nextNodePtr)
	{
		item = r_Item;
		next = nextNodePtr;
	}
	void setItem(const T& r_Item)
	{
		item = r_Item;
	}
	void setNext(Node<T>* nextNodePtr)
	{
		next = nextNodePtr;
	}
	void setPrev(Node<T>* prevNodePtr)
	{
		prev = prevNodePtr;
	}
	Node<T>* getPrev() const
	{
		return prev;
	}
	T getItem() const
	{
		return item;
	}
	Node<T>* getNext() const
	{
		return next;
	}
};
