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


private:
    struct Node
    {
        T data;
        Node *next;
        Node *prev;
    };
    Node *m_head;
};

template <class T>
List<T>::List()
{
    m_head = nullptr;
}

template <class T>
void List<T>::push_front(const T& data)
{
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node *nodePtr;

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
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node *nodePtr;

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
    Node *newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;

    Node *nodePtr;
    Node *prevNode;
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
    Node *nodePtr;
    Node *prevNode;
    int p = 0;

    if (m_head == nullptr)
    {
        return;
    }

    if (pos == 0)
    {
        Node *temp = m_head;
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
    if (m_head == nullptr)
    {
        return;
    }
    else
    {
        Node *temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
}
template <class T>
void List<T>::pop_back(void)
{
    Node *nodePtr;
    Node *prevNode;

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
    Node *nodePtr;
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
    Node *nodePtr;
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


#endif 