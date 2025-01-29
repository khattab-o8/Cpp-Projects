#pragma once
#include <iostream>
#include "clsScreen.h"
#include "clsCurrency.h"
#include "clsInputValidate.h"
using namespace std;

class clsFindCurrencyScreen : protected clsScreen
{
private:

	enum enFindByCodeOrCountry { FindByCode = 1, FindByCountry = 2 };

	static short _ReadChoice()
	{
		short Choice = 0;

		cout << "\nFind By: [1] Code or [2] Country ? ";
		Choice = clsInputValidate::ReadShortNumberBetween(1, 2);

		return Choice;
	}

	static string _ReadCurrencyCode()
	{
		string CurrencyCode = "";

		cout << "\nPlease Enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExist(CurrencyCode))
		{
			cout << "\nInvalid Currency Code!!..Enter again: ";
			CurrencyCode = clsInputValidate::ReadString();
		}

		return CurrencyCode;
	}

	static string _ReadCountryName()
	{
		string CountryName = "";

		cout << "\nPlease Enter Country Name : ";
		CountryName = clsInputValidate::ReadString();

		while (!clsCurrency::IsCountryExist(CountryName))
		{
			cout << "\nInvalid Country Name!!..Enter again: ";
			CountryName = clsInputValidate::ReadString();
		}

		return CountryName;
	}

	static string _ReadCurrencyCodeOrCountryName(enFindByCodeOrCountry FindByCodeOrCountry)
	{
		switch (FindByCodeOrCountry)
		{
		case enFindByCodeOrCountry::FindByCode:
		{
			return _ReadCurrencyCode();
		}
		case enFindByCodeOrCountry::FindByCountry:
		{

			return _ReadCountryName();
		}
		}
	}

	static clsCurrency _FindCurrencyByCodeOrCountry(string CodeOrCountry, enFindByCodeOrCountry FindByCodeOrCountry)
	{
		switch (FindByCodeOrCountry)
		{
		case enFindByCodeOrCountry::FindByCode:
		{
			return clsCurrency::FindByCode(CodeOrCountry);
		}
		case enFindByCodeOrCountry::FindByCountry:
		{

			return clsCurrency::FindByCountry(CodeOrCountry);
		}
		}
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

	static void ShowFindCurrencyScreen()
	{
		_DrawScreenHeader("\t  FindCurrencyScreen");

		short Choice = (enFindByCodeOrCountry)_ReadChoice();
		string S1 = _ReadCurrencyCodeOrCountryName((enFindByCodeOrCountry)Choice);

		clsCurrency Currency = _FindCurrencyByCodeOrCountry(S1, (enFindByCodeOrCountry)Choice);

		cout << "\nCurrency Found :-)\n";
		_PrintCurrency(Currency);
	}

};

