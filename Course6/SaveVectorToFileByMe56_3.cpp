#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void SaveVectorToFile(string fileName , vector<string> &vFileContent)
{
    fstream file ; 
    file.open(fileName , ios::out);

    if(file.is_open())
    { 
        string text ;
        for(string &text : vFileContent)
        {
            if(text != "")
            {
                file << text << endl ;
            }
        } 

        file.close();
    }
    else 
        cout << "\nError opening file: " << fileName << endl ;
}


int main()
{
    vector<string> vFileContent{"mahmoud ahmed "} ; 
    SaveVectorToFile("lover.txt" , vFileContent);

}