#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
using namespace std;

void UsersMainMenueScreen();
void GoBackToUserMenueScreen();
void LoginScreen();
void MainMenueScreen();
void TransactionsMenueScreen();
void GoBackToMainMenue();

const string ClientsFileName = "Clients.txt";
const string UsersFileName = "Users.txt";

struct stUsers
{
	string UserName;
	string Password;
	short Permission;
	bool MarkUserForDelete = false;
};


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

enum eMainMenuePermissions
{
	pAll = -1,
	pClientList = 1,
	pNewClient = 2,
	pDeleteClient = 4,
	pUpdateClient = 8,
	pFindClient = 16,
	pTransctions = 32,
	pManageUsers = 64
};


stUsers CurrentUser; //Global Variable.

bool CheckAccessPermission(eMainMenuePermissions Permission)
{
	if (CurrentUser.Permission == eMainMenuePermissions::pAll)
		return true;

	if ((Permission & CurrentUser.Permission) == Permission)
		return true;

	else
		return false;
}

void PrintAccessDenied()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << "Access Denied,\nYou dont Have Permission To Do this,\nPlease Contact Your Admin.\n";
	cout << "\n" << NumberOfBack_Slash(40) << endl;
}


// 1- Client List:-
//************************************************************************//

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
	if (!CheckAccessPermission(eMainMenuePermissions::pClientList))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}


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
	if (!CheckAccessPermission(eMainMenuePermissions::pNewClient))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}

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
	if (!CheckAccessPermission(eMainMenuePermissions::pDeleteClient))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}

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
	if (!CheckAccessPermission(eMainMenuePermissions::pUpdateClient ))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}


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
	if (!CheckAccessPermission(eMainMenuePermissions::pFindClient))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}


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

bool DepositBalanceToClientByAccountNumber(string AccountNumber, vector <sClients>& vClients, double DepositAmount)
{
	char answer = 'n';

	cout << "\n\nAre you sure you want perform this transaction? y/n ? ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y')
	{
		//ranged loop.
		for (sClients& C : vClients)
		{
			if (C.AccountNumber == AccountNumber)
			{
				C.Balance += DepositAmount;
				SaveClientsDataToFile(ClientsFileName, vClients);

				cout << "\n\nDone Successfully. New balance is: " << C.Balance << endl;
				return true;
			}
		}
	}
	return false;
}

void ShowDepositScreen()
{
	DepositScreen();

	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);
	sClients client;

	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(AccountNumber, vClients, client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(client);

	double DepositAmount = 0;

	cout << "\n" << "Please Enter deposit amount? ";
	cin >> DepositAmount;

	DepositBalanceToClientByAccountNumber(AccountNumber, vClients, DepositAmount);
}

//************************//

// B - Withdraw.

void WithdrawScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Withdraw Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

void ShowWithdrawScreen()
{
	WithdrawScreen();

	vector <sClients> vClients = LoadDataFromFile(ClientsFileName);
	sClients Client;

	string AccountNumber = ReadClientAccountNumber();

	while (!FindClientByAccountNumber(AccountNumber, vClients, Client))
	{
		cout << "\nClient with [" << AccountNumber << "] does not exist.\n";
		AccountNumber = ReadClientAccountNumber();
	}

	PrintClientCard(Client);

	double WithdrawAmount = 0;
	cout << "\n" << "Please Enter withdraw amount? ";
	cin >> WithdrawAmount;

	while (WithdrawAmount > Client.Balance)
	{
		cout << "\n\nAmount Exceeds the balance, you can withdraw up to : " << Client.Balance << endl;
		cout << "Please enter another amount? ";
		cin >> WithdrawAmount;
	}

	DepositBalanceToClientByAccountNumber(AccountNumber, vClients, WithdrawAmount * -1);
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
	cout << "\n\nPress any key to go back to Transactions Menue...";
	system("pause > 0");
	TransactionsMenueScreen();
}

void PerformTransactionOperation(eTransactions Transaction)
{
	switch (Transaction)
	{
	case eTransactions::eDeposit:
		system("cls");
		ShowDepositScreen();
		GoBackToTransactionsMenue();
		break;

	case eTransactions::eWithdraw:
		system("cls");
		ShowWithdrawScreen();
		GoBackToTransactionsMenue();
		break;

	case eTransactions::eTotalBalances:
		system("cls");
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
	if (!CheckAccessPermission(eMainMenuePermissions::pTransctions))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}


	system("cls");

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
//MainMenueScreen.

enum enMenueOptions
{
	eClientList = 1,
	eNewClient = 2,
	eDeleteClient = 3,
	eUpdateClient = 4,
	FindClient = 5,
	Transactions = 6,
	ManageUsers = 7,
	Logout = 8
};

short ReadMenueOption()
{
	short Number = 0;
	cout << "Choose what do you want to do? [1 to 8]?  ";
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

	case enMenueOptions::ManageUsers:
		system("cls");
		UsersMainMenueScreen();
		GoBackToMainMenue();
		break;

	case enMenueOptions::Logout:
		system("cls");
		LoginScreen();
		break;
	}
}

void MainMenueScreen()
{
	system("cls");

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
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[7] Manage Users.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[8] Logout.";
	cout << "\n" << NumberOfEquals(50) << "\n";

	PerformMenueOptions((enMenueOptions)ReadMenueOption());
}

//************************************************************************//
// 1- User List :-

string ReadUserName()
{
	string UserName = "";

	cout << "\nPlease Enter UserName? ";
	cin >> UserName;

	return UserName;
}

stUsers ConvertLineToUserRecord(string S, string Separator = "#--#")
{
	stUsers User;
	vector <string> vString;

	vString = SplitString(S, Separator);

	User.UserName = vString[0];
	User.Password = vString[1];
	User.Permission = stoi(vString[2]);

	return User;
}

vector <stUsers> LoadDateFromUserFile(string FileName)
{
	vector <stUsers> vUsers;

	fstream MyFile;
	MyFile.open(FileName, ios::in); //read mode.

	if (MyFile.is_open())
	{
		string line = "";
		stUsers User;

		while (getline(MyFile, line))
		{
			User = ConvertLineToUserRecord(line);
			vUsers.push_back(User);
		}

		MyFile.close();
	}

	return vUsers;
}

void UsersInfo(stUsers User)
{
	cout << "| " << setw(16) << left << User.UserName;
	cout << "| " << setw(11) << left << User.Password;
	cout << "| " << setw(47) << left << User.Permission;
	cout << endl;
}

void UssersList()
{
	vector <stUsers> vUsers;
	vUsers = LoadDateFromUserFile(UsersFileName);

	cout << "\n" << NumberOfTabs(5);
	cout << "Users List (" << vUsers.size() << ") User(s)." << endl;
	cout << NumberOfSpaces(56) << "\n\n";
	cout << "| " << setw(16) << left << "User Name";
	cout << "| " << setw(11) << left << "Password";
	cout << "| " << setw(47) << left << "Permissions";
	cout << "\n" << NumberOfSpaces(56) << "\n\n";

	//ranged loop.
	for (stUsers& User : vUsers) {

		UsersInfo(User);
	}

	cout << "\n" << NumberOfSpaces(56) << "\n";
}

//************************************************************************//
// 2 - Add New User.

void NewUserScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Add New User Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
	cout << "Adding New User:\n\n";
}

string ConvertUserRecordToLine(stUsers user, string Separator = "#--#")
{
	string UserDataLine = "";

	UserDataLine += user.UserName + Separator;
	UserDataLine += user.Password + Separator;
	UserDataLine += to_string(user.Permission);

	return UserDataLine;
}

void UpdateUserFileWithNewInformation(string Line, string Filename)
{
	fstream MyFile;
	MyFile.open(Filename, ios::out | ios::app); //append Mode.

	if (MyFile.is_open())
	{
		MyFile << Line << endl;

		MyFile.close();
	}
}

bool UserExistsByUserName(string Username, string Filename)
{
	fstream MyFile;
	MyFile.open(Filename, ios::in); //read Mode.

	if (MyFile.is_open())
	{
		string line = "";
		stUsers user;

		while (getline(MyFile, line))
		{
			user = ConvertLineToUserRecord(line);
			if (user.UserName == Username)
			{
				MyFile.close();
				return true;
			}
		}
		MyFile.close();
	}

	return false;
}

short ReadPermissionToSet()
{
	short Permissions = 0;
	char answer = 'n';

	cout << "\nDo you want to give full access? y/n? ";
	cin >> answer;

	if (answer == 'Y' || answer == 'y') {

		return eMainMenuePermissions::pAll;
	}

	cout << "\nDo you want to give access to : \n";

	cout << "\nShow Client List? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		Permissions += eMainMenuePermissions::pClientList;
	}

	cout << "\nAdd New Client? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		Permissions += eMainMenuePermissions::pNewClient;
	}

	cout << "\nDelete Client? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		Permissions += eMainMenuePermissions::pDeleteClient;
	}

	cout << "\nUpdate Client? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		Permissions += eMainMenuePermissions::pUpdateClient;
	}

	cout << "\nFind Client? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		Permissions += eMainMenuePermissions::pFindClient;
	}

	cout << "\nTransactions? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		Permissions += eMainMenuePermissions::pTransctions;
	}

	cout << "\nManage Users? y/n ? ";
	cin >> answer;
	if (answer == 'Y' || answer == 'y') {

		
		Permissions += eMainMenuePermissions::pManageUsers;
	}

	return Permissions;
}

stUsers ReadUserInformation()
{
	stUsers User;

	cout << "Enter Username ? ";
	getline(cin >> ws, User.UserName);

	while (UserExistsByUserName(User.UserName, UsersFileName))
	{
		cout << "\nUser with [" << User.UserName << "] already exists, Enter another Username? ";
		getline(cin >> ws, User.UserName);
	}

	cout << "\nEnter Password ? ";
	getline(cin, User.Password);

	User.Permission = ReadPermissionToSet();

	return User;
}

void AddNewUser()
{
	vector <stUsers> vUsers;
	vUsers = LoadDateFromUserFile(UsersFileName);

	char answer = 'n';
	string Line = "";
	stUsers user;

	do
	{
		system("cls");
		NewUserScreen();
		user = ReadUserInformation();
		Line = ConvertUserRecordToLine(user);
		UpdateUserFileWithNewInformation(Line, UsersFileName);
		//update vector.
		vUsers = LoadDateFromUserFile(UsersFileName);

		cout << "\nUser Added Successfully, do you want to add more Users? Y/N? ";
		cin >> answer;


	} while (toupper(answer) == 'Y');
}

//************************************************************************//
// 3 - Delete User.

void DeleteUserScreen()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Delete User Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

void PrintUserCard(stUsers user)
{
	cout << "\nThe following are the User details:\n";
	cout << NumberOfBack_Slash(40) << endl;
	cout << "User Name   : " << user.UserName << "\n";
	cout << "Password    : " << user.Password << "\n";
	cout << "Permissions : " << user.Permission << "\n";
	cout << NumberOfBack_Slash(40) << endl;
}

bool FindUserByUsername(string Username, vector <stUsers> vUsers, stUsers& U)
{
	for (stUsers& user : vUsers)
	{
		if (user.UserName == Username)
		{
			U = user;
			return true;
		}
	}
	return false;
}

bool MarkUserToBeDeleted(string UserName, vector <stUsers>& vUsers)
{
	for (stUsers& user : vUsers)
	{
		if (user.UserName == UserName)
		{
			user.MarkUserForDelete = true;
			return true;
		}
	}
	return false;
}

vector <stUsers> SaveUserDataToFile(string FileName,vector <stUsers> vUsers)
{
	string line = "";

	fstream MyFile;
	MyFile.open(FileName, ios::out); //overwrite.

	if (MyFile.is_open())
	{
		for (stUsers& user : vUsers)
		{
			if (user.MarkUserForDelete == false)
			{
				line = ConvertUserRecordToLine(user);
				MyFile << line << endl;
			}
		}

		MyFile.close();
	}

	return vUsers;
}

bool DeleteUserByUserName(string UserName, vector <stUsers>& vUsers)
{
	stUsers User;
	char answer = 'n';

	if (FindUserByUsername(UserName, vUsers, User))
	{
		if (UserName == "Admin")
		{
			cout << "\n\nYou cannot Delete This User.";
			return true;
		}

		PrintUserCard(User);

		cout << "\n\nAre you sure you want delete this User? y/n ? ";
		cin >> answer;

		if (toupper(answer) == 'Y') {

			MarkUserToBeDeleted(UserName, vUsers);
			SaveUserDataToFile(UsersFileName, vUsers);

			//Update Users Vector.
			vUsers = LoadDateFromUserFile(UsersFileName);

			cout << "\n\nUser Deleted Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Username (" << UserName << ") is Not Found!";
		return false;
	}
}

void DeleteUserFromSystem()
{
	vector <stUsers> vUsers = LoadDateFromUserFile(UsersFileName);

	DeleteUserScreen();

	string UserName = ReadUserName();

	DeleteUserByUserName(UserName, vUsers);
}

//************************************************************************//
// 4 - Update User.

void UpdateUserScreenHeader()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Update Users Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

stUsers UpdateUserInformation(string Username)
{
	stUsers User;

	User.UserName = Username;

	cout << "\nEnter Password? ";
	getline(cin >> ws, User.Password);

	User.Permission = ReadPermissionToSet();

	return User;
}

vector <stUsers> UpdateUserVector(string Username, vector <stUsers>& vUsers)
{

	//ranged loop.
	for (stUsers& user : vUsers)
	{
		if (user.UserName == Username)
		{
			user = UpdateUserInformation(Username);
			break;
		}
	}
	return vUsers;
}

bool UpdateUserByUserName(string Username, vector <stUsers>& vUsers)
{
	stUsers User;
	char answer = 'n';

	if (FindUserByUsername(Username, vUsers, User))
	{
		PrintUserCard(User);

		cout << "\n\nAre you sure you want update this User? y/n ? ";
		cin >> answer;

		if (toupper(answer) == 'Y')
		{
			vUsers = UpdateUserVector(Username, vUsers);
			SaveUserDataToFile(UsersFileName, vUsers);

			cout << "\n\nUser Updated Successfully.";
			return true;
		}
	}
	else
	{
		cout << "\nUser with Username (" << Username << ") is Not Found!";
		return false;
	}
}

void UpdateUsers()
{
	vector <stUsers> vUsers = LoadDateFromUserFile(UsersFileName);
	UpdateUserScreenHeader();

	string UserName = ReadUserName();

	UpdateUserByUserName(UserName, vUsers);
}

//************************************************************************//
// 5 - Find User.

void FindUserScreenHeader()
{
	cout << "\n" << NumberOfBack_Slash(40) << endl;
	cout << NumberOfTabs(1) << "Find User Screen\n";
	cout << NumberOfBack_Slash(40) << endl;
}

void FindTheUser()
{
	vector <stUsers> vUsers = LoadDateFromUserFile(UsersFileName);
	stUsers User;

	FindUserScreenHeader();

	string Username = ReadUserName();

	if (FindUserByUsername(Username, vUsers, User))
	{
		PrintUserCard(User);
	}
	else {
		cout << "\nUser with Username (" << Username << ") is Not Found!";
	}
}


//************************************************************************//
//User Menue.

enum enUserMenueOptions
{
	ListUsers = 1,
	NewUser = 2,
	DeleteUser = 3,
	UpdateUser = 4,
	FindUser = 5,
	MainMenue = 6
};

short ReadUsersMenueOptions()
{
	short Number = 0;
	cout << "Choose what do you want to do? [1 to 6]? ";
	cin >> Number;

	return Number;
}

void GoBackToUserMenueScreen()
{
	cout << "\n\nPress any key to go back to Transactions Menue...";
	system("pause > 0");

	UsersMainMenueScreen();
}

void PerformUserMenueOption(enUserMenueOptions UserOptions)
{
	switch (UserOptions)
	{
	case enUserMenueOptions::ListUsers:
		system("cls");
		UssersList();
		GoBackToUserMenueScreen();
		break;

	case enUserMenueOptions::NewUser:
		system("cls");
		AddNewUser();
		GoBackToUserMenueScreen();
		break;

	case enUserMenueOptions::DeleteUser:
		system("cls");
		DeleteUserFromSystem();
		GoBackToUserMenueScreen();
		break;

	case enUserMenueOptions::UpdateUser:
		system("cls");
		UpdateUsers();
		GoBackToUserMenueScreen();
		break;

	case enUserMenueOptions::FindUser:
		system("cls");
		FindTheUser();
		GoBackToUserMenueScreen();
		break;

	case enUserMenueOptions::MainMenue:
		system("cls");
		MainMenueScreen();
		break;
	}
}

void UsersMainMenueScreen()
{
	if (!CheckAccessPermission(eMainMenuePermissions::pManageUsers))
	{
		PrintAccessDenied();
		GoBackToMainMenue();
		return;
	}

	system("cls");
	cout << NumberOfEquals(50) << "\n";
	cout << NumberOfTabs(1);
	cout << "     Manage Users Menue Screen " << "\n";
	cout << NumberOfEquals(50) << endl;
	cout << NumberOfTabs(1) << setw(25) << left << "[1] List Users.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[2] Add New User.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[3] Delete User.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[4] Update User.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[5] Find User.";
	cout << "\n" << NumberOfTabs(1) << setw(25) << left << "[6] Main Menue.";
	cout << "\n" << NumberOfEquals(50) << endl;

	PerformUserMenueOption((enUserMenueOptions)ReadUsersMenueOptions());
}

void HeaderLoginScreen()
{
	cout << "\n-----------------------------\n";
	cout << NumberOfTabs(1) << "Login Screen" << "\n";
	cout << "-----------------------------\n";
}

void LoginScreen()
{
	HeaderLoginScreen();

	stUsers User;
	vector <stUsers> vUsers;
	vUsers = LoadDateFromUserFile(UsersFileName);

	string UserName = "";
	string Password = "";

	do
	{
		cout << "Enter UserName? ";
		getline(cin >> ws, UserName);

		cout << "Enter Password? ";
		cin >> Password;

		//ranged loop.
		for (stUsers& user : vUsers) {

			if (user.UserName == UserName && user.Password == Password) {

				::CurrentUser = user;

				MainMenueScreen();
				break;
			}
		}
		system("cls");
		HeaderLoginScreen();
		cout << "Invalid User name/Password!\n";

	} while (true);
}

int main()
{

	LoginScreen();

	system("pause > 0");
	return 0;
}