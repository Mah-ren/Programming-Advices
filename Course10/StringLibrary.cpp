#include <iostream>
#include "TextProcessor.h"
using namespace std;



int main()
{
    TextProcessor text("Mahmou Ahmed Abdel aal Ahmed");
    cout << text.CountWords() << endl;
    cout << TextProcessor::CountWords("ali mohamed");

    cout << text.CountLetter() << endl;





}
