#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack
{
	public:
		Stack();
		void push(const T& data);
		void pop(void);
		void swap(const Stack<T>& stack_a, const Stack<T>& stack_b);
		int size(void);
		bool empty(void);
		T& top(void);
		void display(void);

	private:
		struct Node
		{
			T data;
			Node* next;
		};

		unsigned int m_size;
		Node* stack_ptr;
		
};

template <class T>
Stack<T>::Stack()
{
	m_size = 0;
	stack_ptr = nullptr;
}

template <class T>
void Stack<T>::push(const T& data)
{
	cout << "push" << endl;
	Node* newNode = new Node;
	newNode->data = data;

	if (empty())
	{
		newNode->next = nullptr;
	}
	else
	{
		newNode->next = stack_ptr;
	}

	stack_ptr = newNode;
	m_size++;
}

template <class T>
void Stack<T>::pop(void)
{
	cout << "pop" << endl;
	if (m_size > 0)
	{
		Node* temp = stack_ptr;
		stack_ptr = temp->next;
		delete temp;
		m_size--;
	}
}

template <class T>
void Stack<T>::swap(const Stack<T>& stack_a, const Stack<T>& stack_b)
{
	Node* temp = stack_a;
	stack_b = temp;
	stack_a = stack_b;
}

template <class T>
int Stack<T>::size(void)
{
	return m_size;
}

template <class T>
bool Stack<T>::empty(void)
{
	if (m_size == 0)
	{
		return true;
	}
	return false;
}

template <class T>
T& Stack<T>::top(void)
{
	return stack_ptr->data;
}

template <class T>
void Stack<T>::display(void)
{
	Node* temp = new Node;
	temp = stack_ptr;

	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

#endif

