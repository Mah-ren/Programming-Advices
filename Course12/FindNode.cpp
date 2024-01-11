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

Node *Find(Node* head, int value)
{
    while (head->value != NULL){
        if (head->value == value)
            return head;    

        head = head->next;
    }
    return NULL;
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

    Node *N1 = Find(head, 120);

    (N1 != NULL) ? cout << "\nthe value of " << N1->value << " is found :-)\n": cout << "\n the value of " << N1->value << " is not found :-(\n";
    system("pause > 0");

}
