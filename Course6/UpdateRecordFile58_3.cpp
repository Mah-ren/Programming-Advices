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

void UpdateRecordInFile(string fileName , string record , string updatedRecord)
{
    vector<string> vFileContent ;
    LoadDataFromFileToVector(fileName , vFileContent);

    for(string &line : vFileContent)
    {
        if(line == record)
        {
            line = updatedRecord ;
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
    system("color 0c");
    cout << "\nThis is the content of the file before updating : \n";
    PrintFileContent("Programmer.txt");
   
    string record = " " , updatedRecord = " ";
    cout << "\nPlease Enter the Record that you wanna change it to -> old record : updated record respectivly: \n";
    cin >> record >> updatedRecord; 

    UpdateRecordInFile("Programmer.txt" , record , updatedRecord);
    system("color 06");
    cout << "\nThis is the content of the file before deleting : \n";
    PrintFileContent("Programmer.txt");
}