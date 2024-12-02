#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void MainMenueScreen();
void TransactionsMenueScreen();
void GoBackToMainMenue();

// 1- Client List:-

//************************************************************************//
const string ClientsFileName = "Clients.txt";

struct sClients
{
	string AccountNumber;
	string PinCode;
	string ClientName;
	string Phone;
	double Balance;
	bool MarkClientForDelete = false;
};

vector <string> SplitString(string S, string delim)
{
	vector <string> vString;

	short pos = 0;   string sWord = "";

	while ((pos = S.find(delim)) != std::string::npos)
	{
		sWord = S.substr(0, pos);
		if (sWord != "")
		{
			vString.push_back(sWord);
		}
		S.erase(0, pos + delim.length());
	}
	if (S != "")
	{
		vString.push_back(S);
	}

	return vString;
}

sClients ConvertLineToRecord(string S, string Separator = "#--#")
{
	sClients ClientRecord;
	vector <string> vString;

	vString = SplitString(S, Separator);

	ClientRecord.AccountNumber = vString[0];
	ClientRecord.PinCode = vString[1];
	ClientRecord.ClientName = vString[2];
	ClientRecord.Phone = vString[3];
	ClientRecord.Balance = stod(vString[4]);

	return ClientRecord;
}

vector <sClients> LoadDataFromFile(string FileName)
{
	vector <sClients> vClients;

	fstream MyFile;
	MyFile.open(FileName, ios::in); //read Mode.

	if (MyFile.is_open())
	{
		string line = "";
		sClients Client;

		while (getline(MyFile, line))
		{
			Client = ConvertLineToRecord(line);
			vClients.push_back(Client);
		}
		MyFile.close();
	}

	return vClients;
}

string NumberOfTabs(short Number)
{
	string Tabs = "";
	for (short i = 1; i <= Number; i++)
	{
		Tabs += "\t";
	}
	return Tabs;
}

string NumberOfSpaces(short I)
{
	string Spaces = "";
	for (short i = 1; i <= I; i++)
	{
		Spaces += "__";
	}
	return Spaces;
}

string NumberOfBack_Slash(short J)
{
	string Slashs = "";
	for (short i = 1; i <= J; i++)
	{
		Slashs += "-";
	}
	return Slashs;
}

string NumberOfEquals(short Num)
{
	string Equals = "";
	for (short i = 1; i <= Num; i++)
	{
		Equals += "=";
	}
	return Equals;
}

void ClientInfo(sClients client)
{
	cout << "| " << setw(16) << left << client.AccountNumber;
	cout << "| " << setw(11) << left << client.PinCode;
	cout << "| " << setw(47) << left << client.ClientName;
	cout << "| " << setw(15) << left << client.Phone;
	cout << "| " << setw(12) << left << client.Balance;
	cout << endl;
}

void ShowClientList()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	cout << "\n" << NumberOfTabs(5);
	cout << "Client List (" << vClients.size() << ") Client(s)." << endl;
	cout << NumberOfSpaces(56) << "\n\n";
	cout << "| " << setw(16) << left << "Account Number";
	cout << "| " << setw(11) << left << "Pin Code";
	cout << "| " << setw(47) << left << "Client Name";
	cout << "| " << setw(15) << left << "Phone";
	cout << "| " << setw(12) << left << "Balance" << "\n";
	cout << NumberOfSpaces(56) << "\n\n";

	//ranged loop.
	for (sClients& client : vClients)
	{
		ClientInfo(client);
	}

	cout << "\n" << NumberOfSpaces(56);
}


//************************************************************************//

// 2 - Add New Client :-

void NewClientsScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Add New Clients Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
	cout << "Adding New Client:\n\n";
}

sClients ReadClientInformation(vector <sClients> vClients)
{
	sClients client;

	cout << "Enter Account Number? ";
	getline(cin >> ws, client.AccountNumber);

	for (sClients& C : vClients)
	{
		if (C.AccountNumber == client.AccountNumber)
		{
			while (C.AccountNumber == client.AccountNumber)
			{
				cout << "\n\nClient with [" << client.AccountNumber
					<< "] already exists,Enter another Account Number? ";
				getline(cin >> ws, client.AccountNumber);

				if (C.AccountNumber != client.AccountNumber)
				{
					break;
				}
			}
		}
	}

	cout << "Enter PinCode? ";
	getline(cin, client.PinCode);

	cout << "Enter Name? ";
	getline(cin, client.ClientName);

	cout << "Enter Phone? ";
	getline(cin, client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> client.Balance;

	return client;
}

string ConvertRecordToDataLine(sClients Client, string Separator = "#--#")
{
	string ClientDataLine = "";

	ClientDataLine += Client.AccountNumber + Separator;
	ClientDataLine += Client.PinCode + Separator;
	ClientDataLine += Client.ClientName + Separator;
	ClientDataLine += Client.Phone + Separator;
	ClientDataLine += to_string(Client.Balance);

	return ClientDataLine;
}

void UpdateFileWithNewClientDataLine(string FileName, string DataLine)
{
	fstream MyFile;
	MyFile.open(FileName, ios::out | ios::app); // Append Mode.

	if (MyFile.is_open())
	{
		MyFile << DataLine << endl;

		MyFile.close();
	}
}

void AddNewClient()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	char answer;
	do
	{
		system("cls");
		NewClientsScreen();
		sClients client = ReadClientInformation(vClients);
		UpdateFileWithNewClientDataLine(ClientsFileName, ConvertRecordToDataLine(client));
		vClients = LoadDataFromFile(ClientsFileName);

		cout << "\n\nClient Added Successfully, do you want to add more clients? Y/N? ";
		cin >> answer;

	} while (toupper(answer) == 'Y');

}

//************************************************************************//

// 3 - Delete Client :-

void DeleteClientsScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Delete Client Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

string ReadClientAccountNumber()
{
	string AccountNumber = "";

	cout << "\nPlease enter Account Number? ";
	cin >> AccountNumber;

	return AccountNumber;
}

bool FindClientByAccountNumber(string AccountNumber, vector <sClients> vClients, sClients& stClient)
{
	//ranged loop
	for (sClients& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			stClient = C;
			return true;
		}
	}
	return false;
}

void PrintClientCard(sClients client)
{
	cout << "\nThe following are the client details:\n";
	cout << NumberOfBack_Slash(40) << endl;
	cout << "Account Number   : " << client.AccountNumber << "\n";
	cout << "Pin Code         : " << client.PinCode << "\n";
	cout << "Name             : " << client.ClientName << "\n";
	cout << "Phone            : " << client.Phone << "\n";
	cout << "Acccount Balance : " << client.Balance << "\n";
	cout << NumberOfBack_Slash(40) << endl;

}

bool MarkClientForDelete(string AccountNumber, vector <sClients>& vClients)
{
	//ranged loop
	for (sClients& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.MarkClientForDelete = true;
			return true;
		}
	}
	return false;
}

vector <sClients> SaveClientsDataToFile(string FileName, vector <sClients> vClients)
{
	string DataLine = "";

	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite.

	if (MyFile.is_open())
	{
		//ranged loop
		for (sClients& C : vClients)
		{
			if (C.MarkClientForDelete == false)
			{
				DataLine = ConvertRecordToDataLine(C);
				MyFile << DataLine << endl;
			}
		}
		MyFile.close();
	}

	return vClients;
}

bool DeleteClientByAcoountNumber(string AccountNumber, vector <sClients>& vClients)
{
	sClients Client;
	char answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		cout << "\n\n";
		cout << "Are you sure you want delete this client? y/n ? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			MarkClientForDelete(AccountNumber, vClients);
			SaveClientsDataToFile(ClientsFileName, vClients);

			// Refresh Clients in Vector.

			vClients = LoadDataFromFile(ClientsFileName);

			cout << "\n\nClient Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
		return false;
	}
}

void DeleteClient()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	DeleteClientsScreen();

	string S = ReadClientAccountNumber();
	DeleteClientByAcoountNumber(S, vClients);
}

//************************************************************************//

// 4 - Update Client Info :-

void UpdateClientsScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Update Client Info Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

sClients ReadClientData(string AccountNumber)
{
	sClients client;

	client.AccountNumber = AccountNumber;

	cout << "Enter PinCode? ";
	getline(cin >> ws, client.PinCode);

	cout << "Enter Name? ";
	getline(cin, client.ClientName);

	cout << "Enter Phone? ";
	getline(cin, client.Phone);

	cout << "Enter AccountBalance? ";
	cin >> client.Balance;

	return client;
}

vector <sClients> UpdateClient(string AccountNumber, vector <sClients>& vClients)
{
	sClients client;

	//ranged loop
	for (sClients& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			client = ReadClientData(AccountNumber);
			C = client;
			break;
		}
	}

	return vClients;
}

bool UpdateClientByAccountNumber(string AccountNumber, vector <sClients>& vClients)
{
	sClients C;
	char answer = 'n';

	if (FindClientByAccountNumber(AccountNumber, vClients, C))
	{
		PrintClientCard(C);

		cout << "\n\n";
		cout << "Are you sure you want update this client? y/n ? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			vClients = UpdateClient(AccountNumber, vClients);

			//Refrash Clients Data In File.
			SaveClientsDataToFile(ClientsFileName, vClients);

			cout << "\n\nClient Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
		return false;
	}
}

void UpdateClientInfo()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	UpdateClientsScreen();
	string S = ReadClientAccountNumber();
	UpdateClientByAccountNumber(S, vClients);
}

//************************************************************************//

// 5 - Find Client :-

void FindClientScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Find Client Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

bool IsClientExist(string AccountNumber, vector <sClients> vClients)
{
	sClients client;

	if (FindClientByAccountNumber(AccountNumber, vClients, client))
	{
		PrintClientCard(client);
		return true;
	}
	else
	{
		cout << "\nClient with Account Number (" << AccountNumber << ") is Not Found!\n";
		return false;
	}
}

void FindClientInfo()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	FindClientScreen();
	IsClientExist(ReadClientAccountNumber(), vClients);
}

//************************************************************************//

// 6 - Transactions :-

// A - Deposit.

void DepositScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Deposit Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

double HowMuchMoneyToDeposit()
{
	double depositAmount = 0;

	cout << "\n" << "Please Enter deposit amount? ";
	cin >> depositAmount;

	return depositAmount;
}

vector <sClients> UpdateVectorWithNewDeposit(string AccountNumber, vector <sClients>& vClients, double depositAmount)
{
	for (sClients& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.Balance += depositAmount;
			break;
		}
	}
	return vClients;
}

vector <sClients> UpdateClientsDataToFile(string FileName, vector <sClients> vClients)
{
	string DataLine = "";

	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite.

	if (MyFile.is_open())
	{
		//ranged loop
		for (sClients& C : vClients)
		{
			DataLine = ConvertRecordToDataLine(C);
			MyFile << DataLine << endl;			
		}
		MyFile.close();
	}

	return vClients;
}

bool AddDepositByClientAccountNumber(string AccountNumber, vector <sClients>& vClients)
{
	sClients Client;
	char answer = 'n';
	double depositAmount = 0;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		depositAmount = HowMuchMoneyToDeposit();

		cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			vClients = UpdateVectorWithNewDeposit(AccountNumber, vClients, depositAmount);

			//Update clients Data in file.
			UpdateClientsDataToFile(ClientsFileName, vClients);

			return true;
		}
	}
	else
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n\n";
		cout << "Please enter Account Number? ";    cin >> AccountNumber;

		AddDepositByClientAccountNumber(AccountNumber, vClients);
	}
	return false;
}

void Deposit()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	DepositScreen();

	string S = ReadClientAccountNumber();
	AddDepositByClientAccountNumber(S, vClients);
}

//************************//

// B - Withdraw.

void WithdrawScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Withdraw Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

double WithdrawAmount()
{
	double withdrawAmount = 0;

	cout << "\n" << "Please Enter withdraw amount? ";
	cin >> withdrawAmount;

	return withdrawAmount;




}

vector <sClients> UpdateVectorByWithdraw(string AccountNumber, vector <sClients>& vClients, double WithdrawAmount)
{
	for (sClients& C : vClients)
	{
		if (C.AccountNumber == AccountNumber)
		{
			C.Balance = C.Balance - WithdrawAmount;
			break;
		}
	}
	return vClients;
}

bool WithdrawAmountByClientAccountNumber(string AccountNumber, vector <sClients>& vClients)
{
	sClients Client;
	char answer = 'n';
	double withdrawAmount = 0;

	if (FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		PrintClientCard(Client);

		withdrawAmount = WithdrawAmount();

		//ranged loop.
		for (sClients& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				if (C.Balance < withdrawAmount)
				{
					while (C.Balance < withdrawAmount)
					{
						cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << C.Balance << endl;
						cout << "Please enter another amount? ";
						cin >> withdrawAmount;

						if (C.Balance >= withdrawAmount)
						{
							break;
						}
					}
				}
			}
		}


		cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
		cin >> answer;

		if (answer == 'Y' || answer == 'y')
		{
			vClients = UpdateVectorByWithdraw(AccountNumber, vClients, withdrawAmount);

			//Update clients Data in file.
			UpdateClientsDataToFile(ClientsFileName, vClients);

			return true;
		}
	}
	else
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n\n";
		cout << "Please enter Account Number? ";    cin >> AccountNumber;

		WithdrawAmountByClientAccountNumber(AccountNumber, vClients);
	}
	return false;
}

void Withdraw()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	WithdrawScreen();
	string S = ReadClientAccountNumber();

	WithdrawAmountByClientAccountNumber(S, vClients);
}

//************************//

// C - Total Balances.

void ClientBalanceInfo(sClients client)
{
	cout << "| " << setw(16) << left << client.AccountNumber;
	cout << "| " << setw(47) << left << client.ClientName;
	cout << "| " << setw(12) << left << client.Balance;
	cout << endl;
}

double SumBalances(vector <sClients> vClients)
{
	double sum = 0;

	for (sClients& client : vClients)
	{
		sum += client.Balance;
	}

	return sum;
}

void ClientsBalances()
{
	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);

	cout << "\n" << NumberOfTabs(5);
	cout << "Balances List (" << vClients.size() << ") Client(s)." << endl;
	cout << NumberOfSpaces(56) << "\n\n";
	cout << "| " << setw(16) << left << "Account Number";
	cout << "| " << setw(47) << left << "Client Name";
	cout << "| " << setw(12) << left << "Balance" << "\n";
	cout << NumberOfSpaces(56) << "\n\n";


	//ranged loop.
	for (sClients& client : vClients)
	{
		ClientBalanceInfo(client);
	}

	cout << "\n" << NumberOfSpaces(56);

	cout << "\n\n" << NumberOfTabs(5) << "Total Balances = " << SumBalances(vClients) << "\n\n";

	cout << "Press any key to go back to Transactions Menue...";
}


//************************//

enum eTransactions
{
	eDeposit = 1,
	eWithdraw = 2,
	eTotalBalances = 3,
	eMainMenue = 4
};

short ChooseTransaction()
{
	short Number = 0;
	cout << "\n" << "Choose what do you want to do? [1 to 4]? ";
	cin >> Number;

	return Number;
}

void GoBackToTransactionsMenue()
{
	system("pause > 0");
	TransactionsMenueScreen();
}

void PerformTransactionOperation(eTransactions Transaction)
{
	switch (Transaction)
	{
	case eTransactions::eDeposit:
		system("cls");
		system("color 2f");
		Deposit();
		GoBackToTransactionsMenue();
		break;

	case eTransactions::eWithdraw:
		system("cls");
		system("color 1f");
		Withdraw();
		GoBackToTransactionsMenue();
		break;

	case eTransactions::eTotalBalances:
		system("cls");
		system("color D");
		ClientsBalances();
		GoBackToTransactionsMenue();
		break;

	case eTransactions::eMainMenue:
		system("cls");
		MainMenueScreen();
		break;
	}
}

void TransactionsMenueScreen()
{
	system("cls");
	system("color 4f");

	cout << NumberOfEquals(44) << "\n";
	cout << NumberOfTabs(1);
	cout << "**Transactions Menue Screen** " << "\n";
	cout << NumberOfEquals(44);
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[1] Deposit.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[2] Withdraw.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[3] Total Balances.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[4] Main Menue.";
	cout << "\n" << NumberOfEquals(44);

	PerformTransactionOperation((eTransactions)ChooseTransaction());
}

//************************************************************************//

// 7 - Exit :-

void ProgramEnds()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Program Ends :-)\n";
	cout << NumberOfBack_Slash(40) << endl;
}

//************************************************************************//

enum enMenueOptions
{
	eClientList = 1,
	eNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	FindClient = 5,
	Transactions = 6,
	Exit = 7
};

short ReadMenueOption()
{
	short Number = 0;
	cout << "Choose what do you want to do? [1 to 6]?  ";
	cin >> Number;

	return Number;
}

void GoBackToMainMenue()
{
	cout << "\n\nPress any key to go back to Main Menue...";
	system("pause > 0");
	MainMenueScreen();
}

void PerformMenueOptions(enMenueOptions MenueOptions)
{
	switch (MenueOptions)
	{
	case enMenueOptions::eClientList:
		system("cls");
		ShowClientList();
		GoBackToMainMenue();
		break;

	case enMenueOptions::eNewClient:
		system("cls");
		AddNewClient();
		GoBackToMainMenue();
		break;

	case enMenueOptions::eDeleteClient:
		system("cls");
		DeleteClient();
		GoBackToMainMenue();
		break;

	case enMenueOptions::eUpdateClient:
		system("cls");
		UpdateClientInfo();
		GoBackToMainMenue();
		break;

	case enMenueOptions::FindClient:
		system("cls");
		FindClientInfo();
		GoBackToMainMenue();
		break;

	case enMenueOptions::Transactions:
		system("cls");
		TransactionsMenueScreen();
		break;

	case enMenueOptions::Exit:
		system("cls");
		ProgramEnds();
		GoBackToMainMenue();
		break;
	}
}

void MainMenueScreen()
{
	system("cls");
	system("color 5f");

	cout << NumberOfEquals(50) << "\n";
	cout << NumberOfTabs(2);
	cout << "Main Menue Screen " << "\n";
	cout << NumberOfEquals(50) << endl;
	cout << NumberOfTabs(1) << setw(25) << left << "[1] Show Client List.\n";
	cout << NumberOfTabs(1) << setw(25) << left << "[2] Add New Client.\n";
	cout << NumberOfTabs(1) << setw(25) << left << "[3] Delete Client.\n";
	cout << NumberOfTabs(1) << setw(25) << left << "[4] Update Client Info.\n";
	cout << NumberOfTabs(1) << setw(25) << left << "[5] Find Client.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[6] Transactions.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[7] Exit.";
	cout << "\n" << NumberOfEquals(50) << "\n";

	PerformMenueOptions((enMenueOptions)ReadMenueOption());
}

int main()
{

	MainMenueScreen();

	system("pause > 0");
	return 0;
}