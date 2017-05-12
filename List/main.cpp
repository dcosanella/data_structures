// main.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "list.cpp"
#include <iostream>
#include <string>

using namespace std;

int main()
{
	List<int> list;
	list.push_front(2);
	list.push_front(5);
	list.displayList();
	cout << endl;
	list.push_back(15);
	list.displayList();
	cout << endl;
	list.push_back(20);
	list.displayList();
	cout << endl;
	list.push_front(10);
	list.displayList();
	return 0;
}


