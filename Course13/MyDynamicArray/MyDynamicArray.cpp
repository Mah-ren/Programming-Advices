#include <iostream>
#include "clsDynamicArray.h"
using namespace std;


int main() {
	clsDynamicArray<int> MyDynamicArray(5);
	
	MyDynamicArray.SetItem(0, 10);
	MyDynamicArray.SetItem(1, 20);
	MyDynamicArray.SetItem(2, 30);
	MyDynamicArray.SetItem(3, 40);
	MyDynamicArray.SetItem(4, 50);

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

}