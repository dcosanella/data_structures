#include "stdafx.h"
#include "list.h"
#include <iostream>

using namespace std;

template <class T>
void List<T>::push_front(T data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node *nodePtr;

	if (head == NULL) {
		head = newNode;
	}
	else {
		nodePtr = head;
		head = newNode;
		head->next = nodePtr;
		nodePtr->prev = head;
	}

}

template <class T>
void List<T>::push_back(T data) {
	Node *newNode = new Node;
	newNode->data = data;
	newNode->next = NULL;

	Node *nodePtr;

	if (head == NULL) {
		head = newNode;
	}
	else {
		nodePtr = head;
		while (nodePtr->next != NULL) {
			nodePtr = nodePtr->next;
		}
		nodePtr->next = newNode;
		newNode->prev = nodePtr;
	}
}

template <class T>
void List<T>::insertNode(T data, int pos) {

}

template <class T>
void List<T>::deleteNode(int pos) {

}

template <class T>
void List<T>::pop_front(void) {

}
template <class T>
void List<T>::pop_back(void) {

}

template <class T>
void List<T>::displayList(void) {
	Node *nodePtr;
	if (head == NULL) {
		return;
	}
	else {
		nodePtr = head;
		while (nodePtr) {
			cout << nodePtr->data << endl;
			nodePtr = nodePtr->next;
		}
	}
}