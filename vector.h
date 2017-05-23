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
		void reserve(int size);						// allocate more memory for vector
		int size(void);								// return size of vector
		void display(void);							// display vector

	private:
		unsigned int m_size;			// number of elements in vector
		unsigned int m_capacity;		// max size of vector
		T* m_vector;					// pointer to first element in array
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
	if (m_size == m_capacity)
	{
		reserve(m_capacity * 2);				// double the capacity of vector if vector is full
	}
	m_vector[m_size] = data;
	m_size++;
}

template <class T>
void Vector<T>::pop_back(void)
{
	cout << "pop_back" << endl;
	if (m_size > 0)
	{
		m_size--;
	}
}

template <class T>
void Vector<T>::reserve(int size)
{
	T* new_vector;
	new_vector = new T[size];				// create a temporary vector

	if (new_vector != NULL)
	{
		for (int i = 0; i < m_size; i++)
		{
			new_vector[i] = m_vector[i];	// copy data from original vector to new vector
		}
	}
	if (m_vector != NULL)
	{
		delete[] m_vector;					// delete original array if not empty
	}
	m_vector = new_vector;					// set original vector to temporary vector
	m_capacity = size;						// update capacity
}

template <class T>
int Vector<T>::size(void)
{
	return m_size;
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

