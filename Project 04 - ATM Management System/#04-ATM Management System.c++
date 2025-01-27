#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <windows.h>
using namespace std;

void ATMMainMenue();
void GoBackToMainMenue();
void Login();

const string ClientsFileName = "Clients.txt";

struct stClient
{
	string AccountNumber;
	string PinCode;
	string ClientName;
	string PhoneNumber;
	double Balance;
};

stClient CurrentClient; // Global Variable.

vector <string> SplitString(string S, string Delim = "#--#")
{
	vector <string> vString;

	short Pos = 0;    string sWord = "";
	while ((Pos = S.find(Delim)) != std::string::npos )
	{
		sWord = S.substr(0, Pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}

		S.erase(0, Pos + Delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}
	return vString;
}

stClient ConvertLineToRecord(string S, string Separator = "#--#")
{
	stClient sClient;
	vector <string> vString;

	vString = SplitString(S, Separator);

	sClient.AccountNumber = vString[0];
	sClient.PinCode = vString[1];
	sClient.ClientName = vString[2];
	sClient.PhoneNumber = vString[3];
	sClient.Balance = stod(vString[4]);

	return sClient;
}

string ConvertRecordToDataLine(stClient sClient, string Separator = "#--#")
{
	string DataLine = "";

	DataLine += sClient.AccountNumber + Separator;
	DataLine += sClient.PinCode + Separator;
	DataLine += sClient.ClientName + Separator;
	DataLine += sClient.PhoneNumber + Separator;
	DataLine += to_string(sClient.Balance);

	return DataLine;
}

vector <stClient> LoadDataFromFile(string FileName)
{
	vector <stClient> vClients;
	fstream MyFile;
	MyFile.open(FileName,ios::in); //Read Mode.

	if (MyFile.is_open())
	{
		string Line = "";
		stClient Client;

		while (getline(MyFile, Line))
		{
			Client = ConvertLineToRecord(Line);
			vClients.push_back(Client);
		}

		MyFile.close();
	}

	return vClients;
}

vector <stClient> SaveDataToFile(string FileName, vector <stClient> vClients)
{
	string Line = "";

	fstream MyFile;
	MyFile.open(FileName,ios::out); //Write Mode.

	if (MyFile.is_open())
	{
		for (stClient& Client : vClients)
		{
			Line = ConvertRecordToDataLine(Client);
			MyFile << Line << endl;
		}

		MyFile.close();
	}

	return vClients;
}

/*-----------------------------------------------------------------*/
				     	/* 1- QuickWithdraw */

short ReadWithdrawOption()
{
	short OptionWithdraw = 0;

	do
	{
		cout << "\nChoose what to withdraw from [1] to [8] ? ";
		cin >> OptionWithdraw;

	} while (OptionWithdraw < 1 || OptionWithdraw > 9);

	return OptionWithdraw;
}

short ReturnWithdrawAmountByOption(short QuickWithdrawarr[9], short WithdrawOption)
{
	return QuickWithdrawarr[WithdrawOption];
}

stClient WithdrawAmountFromCurrentClientBalance(int AmountToBeWithDrawn)
{
	 CurrentClient.Balance -= AmountToBeWithDrawn;

	 return CurrentClient;
}

bool UpdateRecordInClientsVector(string AccountNumber, string PinCode, vector <stClient>& vClients)
{
	//Ranged loop.
	for (stClient& Client : vClients)
	{
		if (Client.AccountNumber == CurrentClient.AccountNumber && Client.PinCode == CurrentClient.PinCode)
		{
			Client.Balance = CurrentClient.Balance;
			return true;
		}
	}

	return false;
}

bool CheckAllowedBalanceToWithdraw(short QuickWithdrawarr[9], short WithdrawOption)
{
	return  QuickWithdrawarr[WithdrawOption] <= CurrentClient.Balance;
}

bool QuickWithdraw(short WithdrawOption, vector <stClient>& vClients)
{
	short QuickWithdrawarr[9] = { 0, 20, 50, 100, 200, 400, 600, 800, 1000 };
	char answer = 'n';

	if (WithdrawOption == 9) {
		return false;
	}

	if (CheckAllowedBalanceToWithdraw(QuickWithdrawarr,WithdrawOption))
	{
		cout << "\n\nAre you sure you want perform this transction? y/n ? ";
		cin >> answer;
		if (toupper(answer) == 'Y')
		{
			CurrentClient = WithdrawAmountFromCurrentClientBalance
			(ReturnWithdrawAmountByOption(QuickWithdrawarr, WithdrawOption));

			UpdateRecordInClientsVector(CurrentClient.AccountNumber,
				CurrentClient.PinCode, vClients);

			SaveDataToFile(ClientsFileName, vClients);

			//Update Clients in Vector.
			vClients = LoadDataFromFile(ClientsFileName);
			cout << "\n\nDone Successfully. New balance is: " << CurrentClient.Balance << endl;

			return true;
		}
	}
	else
	{
		cout << "\nThe amount exceeds your balance, make another choice.";
		return false;
	}
}

void QuickWithdrawMenueOptions()
{
	system("color 4f");
	cout << "===========================================\n";
	cout << "\t     Quick Withdraw                        ";
	cout << "\n===========================================\n";
	cout << "\t[1] " << setw(4) << left << "20" << "\t [2] 50 \n";
	cout << "\t[3] " << setw(4) << left << "100" << "\t [4] 200 \n";
	cout << "\t[5] " << setw(4) << left << "400" << "\t [6] 600 \n";
	cout << "\t[7] " << setw(4) << left << "800" << "\t [8] 1000 \n";
	cout << "\t[9] " << setw(4) << left << "Exit";
	cout << "\n===========================================\n";

	cout << "Your Balance is: " << CurrentClient.Balance;
	short WithdrawOptions = ReadWithdrawOption();

	vector <stClient> vClients = LoadDataFromFile(ClientsFileName);
	QuickWithdraw(WithdrawOptions, vClients);
}

/*-----------------------------------------------------------------*/
						/* 2- Normal Withdraw */

int ReadAmountToWithdraw()
{
	int Amount = 0;
	do
	{
		cout << "\nEnter an amount multiple of 5's ? ";
		cin >> Amount;

	} while (Amount % 5 != 0);

	return Amount;
}

bool CheckAmountNotExceedsTheBalance(int Amount)
{
	return Amount <= CurrentClient.Balance;
}

bool ClientNormalWithdraw(int Amount, vector <stClient>& vClients)
{
	char answer = 'n';

	if (CheckAmountNotExceedsTheBalance(Amount))
	{
		cout << "\n\nAre you sure you want perform this transction? y/n ? ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			CurrentClient = WithdrawAmountFromCurrentClientBalance(Amount);

			UpdateRecordInClientsVector(CurrentClient.AccountNumber,
				CurrentClient.PinCode, vClients);

			SaveDataToFile(ClientsFileName, vClients);


			//Update Clients in Vector.
			vClients = LoadDataFromFile(ClientsFileName);
			cout << "\n\nDone Successfully. New balance is: " << CurrentClient.Balance << endl;

			return true;
		}
	}
	else
	{
		cout << "\nThe amount exceeds your balance, make another choice.";
		return false;
	}
}

void NormalWithdraw()
{
	system("color 4f");
	cout << "===========================================\n";
	cout << "\t  Normal Withdraw Screen                   ";
	cout << "\n===========================================\n";
	cout << "Your Balance is: " << CurrentClient.Balance << "\n";

	int Amount = ReadAmountToWithdraw();
	vector <stClient> vClients = LoadDataFromFile(ClientsFileName);

	ClientNormalWithdraw(Amount, vClients);
}

/*-----------------------------------------------------------------*/
						/* 3- Deposit */

int ReadPositiveDepositAmount()
{
	int Deposit = 0;
	do
	{
		cout << "\nEnter a positive Deposit Amount? ";
		cin >> Deposit;

	} while (Deposit <= 0 || Deposit % 5 != 0);

	return Deposit;
}

stClient IncreaseBalanceByDepositAmount(int Deposit)
{
	CurrentClient.Balance += Deposit;

	return CurrentClient;
}

bool DepositAmountToClientBalance(int Deposit, vector <stClient>& vClients)
{
	char answer = 'n';

	cout << "\n\nAre you sure you want perform this transction? y/n ? ";
	cin >> answer;

	if (toupper(answer) == 'Y')
	{
		CurrentClient = IncreaseBalanceByDepositAmount(Deposit);

		UpdateRecordInClientsVector(CurrentClient.AccountNumber
			, CurrentClient.PinCode, vClients);

		SaveDataToFile(ClientsFileName, vClients);

		//Update Clients in Vector.
		vClients = LoadDataFromFile(ClientsFileName);
		cout << "\n\nDone Successfully. New balance is: " << CurrentClient.Balance << endl;

		return true;
	}
	else
	{
		return false;
	}
}

void Deposit()
{
	system("color 2f");
	cout << "===========================================\n";
	cout << "\t     Deposit Screen                        ";
	cout << "\n===========================================\n";

	int Deposit = ReadPositiveDepositAmount();
	vector <stClient> vClients = LoadDataFromFile(ClientsFileName);

	DepositAmountToClientBalance(Deposit, vClients);
}

/*-----------------------------------------------------------------*/
						/* 4- Check Balance */

void CheckBalance()
{
	system("color 2f");
	cout << "===========================================\n";
	cout << "\t  Check Balance Screen                       ";
	cout << "\n===========================================\n";

	cout << "Your Balance is: " << CurrentClient.Balance << endl;
}

/*-----------------------------------------------------------------*/
                    /*ATM Main Menue Screen*/

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause > 0");

	ATMMainMenue();
}

short ReadATMMainMenueOptions()
{
	short Option = 0;

	do
	{
		cout << "Choose what do you want to do? [1 to 5]? ";
		cin >> Option;

	} while (Option < 1 || Option > 5);

	return Option;
}

enum enATMMenueOptions
{
	eQuickWithdraw = 1,
	eNormalWithdraw = 2,
	eDeposit = 3,
	eCheckBalance = 4,
	eLogOut = 5
};

void PerformATMMenueOptions(enATMMenueOptions ATMOption)
{
	switch (ATMOption)
	{
	case enATMMenueOptions::eQuickWithdraw:
		system("cls");
		QuickWithdrawMenueOptions();
		GoBackToMainMenue();
		break;

	case enATMMenueOptions::eNormalWithdraw:
		system("cls");
		NormalWithdraw();
		GoBackToMainMenue();
		break;

	case enATMMenueOptions::eDeposit:
		system("cls");
		Deposit();
		GoBackToMainMenue();
		break;

	case enATMMenueOptions::eCheckBalance:
		system("cls");
		CheckBalance();
		GoBackToMainMenue();
		break;

	case enATMMenueOptions::eLogOut:
		system("cls");
		Login();
		break;
	}
}

void ATMMainMenue()
{
	system("color 5f");
	system("cls");
	cout << "===========================================\n";
	cout << "\t   ATM Main Menue Screen";
	cout << "\n===========================================\n";

	cout << "\t[1] Quick Withdraw.\n";
	cout << "\t[2] Normal Withdraw.\n";
	cout << "\t[3] Deposit.\n";
	cout << "\t[4] Check Balance.\n";
	cout << "\t[5] Logout.\n";
	cout << "===========================================\n";

	PerformATMMenueOptions((enATMMenueOptions)ReadATMMainMenueOptions());
}

/*-----------------------------------------------------------------*/
				       	/*Login Screen*/

void HeaderLoginScreen()
{
	cout << "\n-------------------------------\n";
	cout << "\t Login Screen";
	cout << "\n-------------------------------\n";
}

bool CheckClientByAccountNumberAndPinCode(string Acc_Number, string Pin,vector <stClient> vClients)
{
	for (stClient& client : vClients)
	{
		if (client.AccountNumber == Acc_Number && client.PinCode == Pin)
		{
			::CurrentClient = client;
			return true;
		}
	}

	return false;
}

void Login()
{
	system("color 0f");

	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, 10);


	vector <stClient> vClients = LoadDataFromFile(ClientsFileName);

	string AccountNumber = "";
	string PinCode = "";

	HeaderLoginScreen();

	do
	{
		cout << "Enter Account Number? ";
		cin >> AccountNumber;

		cout << "Enter Pin? ";
		cin >> PinCode;

		CheckClientByAccountNumberAndPinCode(AccountNumber, PinCode, vClients);
		if (CurrentClient.AccountNumber == AccountNumber && CurrentClient.PinCode == PinCode) {

			SetConsoleTextAttribute(h, 7);
			ATMMainMenue();
			break;
		}

		system("cls");
		HeaderLoginScreen();
		cout << "Invalid Account Number/PinCode!\n";

	} while (true);

}


int main()
{
	Login();

	system("pause > 0");
	return 0;
}