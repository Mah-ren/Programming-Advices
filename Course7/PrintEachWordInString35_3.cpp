//!by me
#include <iostream>
#include <string>
using namespace std; 
 
string ReadString(string prompt)
{
    string str;
    
    cout << prompt ;
    getline(cin , str);

    return str ;
}

void PrintStringWords(string str)
{
    cout << "\nYour String Words are: \n";
    bool isFirstLetter = false ; 
                                                        //! |0|1|2|3|4|5|6|7|8|9|10|11|12|13|14|15|16|17|18|19|20|21|22
    for(short i = 0 ; i < str.length() ; ++i)           //* |M|a|h|m|o|u|d| |A|h|m |e |d |A |b |d |e |l |  |a |a |l | 
    {                                                   //! i = 0 ; if(str[0] != ' ' true and true ) "M" ifnot isFirst =true mahmoud                      
        if(str.at(i) != ' ' && !isFirstLetter)          //! i = 6 ; if(str[7] != ' ' false so this false ifyes so \n         and isFirst true                                   
        {                                               //! i = 8 ; if(str[8] != ' ' true but false so false won't )                                          
            cout << str[i] ;
            isFirstLetter = (str[i] == ' ' ? true : false);                                                                                                  
        }                                                                           
    
        if(str.at(i) == ' ')                                                                
        {                                                                   
            cout << "\n" ;                                                                                          
        }
    }
}

void Project()
{
    PrintStringWords(ReadString("\nPlease Enter string: \n"));
}

int main()
{
    Project();
}
