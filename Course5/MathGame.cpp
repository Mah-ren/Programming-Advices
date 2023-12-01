#include <iostream>
#include <ctime>
#include <limits>
#include <cstdlib>
using namespace std;

enum enOperationType
{
    addition = 1,
    subtraction = 2,
    multiply = 3,
    division = 4,
//    mix = 5
};

enum enQuestionLevel
{
    easy = 1,
    medium = 2,
    hard = 3,
  //  mix = 4
};

enum enGameResult
{
    pass = 1,
    fail = 2
};

enum enAnswer
{
    right = 1,
    wrong = 2
};

struct stRoundInfo
{
    short roundNumber = 0 ; 
    enQuestionLevel questionLevel;
    enOperationType opType;
    short number1 = 0 ; 
    short number2 = 0 ; 
    short userAnswer = 0 ; 
    enAnswer answerAccurancy ; 
};

struct stQuizes
{
    short numberOfQuestions = 0;
    short numberOfRightAnswers = 0;
    short numberOfWrongAnswers = 0;
    stRoundInfo roundInfo ;
};

int GenerateRandomIntegerInRange(int min, int max)
{
    return rand() % (max - min + 1) + min;
}

string PrintOperationType(enOperationType opType)
{
    string array[4] {"+" , "-" , "*" , "/"};
    return array[opType - 1] ;
}

string QuestionLevelToString(enQuestionLevel questionLevel)
{
    string array[3] {"Easy" , "Meduim" , "Hard"} ;
    return array[questionLevel - 1] ;
}

short GetValidPositiveIntegerInRange(string prompt, short min, short max)
{
    short number = 1;

    do
    {
        cout << prompt;
        cin >> number;

        if (cin.fail()) // Check if extraction failed (non-integer input)
        {
            cin.clear();                                         // Clear the error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore invalid input
            cout << "\nInvalid input. Please enter a positive integer." << endl;
            continue; // Prompt user again
        }

    } while (number < min || number > max);

    return number;
}
//! بياخد من المستخدم مستوى اللعبة و العلامة ثم يظهر للمستخدم
short GeneratRandomNumbersDependingOnQustionLevel(stRoundInfo &roundInfo)
{
    enQuestionLevel questionLevel = roundInfo.questionLevel ;

    switch (questionLevel)
    {
    case enQuestionLevel::easy:
        return GenerateRandomIntegerInRange(1, 10);
        break;
    case enQuestionLevel::medium:
        return GenerateRandomIntegerInRange(10, 20);
        break;

    case enQuestionLevel::hard:
        return GenerateRandomIntegerInRange(20, 50);
        break;

    /*case enQuestionLevel::mix:
        return GenerateRandomIntegerInRange(1, 50);
        break; */
    }
}

short ResultOfQuestion(stRoundInfo &roundInfo)
{
    
    switch(roundInfo.opType)
    {
    case enOperationType::addition:
        return roundInfo.number1 + roundInfo.number2 ;
    
    case enOperationType::subtraction:
        return roundInfo.number1 - roundInfo.number2 ;
    
    case enOperationType::multiply:
        return roundInfo.number1 * roundInfo.number2 ;
     
    case enOperationType::division:
        return roundInfo.number1 / roundInfo.number2 ;
    }

 //  GenerateRandomIntegerInRange(1,4);    
}

void PrintTheQuestionFormula(stRoundInfo &roundInfo)
{
    
    cout << roundInfo.number1 << "\n";
    cout << roundInfo.number2 << " " << PrintOperationType(roundInfo.opType) << "\n";
    cout << "---------\n";
}

void AskUserForAnsweringQuestion(stRoundInfo &roundInfo)
{
    cin >> roundInfo.userAnswer ;
}

void SetWinnerScreenColor(enAnswer answer)
{
    if(answer == enAnswer::right) //* green 
        system("color a0");            
    else if(answer == enAnswer::wrong) //! red 
    {
        system("color c0");
        cout << "\a";
    }
    else    
        system("color d0");  //~ purple
}

void ShowReactionOfUserAnswer(enAnswer answer , stRoundInfo &roundInfo)
{
    
    if(answer == enAnswer::right)
    {
        SetWinnerScreenColor(enAnswer::right) ;
        cout << "\nRight Answer :-) \n";
    }
    else if(answer == enAnswer::wrong)
    {
        SetWinnerScreenColor(enAnswer::wrong);
        cout << "\nWrong Answer :-( ";
        cout << "\nRight Answer: " << ResultOfQuestion(roundInfo);
    }
}

void CheckAnswerAccurancy(stRoundInfo &roundInfo)
{
    if(roundInfo.userAnswer == ResultOfQuestion(roundInfo))
        ShowReactionOfUserAnswer(enAnswer::right , roundInfo);
    
    else if(roundInfo.userAnswer != ResultOfQuestion(roundInfo))
        ShowReactionOfUserAnswer(enAnswer::wrong , roundInfo);

    else 
        cout << "\nsorry there is an error with else CheckAnswerAccurancy function";
}

void ResetScreen()
{
    system("cls");
    system("color 0f");
}

bool CheckPassOrNot(stQuizes &Quizes)
{
    return Quizes.numberOfRightAnswers >= Quizes.numberOfWrongAnswers ; 
}

void PrintFinalResultAndPassOrFail(stQuizes &Quizes)
{
    cout << "\n_____________________________________\n";
    cout << "Final Result is " ;

    if(CheckPassOrNot(Quizes)== true)    
        cout << "PASS :-) \n";
    else    
        cout << "FAIL :-( \n";
    cout << "_____________________________________\n";
}

stQuizes FillstQuizzes(stRoundInfo &roundInfo , short &numberOfRightAnswers , short &numberOfWrongAnswers)
{
    stQuizes quizze ;  
    quizze.numberOfQuestions    = roundInfo.roundNumber ;
    quizze.numberOfRightAnswers = numberOfRightAnswers  ;
    quizze.numberOfWrongAnswers = numberOfWrongAnswers  ;
    return quizze ;
}

stQuizes PlayGame(short howManyRounds)
{
    stRoundInfo roundInfo;
    stQuizes quizze ; 
    
    short numberOfRightAnswers = 0 , numberOfWrongAnswers = 0 ;
    quizze.roundInfo.questionLevel = (enQuestionLevel)GetValidPositiveIntegerInRange("\nEnter Questions Level [1]: Easy , [2]: Medium , [3]: Hard , [4]: Mix ? ", 1, 3);
    quizze.roundInfo.opType        = (enOperationType)GetValidPositiveIntegerInRange("\nEnter Operation Type [1]: Add , [2]: Sub , [3]: Mul , [4]: Div , [5]: Mix ? ", 1, 4);
       
    for (short gameRound = 1 ; gameRound <= howManyRounds ; ++gameRound)
    {
        cout << "\n\nQuestion [" << gameRound << "/" << howManyRounds << "] \n\n";
        roundInfo.roundNumber    = gameRound;
        roundInfo.number1 = GeneratRandomNumbersDependingOnQustionLevel(roundInfo);
        roundInfo.number2 = GeneratRandomNumbersDependingOnQustionLevel(roundInfo);
        PrintTheQuestionFormula(roundInfo);
        AskUserForAnsweringQuestion(roundInfo);
        CheckAnswerAccurancy(roundInfo);
        if(roundInfo.userAnswer == ResultOfQuestion(roundInfo))
            numberOfRightAnswers++ ;
        else if(roundInfo.userAnswer != ResultOfQuestion(roundInfo))
            numberOfWrongAnswers++ ;
    }

    return FillstQuizzes(roundInfo , numberOfRightAnswers , numberOfWrongAnswers);
}

void ShowFinalResult(stQuizes &Quizes)
{
    cout << "\nNumber of Questions: " << Quizes.numberOfQuestions ;
    cout << "\nNumber of Right Answers: " << Quizes.numberOfRightAnswers ;
    cout << "\nNumber of Wrong Answers: " << Quizes.numberOfWrongAnswers ;
    cout << "\nQuestions Level    : " << QuestionLevelToString(Quizes.roundInfo.questionLevel) ;
    cout << "\nOpType             : " << PrintOperationType(Quizes.roundInfo.opType) ;
}

void MathGameProject()
{
    char playAgain = 'c';

    do
    {
        ResetScreen();
        stQuizes Quizes = PlayGame(GetValidPositiveIntegerInRange("How many Questions do you want to answer ? ", 1, 10));
        PrintFinalResultAndPassOrFail(Quizes);
        ShowFinalResult(Quizes);
        cout << "\nDo you wanna play again? [Y/N]: " ;
        cin >> playAgain ;
    } while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    MathGameProject();
}//~  What is the problem with ShowFinalResult() cause it doesn't print anything after the number of questions and don't ask me if i want to play again or not