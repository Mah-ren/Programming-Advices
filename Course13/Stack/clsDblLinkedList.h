
#pragma once
#include <iostream>


template <class T>
class clsDblLinkedList
{
private:

    int _size = 0;

public:
    /*extern clsDblLinkedList <T> MyDblLinkedList;*/
    class Node
    {

    public:
        T value;
        Node* next;
        Node* prev;
    };

    Node* head = NULL;

    void InsertAtBeginning(T value)
    {

        /*
            1-Create a new node with the desired value.
            2-Set the next pointer of the new node to the current head of the list.
            3-Set the previous pointer of the current head to the new node.
            4-Set the new node as the new head of the list.
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = head;
        newNode->prev = NULL;

        if (head != NULL) {
            head->prev = newNode;
        }
        head = newNode;

        _size++;
    }

    // Print the linked list
    void PrintList()

    {
        Node* Current = head;

        while (Current != NULL) {
            std::cout << Current->value << " ";
            Current = Current->next;
        }
        std::cout << "\n";


    }

    Node* Find(T Value)
    {
        Node* Current = head;
        while (Current != NULL) {

            if (Current->value == Value)
                return Current;

            Current = Current->next;
        }

        return NULL;

    }

    void InsertAfter(Node* current, T value) {


        /*  1 - Create a new node with the desired value.
             2-Set the next pointer of the new node to the next node of the current node.
             3-Set the previous pointer of the new node to the current node.
             4-Set the next pointer of the current node to the new node.
             5-Set the previous pointer of the next node to the new node(if it exists).
        */

        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = current->next;
        newNode->prev = current;

        if (current->next != NULL) {
            current->next->prev = newNode;
        }
        current->next = newNode;

        _size++;
    }

    bool InsertAfter(int index, T value) {
        if (index > _size - 1 || index < 0 || _size <= 0)
            return false;

        Node* itemNode = GetNode(index);
        if (itemNode != NULL) {
            InsertAfter(itemNode, value);
            return true;
        }

        return false;
    }

    void InsertAtEnd(T value) {

        /*
            1-Create a new node with the desired value.
            2-Traverse the list to find the last node.
            3-Set the next pointer of the last node to the new node.
            4-Set the previous pointer of the new node to the last node.
        */


        Node* newNode = new Node();
        newNode->value = value;
        newNode->next = NULL;
        if (head == NULL) {
            newNode->prev = NULL;
            head = newNode;
        }
        else {
            Node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }

        _size++;
    }

    void DeleteNode(Node*& NodeToDelete) {

        /*
            1-Set the next pointer of the previous node to the next pointer of the current node.
            2-Set the previous pointer of the next node to the previous pointer of the current node.
            3-Delete the current node.
        */
        if (head == NULL || NodeToDelete == NULL) {
            return;
        }
        if (head == NodeToDelete) {
            head = NodeToDelete->next;
        }
        if (NodeToDelete->next != NULL) {
            NodeToDelete->next->prev = NodeToDelete->prev;
        }
        if (NodeToDelete->prev != NULL) {
            NodeToDelete->prev->next = NodeToDelete->next;
        }
        delete NodeToDelete;

        _size--;
    }

    void DeleteFirstNode()
    {

        /*
            1-Store a reference to the head node in a temporary variable.
            2-Update the head pointer to point to the next node in the list.
            3-Set the previous pointer of the new head to NULL.
            4-Delete the temporary reference to the old head node.
        */

        if (head == NULL) {
            return;
        }
        Node* temp = head;
        head = head->next;
        if (head != NULL) {
            head->prev = NULL;
        }
        delete temp;
        _size--;
    }

    void DeleteLastNode() {

        /*
            1-Traverse the list to find the last node.
            2-Set the next pointer of the second-to-last node to NULL.
            3-Delete the last node.
        */

        if (head == NULL) {
            return;
        }

        if (head->next == NULL) {
            delete head;
            head = NULL;
            return;
        }

        Node* current = head;
        // we need to find the node before last node.
        while (current->next->next != NULL)
        {
            current = current->next;
        }

        Node* temp = current->next;
        current->next = NULL;
        delete temp;
        _size--;
    }

    /*
    the old way
    int Size()
    {
        Node* Current = head;
        int count = 0;
        while (Current != NULL) {
            count++;
            Current = Current->next;
        }
        return count;

    }*/

    int Size()
    {
        return _size;
    }

    bool IsEmpty()
    {
        return _size < 1;
    }

    void Clear()
    {
        while (_size > 0)
        {
            DeleteFirstNode();
        }
    }

    void Reverse()
    {
        Node* Current = head;
        Node* temp = nullptr;

        while (Current != nullptr) {
            temp = Current->prev;
            Current->prev = Current->next;
            Current->next = temp;
            Current = Current->prev;
        }

        if (temp != nullptr) {
            head = temp->prev;
        }
    }



    Node* GetNode(int index) {

        int counter = 0;
        if (index > _size - 1 || index < 0)
            return NULL;

        Node* Current = head;

        while (Current != NULL && (Current->next) != NULL) {

            if (counter == index)
                break;

            Current = Current->next;
            counter++;
        }

        return Current;
    }

    T GetItem(int index) {
        Node* itemNode = GetNode(index);

        if (itemNode == NULL)
            return NULL;

        return GetNode(index)->value;
    }


    bool UpdateItem(int index, T new_value) {
        Node* itemNode = GetNode(index);

        if (itemNode != NULL) {
            itemNode->value = new_value;
            return true;
        }

        return false;
    }


};


