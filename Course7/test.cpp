 #include <iostream>
 using namespace std;

string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}



string GetFirstLetter(const string& str)
{
    if (!str.empty()) {
        return str.substr(0, 1);
    }
    return "";  // Return an empty string if the input is empty.
}

int main()
{
    string input = ReadString("\nEnter String: \n");
    string c = GetFirstLetter(input);
    cout << "\nThe First Letter: " << c ; 
}