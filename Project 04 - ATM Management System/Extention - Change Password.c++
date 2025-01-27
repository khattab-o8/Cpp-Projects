/*-----------------------------------------------------------------*/
						/* 5- Change Password */

short ReadNewPassword(string Massage)
{
	short Password = 0;

	cout << Massage;
	cin >> Password;

	return Password;
}

bool CheckNewPasswordWithCurrentOne(short Password)
{
	return Password == CurrentClient.PinCode;
}

bool CheckNewPasswordConfirmation(short Password, short ConfirmedPassword)
{
	return Password != ConfirmedPassword;
}

stClient ChangeClientOldPinCode(short ConfirmedPassword)
{
	CurrentClient.PinCode = ConfirmedPassword;

	return CurrentClient;
}

bool UpdateRecordPinCodeInClientsVector(short ConfirmedPassword,string AccountNumber, short PinCode ,vector <stClient>& vClients)
{
	//Ranged loop.
	for (stClient& Client : vClients)
	{
		if (Client.AccountNumber == CurrentClient.AccountNumber && Client.PinCode == CurrentClient.PinCode)
		{
			Client.PinCode = ConfirmedPassword;
			return true;
		}
	}
	return false;
}

bool ChangeCurrentClientPassword(short ConfirmedPassword, vector <stClient>& vClients)
{
	char answer = 'n';

	cout << "\n\nAre you sure you want Confirm changing your Password ? y/n ? ";
	cin >> answer;

	if (toupper(answer) == 'Y')
	{
		CurrentClient = ChangeClientOldPinCode(ConfirmedPassword);

		UpdateRecordPinCodeInClientsVector(ConfirmedPassword,
			CurrentClient.AccountNumber, CurrentClient.PinCode,vClients);

		SaveDataToFile(ClientsFileName, vClients);

		//Update Clients in Vector.
		vClients = LoadDataFromFile(ClientsFileName);

		cout << "\n\nDone your PinCode has been changed Successfully :-).";
		return true;
	}
	else
	{
		return false;
	}
}

void ChangePassword()
{
	cout << "===========================================\n";
	cout << "\t  Change Password Screen                        ";
	cout << "\n===========================================\n";

	vector <stClient> vClients = LoadDataFromFile(ClientsFileName);

	short Password = ReadNewPassword("Please Enter New Password ? ");

	while (CheckNewPasswordWithCurrentOne(Password))
	{
		cout << "\nSorry!! This Password is your old Password, Enter another new one ? ";
		cin >> Password;
	}

	short ConfirmedPassword = ReadNewPassword("\n\nPlease Confirm Your New Password ? ");

	while (CheckNewPasswordConfirmation(Password, ConfirmedPassword))
	{
		ConfirmedPassword = ReadNewPassword("\n\nPlease Confirm Your New Password ? ");
	}

	if (ChangeCurrentClientPassword(ConfirmedPassword, vClients))
	{
		system("pause > 0");
		system("cls");
		Login();
		return;
	}
	else
	{
		GoBackToMainMenue();
	}
}
