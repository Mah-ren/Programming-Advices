#include <iostream>
#include <queue>
using namespace std;


int main()
{
    queue<int> MyQueues1;
    queue<int> MyQueues2;
    
    MyQueues1.push(1);
    MyQueues1.push(2);
    MyQueues1.push(3);
    MyQueues1.push(4);
    MyQueues1.push(5);
    MyQueues1.push(6);
    MyQueues1.push(7);

    cout << "\nthe size of the queue: " << MyQueues1.size();

    while(!MyQueues1.empty())
    {
        cout << "\n" << MyQueue.front();
        MyQueues1.pop();
    }
    cout << "\nthe size of the queue: " << MyQueues1.size();
    cout << "\n" << endl;

    MyQueues1.push(10);
    MyQueues1.push(20);
    MyQueues1.push(30);
    MyQueues1.push(40);

    MyQueues2.push(50);
    MyQueues2.push(60);
    MyQueues2.push(70);
    MyQueues2.push(80);


    cout << "\nprint the first queue\n";
    while(!MyQueues1.empty())
    {
        cout << "\n" << MyQueues1.front();
        MyQueues1.pop();
    }

    cout << "\nprint the second queue\n";
    while(!MyQueues2.empty())
    {
        cout << "\n" << MyQueues2.front();
        MyQueues2.pop();
    }


    MyQueues1.push(10);
    MyQueues1.push(20);
    MyQueues1.push(30);
    MyQueues1.push(40);

    MyQueues2.push(50);
    MyQueues2.push(60);
    MyQueues2.push(70);
    MyQueues2.push(80);


    MyQueues1.swap(MyQueues2);

    cout << "\nprint the first queue\n";
    while(!MyQueues1.empty())
    {
        cout << "\n" << MyQueues1.front();
        MyQueues1.pop();
    }

    cout << "\nprint the second queue\n";
    while(!MyQueues2.empty())
    {
        cout << "\n" << MyQueues2.front();
        MyQueues2.pop();
    }


}