// main.cpp : Defines the entry point for the console application.
//

#include "list.h"
#include "vector.h"
#include "stack.h"
#include <iostream>

using namespace std;

int main()
{
    // Tests for all functions in List class
	/*
    List<int> list;
    list.push_front(2);
    list.push_front(5);
    list.display_list();
    cout << "Size: " << list.size() << endl;
    cout << endl;
    list.push_back(15);
    list.display_list();
    cout << "Size: " << list.size() << endl;
    cout << endl;
    list.push_back(20);
    list.display_list();
    cout << "Size: " << list.size() << endl;
    cout << endl;
	list.sort();
	list.display_list();
	cout << "Size: " << list.size() << endl;
	cout << endl;
    list.push_front(10);
    list.display_list();
    cout << "Size: " << list.size() << endl;
	cout << endl;
	list.reverse();
	list.display_list();
	cout << "Size: " << list.size() << endl;
    cout << endl;
    list.insert_node(17, 3);
    list.display_list();
    cout << "Size: " << list.size() << endl;
	cout << endl;
	list.sort();
	list.display_list();
	cout << "Size: " << list.size() << endl;
    cout << endl;
    list.delete_node(4);
    list.display_list();
    cout << "Size: " << list.size() << endl;
    cout << endl;
    list.pop_front();
    list.display_list();
    cout << "Size: " << list.size() << endl;
    cout << endl;
    list.pop_back();
    list.display_list();
    cout << "Size: " << list.size() << endl;
    cout << endl;
    list.pop_back();
    list.display_list();
    cout << "Size: " << list.size() << endl;
	cout << endl;
	list.reverse();
	list.display_list();
	cout << "Size: " << list.size() << endl;
	*/

	/*
	// Tests for all functions in Vector class
	Vector<int> vector(3, 10);
	vector.display();
	cout << endl;
	cout << "Size: " << vector.size() << endl;
	cout << endl;

	Vector<int> v(2);
	v.push_back(3);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << endl;

	v.push_back(2);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << endl;

	v.push_back(1);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.push_back(4);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.insert(3, 10);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.erase(3);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.insert(2, 20);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.insert(10, 80);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.erase(10);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.insert(5, 25);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.pop_back();
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.pop_back();
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.insert(1, 15);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;

	v.erase(2, 4);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << "Front: " << v.front() << endl;
	cout << "Back: " << v.back() << endl;
	cout << endl;
	*/

	// Tests for all functions in Stack class
	Stack<int> s;
	s.push(15);
	s.push(20);
	s.push(30);
	s.push(23);
	s.push(17);
	cout << "Contents in Stack s:" << endl;
	s.display();
	cout << "Top: " << s.top() << endl;
	cout << "Size: " << s.size() << endl;
	cout << endl;

	s.pop();
	cout << "Contents in Stack s:" << endl;
	s.display();
	cout << "Top: " << s.top() << endl;
	cout << "Size: " << s.size() << endl;
	cout << endl;

	Stack<int> s2;
	s2.push(2);
	s2.push(4);
	s2.push(8);

	cout << "Contents in Stack s2:" << endl;
	s2.display();
	cout << "Top: " << s2.top() << endl;
	cout << "Size: " << s2.size() << endl;
	cout << endl;

	swap(s, s2);

	cout << "Contents in Stack s after swap:" << endl;
	s.display();
	cout << "Top: " << s.top() << endl;
	cout << "Size: " << s.size() << endl;
	cout << endl;

	cout << "Contents in Stack s2 after swap:" << endl;
	s2.display();
	cout << "Top: " << s2.top() << endl;
	cout << "Size: " << s2.size() << endl;
	cout << endl;

	return 0;
}