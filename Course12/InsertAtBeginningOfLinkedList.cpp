#include <iostream>
using namespace std;


class Node 
{
public:
    int value;
    Node *next;
};

void InsertNodeAtBeginning(Node* &head, int value)
{
    Node *new_node = new Node();

    new_node->value = value;
    new_node->next = head;

    head = new_node;
}

void PrintList(Node *head)
{
    while(head != NULL)
    {
        cout << "\nValue is: " << head->value;
        head = head->next;
    }

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

} 

