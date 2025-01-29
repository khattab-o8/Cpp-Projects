#pragma once
#include <iostream>
#include <string>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsUpdateCurrencyRateScreen : protected clsScreen
{
private:

	static string _ReadCurrencyCode()
	{
		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nCurrency is not found, Choose another one: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return CurrencyCode;
	}

	static float _ReadNewRate()
	{
		float NewRate = 0;

		cout << "\nEnter New Rate: ";
		NewRate = clsInputValidate::ReadFloatNumber();

		return NewRate;
	}

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\n" << setw(5) << left << "" << "_______________________________________\n";
		cout << "\n" << setw(5) << left << "" << "\t\t  Currency Card";
		cout << "\n" << setw(5) << left << "" << "_______________________________________\n";
		cout << "\n" << setw(7) << left << "" << "-> Country    : " << Currency.Country();
		cout << "\n" << setw(7) << left << "" << "-> Code       : " << Currency.CurrencyCode();
		cout << "\n" << setw(7) << left << "" << "-> Name       : " << Currency.CurrencyName();
		cout << "\n" << setw(7) << left << "" << "-> Rate(1$) = : " << Currency.Rate();
		cout << "\n" << setw(5) << left << "" << "_______________________________________\n";
	}

public:

	static void ShowUpdateCurrencyRateScreen()
	{
		_DrawScreenHeader("\t Update Currency Screen");

		clsCurrency Currency1 = clsCurrency::FindByCode(_ReadCurrencyCode());

		_PrintCurrency(Currency1);

		char Answer = 'n';

		cout << "\nAre you sure you want to update the rate of this Currency (y/n)? ";
		cin >> Answer;

		if (toupper(Answer) == 'Y') {

			cout << "\n\nUpdate Currency Rate:\n";
			cout << "______________________\n";

			float NewRate = _ReadNewRate();

			Currency1.UpdateRate(NewRate);

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency1);
		}
		else {

			cout << "\nOperation was Cancelled :-(\n";
		}
	}

};

