#include <iostream>
#include <string>
#include <fstream>
#include <vector>
using namespace std;
 

void LoadDataFromFileToVector(string fileName , vector<string> &vFileContent)
{
    fstream file ; 
    file.open(fileName , ios::in);

    if(file.is_open())
    {
        string text ; 
        
        cout << "\nPlease enter the names of the Employees: \n";

        while(getline(file , text)) 
        {
            vFileContent.push_back(text);
        }

        file.close();
    }
    else 
        cout << "\nError opening file: " << fileName << endl ;
}

int main()
{
    vector<string> vFileContent ;
    LoadDataFromFileToVector("vectorFile.txt" , vFileContent);

    cout << "\nThanks for Allah, the problem was that read Mode can't make file and i'll watch this lesson from Abdel rahman Gamal In Shaa Allah";
    for(string &text : vFileContent)
    {
        cout << "\n" << text ;
    }
    
    vFileContent.pop_back();

    for(string &text : vFileContent)
    {
        cout << "\n" << text ;
    }
    


    return 0 ; 
}
