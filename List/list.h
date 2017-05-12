#ifndef LIST_H
#define LIST_H

using namespace std;

template <class T>
class List {
public:
	void push_front(T data);			// add node to end of list
	void push_back(T data);				// add node to end of list
	void insertNode(T data, int pos);	// insert node at certain position
	void deleteNode(int pos);			// delete node at certain position
	void pop_front(void);				// remove node from front of list
	void pop_back(void);				// remove node from back of list
	void displayList(void);				// display list


private:
	struct Node {
		T data;
		Node *next;
		Node *prev;
	};
	Node *head = NULL;
};


#endif 
