#include <iostream>
#include <ctime>
#include <cstdlib>
#include <limits>
using namespace std;

enum enGameChoice
{
    stone = 1,
    paper = 2,
    scissor = 3
};
enum enWinner
{
    player = 1,
    computer = 2,
    drawTime = 3
};

struct stRoundInfo
{
    short roundNumber = 0;
    enGameChoice playerChoice;
    enGameChoice ComputerChoice;
    enWinner winner;
    string winnerName;
};
struct stGameResult
{
    short gameRounds = 0 ;
    short playerWinTimes = 0 ;
    short computerWinTimes = 0 ;
    short drawTimes = 0 ;
    enWinner finalWinner ;
    string winnerName = "" ;
};


int GenerateRandomIntegerInRange(int min, int max)
{
    return rand() % (max - min + 1) + min ;
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

char GetCharByUser(string prompt)
{
    char playAgain = 'c';

    cout << prompt;
    cin >> playAgain;

    return playAgain;
}

void ResetScreen()
{
    system("cls");
    system("color 0f");
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

enWinner WhoWonTheRound(stRoundInfo roundInfo)
{
    if(roundInfo.playerChoice == roundInfo.ComputerChoice)
        return enWinner::drawTime ;

    switch (roundInfo.playerChoice)
    {
    case enGameChoice::stone:
        if(roundInfo.ComputerChoice == enGameChoice::scissor)
            return enWinner::player ;
            break ;
    case enGameChoice::paper:
        if(roundInfo.ComputerChoice == enGameChoice::stone)
            return enWinner::player ;
            break ;
    case enGameChoice::scissor:
        if(roundInfo.ComputerChoice == enGameChoice::paper)
            return enWinner::player ;
            break ; 
    }

    return enWinner::computer ;
}

string ChoiceName(enGameChoice choice)
{
    string array[3] = {"Stone" , "Paper" , "Scissor"} ;
    return array[choice - 1] ;
}

string WinnerName(enWinner winner)
{
    string array[3] = {"Player" , "Computer" , "No Winner"} ;
    return array[winner - 1] ;
}

void SetWinnerScreenColor(enWinner winner)
{
    if(winner == enWinner::player)
        system("color a0");
    else if(winner == enWinner::computer)
    {
        system("color c0");
        cout << "\a";
    }
    else 
        system("color d0");
}

void PrintRoundResults(stRoundInfo roundInfo)
{
    cout << "\n______________Round[" << roundInfo.roundNumber << "]______________\n";
    cout << "Player Choice   :" << ChoiceName(roundInfo.playerChoice) << endl ;
    cout << "Computer Choice :" << ChoiceName(roundInfo.ComputerChoice) << endl ;
    cout << "Round Winner    :[" << roundInfo.winnerName << "]" ;
    cout << "\n____________________________________\n";

    SetWinnerScreenColor(roundInfo.winner);
}

enWinner WhoWonTheGame(stGameResult gameResult)
{
    if(gameResult.playerWinTimes > gameResult.computerWinTimes)
        return enWinner::player ; 
    else if(gameResult.computerWinTimes > gameResult.playerWinTimes)
        return enWinner::computer ;
    else 
        return enWinner::drawTime ;
} 

stGameResult FillStGameResult(stRoundInfo roundInfo , short playerWinTimes , short computerWinTimes , short drawTimes)
{
    
    stGameResult gameResult ;
    gameResult.gameRounds       = roundInfo.roundNumber ;
    gameResult.playerWinTimes   = playerWinTimes ; 
    gameResult.computerWinTimes = computerWinTimes ; 
    gameResult.drawTimes        = drawTimes ;
    gameResult.finalWinner      = WhoWonTheGame(gameResult);
    gameResult.winnerName       = WinnerName(gameResult.finalWinner);
}

void ShowGameOverScreen()
{
    cout << Tabs(2) << "______________________________________\n\n";
    cout << Tabs(2) << "            +++Game Over+++            \n";
    cout << Tabs(2) << "______________________________________\n\n";
}

stGameResult PlayGame(short numberOfRounds)
{
    stRoundInfo roundInfo ;
    short playerWinTimes = 0  , computerWinTimes = 0 , drawTimes = 0 ; 
    for(short gameRound = 1 ; gameRound <= numberOfRounds ; ++gameRound)
    {
        cout << "\nRound [" << gameRound << "] begins: \n";
        roundInfo.roundNumber    = gameRound ;
        roundInfo.playerChoice   = (enGameChoice)GetValidPositiveIntegerInRange("\nYour Choice: [1]:Stone , [2]:Paper , [3]:Scissor ? " , 1 , 3);
        roundInfo.ComputerChoice = (enGameChoice)GenerateRandomIntegerInRange(1,3);
        roundInfo.winner         = WhoWonTheRound(roundInfo);
        roundInfo.winnerName     = WinnerName(roundInfo.winner);
        
        if(roundInfo.winner == enWinner::player)
            playerWinTimes ++ ;
        else if(roundInfo.winner == enWinner::computer)
            computerWinTimes ++ ;
        else    
            drawTimes ++ ;
        
        PrintRoundResults(roundInfo);
        
    }
    
    return FillStGameResult(roundInfo , playerWinTimes , computerWinTimes , drawTimes);
}

void ShowFinalResult(stGameResult gameResult)
{
    cout << Tabs(2) << "---------------[Game Results]--------------\n\n";
    cout << Tabs(2) << "Game Rounds        :" << gameResult.gameRounds << "\n";
    cout << Tabs(2) << "Player Won Times   :" << gameResult.playerWinTimes << "\n";
    cout << Tabs(2) << "Computer Won Times :" << gameResult.computerWinTimes << "\n";
    cout << Tabs(2) << "Draw Times         :" << gameResult.drawTimes << "\n";
    cout << Tabs(2) << "Final Winner       :" << gameResult.finalWinner << "\n\n";
    cout << Tabs(2) << "--------------------------------------------" ;
}

void StartStonePaperScissorGame()
{
    char playAgain = 'y';

    do
    {
        ResetScreen();
        stGameResult gameResult = PlayGame(GetValidPositiveIntegerInRange("\nHow many rounds do you want to play?\n", 1 , 10));
        ShowGameOverScreen();
        ShowFinalResult(gameResult);
        cout << "\nDo you want to play again? ";
        cin >> playAgain ;
    } while (playAgain == 'y' || playAgain == 'Y');
}

int main()
{
    srand((unsigned)time(NULL));

    StartStonePaperScissorGame();
}
 