#include <iostream>
#include "String.h"
using namespace std;



int main()
{
    String text("Mahmoud Ahmed Abdel aal Ahmed");

    //! Converting String To Upper
    cout << "\nConvertirng object to uper: " << text.ConvertingStringToUpper();
    cout << "\nConvertirng  \"ali mohamed\" to upper is: " << String::ConvertingStringToUpper("ali mohamed");


    cout << "\n";


    //! CountingLowerLetters
    cout << "\nCounting Lower Letters In Object is: " << text.CountingLowerLetters();
    cout << "\nCounting Lower Letters In \"ali mohamed \"is: " << String::CountingLowerLetters("ali mohamed");


    cout << "\n";


    //! CountingUpperLetters
    cout << "\nCounting Upper Letters In Object is: " << text.CountingUpperLetters();
    cout << "\nCounting Upper Letters In\"ali mohamed\"is: " << String::CountingUpperLetters("ali mohamed");

    cout << "\n";

    // //! CountLettersRepeated
    // cout << "\nThe Letters repeated in object are: " << text.CountLettersRepeated(true);
    // cout << "\nThe Letters repeated in \"ali mohamed\" are: " << String::CountLettersRepeated("ali mohamed", true);

    // cout << "\n";


    //! CountSpecificLetter
    cout << "\nthe number of letter d is in object: " << text.CountSpecificLetter('d');
    cout << "\nthe number of letter d in \"ali mohamed\" is : " << String::CountSpecificLetter('d', "ali mohamed");


    cout << "\n";


    //! CountVowelsInString
    cout << "\nThe vowels in object is: " << text.CountVowels();
    cout << "\nThe vowels in \"ali mohaemd\" is: " << String::CountVowels("ali mohaemd");

    cout << "\n";

    //! CountWords
    cout << "\nThe number of words in object: " << text.CountWords() << endl;
    cout << "\nThe number of words \"ali mohamed\" is: " << String::CountWords("ali mohamed");


    cout << "\n";

    //! InvertAllLettersCase
    cout << "\nInverting all letters in object is: " << text.InvertAllLettersCase();
    cout << "\nInverting all letters in \"ali mohamed\" is: " << String::InvertAllLettersCase("ali mohamed");

    cout << "\n";

    //! RemovePunctuations
    cout << "\nThe object after rmoving the punctuation is: " << text.RemovePunctuations();
    cout << "\nThe \"ali, && mohamed\" after rmoving the punctuation is: " << String::RemovePunctuations("ali, && mohamed");
    
    cout << "\n";
    
    //! ReplaceTwoWordsInStringWithSplit
    cout << "\nthe object after replacing the word Mahmoud with Mostafa is: " << text.ReplaceTwoWordsInStringWithSplit("Mahmoud", "Mostafa", true);
    cout << "\nthe string == object after replacing the word Mahmoud with Mostafa is: " << String::ReplaceTwoWordsInStringWithSplit("Mahmoud Ahmed Abdel aal Ahmed", "Mahmoud", "Mostafa", true);
    
    cout << "\n";

    //! UpperFirstLetterOfEachWord
    cout << "\nThe object after upper first letter of each word: " << text.UpperFirstLetterOfEachWord();
    cout << "\nThe ali mohamed after upper first letter of each word: " << String::UpperFirstLetterOfEachWord("ali mohamed");
        
    cout << "\n";

    //! Trim
    cout << "\nTrim this text \"     Mahmoud Ahmed Abdel aal Ahmed       \": " << String::Trim("     Mahmoud Ahmed Abdel aal Ahmed       ");
    
    cout << "\n";

    //! Trim
    cout << "\nTrim this text \"     Mahmoud Ahmed Abdel aal Ahmed       \": " << String::Trim("     Mahmoud Ahmed Abdel aal Ahmed       ");
 
    cout << "\n";
 
    //! TrimRight
    cout << "\nTrim this text \"Mahmoud Ahmed Abdel aal Ahmed       \": " << String::TrimRight("Mahmoud Ahmed Abdel aal Ahmed       ");
 
    cout << "\n";
    //! join String
    vector<string> vNames;
    vNames = {"Mahmoud", "Ahmed", "Abdel", " aal", "Ahmed"};
    cout << "\nJoin String: " << String::JoinString(vNames, " ");
    cout << "\nJoin String without the delimiter: " << String::JoinString(vNames);
    
    cout << "\n";
    
    //!append
    cout << "\nthe object after adding ali mohamed: " << text.Append("ali mohamed");
    cout << "\nthe object after adding ali mohamed: " << String::Append("Mahmoud Ahemd Abdel aal Ahmed", "ali mohamed");
    cout << "\n";
    
    cout << "\n";
    cout << "\nthe length is: " << text.Length();
    cout << "\nthe length of ali mohamed is: " << String::Length("ali mohamed");

    cout << "\n";


    cout << "\nReverse the object: " << text.ReverseWords("mahmoud ahmed abdel aal ahmed", " ");
}
