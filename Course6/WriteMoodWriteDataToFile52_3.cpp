#include <iostream>
#include <string>
#include <fstream>
using namespace std ;


void PrintFileContent(string fileName)
{
    fstream myFile ; 
    myFile.open(fileName , ios::in);
    
    if(myFile.is_open())
    {
        string text ; 
        
        while(getline(myFile , text))
        {
            cout  << text << "\n" ;
        }
        myFile.close();
    }    
}

int main()
{
    PrintFileContent("myFile.txt");
}




































