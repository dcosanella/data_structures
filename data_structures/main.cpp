// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.h"
#include <iostream>

using namespace std;

int main()
{
	// Tests for all functions in List class
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
	list.push_front(10);
	list.display_list();
	cout << "Size: " << list.size() << endl;
	cout << endl;
	list.insert_node(17, 3);
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
	return 0;
}
