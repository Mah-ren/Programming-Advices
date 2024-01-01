#pragma once
#include <iostream>
#include <string>
using namespace std;

class TextProcessor
{
private:
    string _text;
public:
    TextProcessor(string text)
    {
        _text = text;
    }

    static short CountWords(string text)
    {
        short position = 0 , count = 0 ; 
        string delimeter = " " , word;
        
        while((position = text.find(delimeter)) != text.npos)
        {
            word = text.substr(0 , position);

            if(word != "")
                ++count ;

            text.erase(0 , position + delimeter.length());
        }

        if(text != "")
            ++count ; 

        return count ;
    }
    short CountWords()
    {
        return CountWords(_text);
    }
    static short CountLetter(char c , string str)
    {
        short count = 0 ; 
        
        for(int i = 0 ; i < str.length() ; ++i)
        {
            if(str.at(i) == c)
                count++ ;
        }

        return count ;
    }
    short CountLetter(char c)
    {
        return CountLetter(c, _text);
    }







};