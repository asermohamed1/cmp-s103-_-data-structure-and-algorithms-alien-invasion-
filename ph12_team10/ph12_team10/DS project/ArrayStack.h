#pragma once

#include <iostream>
using namespace std;

template <class T>
class ArrayStack
{
	enum { MAX_SIZE = 200 };
private:
	T items[MAX_SIZE];		
	int top; 
	int count;
public:
	ArrayStack()
	{
		top = -1;
		count = 0;
	}
	bool isEmpty() const
	{
		return top == -1;
	}
	bool push(const T& newEntry)
	{
		if (top == MAX_SIZE - 1) return false;

		top++;
		items[top] = newEntry;
		count++;
		return true;
	}
	int size() { return count; }
	void print()
	{
		cout << "[";
		for (int i = 0;i <= top;i++)
		{
			cout << items[i]->GetId();
			if (i != top) cout << ",";
			else cout << "]";
		}
	}
	bool pop(T& TopEntry)
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		top--;
		count--;
		return true;
	}
	bool peek(T& TopEntry) const
	{
		if (isEmpty()) return false;

		TopEntry = items[top];
		return true;
	}
};

