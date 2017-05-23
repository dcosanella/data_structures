// main.cpp : Defines the entry point for the console application.
//

#include "list.h"
#include "vector.h"
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
    return 0;
	*/

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
	cout << endl;

	v.push_back(4);
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << endl;

	v.pop_back();
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << endl;

	v.pop_back();
	v.display();
	cout << endl;
	cout << "Size: " << v.size() << endl;
	cout << endl;
}