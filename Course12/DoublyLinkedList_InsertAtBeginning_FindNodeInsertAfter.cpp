#include <iostream>
using namespace std;

// Create a node
class Node
{
public:
    int value;
    Node *next;
    Node *prev;
};

void InsertAtBeginning(Node *&head, int value)
{

    /*
        1-Create a new node with the desired value.
        2-Set the next pointer of the new node to the current head of the list.
        3-Set the previous pointer of the current head to the new node.
        4-Set the new node as the new head of the list.
    */

    Node *newNode = new Node();
    newNode->value = value;
    newNode->next = head;
    newNode->prev = NULL;

    if (head != NULL)
    {
        head->prev = newNode;
    }
    head = newNode;
}

void PrintNodeDetails(Node *head)
{

    if (head->prev != NULL)
        cout << head->prev->value;
    else
        cout << "NULL";

    cout << " <--> " << head->value << " <--> ";

    if (head->next != NULL)
        cout << head->next->value << "\n";
    else
        cout << "NULL";
}

// Print the linked list
void PrintListDetails(Node *head)
{
    cout << "\n\n";
    while (head != NULL)
    {
        PrintNodeDetails(head);
        head = head->next;
    }
}

// Print the linked list
void PrintList(Node *head)
{
    cout << "NULL <--> ";
    while (head != NULL)
    {
        cout << head->value << " <--> ";
        head = head->next;
    }
    cout << "NULL";
}

Node *Find(Node *head, int value)
{
    while (head != NULL)
    {
        if (head->value == value)
            return head;
        head = head->next;
    }
    return NULL;
}

void InsertAtEnd(Node *&head, int value)
{
    Node *new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        new_node->prev = NULL;
    }

    else
    {
        Node *Current = head;
        while (Current->next != NULL)
            Current = Current->next;
        new_node->prev = Current;
        Current->next = new_node;
    }
}

void InsertAfter(Node *Current, int value)
{
    if (Current != NULL && Current->next != NULL)
    {

        Node *new_node = new Node();

        new_node->value = value;
        new_node->next = Current->next;
        new_node->prev = Current;
        Current->next = new_node;
        new_node->next->prev = new_node;
    }
}

void DeleteNode(Node *&head, Node *&NodeToDelete)
{

    /*
        1-Set the next pointer of the previous node to the next pointer of the current node.
        2-Set the previous pointer of the next node to the previous pointer of the current node.
        3-Delete the current node.
    */
    if (head == NULL || NodeToDelete == NULL)
    {
        return;
    }
    if (head == NodeToDelete)
    {
        head = NodeToDelete->next;
    }
    if (NodeToDelete->next != NULL)
    {
        NodeToDelete->next->prev = NodeToDelete->prev;
    }
    if (NodeToDelete->prev != NULL)
    {
        NodeToDelete->prev->next = NodeToDelete->next;
    }
    delete NodeToDelete;
}

void DeleteFirstNode(Node *&head)
{
    if (head != NULL)
    {
        Node *toDelete = head;
        head = head->next;

        if (head != NULL)
        {
            head->prev = NULL;

            delete toDelete;
        }
    }
}

void DeleteLastNode(Node *&head){
    
    if (head == NULL){
        return;
    }
    if (head->next == NULL){
        delete head;
        head = NULL;
        return;
    }
    
    Node *toDelete = head;
    
    while (toDelete->next != NULL){
        toDelete = toDelete->next;
    }
    toDelete->prev->next = NULL;
    delete toDelete;
}


int main()
{
    Node *head = NULL;

    InsertAtBeginning(head, 5);
    InsertAtBeginning(head, 4);
    InsertAtBeginning(head, 3);
    InsertAtBeginning(head, 2);
    InsertAtBeginning(head, 1);

    cout << "\nLinked List Contenet:\n";
    PrintList(head);
    PrintListDetails(head);

    int value = 343;
    Node *N1 = Find(head, value);

    if (N1 != NULL)
    {
        cout << "\n"
                << value << " is found. :-)";
    }
    else
        cout << "\n"
                << value << " is not found. :-(";

    cout << "\n\n";

    InsertAtEnd(head, 50);
    cout << "\nLinked List Contenet:after inserting at end\n";
    PrintList(head);
    PrintListDetails(head);

    InsertAfter(N1, 100);
    cout << "\nLinked List Contenet:after inserting after\n";
    PrintList(head);
    PrintListDetails(head);

    N1 = Find(head, 100);
    DeleteNode(head, N1);
    cout << "\nLinked List Contenet:after deleting node\n";
    PrintList(head);
    PrintListDetails(head);

    N1 = Find(head, 5);
    DeleteNode(head, N1);
    cout << "\nLinked List Contenet:after deleting node\n";
    PrintList(head);
    PrintListDetails(head);

    DeleteFirstNode(head);
    cout << "\nLinked List Contenet:after deleting the first node\n";
    PrintList(head);
    PrintListDetails(head);

    DeleteFirstNode(head);
    cout << "\nLinked List Contenet:after deleting the first node\n";
    PrintList(head);
    PrintListDetails(head);

    InsertAtEnd(head, 50);
    cout << "\nLinked List Contenet:after inserting at end\n";
    PrintList(head);
    PrintListDetails(head);
 
    DeleteLastNode(head);
    cout << "\nLinked List Contenet:after deleting the last node\n";
    PrintList(head);
    PrintListDetails(head);

    DeleteLastNode(head);
    cout << "\nLinked List Contenet:after deleting the last node\n";
    PrintList(head);
    PrintListDetails(head);

}