#include <iostream>
using namespace std;

class Node
{
public:
    Node()
    {
    }
    int value;
    Node *next;
};

void InsertNodeAtBeginning(Node *&head, int value)
{
    Node *new_node = new Node();

    new_node->value = value;
    new_node->next = head;

    head = new_node;
}

void PrintList(Node *head)
{
    while (head != NULL)
    {
        cout << head->value << endl;
        head = head->next;
    }
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

void InsertAfter(Node *prev_node, int value)
{
    if (prev_node != NULL)
    {
        Node *new_node = new Node();
        new_node->value = value;
        new_node->next = prev_node->next;
        prev_node->next = new_node;
    }
    else
        cout << "\nError: Previous Node is NULL.";
}

void InsertAtEnd(Node *&head, int value)
{
    Node *new_node = new Node();
    new_node->value = value;
    new_node->next = NULL;

    if (head == NULL)
    {
        head = new_node;
        return;
    }

    Node *LastNode = head;

    while (LastNode->next != NULL)
    {
        LastNode = LastNode->next;
    }
    LastNode->next = new_node;
    return;
}

void DeleteNode(Node *&head, int value)
{
    Node *Current = head, *Prev = head;
    if (head == NULL)
    {
        cout << "\nError: Head Node is NULL \"from node\"";
        return;
    }

    if (Current->value == value)
    {
        head = Current->next;
        delete Current;
        return;
    }

    while (Current != NULL && Current->value != value)
    {
        Prev = Current;
        Current = Current->next;
    }

    if (Current == NULL)
        return;

    Prev->next = Current->next;
    delete Current;
    return;
}

void DeleteFirstNode(Node *&head)
{
    Node *Current = head;

    if (Current == NULL){
        cout << "\nError: Empty List\"from delete first node\"\n";
        return;
    }

    if (Current->next = NULL){
        cout << "\nthere is only one node \"from delete first node\":-)";
        delete Current;
        return;
    }


    head = Current->next;
    delete Current;
    return;
}

void DeleteLastNode(Node *&head)
{
    Node *Current = head, *Prev = head;

    if (head == NULL){
        cout << "\nError: Empty List\n";
        return;
    }

    while (Current != NULL && Current->next != NULL){
        Prev = Current;
        Current = Current->next;
    }
    Prev->next = NULL;
    delete Current;
    return;
}

int main()
{
    Node *head;
    head = NULL;

    InsertNodeAtBeginning(head, 10);
    InsertNodeAtBeginning(head, 20);
    InsertNodeAtBeginning(head, 30);
    InsertNodeAtBeginning(head, 40);
    PrintList(head);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout << "\ninsert after\n";
    Node *prev_node = NULL;
    prev_node = Find(head, 20);
    InsertAfter(prev_node, 500);
    PrintList(head);
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout << "\ninsert at end\n";
    InsertAtEnd(head, 1000);
    PrintList(head);
    // //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // cout << "\ndelete\n";
    // DeleteNode(head, 500);
    // PrintList(head);
    // //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // cout << "\n\ndelete first node.\n";
    // DeleteFirstNode(head);
    // DeleteFirstNode(head);
    // DeleteFirstNode(head);
    // DeleteFirstNode(head);
    // PrintList(head);
    // //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    cout << "\n\nDelete Last node.\n";
    DeleteLastNode(head);
    PrintList(head);
}
