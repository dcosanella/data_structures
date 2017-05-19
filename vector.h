#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>

using namespace std;

template <class T>
class Vector
{
	public:
		Vector(void);								// creates empty vector
		Vector(unsigned int size);					// creates vector with specific size
		Vector(unsigned int size, const T& data);	// creates vector with specific size and fills it with data.
		void push_back(const T& data);				// inserts data at end of vector
		void pop_back(void);						// deletes last element of vector

		void display(void);							// display vector

	private:
		unsigned int m_size;			// number of elements in vector
		unsigned int m_capacity;		// max size of vector
		T *m_vector;					// pointer to first element in array
};

template <class T>
Vector<T>::Vector(void)
{
	m_size = 0;
	m_capacity = 0;
	m_vector = 0;
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
	m_size = 0;
	m_capacity = size;
	m_vector = new T[size];
	for (int i = 0; i < size; i++)
	{
		m_vector[i] = NULL;
	}
}

template <class T>
Vector<T>::Vector(unsigned int size, const T& data)
{
	m_size = size;
	m_capacity = size;
	m_vector = new T[size];

	for (int i = 0; i < size; i++)
	{
		m_vector[i] = data;
	}
}

template <class T>
void Vector<T>::push_back(const T& data)
{
	cout << "push_back" << endl;
	int i = 0;
	while (m_vector[i] != NULL && i < m_capacity)
	{
		i++;
	}
	if (i == m_capacity)
	{
		T *temp = new T[m_capacity++];			// create new pointer to new array
		for (int j = 0; j < m_capacity; j++)
		{
			temp[j] = m_vector[j];				// copy vector elements to temp
		}
		m_vector = temp;						// set vector equal to temp
		temp = nullptr;							// set temp to nullptr and delete pointer
		delete temp;
	}
	m_vector[i] = data;
	m_size++;
}

template <class T>
void Vector<T>::pop_back(void)
{
	cout << "pop_back" << endl;
	m_vector[m_size--] = NULL;
	m_capacity--;
}

template <class T>
void Vector<T>::display(void)
{
	for (int i = 0; i < m_size; i++)
	{
		if (m_vector[i] != NULL)
		{
			cout << m_vector[i] << " ";
		}
	}
}


#endif

