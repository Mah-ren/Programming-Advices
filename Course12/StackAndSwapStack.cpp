#include <iostream>
#include <stack>
using namespace std;


int main()
{
    stack<int> stkNumbers1;
    stack<int> stkNumbers2;
    
    stkNumbers1.push(1);
    stkNumbers1.push(2);
    stkNumbers1.push(3);
    stkNumbers1.push(4);
    stkNumbers1.push(5);
    stkNumbers1.push(6);
    stkNumbers1.push(7);

    cout << "\nthe size of the stack: " << stkNumbers1.size();

    while(!stkNumbers1.empty())
    {
        cout << "\n" << stkNumbers1.top();
        stkNumbers1.pop();
    }
    cout << "\nthe size of the stack: " << stkNumbers1.size();
    cout << "\n" << endl;

    stkNumbers1.push(10);
    stkNumbers1.push(20);
    stkNumbers1.push(30);
    stkNumbers1.push(40);

    stkNumbers2.push(50);
    stkNumbers2.push(60);
    stkNumbers2.push(70);
    stkNumbers2.push(80);


    cout << "\nprint the first stack\n";
    while(!stkNumbers1.empty())
    {
        cout << "\n" << stkNumbers1.top();
        stkNumbers1.pop();
    }

    cout << "\nprint the second stack\n";
    while(!stkNumbers2.empty())
    {
        cout << "\n" << stkNumbers2.top();
        stkNumbers2.pop();
    }


    stkNumbers1.push(10);
    stkNumbers1.push(20);
    stkNumbers1.push(30);
    stkNumbers1.push(40);

    stkNumbers2.push(50);
    stkNumbers2.push(60);
    stkNumbers2.push(70);
    stkNumbers2.push(80);


    stkNumbers1.swap(stkNumbers2);

    cout << "\nprint the first stack\n";
    while(!stkNumbers1.empty())
    {
        cout << "\n" << stkNumbers1.top();
        stkNumbers1.pop();
    }

    cout << "\nprint the second stack\n";
    while(!stkNumbers2.empty())
    {
        cout << "\n" << stkNumbers2.top();
        stkNumbers2.pop();
    }


}