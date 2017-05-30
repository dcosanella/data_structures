#ifndef STACK_H
#define STACK_H

#include <iostream>

using namespace std;

template <class T>
class Stack
{
	public:
		Stack(void);
		void push(const T& data);
		void pop(void);
		void swap(Stack<T>& stack);
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
		Node* m_stack_ptr;
		
};

template <class T>
Stack<T>::Stack(void)
{
	m_size = 0;
	m_stack_ptr = nullptr;
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
		newNode->next = m_stack_ptr;
	}

	m_stack_ptr = newNode;
	m_size++;
}

template <class T>
void Stack<T>::pop(void)
{
	cout << "pop" << endl;
	if (m_size > 0)
	{
		Node* temp = m_stack_ptr;
		m_stack_ptr = temp->next;
		delete temp;
		m_size--;
	}
}

template <class T>
void Stack<T>::swap(Stack<T>& stack)
{
	Node* temp = m_stack_ptr;
	m_stack_ptr = stack.m_stack_ptr;
	stack.m_stack_ptr = temp;

	int temp_size = m_size;
	m_size = stack.m_size;
	stack.m_size = temp_size;
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
	return m_stack_ptr->data;
}

template <class T>
void Stack<T>::display(void)
{
	Node* temp = new Node;
	temp = m_stack_ptr;

	while (temp)
	{
		cout << temp->data << endl;
		temp = temp->next;
	}
	cout << "NULL" << endl;
}

#endif

