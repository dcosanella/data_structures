#ifndef LIST_H
#define LIST_H

#include <iostream>

using namespace std;

template <class T>
class List
{
public:
	List();										// constructor
	void push_front(const T& data);				// add node to end of list
	void push_back(const T& data);				// add node to end of list
	void insert_node(const T& data, int pos);	// insert node at certain position
	void delete_node(int pos);					// delete node at certain position
	void pop_front(void);						// remove node from front of list
	void pop_back(void);						// remove node from back of list
	void display_list(void);					// display list
	int size(void);								// calculate the size of list
	bool empty(void);							// find out if list is empty
	void reverse(void);							// reverse list
	void sort(void);							// sort list in ascending order (selection sort)


private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
    };
    Node* m_head;
};

template <class T>
List<T>::List()
{
    m_head = nullptr;
}

template <class T>
void List<T>::push_front(const T& data)
{
	cout << "push_front" << endl;
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* nodePtr;

    if (m_head == nullptr)
    {
        m_head = newNode;
    }
    else
    {
        nodePtr = m_head;
        m_head = newNode;
        m_head->next = nodePtr;
        nodePtr->prev = m_head;
    }

}

template <class T>
void List<T>::push_back(const T& data)
{
	cout << "push_back" << endl;
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* nodePtr;

    if (m_head == nullptr)
    {
        m_head = newNode;
    }
    else {
        nodePtr = m_head;
        while (nodePtr->next != nullptr)
        {
            nodePtr = nodePtr->next;
        }
        nodePtr->next = newNode;
        newNode->prev = nodePtr;
    }
}

template <class T>
void List<T>::insert_node(const T& data, int pos)
{
	cout << "insert_node" << endl;
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node* nodePtr;
    Node* prevNode;
    int p = 0;

    if (m_head == nullptr)
    {
        return;
    }
    if (pos >= 1)
    {
        nodePtr = m_head;
        while (p <= pos - 1)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            p++;
        }
        prevNode->next = newNode;
        newNode->next = nodePtr;
        newNode->prev = prevNode;
        nodePtr->prev = newNode;
    }
}

template <class T>
void List<T>::delete_node(int pos)
{
	cout << "delete_node" << endl;
    Node* nodePtr;
    Node* prevNode;
    int p = 0;

    if (m_head == nullptr)
    {
        return;
    }

    if (pos == 0)
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    else
    {
        nodePtr = m_head;
        while (p <= pos - 1)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
            p++;
        }
        prevNode->next = nodePtr->next;
        nodePtr->next->prev = prevNode;
        delete nodePtr;
    }
}

template <class T>
void List<T>::pop_front(void)
{
	cout << "pop_front" << endl;
    if (m_head == nullptr)
    {
        return;
    }
    else
    {
        Node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}
template <class T>
void List<T>::pop_back(void)
{
	cout << "pop_back" << endl;
    Node* nodePtr;
    Node* prevNode;

    if (m_head == nullptr)
    {
        return;
    }
    else
    {
        nodePtr = m_head;
        while (nodePtr->next != nullptr)
        {
            prevNode = nodePtr;
            nodePtr = nodePtr->next;
        }
        prevNode->next = nullptr;
        delete nodePtr;
    }
}

template <class T>
void List<T>::display_list(void)
{
    Node* nodePtr;
    if (m_head == nullptr)
    {
        return;
    }
    else
    {
        nodePtr = m_head;
        while (nodePtr)
        {
            cout << nodePtr->data << " ";
            nodePtr = nodePtr->next;
        }
        cout << endl;
    }
}

template <class T>
int List<T>::size(void)
{
    Node* nodePtr;
    int size = 0;

    if (m_head != nullptr)
    {
        nodePtr = m_head;
        while (nodePtr)
        {
            nodePtr = nodePtr->next;
            size++;
        }
    }
    return size;
}

template <class T>
bool List<T>::empty(void)
{
	cout << "empty" << endl;
	if (m_head == nullptr)
	{
		return true;
	}
	else
	{
		return false;
	}
}

template <class T>
void List<T>::reverse(void)
{
	cout << "reverse" << endl;
	Node* nodePtr;
	Node* nextNode;
	Node* prevNode;

	if (m_head == nullptr)
	{
		return;
	}
	else
	{
		nodePtr = m_head;
		prevNode = nullptr;
		while (nodePtr != nullptr)
		{
			nodePtr->prev = nodePtr->next;
			nextNode = nodePtr->next;	// set nextNode pointer to the next node
			nodePtr->next = prevNode;	// set next pointer to the previous node (step 1 of reversal)
			prevNode = nodePtr;			// set the previous node to the current node (step 2 of reversal)
			nodePtr = nextNode;			// set current node to the next node
		}
		prevNode->prev = nullptr;
		m_head = prevNode;
	}

}

template <class T>
void List<T>::sort(void)
{
	cout << "sort" << endl;
	Node* nodePtr;
	Node* nextNode;
	Node* currNode;

	if (m_head == nullptr)
	{
		return;
	}
	else
	{
		for(nodePtr = m_head; nodePtr->next != nullptr; nodePtr = nodePtr->next)
		{
			for (nextNode = nodePtr->next; nextNode != nullptr; nextNode = nextNode->next)
			{
				if (nodePtr->data > nextNode->data)
				{
					T tempData = nodePtr->data;
					nodePtr->data = nextNode->data;
					nextNode->data = tempData;
				}
			}
		}
	}
}


#endif 