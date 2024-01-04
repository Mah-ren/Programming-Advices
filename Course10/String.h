#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

class String
{
private:
    string _text;

protected:
    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }

        return S1;
    }

    static vector<string> replaceTwoWords(vector<string> vString, string StringToReplace, string sReplaceTo, bool caseSensitive)
    {
        string temp;
        if (!caseSensitive)
        {
            for (string &element : vString)
            {
                if (element == StringToReplace)
                    element = sReplaceTo;
            }
        }
        else
        {
            for (string &element : vString)
            {
                temp = ConvertingStringToUpper(element);
                StringToReplace = ConvertingStringToUpper(StringToReplace);
                if (temp == StringToReplace)
                    element = sReplaceTo;
            }
        }

        return vString;
    }


public:
    String(string text)
    {
        _text = text;
    }
    static vector<string> SplitString(string text, string delimiter)
    {
        vector<string> vLineOfData;
        string word;
        short position = 0;

        while ((position = text.find(delimiter)) != text.npos)
        {
            word = text.substr(0, position);

            if (word != "")
                vLineOfData.push_back(word);

            text.erase(0, position + delimiter.length());
        }

        if (text != "")
            vLineOfData.push_back(text);

        return vLineOfData;
    }
    vector<string> SplitString(string delimiter)
    {
        return SplitString(_text, delimiter);
    }
    static string Append(string str, string stringToAdd)
    {
        vector<string> vString;
        vString = SplitString(str, " ");
        vString.push_back(stringToAdd);
        return JoinString(vString);
    }
    string Append(string stringToAdd)
    {
        vector<string> vString;
        vString = SplitString(_text);
        vString.push_back(stringToAdd);
        return JoinString(vString);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string ConvertingStringToUpper(string text)
    {
        for (char &ch : text)
            ch = toupper(ch);

        return text;
    }
    string ConvertingStringToUpper()
    {
        return ConvertingStringToUpper(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    // static short CountLettersRepeated(string text, bool matchCase)
    // {
    //     short counter = 0;

    //     for (short i = 0; i < text.length(); i++)
    //     {
    //         for (short j = i + 1; j < text.length(); j++)
    //         {
    //             if (!isPunctuation(text[i]))
    //             {
    //                 if (matchCase)
    //                 {
    //                     if (text[i] == text[j])
    //                         counter++;
    //                     for (char &c : text)
    //                     {
    //                         if (text[i] == c)
    //                             c = ' ';
    //                     }
    //                 }
    //                 else
    //                 {
    //                     if (toupper(text[i]) == toupper(text[i]))
    //                     {
    //                         counter++;
    //                         for (char &c : text)
    //                         {
    //                             if (toupper(text[i]) == toupper(c))
    //                                 c = ' ';
    //                         }
    //                     }
    //                 }
    //             }
    //             else
    //                 continue;
    //         }
    //     }
    //     return counter;
    // }

    // short CountLettersRepeated(bool matchCase)
    // {
    //     return CountLettersRepeated(_text, matchCase);
    // }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static short CountingLowerLetters(string str)
    {
        short lowerLetters = 0;

        for (int i = 0; i < str.length(); ++i)
        {
            if (islower(str.at(i)))
                lowerLetters++;
        }

        return lowerLetters;
    }
    short CountingLowerLetters()
    {
        return CountingLowerLetters(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static short CountingUpperLetters(string str)
    {
        short upperLetters = 0;

        for (char &ch : str)
        {
            if (isupper(ch))
                upperLetters++;
        }

        return upperLetters;
    }
    short CountingUpperLetters()
    {
        return CountingUpperLetters(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static short CountSpecificLetter(char c, string text)
    {
        short count = 0;

        for (char &ch : text)
        {
            if (ch == c)
                ++count;
        }

        return count;
    }
    short CountSpecificLetter(char c)
    {
        return CountSpecificLetter(c, _text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static short CountVowels(string text)
    {
        short count = 0;

        for (char &ch : text)
        {
            if (isVowl(ch))
                count++;
        }

        return count;
    }
    short CountVowels()
    {
        return CountVowels(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static short CountWords(string text)
    {
        short position = 0, count = 0;
        string delimiter = " ", word;

        while ((position = text.find(delimiter)) != text.npos)
        {
            word = text.substr(0, position);

            if (word != "")
                ++count;

            text.erase(0, position + delimiter.length());
        }

        if (text != "")
            ++count;

        return count;
    }
    short CountWords()
    {
        return CountWords(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string LowerFirstLetterOfEachWord(string text)
    {
        bool isFirstLetter = true;

        for (char &ch : text)
        {
            if (ch != ' ' && isFirstLetter)
                ch = tolower(ch);

            isFirstLetter = (ch == ' ' ? true : false);
        }
    
        return text;
    }
    string LowerFirstLetterOfEachWord()
    {
        return LowerFirstLetterOfEachWord(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string UpperFirstLetterOfEachWord(string text)
    {
        bool isFirstLetter = true;

        for (char &ch : text)
        {
            if (ch != ' ' && isFirstLetter)
                ch = toupper(ch);

            isFirstLetter = (ch == ' ' ? true : false);
        }

        return text;
    }
    
    string UpperFirstLetterOfEachWord()
    {
        return UpperFirstLetterOfEachWord(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string InvertAllLettersCase(string text)
    {
        for (char &ch : text)
            ch = InvertLetterCase(ch);

        return text;
    }
    string InvertAllLettersCase()
    {
        return InvertAllLettersCase(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string RemovePunctuations(string text)
    {
        string s = "";
        for (short i = 0; i < text.length(); ++i)
        {
            if (!isPunctuation(text[i]))
                s += text[i];
        }

        return s;
    }
    string RemovePunctuations()
    {
        return RemovePunctuations(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string ReplaceTwoWordsInStringWithSplit(string str, string stringToReplace, string sReplaceTo, bool matchCase)
    {
        vector<string> vString;
        vString = SplitString(str, " ");
        for (string &s : vString)
        {
            if (matchCase)
                if (s == stringToReplace)
                    s = sReplaceTo;
                else if (LowerAllString(s) == LowerAllString(stringToReplace))
                    s = sReplaceTo;
        }

        return JoinString(vString, " ");
    }
    string ReplaceTwoWordsInStringWithSplit(string stringToReplace, string sReplaceTo, bool matchCase)
    {
        return ReplaceTwoWordsInStringWithSplit(_text, stringToReplace, sReplaceTo, matchCase);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string TrimLeft(string str)
    {    
        for(int i = 0 ; i < str.length() ; i++)
        {
            if(str.at(i) != ' ') 
                return str.substr(i, str.length() - i) ;
        }
        
        return "" ;
    }
    string TrimLeft()
    {
        return TrimLeft(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string TrimRight(string str , string delimiter=" ")
    {    
        for(int i = str.length()-1 ; i >= 0 ; --i)
        {
        if(str.at(i) != ' ')
        return str.substr(0 , i+1) ;
        }

        return "" ;
    }
    string TrimRight()
    {
        return TrimRight(_text);
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string Trim(string str)
    {
        return TrimLeft(TrimRight(str));
    }
    string Trim()
    {
        return TrimLeft(TrimRight(_text));
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static string JoinString(vector<string> vNames, string delimiter)
    {
        string str;

        for (const string &element : vNames)
        {
            str += element + delimiter;
        }
        return str.substr(0, str.length() - delimiter.length());
    }
    static string JoinString(vector<string> vNames)
    {
        return JoinString(vNames, " ");
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static bool isVowl(char c)
    {
        c = tolower(c);
        return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static bool isPunctuation(char c)
    {
        return (c == '!' || c == '"' || c == '#' || c == '$' || c == '%' || c == '&' || c == '\'' || c == '(' || c == ')' || c == '*' || c == '+' || c == ',' || c == '-' || c == '.' || c == '/' || c == ':' || c == ';' || c == '<' || c == '=' || c == '>' || c == '?' || c == '@' || c == '[' || c == '\\' || c == ']' || c == '^' || c == '_' || c == '`' || c == '{' || c == '|' || c == '}' || c == '~');
    }
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    static bool isWordFoundInVector(vector<string> vString, string word, bool caseSensitive = false)
    {
        if (!caseSensitive)
        {
            for (string &element : vString)
            {
                if (element == word)
                    return true;
            }
        }
        else
        {
            for (string element : vString)
            {
                element = ConvertingStringToUpper(element);
                word = ConvertingStringToUpper(word);
                if (element == word)
                    return true;
            }
        }
    }

    static bool isUpperLetter(char c)
    {
        return (static_cast<int>(c) >= 65 && static_cast<int>(c) <= 90);
    }

    static char InvertLetterCase(char c)
    {
        return isUpperLetter(c) ? tolower(c) : toupper(c);
    }

    static short Length(string text)
    {
        return text.length();
    }
    short Length()
    {
        return Length(_text);
    }
    static string ReverseWords(string str , string delimiter = " ")
    {
        vector<string> vString ; 
        string newString ;
        
        vString = SplitString(str , delimiter);

        vector<string>::iterator iter = vString.end();
        while(iter != vString.begin())
        {
            --iter ;
            newString += *iter + delimiter ;
        }

        return newString.substr(0 , newString.length()-delimiter.length()) ;
    }
    string ReverseWords(string delimiter = " ")
    {
        return ReverseWords(_text, delimiter);
    }


};