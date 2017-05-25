#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <cassert>

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
		const T& front(void);						// return first element of vector
		const T& back(void);						// return last element of vector
		void insert(unsigned int pos, const T& data);		// insert data before position in vector
		void erase(unsigned int pos);				// erase data at given index
		void erase(unsigned int begin, unsigned int end);	// erase data within range of indexes
		T& operator[](unsigned int i);				// return data at specified index
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

	new_vector = nullptr;
	delete[] new_vector;
}

template <class T>
int Vector<T>::size(void)
{
	return m_size;
}

template <class T>
const T& Vector<T>::front(void)
{
	return m_vector[0];
}

template <class T>
const T& Vector<T>::back(void)
{
	int size = m_size - 1;					// create temporary size variable to store size of vector
	return m_vector[size];
}

template <class T>
void Vector<T>::insert(unsigned int pos, const T& data)
{
	cout << "insert" << endl;
	if (pos > 0)
	{
		T* temp_vector;
		temp_vector = new T[m_size];

		if (pos > m_size)
		{
			push_back(data);
			return;
		}

		for (int i = 0; i < m_size; i++)
		{
			if (i < pos - 1)
			{
				temp_vector[i] = m_vector[i];
			}
			else if (i == pos - 1)
			{
				temp_vector[i] = data;
				m_size++;
			}
			else if (i > pos - 1)
			{
				temp_vector[i] = m_vector[i - 1];
			}
		}

		if (m_vector != NULL)
		{
			m_vector = nullptr;
			delete[] m_vector;					// delete original array if not empty
		}

		m_vector = temp_vector;
		temp_vector = nullptr;
		delete[] temp_vector;
	}
}

template <class T>
void Vector<T>::erase(unsigned int pos)
{
	cout << "erase(pos)" << endl;
	if (pos < m_size)
	{
		for (int i = pos - 1; i < m_size; i++)
		{
			m_vector[i] = m_vector[i + 1];
		}
		m_size--;
	}
	else
	{
		pop_back();
	}
}

template <class T>
void Vector<T>::erase(unsigned int begin, unsigned int end)
{
	cout << "erase(begin, end)" << endl;
	if (end > begin && end < m_size && begin > 0)
	{
		int j = end - 1;

		for (int i = begin - 1; i < m_size; i++)
		{
			m_vector[i] = m_vector[j + 1];
			j++;
		}
		m_size = m_size - ((end - begin) + 1);
	}
}

template <class T>
T& Vector<T>::operator[](unsigned int i)
{
	assert(i >= 0 && i < m_size);
	return m_vector[i];
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

