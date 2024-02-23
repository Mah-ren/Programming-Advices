#include <iostream>
#include "clsDynamicArray.h"
using namespace std;
/*hello*/

int main() {
	clsDynamicArray<int> MyDynamicArray(5);
	
	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(2, 30);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);

	int index = MyDynamicArray.Find(40);
	if (index == -1)
		cout << "\nindex is not found." << endl;
	else
		cout << "\nindex is  found." << endl;
	cout << "\nthese are the items: ";
	MyDynamicArray.PrintList();
	MyDynamicArray.DeleteItem(40);
	cout << "\nthis is the array after deleting 40: ";
	MyDynamicArray.PrintList();


	cout << "\nnow i want to insert 40 after deleting it at index 3: ";
	MyDynamicArray.InsertAt(3, 40);
	cout << "\nthese are the items: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();
	MyDynamicArray.InsertAfter(2, 99);
	cout << "\nthis is the array after inserting 99 after index2: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();
	MyDynamicArray.InsertBefore(2, 88);
	cout << "\nthis is the array after inserting 88 before index2: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();



	MyDynamicArray.InsertAtEnd(77);
	cout << "\nthis is the array after inserting 77 at end: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();

	MyDynamicArray.InsertAtBeginning(33);
	cout << "\nthis is the array after inserting 33  at beginning: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();


	cout << "\nthese are the items: ";
	MyDynamicArray.PrintList();

	MyDynamicArray.DeleteItemAt(2);
	cout << "\nthis is the array after deleting the second item: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();
	MyDynamicArray.DeleteFirstItem();
	cout << "\nthese is the array after deleting the first item: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();
	MyDynamicArray.DeleteLastItem();
	cout << "\nthese is the array after deleting the last item: ";
	MyDynamicArray.PrintList();
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();
	MyDynamicArray.PrintList();
	cout << "\nthis is the size of the array before the resize: " << MyDynamicArray.Size();
	MyDynamicArray.Resize(3);
	cout << "\nthis is the size of the array after the resize: " << MyDynamicArray.Size();
	cout << "\nand this is the array inices: ";
	MyDynamicArray.PrintList();
	MyDynamicArray.Resize(10);
	cout << "\nthis is the indices value after resizing to 10: ";
	MyDynamicArray.PrintList();
	
	cout << "\n\nthis is the size: " << MyDynamicArray.Size();

	cout << "\n-------------------------------------";

	cout << "\nthis is the first index value: " << MyDynamicArray.GetItem(0);

	MyDynamicArray.Reverse();
	cout << "\nthis is the array after reverse(): ";
	MyDynamicArray.PrintList();

	MyDynamicArray.Clear();

	cout << "\nthis is the size after the clear(): ";
	MyDynamicArray.Size();
	cout << "\nthis is the array after clear(): ";
	MyDynamicArray.PrintList();


}