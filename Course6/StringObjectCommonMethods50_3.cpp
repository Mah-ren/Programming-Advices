#include <iostream>
using namespace std;


int main()
{
    string S1 = "Mahmoud Ahmed Abdel aal Ahmed";
    cout << "\nThe Length of the String : " << S1.length(); 
    
    cout << "\nThis is the first index with .at(index): " << S1.at(0) ;
    cout << "\nThis is the first index like an array : " << S1[0] ;
    S1.append("Abo Hamad");
    cout << "\nThis is S1 After appending : " << S1 ;
    S1.insert(7 , " Programmer ") ;
    cout << "\nThis is S1 after inserting word \"Programmer\" : " << S1 ;
    S1.push_back('X');
    cout << "\nS1 After pushing back: " << S1 ;
    S1.pop_back();
    cout << "\nS1 After Poping back: " << S1 ;
    cout << "\nGive me the first word of the string: " << S1.substr(0,29);

    cout << "\nfind Pro " << S1.find("Pro") ;
    if(S1.find("Mah") != S1.npos)
  
        cout << "\nMah Pos: " << S1.find("Mah") ;
  
    else 
        cout << "\nMah is not found " << "\n";

    S1.clear();
    cout << S1 << "not found " ;

}