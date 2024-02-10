#include <iostream>
#include "clsDblLinkedList.h"
#include "clsMyQueue.h"
#include <string>
using namespace std;

int main()
{
    clsMyQueue<int> MyQueue;
    MyQueue.Push(1);
    MyQueue.Push(2);
    MyQueue.Push(4);
    MyQueue.Push(6);
    MyQueue.Push(8);



    clsDblLinkedList <int> MydblLinkedList;
    
    if (MydblLinkedList.IsEmpty())
        cout << "\nthis double linked list is empty\n";
    else
        cout << "\nthis double linked list is not empty\n";

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);

    std::cout << "\nLinked List Content:\n";
    MydblLinkedList.PrintList();
    
    int value1 = 2, value2 = 500;
    MydblLinkedList.UpdateItem(value1, value2);

    cout << "\nthis is linked list after updating [" << value1 << "] to [" << value2 << "]: ";
    MydblLinkedList.PrintList();

    int index = 4;
    int result = MydblLinkedList.GetItem(index);
    cout << "\nthe value of index " << index << " is: " << result;

    clsDblLinkedList<int> ::Node* M;
    M = MydblLinkedList.GetNode(index);
    cout << "\nthe value of index [" << index << "] is: " << M->value;


    
    clsDblLinkedList <int> ::Node* N;
    N = MydblLinkedList.Find(2);

    cout << "\nThe Value of the previous Node is: " << N->prev->value;
    cout << "\nNode Value is: " << N->value;
    cout << "\nThe Value of the next Node Value is: " << N->next->value;


    MydblLinkedList.Reverse();
    std::cout << "\nLinked List Content After Reverse function:\n";
    MydblLinkedList.PrintList();   
    
    MydblLinkedList.Reverse();
    std::cout << "\nLinked List Content After Reverse function again:\n";
    MydblLinkedList.PrintList();

    std::cout << "\nthe size of the linked list: " << to_string(MydblLinkedList.Size());

    if (MydblLinkedList.IsEmpty())
        cout << "\nthis double linked list is empty\n";
    else
        cout << "\nthis double linked list is not empty\n";
   

    clsDblLinkedList<int>::Node* N1 = MydblLinkedList.Find(2);

    if (N1 != NULL)
        std::cout << "\nNode with value 2 is Found :-)\n";
    else
        std::cout << "\nNode Is not found :-(\n";

    MydblLinkedList.InsertAfter(N1, 500);
    std::cout << "\nAfter Inserting 500 after 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAfter(2, 900);
    std::cout << "\nAfter Inserting 900 after  index 2:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.InsertAtEnd(700);
    std::cout << "\nAfter Inserting 700 at end:\n";
    MydblLinkedList.PrintList();

    clsDblLinkedList<int>::Node* N2 = MydblLinkedList.Find(4);
    MydblLinkedList.DeleteNode(N2);
    std::cout << "\nAfter Deleting 4:\n";
    MydblLinkedList.PrintList();

    MydblLinkedList.DeleteFirstNode();
    std::cout << "\nAfter Deleting First Node:\n";
    MydblLinkedList.PrintList();

    std::cout << "\nAfter Deleting Last Node:\n";
    MydblLinkedList.DeleteLastNode();
    MydblLinkedList.PrintList();

    cout << "\nThe Double Linked List after Clear: " << endl;
    MydblLinkedList.Clear();
    MydblLinkedList.PrintList();
    cout << "\nthe size of the double linked list: " << to_string(MydblLinkedList.Size()) << endl;

    MydblLinkedList.InsertAtBeginning(5);
    MydblLinkedList.InsertAtBeginning(4);
    MydblLinkedList.InsertAtBeginning(3);
    MydblLinkedList.InsertAtBeginning(2);
    MydblLinkedList.InsertAtBeginning(1);
    cout << "\nThis is the Double Linked List after adding 5, 4, 3, 2, and 1: " << endl;
    MydblLinkedList.PrintList();

    cout << "\nthe size of the double linked list: " << to_string(MydblLinkedList.Size());


    system("pause>0");


    return 0;
}