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

		void display(void);

	private:
		unsigned int m_size;
		unsigned int m_capacity;
		T *vector;					// pointer to first element in array
};

template <class T>
Vector<T>::Vector(void)
{
	m_size = 0;
	m_capacity = 0;
	vector = 0;
}

template <class T>
Vector<T>::Vector(unsigned int size)
{
	m_size = size;
	m_capacity = size;
	vector = new T[size];
}

template <class T>
Vector<T>::Vector(unsigned int size, const T& data)
{
	m_size = size;
	m_capacity = size;
	vector = new T[size];

	for (int i = 0; i < size; i++)
	{
		vector[i] = data;
	}
}

template <class T>
void Vector<T>::display(void)
{
	for (int i = 0; i < m_size; i++)
	{
		cout << vector[i] << " ";
	}
}


#endif

