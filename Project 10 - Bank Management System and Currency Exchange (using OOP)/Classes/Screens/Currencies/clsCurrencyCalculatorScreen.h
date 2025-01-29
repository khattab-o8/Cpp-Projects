#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsCurrencyCalculatorScreen : protected clsScreen
{

private:

	static float _ReadAmount()
	{
		float Amount = 0;

		cout << "\nEnter Amount to Exchange: ";
		Amount = clsInputValidate::ReadFloatNumber();

		return Amount;
	}

	static clsCurrency GetCurrency(string Massage)
	{
		string CurrencyCode = "";

		cout << Massage;
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nInvalid Currency Code!!..Enter again: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return clsCurrency::FindByCode(CurrencyCode);
	}

	static void _PrintConvertingToUSD(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		_PrintCurrency(CurrencyFrom, "  Covert From:");

		float AmountInUSD = CurrencyFrom.ConvertToUSD(Amount);

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode();
		cout << " = " << AmountInUSD << " USD" << endl;
	}

	static void _PrintCurrencyCalculatorResult(clsCurrency CurrencyFrom, clsCurrency CurrencyTo, float Amount)
	{
		_PrintConvertingToUSD(CurrencyFrom, CurrencyTo, Amount);

		if (CurrencyTo.CurrencyCode() == "USD") {

			return;
		}

		cout << "\nConverting From USD to: \n";
		_PrintCurrency(CurrencyTo, "  Covert To:");

		cout << "\n" << Amount << " " << CurrencyFrom.CurrencyCode() << " = ";
		cout << CurrencyFrom.ConvertToOtherCurrency(CurrencyTo, Amount);
		cout << " " << CurrencyTo.CurrencyCode() << endl;
	}

	static void _PrintCurrency(clsCurrency Currency, string Massage)
	{
		cout << "\n" << setw(5) << left << "" << "_______________________________________\n";
		cout << "\n" << setw(5) << left << "" << "\t\t" << Massage;
		cout << "\n" << setw(5) << left << "" << "_______________________________________\n";
		cout << "\n" << setw(7) << left << "" << "-> Country    : " << Currency.Country();
		cout << "\n" << setw(7) << left << "" << "-> Code       : " << Currency.CurrencyCode();
		cout << "\n" << setw(7) << left << "" << "-> Name       : " << Currency.CurrencyName();
		cout << "\n" << setw(7) << left << "" << "-> Rate(1$) = : " << Currency.Rate();
		cout << "\n" << setw(5) << left << "" << "_______________________________________\n";
	}

public:

	static void ShowCurrencyCalculatorScreen()
	{
		char Answer = 'y';

		do
		{
			system("cls");
			_DrawScreenHeader("     Currency Calculator Screen");

			clsCurrency CurrencyFrom = GetCurrency("\nPlease Enter Currency1 Code : ");
			clsCurrency CurrencyTo = GetCurrency("\nPlease Enter Currency2 Code: ");

			float Amount = _ReadAmount();

			_PrintCurrencyCalculatorResult(CurrencyFrom, CurrencyTo, Amount);

			cout << "\nDo you want to perform another calculation? y/n ? ";
			cin >> Answer;

		} while (toupper(Answer) == 'Y');
	}

};

