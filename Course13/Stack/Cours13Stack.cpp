#include <iostream>
#include "clsMyStack.h"
using namespace std;


int main() {
		
	clsMyStack<int> MyStack;
	cout << "\nthis is the push functions: " << endl;
	MyStack.Push(1);
	MyStack.Push(2);
	MyStack.Push(4);
	MyStack.Push(6);
	MyStack.Push(8);
	MyStack.Push(10);
	MyStack.Push(12);


	MyStack.Print();
	


	cout << "\nthis is value of the first index: " << MyStack.Top();
	cout << "\nthis is value of the last index: " << MyStack.Bottom();
	cout << "\nthis is the value of the 4 index: " << MyStack.GetItem(4);
	if (MyStack.IsEmpty())
		cout << "\nthe stack is empty.";
	else
		cout << "\nthe stack is not empty.";
	MyStack.Pop();
	MyStack.Pop();
	MyStack.Pop();
	
	cout << "\nthis is the stack after deleting the first three indeces: ";
	MyStack.Print();

	MyStack.InsertAtBack(100);
	cout << "\nthis is the stack after inserting 100 at back : ";
	MyStack.Print();

	MyStack.InsertAtFront(90);
	cout << "\nthis is the stack after inserting 90 at front: ";
	MyStack.Print();


	cout << "\nthis is the size of the stack: " << MyStack.Size();

	MyStack.Clear();
	cout << "\nthis is the stack after clear(): ";
	MyStack.Print();

	cout << "\nthis is the size of the stack after clear(): " << MyStack.Size();

	if (MyStack.IsEmpty())
		cout << "\nthe stack is empty.";
	else
		cout << "\nthe stack is not empty.";

}