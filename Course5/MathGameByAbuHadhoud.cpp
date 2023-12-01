#include <iostream>
#include <ctime>
#include <limits>
#include <cstdlib>
using namespace std;

enum enOperationType{addition = 1 , subtraction = 2 , multiply = 3 , division = 4 , mixOpType = 5};

enum enQuestionLevel{easy = 1 , medium = 2 , hard = 3 , mix = 4} ;

struct stQuestion
{
    short number1 = 0 ; 
    short number2 = 0 ; 
    enOperationType operationType ;
    enQuestionLevel questionLevel ; 
    short correctAnswer = 0 ; 
    short playerAnswer = 0 ; 
    bool answerResult = false ; 
};

struct stQuizz
{  //! اعمل اريه عشان تضع فيه معلومات كل سؤال 
    stQuestion QuestionList[100] ;
    short NumberOfQuestions = 0 ; 
    enQuestionLevel questionsLevel ; 
    enOperationType opType ;
    short numberOfRightAnswers = 0 ; 
    short numberOfWrongAnswers = 0 ; 
    bool isPass = false ;
};

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

short GenerateRandomIntegerInRange(short min, short max)
{
    return rand() % (max - min + 1) + min;
}

short SimpleCalculator(short number1 , short number2 , enOperationType opType)
{
    switch(opType)
    {
    case enOperationType::addition :
        return number1 + number2 ; 
    case enOperationType::subtraction : 
        return number1 - number2 ; 
    case enOperationType::multiply : 
        return number1 * number2 ; 
    case enOperationType::division : 
        return number1 / number2 ; 
    default :
        return number1 + number2 ;
    }
}

stQuestion GenerateQuestion(enQuestionLevel questionLevel , enOperationType opType)
{
    stQuestion question ;

    if(questionLevel == enQuestionLevel::mix)
        questionLevel = (enQuestionLevel)GenerateRandomIntegerInRange(1 , 4);
    if(opType == enOperationType::mixOpType)
        opType = (enOperationType)GenerateRandomIntegerInRange(1 , 5);
    switch(questionLevel)
    {
    case enQuestionLevel::easy:
        question.number1 = GenerateRandomIntegerInRange(1 , 10);
        question.number2 = GenerateRandomIntegerInRange(1 , 10);

        question.correctAnswer = SimpleCalculator(question.number1 , question.number2 , opType);
        question.questionLevel = questionLevel ;
        return question ; 
    case enQuestionLevel::medium:
        question.number1 = GenerateRandomIntegerInRange(10 , 20);
        question.number2 = GenerateRandomIntegerInRange(10 , 20);

        question.correctAnswer = SimpleCalculator(question.number1 , question.number2 , opType);
        question.questionLevel = questionLevel ;
        return question ; 
    case enQuestionLevel::hard: 
        question.number1 = GenerateRandomIntegerInRange(20 , 30);
        question.number2 = GenerateRandomIntegerInRange(20 , 30);

        question.correctAnswer = SimpleCalculator(question.number1 , question.number2 , opType);
        question.questionLevel = questionLevel ;
        return question ; 
    }
    return question ; 
}

string GetOpTypeSymbol(enOperationType opType)
{
    switch(opType)
    {
    case enOperationType::addition : 
        return "+"; 
    case enOperationType::subtraction :
        return "-";
    case enOperationType::multiply :
        return "*";
    case enOperationType::division :
        return "/";
    }
}

void PrintTheQuestion(stQuizz &quizz , short questionNumber)
{
    cout << "\nQuestion [" << questionNumber + 1 << "/" << quizz.NumberOfQuestions << "]\n\n";
    cout << quizz.QuestionList[questionNumber].number1 << endl ;
    cout << quizz.QuestionList[questionNumber].number2 << " " << GetOpTypeSymbol(quizz.QuestionList[questionNumber].operationType) ;
    cout << "\n___________\n" ;
}

short ReadQuestionAnswer()
{
    short answer = 0 ; 
    cin >> answer ;
    return answer ;
}

void SetScreenColor(bool right)
{
    if(right)
        system("color 2f");
    else 
    {
        system("color 4f");
        cout << "\a";
    }
}

void CorrectTheQuestionAnswer(stQuizz &quizz , short questionNumber)
{
    if(quizz.QuestionList[questionNumber].playerAnswer != quizz.QuestionList[questionNumber].correctAnswer)
    {
        quizz.QuestionList[questionNumber].answerResult = false ; 
        quizz.numberOfWrongAnswers++ ;
        
        cout << "Wrong Answer :-( \n" ;
        cout << "The Right answer is: " << quizz.QuestionList[questionNumber].correctAnswer << "\n"; 
    }
    else 
    {
        quizz.QuestionList[questionNumber].answerResult = true ;
        quizz.numberOfRightAnswers++ ;
        cout << "Right Answer :-)\n";
    }
    cout << endl ;
    SetScreenColor(quizz.QuestionList[questionNumber].answerResult);
}

void AskAndCorrectQuestionListAnswers(stQuizz &quizz)
{
    for(short questionNumber = 0 ; questionNumber < quizz.NumberOfQuestions ; ++questionNumber)
    {
        PrintTheQuestion(quizz , questionNumber);
        quizz.QuestionList[questionNumber].playerAnswer = ReadQuestionAnswer();
        CorrectTheQuestionAnswer(quizz , questionNumber);
    }

    quizz.isPass = (quizz.numberOfRightAnswers >= quizz.numberOfWrongAnswers) ;
}

stQuizz GenerateQuizzQuestions(stQuizz &quizz)
{
    for(short question = 0 ; question < quizz.NumberOfQuestions ; ++question)
    {
        quizz.QuestionList[question] = GenerateQuestion(quizz.questionsLevel , quizz.opType);
    }
}

void ResetScreen()
{
    system("cls");
    system("color 0f");
}

string GetFinalResultsText(bool pass)
{
    if(pass)
        return "PASS :-)";
    else    
        return "FAIL :-(";
}

string Tabs(short numberOfTabs)
{
    string t = "";
    for(short i = 0 ; i < numberOfTabs ; ++i)
    {
        t += t + "\t";
    }
    return t ;
}

void PrintQuizzResult(stQuizz &quizz)
{
    cout << "\n" ;
    cout << Tabs(3) << "______________________________________________\n\n";
    cout << Tabs(3) << "Final Result is    : " << GetFinalResultsText << "\n" ;
    cout << Tabs(3) <<  "______________________________________________\n\n";
    cout << Tabs(3) << "Number of Questions: " << quizz.NumberOfQuestions << "\n" ;
    cout << Tabs(3) << "Question Level     : " << quizz.questionsLevel    << "\n" ;
    cout << Tabs(3) << "Operation Type      : " << quizz.opType           << "\n" ;
    cout << Tabs(3) << "Number of Right Answers : " << quizz.numberOfRightAnswers << "\n" ;
    cout << Tabs(3) << "Number of Wrong Answers : " << quizz.numberOfWrongAnswers << "\n" ;
    cout << Tabs(3) <<  "______________________________________________\n\n";

}

void PlayMathGame()
{
    stQuizz quizz ; 

    quizz.NumberOfQuestions = GetValidPositiveIntegerInRange("\nPlease Enter how many Questions do you wanna take? " , 1 , 10) ;
    quizz.questionsLevel    = (enQuestionLevel) GetValidPositiveIntegerInRange("\nEnter Questions Level [1]: Easy , [2]: Medium , [3]: Hard , [4]: Mix ? ", 1, 3);
    quizz.opType            = (enOperationType) GetValidPositiveIntegerInRange("\nEnter Operation Type [1]: Add , [2]: Sub , [3]: Mul , [4]: Div , [5]: Mix ? ", 1, 4);

    GenerateQuizzQuestions(quizz); 
    AskAndCorrectQuestionListAnswers(quizz);
    PrintQuizzResult(quizz);
}


void StartGame()
{
    char playAgain = 'y' ;

    do
    {
        ResetScreen();
        PlayMathGame();

        cout << "\nDo you wanna play again? ";
        cin >> playAgain ;
    } while (playAgain == 'Y' || playAgain == 'y');
    
}

int main()
{
    srand(static_cast<unsigned>(time(NULL)));
    StartGame();
}