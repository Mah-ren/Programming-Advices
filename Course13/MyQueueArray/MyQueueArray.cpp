#include <iostream>
#include "clsMyQueueArr.h"
using namespace std;


int main()
{
    clsMyQueueArr<int> MyQueueArray;
    
    MyQueueArray.Push(1);
    MyQueueArray.Push(2);
    MyQueueArray.Push(4);
    MyQueueArray.Push(6);
    MyQueueArray.Push(8);

    cout << "\nthis is the queue content: ";
    MyQueueArray.Print();

    MyQueueArray.Pop();
    MyQueueArray.Pop();
    MyQueueArray.Pop();

    cout << "\nthe queue content after deleting the first three numbers: ";
    MyQueueArray.Print();

    MyQueueArray.Push(40);
    MyQueueArray.Push(50);
    MyQueueArray.Push(90);

    cout << "\nAdding 3 digits 40, 50, 90:\n";
    MyQueueArray.Print();

    cout << "\nthis is the first digit: " << MyQueueArray.front();
    cout << "\nthis is the last digit: " << MyQueueArray.back();

    cout << "\nthis is the size of the queue: " << MyQueueArray.Size();

    cout << "\nthis is the first extension GetItem(2) means the second index: " << MyQueueArray.GetItem(2);
    cout << "\nExtension2: Reverse()";
    MyQueueArray.Reverse();
    MyQueueArray.Print();

    cout << "\nreversing it again: ";
    MyQueueArray.Reverse();
    MyQueueArray.Print();

    cout << "\nExtension3: UpdateItem(3, 500)\n";
    MyQueueArray.UpdateItem(3, 500);
    MyQueueArray.Print();

    MyQueueArray.InsertAfter(2, 23);
    cout << "\nthis is Extension4 insertAfter(2, 23) \n";
    MyQueueArray.Print();


    MyQueueArray.InsertAtBeginning(99);
    cout << "\nthis is the Extension5 insert 99at front: ";
    MyQueueArray.Print();

    MyQueueArray.InsertAtBack(88);
    cout << "\nthis is the Extension5 insert 88 at back: ";
    MyQueueArray.Print();

    cout << "\nthis is the size before clear(): " << MyQueueArray.Size();

    MyQueueArray.Clear();
    cout << "\nthis is the queue after clear() ";
    MyQueueArray.Print();


    cout << "\nthis is the size after clear(): " << MyQueueArray.Size();


    if (MyQueueArray.IsEmpty())
        cout << "\nthis double linked list is empty\n";
    else
        cout << "\nthis double linked list is not empty\n";

    MyQueueArray.InsertAtBeginning(5);
    MyQueueArray.InsertAtBeginning(4);
    MyQueueArray.InsertAtBeginning(3);
    MyQueueArray.InsertAtBeginning(2);
    MyQueueArray.InsertAtBeginning(1);

    std::cout << "\nArray Content:\n";
    MyQueueArray.PrintList();

    int value1 = 2, value2 = 500;
    MyQueueArray.UpdateItem(value1, value2);

    cout << "\nthis is array after updating [" << value1 << "] to [" << value2 << "]: ";
    MyQueueArray.PrintList();

    int index = 4;
    int result = MyQueueArray.GetItem(index);
    cout << "\nthe value of index " << index << " is: " << result;


    MyQueueArray.Reverse();
    std::cout << "\nLinked List Content After Reverse function:\n";
    MyQueueArray.PrintList();

    MyQueueArray.Reverse();
    std::cout << "\nLinked List Content After Reverse function again:\n";
    MyQueueArray.PrintList();

    std::cout << "\nthe size of the linked list: " << MyQueueArray.Size();

    if (MyQueueArray.IsEmpty())
        cout << "\nthis double linked list is empty\n";
    else
        cout << "\nthis double linked list is not empty\n";




    MyQueueArray.InsertAfter(2, 500);
    std::cout << "\nAfter Inserting 500 after index 2:\n";
    MyQueueArray.PrintList();

    MyQueueArray.InsertAfter(2, 900);
    std::cout << "\nAfter Inserting 900 after  index 2:\n";
    MyQueueArray.PrintList();

    MyQueueArray.InsertAtEnd(700);
    std::cout << "\nAfter Inserting 700 at end:\n";
    MyQueueArray.PrintList();

    MyQueueArray.DeleteItem(4);
    std::cout << "\nAfter Deleting 4:\n";
    MyQueueArray.PrintList();

    MyQueueArray.DeleteFirstItem();
    std::cout << "\nAfter Deleting First Node:\n";
    MyQueueArray.PrintList();

    std::cout << "\nAfter Deleting Last Node:\n";
    MyQueueArray.DeleteLastItem();
    MyQueueArray.PrintList();

    cout << "\nThe Double Linked List after Clear: " << endl;
    MyQueueArray.Clear();
    MyQueueArray.PrintList();
    cout << "\nthe size of the double linked list: " << MyQueueArray.Size() << endl;

    MyQueueArray.InsertAtBeginning(5);
    MyQueueArray.InsertAtBeginning(4);
    MyQueueArray.InsertAtBeginning(3);
    MyQueueArray.InsertAtBeginning(2);
    MyQueueArray.InsertAtBeginning(1);
    cout << "\nThis is the Double Linked List after adding 5, 4, 3, 2, and 1: " << endl;
    MyQueueArray.PrintList();

    cout << "\nthe size of the double linked list: " << MyQueueArray.Size();


    system("pause>0");


    return 0;


} 