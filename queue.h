#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

using namespace std;

template <class T>
class Queue
{
	public:
		Queue(void);
		void push(const T& data);
		void pop(void);
		void swap(Queue<T>& queue);
		int size(void);
		bool empty(void);
		T& front(void);
		T& back(void);
		void display(void);

	private:
		struct Node
		{
			T data;
			Node* next;
		};

		unsigned int m_size;
		Node* m_front;
		Node* m_back;
};

template <class T>
Queue<T>::Queue(void)
{
	m_size = 0;
	m_front = nullptr;
	m_back = nullptr;
}

template <class T>
void Queue<T>::push(const T& data)
{
	cout << "push" << endl;
	Node* newNode = new Node;
	newNode->data = data;
	newNode->next = nullptr;
	
	if (m_front == nullptr)
	{
		m_front = newNode;
		m_back = m_front;
	}
	else
	{
		m_back->next = newNode;
		m_back = newNode;
	}
	m_size++;
}

template <class T>
void Queue<T>::pop(void)
{
	cout << "pop" << endl;
	if (m_size > 0)
	{
		Node* temp = m_front;
		m_front = temp->next;
		delete temp;
		m_size--;
	}
	else
	{
		cout << "Unable to pop. Queue is empty." << endl;
	}
}

template <class T>
void Queue<T>::swap(Queue<T>& queue)
{
	Node* temp = m_front;
	m_front = queue.m_front;
	queue.m_front = temp;

	Node* temp_back = m_back;
	m_back = queue.m_back;
	queue.m_back = temp_back;

	int temp_size = m_size;
	m_size = queue.m_size;
	queue.m_size = temp_size;
}

template <class T>
int Queue<T>::size(void)
{
	return m_size;
}

template <class T>
bool Queue<T>::empty(void)
{
	if (m_size == 0)
	{
		return true;
	}
	return false;
}

template <class T>
T& Queue<T>::front(void)
{
	return m_front->data;
}

template <class T>
T& Queue<T>::back(void)
{
	return m_back->data;
}

template <class T>
void Queue<T>::display(void)
{
	Node* temp = new Node;
	temp = m_front;

	while (temp)
	{
		cout << temp->data;
		if (temp->next != nullptr)
		{
			cout << " <-- ";
		}
		temp = temp->next;
	}
	cout << endl;
}

#endif
