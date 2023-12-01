//! Show All Clients By My Self

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <limits>
using namespace std;

typedef struct stClientData
{
    string accountNumber;
    string pinCode;
    string name;
    string phone;
    double balance = 0;
    short numberOfClients = 0;
} CD;


void PrintClientsData(vector<CD>vClients);
vector<string> SplitString(string str, string delimeter = "#//#");
vector<CD> LoadDataFromFileToVector(string);
string Tabs(short numberOfTabs);
void AddClients(string fileName, string delimiter = "#//#");
void AddNewClient(string fileName, string delimiter = "#//#");
void AddDataLineToFile(string fileName, string dataLine);
CD ReadNewClientData();
string ConvertRecordToLine(string delimiter, CD cd);
CD ConvertLineToRecord(string line);
void ShowClientsStatement(size_t);
void PrintOneClientData(CD cd);



void Project()
{
    //! أول حاجة بملئ الاستركت ثم احوله لاسترنج عبارة عن نص ثم اطبع الاسترنج للملف
    string fileName = "ShowClients.txt";
    string delimiter = "#//#";
    AddClients(fileName);

    /*
        ~ دي طريقتي أنا
        ~ اخزن فيه عناصر السطر يعني هو بيقسم السطر على حسب ال vLine كده أنا معايا فكتور متخزن فيه اسطر , محتاج اعمل فكتور اسمه
        ~  Matrix اللي هو  vClients ثم يخزن هذه العناصر اللي هي مكونات الاستركت فيتم تخزينها في  delimiter or separatorعشان
        ~   vClients[100][5]يساوي الاكونت نمبر ثم يدخله في المصفوفة اللي اسمها  vLine  ثم يخلي العنصر الاول من  vLine إنه ميعملش اصلا مصفوفة لكن لما يحول البيانات من الملف للفكتور بدل ما يحول السطر لفكتور اسمه

    */
    //!      دي طريقة أبو هدهود
    //! إني بدل ما اخزن السطر اللي في الملف في فكتور ثم ادخل عناصر هذا الفكتور في المصفوفة ثم اكرر هذه العملية بعدد
    //! vClients الاسطر . اقوم ماحول السطر و اخليه استركت ثم اخزن الاستركت في الفكتور اللي اسمه

    vector<CD>vClients = LoadDataFromFileToVector(fileName);


    PrintClientsData(vClients);
}

int main()
{
    Project();
}
//! //////////////////////////////////////////////////////////////////////////////////////////////

void PrintClientsData(vector<CD>vClients)
{
    ShowClientsStatement(vClients.size());
    for(CD cd : vClients)
    {
        PrintOneClientData(cd);
    }
    cout << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}

void PrintOneClientData(CD cd)
{
    cout << "| " << setw(15) << left << cd.accountNumber
         << "| " << setw(10) << left << cd.pinCode
         << "| " << setw(40) << left << cd.name
         << "| " << setw(12) << left << cd.phone
         << "| " << setw(12) << left << cd.balance
         << "|" << endl;
}

void AddClients(string fileName, string delimiter)
{
    char addMore = 'y';
    while (toupper(addMore) == 'Y')
    {
        system("cls");
        cout << "\nAdding New Client:\n\n";
        AddNewClient(fileName);

        system("color 0a");
        cout << "\n\aClient Added Successfuly, Do you want to add more clients? [Y/N] ";
        cin >> addMore;
    }
}

void AddNewClient(string fileName, string delimiter)
{
    AddDataLineToFile(
        fileName, ConvertRecordToLine(
                      delimiter, ReadNewClientData()));
}

void AddDataLineToFile(string fileName, string dataLine)
{
    fstream myFile;
    myFile.open(fileName, ios::app);
    if (myFile.is_open())
    {
        myFile << dataLine << endl;
        myFile.close();
    }
}

CD ReadNewClientData()
{
    CD cd;

    cout << "Enter Account Number: ";
    getline(cin >> ws, cd.accountNumber);

    cout << "Enter Pin Code: ";
    getline(cin, cd.pinCode);

    cout << "Enter Name: ";
    getline(cin, cd.name);

    cout << "Enter Phone: ";
    getline(cin, cd.phone);

    cout << "Enter Account Balance: ";
    cin >> cd.balance;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); //~ Clear buffer
    return cd;
}

string ConvertRecordToLine(string delimiter, CD cd)
{
    return (cd.accountNumber + delimiter + (cd.pinCode) + delimiter + cd.name + delimiter + cd.phone + delimiter + to_string(cd.balance));
}

string Tabs(short numberOfTabs)
{
    string t = "";

    for (short i = 0; i < numberOfTabs; ++i)
    {
        t += t + "\t";
    }

    return t;
}

void ShowClientsStatement(size_t ClientsNumber)
{
    cout << "\n"
         << Tabs(2) << "Client List [" << ClientsNumber << "] Client(s)\n"
         << "-------------------------------------------------"
         << "--------------------------------------------------" << endl
         << "| " << setw(15) << left << "Account Number"
         << "| " << setw(10) << left << "Pin Code "
         << "| " << setw(40) << left << "Client Name"
         << "| " << setw(12) << left << "Phone "
         << "| " << setw(12) << left << "Balance"
         << "|"  << endl
         << "-------------------------------------------------"
         << "--------------------------------------------------" << endl;
}

vector<string> SplitString(string str, string delimeter)
{
    vector<string> vLineOfData;
    string word;
    short position = 0;

    while ((position = str.find(delimeter)) != str.npos)
    {
        word = str.substr(0, position);

        if (word != "")
        {
            vLineOfData.push_back(word);
        }

        str.erase(0, position + delimeter.length());
    }

    if (str != "")
    {
        vLineOfData.push_back(str);
    }

    return vLineOfData;
}

vector<CD> LoadDataFromFileToVector(string fileName)
{
    vector<CD> vClients;
    CD cd;

    fstream myFile;
    myFile.open(fileName, ios::in);
    if (myFile.is_open())
    {
        string line;

        while (getline(myFile, line))
        {
            cd = ConvertLineToRecord(line);
            vClients.push_back(cd);
        }
        myFile.close();
    }

    return vClients;
}

CD ConvertLineToRecord(string line)
{
    vector<string> vClient;
    CD cd;
    vClient = SplitString(line);
    cd.accountNumber = vClient[0];
    cd.pinCode = vClient[1];
    cd.name = vClient[2];
    cd.phone = vClient[3];
    cd.balance = stod(vClient[4]);

    return cd;
}