#include <iostream>
#include <map>
using namespace std;


int main()
{
    string key1, key2; int value1, value2; 
    
    cout << "\nEnter the first key && it's value: ";
    cin >> key1 >> value1;
    
    cout << "\nEnter the second key && it's value: ";
    cin >> key2 >> value2;

    map<string, int> studentGrades;
    studentGrades[key1] = value1;

    studentGrades[key2] = value2;

    for(auto &pair : studentGrades)
        cout << "\nName: " << pair.first << "\nGrade: " << pair.second << "\n\n";

    if (studentGrades.find(key1) != studentGrades.end())
        cout << "\n" << key1 << " is found ";
    


    
}
