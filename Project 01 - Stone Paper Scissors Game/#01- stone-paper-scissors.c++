#include<iostream>
#include <cstdlib>
using namespace std;

enum enGameChoice { Stone = 1, Paper = 2, Scissors = 3 };
enum enWinner { Player1 = 1, Computer = 2, Draw = 3 };

struct stRoundInfo 
{
	short RoundNumber = 0;
	enGameChoice Player1Choice;
	enGameChoice ComputerChoice;
	enWinner Winner;
	string WinnerName;
};
struct stGameInfo
{
	short GameRounds = 0;
	short Player1WonTimes = 0;
	short ComputerWonTimes = 0;
	short DrawTimes = 0;
	enWinner GameWinner;
	string GameWinnerName;
};

int RandomNumber(int From, int To)
{
	int randNum = rand() % (To - From + 1) + From;
	return randNum;
}

short ReadHowManyTimes()
{
	short RoundsNumber = 0;
	do
	{
		cout << "How Many Rounds 1 to 10 ? \n";
		cin >> RoundsNumber;

	} while (RoundsNumber < 1 || RoundsNumber > 10);

	return RoundsNumber;
}

enGameChoice ReadPlayer1Choice()
{
	short Choice = 0;

	do
	{
		cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
		cin >> Choice;

	} while (Choice < 1 || Choice > 3);

	return (enGameChoice)Choice;
}

enGameChoice GetComputerChoice()
{
	return (enGameChoice)RandomNumber(1, 3);
}

enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
	if (RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
		return enWinner::Draw;

	switch (RoundInfo.Player1Choice)
	{
	case enGameChoice::Paper:
		if (RoundInfo.ComputerChoice == enGameChoice::Scissors)
			return enWinner::Computer;
		break;

	case enGameChoice::Stone:
		if (RoundInfo.ComputerChoice == enGameChoice::Paper)
			return enWinner::Computer;
		break;

	case enGameChoice::Scissors:
		if (RoundInfo.ComputerChoice == enGameChoice::Stone)
			return enWinner::Computer;
		break;
	}

	return enWinner::Player1;
}

enWinner WhoWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
	if (Player1WinTimes > ComputerWinTimes)
		return enWinner::Player1;
	else if (ComputerWinTimes > Player1WinTimes)
		return enWinner::Computer;
	else
		return enWinner::Draw;
}

string WinnerName(enWinner Winner)
{
	string WinnerName[3] = { "Player1", "Computer", "No Winner" };
	return WinnerName[Winner - 1];
}

string ChoiceName(enGameChoice Choice)
{
	string GameChoice[3] = { "Stone", "Paper", "Scissors" };
	return GameChoice[Choice - 1];
}

void SetWinnerScreenColor(enWinner Winner)
{
	switch (Winner)
	{
	case enWinner::Player1:
		system("color 2F");
		break;
	case enWinner::Computer:
		system("color 4F");
		cout << "\a";
		break;
	default:
		system("color 6F");
		break;
	}
}

void PrintRoundInfo(stRoundInfo RoundInfo)
{
	cout << "\n__________________Round [" << RoundInfo.RoundNumber << "]__________________\n\n";
	cout << "Player1  Choice: " << ChoiceName(RoundInfo.Player1Choice) << endl;
	cout << "Computer Choice: " << ChoiceName(RoundInfo.ComputerChoice) << endl;
	cout << "Round Winner   : " << "[" << RoundInfo.WinnerName << "]" << endl;
	cout << "_____________________________________________\n\n";

	SetWinnerScreenColor(RoundInfo.Winner);
}

stGameInfo FillGameInfo(short RoundsNumber, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
	stGameInfo GameInfo;

	GameInfo.GameRounds = RoundsNumber;
	GameInfo.Player1WonTimes = Player1WinTimes;
	GameInfo.ComputerWonTimes = ComputerWinTimes;
	GameInfo.DrawTimes = DrawTimes;
	GameInfo.GameWinner = WhoWonTheGame(Player1WinTimes, ComputerWinTimes);
	GameInfo.GameWinnerName = WinnerName(GameInfo.GameWinner);

	return GameInfo;
}

stGameInfo StartRound(short RoundsNumber)
{
	stRoundInfo RoundInfo;
	short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0;

	for (short GameRound = 1; GameRound <= RoundsNumber; GameRound++)
	{
		cout << "\nRound [" << GameRound << "] begins: \n";

		RoundInfo.RoundNumber = GameRound;
		RoundInfo.Player1Choice = ReadPlayer1Choice();
		RoundInfo.ComputerChoice = GetComputerChoice();
		RoundInfo.Winner = WhoWonTheRound(RoundInfo);
		RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);

		if (RoundInfo.Winner == enWinner::Player1)
			Player1WinTimes++; 

		else if (RoundInfo.Winner == enWinner::Computer)
			ComputerWinTimes++;

		else
			DrawTimes++;

		PrintRoundInfo(RoundInfo);
	}

	return FillGameInfo(RoundsNumber, Player1WinTimes, ComputerWinTimes, DrawTimes);

}

string Tabs(short NumberOfTabs)
{
	string tab = "";
	for (int i  = 1; i <= NumberOfTabs; i++)
	{
		tab = tab + "\t";
	}

	return tab;
}

void PrintFinalGameResults(stGameInfo GameInfo)
{
	cout << Tabs(4) << "_____________________[Game Results]_____________________\n\n";
	cout << Tabs(4) << "Game Rounds        : " << GameInfo.GameRounds << "\n";
	cout << Tabs(4) << "Player1 won times  : " << GameInfo.Player1WonTimes << "\n";
	cout << Tabs(4) << "Computer won times : " << GameInfo.ComputerWonTimes << "\n";
	cout << Tabs(4) << "Draw times         : " << GameInfo.DrawTimes << "\n";
	cout << Tabs(4) << "Final winner       : " << GameInfo.GameWinnerName << "\n";
	cout << Tabs(4) << "________________________________________________________\n\n";

	//SetWinnerScreenColor(GameInfo.GameWinner);
}

void PrintGameOverScreen()
{
	cout << Tabs(4) << "________________________________________________________\n\n";
	cout << Tabs(4) << "               +++ G a m e  O v e r +++                   \n";
	cout << Tabs(4) << "________________________________________________________\n\n";
}

void ResetScreen()
{
	system("cls");
	system("color 0F");
}

void StartGame()
{
	char PlayAgain;
	do
	{
		ResetScreen();
		stGameInfo GameInfo = StartRound(ReadHowManyTimes());
		PrintGameOverScreen();
		PrintFinalGameResults(GameInfo);

		cout << Tabs(4) << "Do you want to play again? Y/N? ";
		cin >> PlayAgain;

	} while (PlayAgain == 'Y' || PlayAgain == 'y');

}

int main()
{
	srand((unsigned)time(NULL));
	StartGame();

	return 0;
}
