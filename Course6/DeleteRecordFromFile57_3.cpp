#include <iostream>
#include <vector>
#include <fstream>
#include <string>
using namespace std; 



void LoadDataFromFileToVector(string fileName , vector<string> &vFileContent)
{
    fstream file ; 
    file.open(fileName , ios::in);

    if(file.is_open())
    {
        string line ; 
        
           while(getline(file , line)) 
        {
            vFileContent.push_back(line);
        }

        file.close();
    }
    else 
        cout << "\nError opening file: " << fileName << endl ;
}

void SaveVectorToFile(string fileName , vector<string> &vFileContent)
{
    fstream File ; 
    File.open(fileName , ios::out);
    
    if(File.is_open())
    {
        for(string &line : vFileContent)
        {
            if(line != "")
            {
                File << line << endl ;
            }
        }

        File.close();
    }
}

void DeleteRecordFromFile(string fileName , string record)
{
    vector<string> vFileContent ;
    LoadDataFromFileToVector(fileName , vFileContent);

    for(string &line : vFileContent)
    {
        if(line == record)
        {
            line = "" ;
        }
    }
    
    SaveVectorToFile(fileName , vFileContent);
}

void PrintFileContent(string fileName)
{
    fstream File ; 
    File.open(fileName , ios::in);
    if(File.is_open())
    {
        string line ;

        while(getline(File , line))
        {
            cout << line << endl ;
        }

        File.close();
    }
}

int main()
{
    cout << "\nThis is the content of the file before deleting : \n";
    PrintFileContent("Programmer.txt");
    string record = " ";
    cout << "\nPlease Enter the Record that you wanna search for: \n";
    cin >> record ;
    DeleteRecordFromFile("Programmer.txt" , record);
    cout << "\nThis is the content of the file before deleting : \n";
    PrintFileContent("Programmer.txt");
}