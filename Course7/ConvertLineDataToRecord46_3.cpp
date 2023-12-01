#include <iostream>
#include <vector>
#include <limits>
using namespace std; 

typedef struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone; 
    double balance;
}CD;


void ConvertLineDataToRecord(CD& , string);
void PrintRecord(CD);
void PrintVector(vector<string>&);
vector<string> SplitString(string , string);
CD ReadNewClientData(string);
string ConvertRecordToLine(string , CD);
string GetStringInput(string);


void Project()
{
    CD cd ;
    string delimiter = GetStringInput("\nPlease Enter The Delimiter: ");

    string lineRecord = "pro219#//#1234#//#Mahmoud Ahmed Abdel aal Ahmed #//#01159340935#//#500";

    cout << "\nThe following is the extracted client record:\n\n";
    ConvertLineDataToRecord(cd , lineRecord);
    PrintRecord(cd);
}

int main()
{
    Project();
}


void PrintVector(vector<string> &vString)
{
    for(string &element : vString)
    {
        cout << element << "\n";
    }

    cout << endl ;
}   
CD ReadNewClientData(string prompt)
{
    CD cd ;
   
    cout << prompt ;
    
    cout << "\nEnter Account Number: ";
    getline(cin , cd.accountNumber);

    cout << "\nEnter Pin Code: ";
    getline(cin , cd.pinCode);    

    cout << "\nEnter Name: ";
    getline(cin , cd.name) ;
    
    cout << "\nEnter Phone: ";
    getline(cin , cd.phone);

    cout << "\nEnter Account Balance: ";
    cin >> cd.balance ;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //~ Clear buffer
    return cd ;
}

string ConvertRecordToLine(string delimiter , CD cd)
{
    return  (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
}

string GetStringInput(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

 
void ConvertLineDataToRecord(CD &cd , string lineRecord)
{
    vector<string> vString ; 
    vString = SplitString(lineRecord , "#//#");

    for(short i = 0 ; i < vString.size() ; ++i)
    {
        cd.accountNumber = vString[0] ; 
        cd.pinCode       = vString[1] ;
        cd.name          = vString[2] ;
        cd.phone         = vString[3] ;
        cd.balance       = stod(vString[4]) ;
    }
}
 

vector<string> SplitString(string str , string delimeter)
{
    vector<string> vString ;
    string word ;
    short position = 0 ;
 
    while((position = str.find(delimeter)) != str.npos)
    {   
        word = str.substr(0,position);
        
        if(word != "")
        {
            vString.push_back(word);
        }
        
        str.erase(0 , position + delimeter.length());
    }

    if(str != "")
    {
        vString.push_back(str);
    } 

    return vString ;
}
 
void PrintRecord(CD cd)
{
    cout << "\nAcount Number: " << cd.accountNumber ;
    cout << "\nPin Code: " << cd.pinCode ;
    cout << "\nName: " << cd.name ;
    cout << "\nPhone: " << cd.phone ;
    cout << "\nBalance: " << cd.balance ;
}